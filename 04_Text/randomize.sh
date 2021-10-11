#!/bin/bash

tmp_file=`mktemp`
while IFS= read -r line;
do
    printf '%s\n' "$line" >> $tmp_file
done

lines=`wc -l $tmp_file | cut -d " " -f 1`
symbs=`wc -m $tmp_file | cut -d " " -f 1`
bytes_id=`shuf -i 1-$symbs`

echo -e $bytes_id


tput clear
i=1
while [[ $i -le "$symbs" ]];
do
    sleep $1
    cur_byte=`echo -e $bytes_id | cut  -d' ' -f$i`
    line=1
    g_pos=0
    prev_pos=0
    while /bin/true;
    do
        line_size=`cut $tmp_file -d$'\n' -f$line | wc -m`
        let "next_pos = $g_pos + $line_size"
        if [[ $next_pos -ge $cur_byte ]]; 
        then
            break;
        fi
        prev_pos=$g_pos
        g_pos=$next_pos
        (( line++ ))
    done

    let "line= $line - 1";
    let "g_pos= $cur_byte - $g_pos - 1";
    byte=`cut -z $tmp_file -b $cur_byte | rev | rev`

    tput cup $line $g_pos;
    echo -e "$byte"
    (( i++ ))
done

tput cup $lines 0
rm -rf $tmp_file
