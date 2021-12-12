bin_PROGRAMS=binsearch

%.1:	%
	$(HELP2MAN) --no-info --output=$@ ./$<

doc_main_page: binsearch
	echo -E "/// @mainpage\n# Documentation\n\n" >> Doc.md
	./binsearch --help >>& Doc.md 