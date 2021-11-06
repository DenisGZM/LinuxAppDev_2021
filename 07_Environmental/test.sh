#! /bin/bash

echo "Sha1 configure.ac" | ./rhasher > rhasher_res
sha1sum configure.ac > sha1sum_res
diff rhasher_res sha1sum_res
res=$?
rm -rf rhasher_res sha1sum_res;
if [ $res != "0" ]; then
    echo -e "Fail!\n";
    exit 1;
else
    echo "Success"
fi

echo "Md5 configure.ac" | ./rhasher > rhasher_res
md5sum configure.ac > md5sum_res
diff rhasher_res md5sum_res
res=$?
rm -rf rhasher_res md5sum_res;
if [ $res != "0" ]; then
    echo -e "Fail!\n";
    exit 1;
else
    echo "Success"
fi