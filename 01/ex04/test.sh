# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iurilandolt <iurilandolt@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 16:09:31 by iurilandolt       #+#    #+#              #
#    Updated: 2024/06/18 01:43:26 by iurilandolt      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

if [ "$#" -eq 1 -a "$1" == "-c" ]; then
    rm -rf test
    echo "Cleaned up the test directory."
    exit 0
fi

if [ "$#" -ne 2 ]; then
    echo "Usage: ./test.sh [find] [replace by]"
    exit 1
fi

if [ ! -f seditor ]; then
    echo "seditor executable not found. Please compile the code."
    exit 1
fi

mkdir -p test

touch test/test
echo "
Alice was beginning to get very tired of sitting by her sister on the bank, 
and of having nothing to do: once or twice she had peeped into the book her sister was reading,
but it had no pictures or conversations in it, and what is the use of a book,
thought Alice without pictures or conversation?
So she was considering in her own mind (as well as she could,
for the hot day made her feel very sleepy and stupid),
whether the pleasure of making a daisy-chain would be worth the trouble of getting up and picking the daisies,
when suddenly a White Rabbit with pink eyes ran close by her.
There was nothing so very remarkable in that;
nor did Alice think it so very much out of the way to hear the Rabbit say to itself,
Oh dear! Oh dear! I shall be late!
(when she thought it over afterwards, it occurred to her that she ought to have wondered at this,
but at the time it all seemed quite natural);
but when the Rabbit actually took a watch out of its waistcoat-pocket,
and looked at it, and then hurried on,
Alice started to her feet,
for it flashed across her mind that she had never before seen a rabbit with either a waistcoat-pocket,
or a watch to take out of it, and burning with curiosity, she ran across the field after it,
and fortunately was just in time to see it pop down a large rabbit-hole under the hedge.



test empty lines.


ok.




nice. 
" > test/test

touch test/empty
touch test/noread
echo "Don't read this." > test/noread
chmod -r test/noread

for file in test/test test/empty test/noread; do
    echo "Testing Seditor with $file"
    ./seditor "$file" "$1" "$2"
done

for file in test/test test/empty test/noread; do
    echo "Testing sed with $file"
    sed "s/$1/$2/g" "$file" > "${file}.sedreplace"
done

for file in test/test test/empty test/noread; do
    echo "Comparing Seditor with sed for $file"
    diff "${file}.sedreplace" "${file}.replace"
    if [ "$?" -ne 0 ]; then
        echo "Test failed."
    else
        echo "Test passed."
    fi
done