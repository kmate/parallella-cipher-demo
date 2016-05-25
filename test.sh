echo -n "$1" | md5sum | cat - "$2" | ./cipher > test.enc
openssl bf-ecb -d -nosalt -nopad -k "$1" -in test.enc -out test.dec
# diff -y <(xxd "$2") <(xxd test.dec) | colordiff
diff "$2" test.dec
rm -rf test.enc test.dec

