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

SystemBlock(SB):大分類  
FunctionModule(FM):中分類  
ProcessingUnit(PU):小分類  

 ![image](https://user-images.githubusercontent.com/29003588/93002044-c34c8100-f56e-11ea-8331-81d05efa8f19.png)  

## ファイル名・関数名規則  
Lから始まるもの  
　　SB間ヘッダーに入る関数  
大文字から始まるもの  
　　FM間ヘッダーに入る関数  
小文字から始まるもの  
　　PU間ヘッダーに入る関数  

もしビルドするならyottadbが必要なので、なかったらyottadbぽいところを消す感じで。  

## git上だとobjフォルダないので、手で作るか、makefileで作る必要がある

