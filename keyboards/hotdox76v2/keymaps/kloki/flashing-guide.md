# Flashing the HotDox 76v2 Split Keyboard

## Prerequisites

-   QMK CLI installed (`qmk setup`)
-   USB cable
-   Both halves connected to each other via TRRS cable

## Quick flash (default: left half = USB)

With this method, always plug USB into the **left half** during normal use.

1. Connect the **left half** to your computer via USB
2. Enter bootloader mode (press the QK_BOOT key or the physical reset button)
3. Flash:
    ```sh
    qmk flash -kb hotdox76v2 -km kloki
    ```
4. Disconnect the left half
5. Connect the **right half** to your computer via USB
6. Enter bootloader mode again
7. Flash the same command:
    ```sh
    qmk flash -kb hotdox76v2 -km kloki
    ```
8. Disconnect, reconnect USB to the **left half** for normal use

Both halves receive identical firmware. During normal use the right half communicates through the TRRS cable.

## EE_HANDS flash (either side can be USB)

This writes handedness into each half's EEPROM, so QMK always knows which side is left/right regardless of which one has USB.

This only needs to be done **once per half** (or after an EEPROM reset). After that you can use the regular flash command.

### First-time setup

1. Connect the **left half** via USB, enter bootloader mode, then:
    ```sh
    qmk flash -kb hotdox76v2 -km kloki -bl dfu-split-left
    ```
2. Connect the **right half** via USB, enter bootloader mode, then:
    ```sh
    qmk flash -kb hotdox76v2 -km kloki -bl dfu-split-right
    ```

### Subsequent flashes

Once handedness is stored in EEPROM, use the regular flash command for both halves:

```sh
qmk flash -kb hotdox76v2 -km kloki
```

The EEPROM value persists across firmware updates.

### Required config change

Add this to `config.h` (or your keymap's `config.h`):

```c
#define EE_HANDS
```

## Entering bootloader mode

There are two ways to enter the bootloader:

1. **QK_BOOT keycode** - press the key mapped to `QK_BOOT` in your keymap (on the \_FN layer, top-left of right half)
2. **Physical reset button** - press the reset button on the PCB (usually accessible through a small hole on the bottom of the case)

## Troubleshooting

-   **OLEDs are flipped** - you plugged USB into the right half without EE_HANDS configured. Either switch USB to the left half, or set up EE_HANDS as described above.
-   **"Waiting for bootloader"** - the keyboard hasn't entered bootloader mode yet. Press the reset button or QK_BOOT key.
-   **Right half not responding** - check the TRRS cable connection between the halves. The right half is powered and communicates through this cable during normal use.
