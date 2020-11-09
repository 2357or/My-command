# My-command
- 自作ターミナルコマンド
- [参考記事](https://note.com/2357note/n/ne9c0fc219f37)

## セットアップ
1. パスを通す
    - [dotfiles](https://github.com/2357or/dotfiles)の.zprofileならばすでに通っている
    - そうでないならば以下を実行  
    `echo "export PATH=$HOME/My-command/bin:$PATH" > ~/.zprofile`
1. `cmd help` を実行してみる
    - 実行できた --> セットアップ完了
    - 実行できない --> 次の「実行権限を付与」へ
1. 以下のコマンドを実行、sudoコマンドを使用するのでパスワードを入力すること
    ```bash
    sudo chmod 755 ~/My-command/bin/cmds/help
    sudo chmod 755 ~/My-command/bin/cmds/timer
    ```


## コマンドリスト

cmd help
    - ヘルプの表示
cmd timer
    - bash簡易タイマー
