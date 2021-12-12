SUBDIRS = src
lang:
	xgettext -c -k_ src/binsearch.c -o po/guess.pot
	msgmerge -U po/ru/guess.po po/guess.pot
	mkdir -p ru_RU/LC_MESSAGES
	msgfmt po/ru/guess.po -o ru_RU/LC_MESSAGES/guess.mo

@DX_RULES@

all-local:	doxygen-doc

clean-gen: gitclean

gitclean:
	git clean -fd