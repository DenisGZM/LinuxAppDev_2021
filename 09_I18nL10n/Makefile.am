bin_PROGRAMS=binsearch
src_PROGRAMS=binsearch.c

lang: binsearch.c
	xgettext -c -k_ binsearch.c -o po/guess.pot
	msgmerge -U po/ru/guess.po po/guess.pot
	msgfmt po/ru/guess.po -o ru_RU.UTF-8/LC_MESSAGES/guess.mo

gitclean:
	git clean -fd