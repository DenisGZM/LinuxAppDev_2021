GENERATES = prog prog-* README *.a *.so 
TRASH = *.o *~ o.* *_out_*
CFLAGS = -Wall

all: README prog

prog: const.o fun.o prog.o
prog-a: prog.o liboutput_static.a
	cc -L. prog.o -loutput_static -o $@
prog-so: prog.o liboutput.so
	cc -L. prog.o -loutput -o $@

README: prog
	./$< 2> $@

fun.o: outlib.h

liboutput_static.a: const.o fun.o
	ar -rcs $@ const.o fun.o

liboutput.so: fun.o const.o
	cc -fPIC -c -o const.o const.c
	cc -fPIC -c -o fun.o fun.c
	cc -shared fun.o const.o -o liboutput.so

run_prog: prog
	./prog 1> prog_out_0
	./prog abc cdf efr > prog_out_3

run_prog_a: prog-a
	./prog-a 1> prog_a_out_0
	./prog-a abc cdf efr > prog_a_out_3

run_prog_so: prog-so
	LD_LIBRARY_PATH=`pwd` ./prog-so 1> prog_so_out_0
	LD_LIBRARY_PATH=`pwd` ./prog-so abc cdf efr > prog_so_out_3

test: run_prog run_prog_a run_prog_so
	cmp prog_out_0 prog_a_out_0
	cmp prog_a_out_0 prog_so_out_0
	cmp prog_out_3 prog_a_out_3
	cmp prog_a_out_3 prog_so_out_3
clean:
	rm -f $(TRASH)

distclean: clean
	rm -rf $(GENERATES)