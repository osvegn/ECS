#!/bin/bash

c_files=$(find ./source -name "*.c" && find ./include -name "*.h" && find ./tests -name "*.c")

line1="\*"
line2="* Filename:"
line3="* Path:"
line4="* Created Date:"
line5="* Author:"
line6="\*"
line7="* Copyright (c) 2023 ECS"

rvalue=0

for file in $c_files
do
    if [ -f $file ]
    then
        error=0
        # check line 1 has '/*'
        if ! head -n 1 $file | grep -q "$line1"
        then
            echo "Error: $file does not start with /*"
            $error=$($error+1)
        fi
        # check line 2 has '* Filename:'
        if ! head -n 2 $file | tail -n 1 | grep -q "$line2"
        then
            echo "Error: $file does not have * Filename: on line 2"
            $error=$($error+1)
        fi
        # check line 3 has '* Path'
        if ! head -n 3 $file | tail -n 1 | grep -q "$line3"
        then
            echo "Error: $file does not have * Path: on line 3"
            $error=$($error+1)
        fi
        # check line 4 has '* Created Date:'
        if ! head -n 4 $file | tail -n 1 | grep -q "$line4"
        then
            echo "Error: $file does not have * Created Date: on line 4"
            $error=$($error+1)
        fi
        # check line 5 has '* Author:'
        if ! head -n 5 $file | tail -n 1 | grep -q "$line5"
        then
            echo "Error: $file does not have * Author: on line 5"
            $error=$($error+1)
        fi
        # check line 6 has '*'
        if ! head -n 6 $file | tail -n 1 | grep -q "$line6"
        then
            echo "Error: $file does not have * on line 6"
            $error=$($error+1)
        fi
        # check line 7 has '* Copyright (c) 2023 ECS'
        if ! head -n 7 $file | tail -n 1 | grep -q "$line7"
        then
            echo "Error: $file does not have * on line 7"
            error=$(($error+1))
        fi

        if [[ $error == 0 ]]
        then
            echo "$file: OK"
        else
            rvalue=1
            echo "$file: KO"
        fi
    fi
done
exit $rvalue