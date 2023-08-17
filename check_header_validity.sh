#!/bin/bash

c_files=$(find . -name "*.c" && find . -name "*.h")

for file in $c_files
do
    if [ -f $file ]
    then
        # check line 1 has '/*'
        if ! head -n 1 $file | grep -q "\*"
        then
            echo "Error: $file does not start with /*"
        fi
        # check line 2 has '* Filename:'
        if ! head -n 2 $file | tail -n 1 | grep -q "* Filename:"
        then
            echo "Error: $file does not have * Filename: on line 2"
        fi
        # check line 3 has '* Path'
        if ! head -n 3 $file | tail -n 1 | grep -q "* Path:"
        then
            echo "Error: $file does not have * Path: on line 3"
        fi
        # check line 4 has '* Created Date:'
        if ! head -n 4 $file | tail -n 1 | grep -q "* Created Date:"
        then
            echo "Error: $file does not have * Created Date: on line 4"
        fi
        # check line 5 has '* Author:'
        if ! head -n 5 $file | tail -n 1 | grep -q "* Author:"
        then
            echo "Error: $file does not have * Author: on line 5"
        fi
        # check line 6 has '*'
        if ! head -n 6 $file | tail -n 1 | grep -q "\*"
        then
            echo "Error: $file does not have * on line 6"
        fi
        # check line 7 has '* Copyright (c) 2023 ECS'
        if ! head -n 7 $file | tail -n 1 | grep -q "* Copyright (c) 2023 ECS"
        then
            echo "Error: $file does not have * on line 7"
        fi

    fi
done