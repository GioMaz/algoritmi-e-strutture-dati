#!/usr/bin/env bash

for dir in $(ls -d */)
do
    rm $dir/Makefile
done
