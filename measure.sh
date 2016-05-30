echo "Measuring $2"
echo -n "$1" | md5sum | cat - "$2" | (/usr/bin/time -f "%e" ./cipher > test_a.enc)
#openssl bf-ecb -nosalt -nopad -k "$1" -in "$2" -out test_b.enc
#diff test_a.enc test_b.enc | colordiff
rm -rf test_a.enc test_b.enc

