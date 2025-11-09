# NEO60 - PCB

![neo60](https://i.imgur.com/vOyu6SFh.jpg)

A 60% made by NEO Studio.

* Keyboard Maintainer: [NEO Studio](https://github.com/owlab-git)
* Hardware Supported: neo60 PCB
* Hardware Availability: IC: https://qwertykeys.notion.site/Neo-65-6c8ae7895ec442dea809057c3dc5e113

This is a fork of https://github.com/lizhenmingdirk/qmk_firmware/tree/e9be341dd835a71bab2f3fa76ed85ac129e1be7f/keyboards/neo/neo60/keymaps/via with the following differences:
1. `MK_3_SPEED` is enabled
2. Debounce keys are disabled.

## Usage

Set up QMK, then run

```sh
qmk compile -kb neo/neo60 -km e-liang
```

To configure the keyboard, go to https://www.usevia.app/ and load the [`Neo60Cu_wired.json`](./keymaps/e-liang/Neo60Cu_wired.json) file.

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
