# title : Makefile for kyousin_banner
# begin : 2017-05-10 14:35:47 

CC = gcc
#CPARAMS = 
#INCLUDES = -I 
LIBS = -lXt -lX11
#LDFLAGS = -w -r

# ターゲット
TARGET = place-bitmap

# バナー表示プログラムの生成
place-bitmap: place-bitmap.c
	$(CC) $(TARGET).c -o $(TARGET) $(LIBS) 

# コードの整理
clean:
	$(RM) place-bitmap
	$(RM) *~

# インストール
install:
	mkdir /opt/kyousin_banner/
	cp kyousin.awk  /opt/kyousin_banner/
	cp kyousin.png  /opt/kyousin_banner/
	cp place-bitmap /opt/kyousin_banner/
