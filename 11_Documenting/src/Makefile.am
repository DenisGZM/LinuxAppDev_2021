bin_PROGRAMS=binsearch

%.1:	%
	$(HELP2MAN) --no-info --output=$@ ./$<

lang:
	xgettext -c -k_ binsearch.c -o po/guess.pot
	msgmerge -U ../po/ru/guess.po ../po/guess.pot
	mkdir -p ../ru_RU/LC_MESSAGES
	msgfmt ../po/ru/guess.po -o ../ru_RU/LC_MESSAGES/guess.mo

clean-gen: gitclean

gitclean:
	git clean -fd