#!/usr/bin/env python3
# SPDX-License-Identifier: BSD-3-Clause
"""Validate LPC8xx vector checksum and CRP word in a generated binary."""

from __future__ import annotations

import argparse
import struct
import sys
from pathlib import Path

VECTOR_CHECKSUM_OFFSET = 0x1C
CRP_OFFSET = 0x2FC
SAFE_CRP_VALUES = {0xFFFFFFFF, 0x4E697370}


def read_word(data: bytes, offset: int) -> int:
    if len(data) < offset + 4:
        raise ValueError(f"image is too small for word at 0x{offset:x}")
    return struct.unpack_from("<I", data, offset)[0]


def validate(path: Path) -> list[str]:
    data = path.read_bytes()
    errors: list[str] = []

    if len(data) < CRP_OFFSET + 4:
        errors.append(f"{path}: image is too small to contain CRP at 0x{CRP_OFFSET:x}")
        return errors

    vector_words = [read_word(data, offset) for offset in range(0, 0x20, 4)]
    checksum = sum(vector_words) & 0xFFFFFFFF
    if checksum != 0:
        actual = read_word(data, VECTOR_CHECKSUM_OFFSET)
        errors.append(
            f"{path}: invalid LPC vector checksum at 0x{VECTOR_CHECKSUM_OFFSET:x}; "
            f"sum=0x{checksum:08x}, checksum_word=0x{actual:08x}"
        )

    crp = read_word(data, CRP_OFFSET)
    if crp not in SAFE_CRP_VALUES:
        errors.append(
            f"{path}: unsafe CRP word 0x{crp:08x} at 0x{CRP_OFFSET:x}; "
            "expected 0xffffffff or 0x4e697370"
        )

    return errors


def main(argv: list[str]) -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("image", type=Path)
    args = parser.parse_args(argv)

    errors = validate(args.image)
    if errors:
        for error in errors:
            print(error, file=sys.stderr)
        return 1

    print(f"{args.image}: LPC vector checksum and CRP are valid")
    return 0


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
