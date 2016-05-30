cp "$2" "$2.enc"
echo -n "$1" | echo "`md5sum | cut -d' ' -f1`$2.enc" | ./cipher
cat "$2.enc"
rm -rf "$2.enc"

