.IPHONY: clean
move: move.c
	gcc -o move move.c

lib_prot: prot.c
	gcc prot.c -ldl -fPIC -shared -O0 -o prot.so

test_strace_inj: move
	./test_strace_inj.sh

test_prot: lib_prot move
	./test_prot.sh

test: test_strace_inj test_prot

clean:
	git clean -fd
