echo "Measuring $2"
cp "$2" "$2.enc"
echo -n "$1" | echo "`md5sum | cut -d' ' -f1`$2.enc" | (/usr/bin/time -f "%e" ./cipher)
/usr/bin/time -f "%e" openssl bf-ecb -nosalt -nopad -k "$1" -in "$2" -out "$2.ref.enc"
diff "$2.enc" "$2.ref.enc" | colordiff
rm -rf "$2.enc" "$2.ref.enc"

