# yottadbと多段階層のmakefile練習

今のところ何もしないシステムだが、応用がききそうなリポジトリに成長させたい。  

## yottadb

yottadbはkey-value形式のデータベースです。  
参考資料はこれら。  
https://yottadb.com  
https://docs.yottadb.com/MultiLangProgGuide/cprogram.html  

とんでもなくマイナーだけど、可能性を感じる。DBの性能で悩まされる前に色々触っておこう。  


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

