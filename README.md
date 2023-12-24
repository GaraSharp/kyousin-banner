---
title : Readme.md
begin : 2017-05-10 14:40:19 
modif : 2023-12-24 18:34:42 
---

「凶シンモニター」(準備中)
==============

~~他人のTwitterページ(Tweetではありません、念の為)を取り込み、何かしら変更があった場合に画面上にバナーを表示するという単純なプログラムです。~~
Twitter がwget で取得不能なので、別の手段を模索中。

現在は、ランダムに時間待ちをして、バナー表示するだけのコードと成り下がっております。

# ソースの入手

git clone GaraSharp/kyousin-banner 

でイケる ?

# 作成

1. 先ずは、Xt, Xlib関連のヘッダを導入しておきます

```Ubuntu
$ sudo apt-get install libxt-dev
```

2. コンパイル

```
make
```

今は、banner 表示だけしか能のないものなので、インストールの必要はありません。

make して出来た place-bitmap を実行して、お楽しみ下さい。
