key=$1
keylen=${#key}
keydata=`for c in \`grep -o . <<< $key\`; do echo -n $c | od -An -t uC; done`
keyinput=`echo -e "$keylen\n$keydata"`
echo -n "$keyinput" | cat - "$2" | ./cipher

