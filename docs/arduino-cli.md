# Arduino CLI Package Notes

## Manual Install

Arduino CLI discovers third-party packages under:

```text
<sketchbook>/hardware/<vendor>/<architecture>/
```

For this repo, the vendor is `zackees` and architecture is `lpc8xx`, producing
these FQBNs:

```text
zackees:lpc8xx:lpc845brk
zackees:lpc8xx:lpcxpresso804
zackees:lpc8xx:lpcxpresso845max
```

Use a symlink or junction from the sketchbook hardware directory to the repo
checkout during development.

## Tool Dependencies

`platform.txt` expects Arduino's `arm-none-eabi-gcc` tool to be installed. One
simple way to install it during local validation is:

```sh
arduino-cli core update-index
arduino-cli core install arduino:sam
```

OpenOCD/CMSIS-DAP upload recipes use Arduino's installed `openocd` tool when
available. Manual ISP is documented as a fallback, not as the default install
path.

## Board Manager

Board Manager support requires a published archive and package index entry with
URL, archive size, checksum, and `toolsDependencies`. This repository does not
publish those values until the first release archive exists.
