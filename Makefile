all: myenv

myenv: myenv.c
	cc -D_GNU_SOURCE -Wall -std=c99 -o myenv myenv.c

