# myprintenvプログラムの作成

```printenv```コマンドのクローン```myprintenv```プログラムを作りなさい．

### 作成手順
1. printenvの仕様を調べる<br>
オンラインマニュアル（```man 1 printenv```）を読んだり，
```printenv```を実際に実行したりして，
printenvプログラムの仕様を調べる．

2. myprintenvプログラムを作る<br>
レポジトリをクローンし```myprintenv.c```を編集してプログラムを完成する．
プログラムはなるべく本物のprintenvと同じ動作をするように作る．

### コンパイル方法
```Makefile```を準備してあるので```make```コマンドでコンパイルできる．

```
$ make
cc -Wall -std=c99 -o myprintenv myprintenv.c
$
```
