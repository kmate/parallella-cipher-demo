cp "$2" "$2.enc"
echo -n "$1" | echo "`md5sum | cut -d' ' -f1`$2.enc" | ./cipher
openssl bf-ecb -d -nosalt -nopad -k "$1" -in "$2.enc" -out "$2.dec"
diff "$2" "$2.dec" | colordiff
rm -rf "$2.enc" "$2.dec"

