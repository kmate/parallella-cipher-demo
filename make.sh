rm -rf gen/*
rm -rf cipher
cabal build
dist/build/parallella-cipher-demo/parallella-cipher-demo
gcc -std=gnu99 -D_BSD_SOURCE -Iinclude -I../imperative-edsl/include ../imperative-edsl/csrc/chan.c gen/cipher.c -lpthread -o cipher

