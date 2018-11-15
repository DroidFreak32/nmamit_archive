#!/bin/sh

echo"searching for pattern $1 from the file $2"
grep $1 $2
echo"seleted records shown above"
