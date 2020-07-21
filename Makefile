all: myprintenv

myprintenv: myprintenv.c
	cc -Wall -std=c99 -o myprintenv myprintenv.c

