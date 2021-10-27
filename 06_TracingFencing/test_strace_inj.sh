#/bin/bash

cp move.c infile
strace -ewrite -e fault=write:error=EPERM:when=2 ./move infile outfile 2> /dev/null
if [ $? -eq 30 ] && [ -f infile ] && [ ! -f outfile ]; then
    echo -e "Successfully failed on write!\n";
fi

cp move.c infile
strace -eread -e fault=write:error=EPERM:when=2 ./move infile outfile 2> /dev/null
if [ $? -eq 30 ] && [ -f infile ] && [ ! -f outfile ]; then
    echo -e "Successfully failed on read!\n";
fi

rm -rf infile
touch outfile
./move infile outfile  2> /dev/null
if [ $? -eq 20 ] && [ ! -f infile ] && [ -f outfile ]; then
    echo -e "Successfully checked if file exist!\n";
fi

touch infile
strace -e fault=close:error=EPERM:when=4 ./move infile outfile 2> /dev/null
if [ $? -eq 66 ] && [ -f infile ] && [ -f outfile ]; then
    echo -e "Epic fail happened! Couldn't close outfile. Leave it as is!\n";
fi

rm -rf infile outfile