# MW75R2

![MW75R2](https://i.imgur.com/S9Gd81b.jpg?1)

Support Atmega32u4 keyboard.

* Keyboard Maintainer: [TW59420](https://github.com/TW59420)
* Hardware Supported: Atmega32u4

Make example for this keyboard (after setting up your build environment):

    make mwstudio/mw75r2:default 

Flashing example for this keyboard:

    make mwstudio/mw75r2:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader
* **Physical reset button**: Short press the button on the back of the PCB to enter the Bootloader and flash the firmware
* **Keycode in layout**: Press the key mapped to RESET if it is available
