#! /bin/bash

for i in *.in
do

file=${i%.*}
./../program < "${file}".in > "${file}".txt

if ! (cmp --silent -- "${file}.out" "${file}.txt"); then
echo "$file" are diferent
echo
diff "${file}".out "${file}".txt
echo
echo
fi
rm "${file}".txt
done
