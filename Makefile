all: myenv

myenv: myenv.c
	cc -Wall -std=c99 -o myenv myenv.c

