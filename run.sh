echo -n "$1" | md5sum | cat - "$2" | ./cipher

