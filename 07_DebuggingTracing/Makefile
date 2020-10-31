all: libfakeaboart.so abort

libfakeaboart.so: fakeabort.c
	gcc fakeabort.c -ldl -fPIC -shared -O0 -o libfakeabort.so

abort: fakemain.c
	gcc -o abort -O0 fakemain.c

test-all: test test-fake
.ONESHELL:
test: libfakeaboart.so abort
	-LD_PRELOAD=`pwd`/libfakeabort.so ./abort
	res=$$?
	if [ $$res = 134 ]; then echo "OK - ABORT";
	elif [ $$res = 137 ]; then echo "NOT OK - KILLED";
	fi;

test-fake: libfakeaboart.so abort
	FAKEABORT=1 LD_PRELOAD=`pwd`/libfakeabort.so ./abort
	res=$$?
	if [ $$res = 134 ]; then echo "NOT OK - ABORT";
	elif [ $$res = 137 ]; then echo "OK - KILLED";
	fi;
