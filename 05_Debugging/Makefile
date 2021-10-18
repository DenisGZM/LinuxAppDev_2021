
.IPHONY: clean

range: range.c
	gcc range.c -o range -g -O0
test: range
	gdb < print_5.in ./range |& grep @@@ | grep = | awk -F "= " '{ print $$2 }' > print_5.out
	diff print_5.out print_5.exp

	gdb < print_some.in ./range |& grep @@@ | grep = | awk -F "= " '{ print $$2 }' > print_some.out
	diff print_some.out print_some.exp
clean: 
	rm -rf print_some.out print_5.out range