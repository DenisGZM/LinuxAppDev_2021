#!/bin/bash

# Makefile code:
# touch PROTECTED_file
# LD_PRELOAD=./prot.so ./move PROTECTED_file abcd
# if [ ! -f PROTECTED_file ]; then \
# 	echo Failed! Protected file deleted; \
# else \
# 	echo Success!; \
# fi

# ./move PROTECTED_file abcd
# if [ -f PROTECTED_file ]; then \
# 	echo Failed! File wasnt deleted; \
# else \
# 	echo Success!; \
# fi
# rm -rf PROTECTED_file abcd
# 
# but it print all these operators...

touch PROTECTED_file
LD_PRELOAD=./prot.so ./move PROTECTED_file abcd
ls PROTECTED_file >& /dev/null
if [ $? == "2" ]; then
    echo Failed! Protected file deleted;
else
    echo Success!;
fi

./move PROTECTED_file abcd
ls PROTECTED_file >& /dev/null
if [ $? != "2" ]; then

    echo Failed! File wasnt deleted;
else
    echo Success!;
fi
rm -rf PROTECTED_file abcd