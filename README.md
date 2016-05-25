# parallella-cipher-demo
Demo application for encryption on Parallella using RAW-Feldspar and Zeldspar

## Instructions

### Preparation

    git clone git@github.com:emilaxelsson/imperative-edsl
    git clone git@github.com:emilaxelsson/raw-feldspar
    git clone git@github.com:koengit/zeldspar
    git clone git@github.com:kmate/raw-feldspar-mcs
    git clone git@github.com:kmate/parallella-cipher-demo
    cd parallella-cipher-demo
    cabal sandbox init
    cabal sandbox add-source ../imperative-edsl
    cabal sandbox add-source ../raw-feldspar
    cabal sandbox add-source ../zeldspar
    cabal sandbox add-source ../raw-feldspar-mcs
    cabal install --constraint="language-c-quote -full-haskell-antiquotes"

### Usage

To build, use

    ./make.sh

or on a Parallella:

    ./make_epiphany.sh

Encrypt a file:

    ./run this-is-my-key input-file.dat > encrypted-file.dat

## Known issues

* The current implementation has a really bad performance as it does the processing wiht block-sized (64bit) chunk transfers
* It should be compatible with `openssl`, but it is currently not. Hopefully the data encoded with the future versions could be decoded like:

    ~~~
    openssl bf-ecb -nosalt -nopad -d -k this-is-my-key -in encrypted-file.dat > decrypted-file.dat
    ~~~
