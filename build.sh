#!/bin/bash

cd src
make $1
cd ..
mv src/mazer ./bin
