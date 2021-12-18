bin_PROGRAMS = binsearch

noinst_DATA = binsearch.mo

man1_MANS = binsearch.1

%.1:	%
	$(HELP2MAN) --no-info --output=$@ ./$<
	
%.mo:	%.c
	xgettext -c -k_ $< -o ../po/$(*F).pot
	msgmerge -U ../po/ru/$(*F).po ../po/$(*F).pot
	mkdir -p ../ru_RU/LC_MESSAGES
	msgfmt ../po/ru/$(*F).po -o ../ru_RU/LC_MESSAGES/$(*F).mo
	mkdir -p $(DESTDIR)$(localedir)/ru_RU/LC_MESSAGES
	cp ../ru_RU/LC_MESSAGES/$(*F).mo $(DESTDIR)$(localedir)/ru_RU/LC_MESSAGES/$(*F).mo