# Keyball61用 カスタムファームウェア


## オリジナルの情報はこちらを参照してください

https://github.com/Yowkees/keyball


## オリジナルからの変更点

1. Automouse Layer の有効化

- QMK標準機能の `POINTING_DEVICE_AUTO_MOUSE_ENABLE` を有効にしています。トラボを動かすと Layer2が有効になります。 
- 通常この機能を有効にした場合、MOUSE関連のキーコード以外が謳歌された場合デフォルトレイヤーに戻りますが `SCRL_MO` を押下した場合は戻らないようにしています。

2. サブ側(USBを接続していない側)のOLEDに`ビルド番号` `keymap名` `Uptime` を表示するようにしています。

これらのカスタマイズを行うため一部LED効果をコメントアウトしています。

## How to build

1. Check out this repository.

    ```console
    $ git clone https://github.com/hiroki-tagami/keyball.git keyball
    ```

2. Check out [qmk/qmk_firmware](https://github.com/qmk/qmk_firmware/) repository in another place.

    ```console
    $ git clone https://github.com/qmk/qmk_firmware.git --depth 1 --recurse-submodules --shallow-submodules -b 0.22.3 qmk
    ```

    Currently Keyball firmwares are verified to compile with QMK 0.22.3

3. Create a symbolic link to this `keyball/` directory from [qmk/qmk_firmware]'s `keyboards/` directory.

    ```console
    $ ls
    keyball/ qmk/

    $ cd qmk/keyboards
    $ ln -s ../../keyball/qmk_firmware/keyboards/keyball keyball
    $ ls keyball/
    drivers/  keyball39/  keyball44/  keyball46/  keyball61/  lib/  one47/  readme.md
    $ cd ..
    ```

4. `make` your Keyball firmware.

    ```console
    # Build Keyball39 firmware with "default" keymap
    $ make SKIP_GIT=yes keyball/keyball39:default

    # Build Keyball44 firmware with "default" keymap
    $ make SKIP_GIT=yes keyball/keyball44:default

    # Build Keyball61 firmware with "default" keymap
    $ make SKIP_GIT=yes keyball/keyball61:default
    ```

There are three keymaps provided at least:

* `via` - Standard version with [Remap](https://remap-keys.app/) or VIA to change keymap
* `test` - Easy-to-use version for checking operation at build time
* `default` - Base version for creating your own customized firmware

## 参考資料

[keycode一覧](https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md)
[OLEDの基礎知識](https://qiita.com/koktoh/items/3d057e747915aee814cd)