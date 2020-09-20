# yottadbと多段階層のmakefile練習

今のところ何もしないシステムだが、応用がききそうなリポジトリに成長させたい。  

## yottadb

yottadbはkey-value形式のデータベースです。  
参考資料はこれら。  
https://yottadb.com  
https://docs.yottadb.com/MultiLangProgGuide/cprogram.html  

とんでもなくマイナーだけど、可能性を感じる。DBの性能で悩まされる前に色々触っておこう。  

## 環境

```
ubuntu@ubuntu:~/workspace/c/tmp$ uname -a
Linux ubuntu 4.15.0-1068-raspi2 #72-Ubuntu SMP PREEMPT Fri Aug 14 05:09:54 UTC 2020 aarch64 aarch64 aarch64 GNU/Linux
ubuntu@ubuntu:~/workspace/c/tmp$ lsb_release -a
No LSB modules are available.
Distributor ID: Ubuntu
Description:    Ubuntu 18.04.5 LTS
Release:        18.04
Codename:       bionic
ubuntu@ubuntu:~/workspace/c/tmp$ gcc -v
Using built-in specs.
COLLECT_GCC=gcc-8
COLLECT_LTO_WRAPPER=/usr/lib/gcc/aarch64-linux-gnu/8/lto-wrapper
Target: aarch64-linux-gnu
Configured with: ../src/configure -v --with-pkgversion='Ubuntu/Linaro 8.4.0-1ubuntu1~18.04' --with-bugurl=file:///usr/share/doc/gcc-8/README.Bugs --enable-languages=c,ada,c++,go,d,fortran,objc,obj-c++ --prefix=/usr --with-gcc-major-version-only --program-suffix=-8 --program-prefix=aarch64-linux-gnu- --enable-shared --enable-linker-build-id --libexecdir=/usr/lib --without-included-gettext --enable-threads=posix --libdir=/usr/lib --enable-nls --enable-clocale=gnu --enable-libstdcxx-debug --enable-libstdcxx-time=yes --with-default-libstdcxx-abi=new --enable-gnu-unique-object --disable-libquadmath --disable-libquadmath-support --enable-plugin --enable-default-pie --with-system-zlib --disable-libphobos --enable-multiarch --enable-fix-cortex-a53-843419 --disable-werror --enable-checking=release --build=aarch64-linux-gnu --host=aarch64-linux-gnu --target=aarch64-linux-gnu
Thread model: posix
gcc version 8.4.0 (Ubuntu/Linaro 8.4.0-1ubuntu1~18.04)
ubuntu@ubuntu:~/workspace/c/tmp$
```

## 実行例

```
ubuntu@ubuntu:~/workspace/c/tmp/Bfp$ bin/Bfpmainproc
Bfpalmdrive
Bfpcommod
Udvmanprint
software versoin etc...
worldydbhello
ubuntu@ubuntu:~/workspace/c/tmp/Bfp$ bin/Bfpmainproc -v
system infomation...
etc...
ubuntu@ubuntu:~/workspace/c/tmp/Bfp$
```

## コード設計

### 階層による分類

BlockFucntins(BF):大分類  
FunctionModule(FM):中分類  
ProcessingUnit(PU):小分類  

 ![image](https://user-images.githubusercontent.com/29003588/93002044-c34c8100-f56e-11ea-8331-81d05efa8f19.png)  

## ファイル名・関数名規則  
Lから始まるもの  
　　BF間ヘッダーに入る関数  
大文字から始まるもの  
　　FM間ヘッダーに入る関数  
小文字から始まるもの  
　　PU間ヘッダーに入る関数  

もしビルドするならyottadbが必要なので、なかったらyottadbぽいところを消す感じで。  

## BF機能(想定)

- Bfp:メイン機能のスタート。最初に起動するプロセス。

- Daf:データアクセス機能を提供する。

- Udv:わからない

## git上だとobjフォルダないので、手で作るか、makefileで作る必要がある

