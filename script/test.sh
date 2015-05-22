#!/usr/bin/env bash

./build/bin/ArrayListTest
exit1=$?

./build/bin/StackTest
exit2=$?

exit $(($exit1+$exit2))