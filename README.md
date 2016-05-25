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

    ./run.sh this-is-my-key input-file.dat > encrypted.dat

The encrypted file could be restored like this:

    openssl bf-ecb -d -nosalt -nopad -k this-is-my-key -in encrypted.dat -out decrypted.dat

## Known issues

* The current implementation has a really bad performance as it does the processing wiht block-sized (64bit) chunk transfers

