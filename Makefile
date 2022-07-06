all: myenv

myenv: myenv.c myputenv.c myputenv.h
	cc -D_GNU_SOURCE -Wall -std=c99 -o myenv myenv.c myputenv.c

clean:
	rm -f myenv

