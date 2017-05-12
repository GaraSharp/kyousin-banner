「凶シンモニター」
==============

(first appearance on 2017-05-12 18:27)

他人のTwitterページ(Tweetではありません、念の為)を取り込み、何かしら変更があった場合に画面上にバナーを表示するという単純なプログラムです。

#  ソースの入手

git clone https://github.com/GaraSharp/kyousin-banner

でイケる ?


#  導入

1.  先ずは、Xt, Xlib関連のヘッダを導入しておきます

```Ubuntu
$ sudo apt-get install libxt-dev
```

2. 必要に応じて、kyousin.awk をいじって下さい

awkスクリプト中に、参照するTwitterページが埋め込んであります。
変更がない場合、 「地震速報」様 (@earthquake_jp) のTwitterページをダウンロードします。


3. コンパイル、インストール

```コンパイル 
$ make
```

実行ファイルは、/opt/kyousin_banner/ に置かれます。

```インストール
$ sudo make install
```


あと、GNOMEデスクトップの場合、kyousin.desktop ファイルをダブルクリックすると、
「信用できないアプリケーションのランチャー」というダイアログが出ます。

「Trust and Launch」をクリックすると、ランチャーとして登録され、実行されます。
(古いGNOMEの場合、ファイルのプロパティから実行属性を付ける事で、実行可能ランチャーに出来ます)

更に、

```for GNOME
$ cp kyousin.desktop ~/.local/share/applications/
```

とすると、チョットいい感じ ?
(Superキーを押して、kyo、とタイプインしてみてネ)

