 #!/bin/bash



if [ -f cipher.c ]
then


gcc -o cipher cipher.c

#invalid input
echo "Test 1
input:
-e: <empty>
-key = <empty>
-word: <empty

output:"

./cipher

echo exit code: $?



echo "
Test 2
input:
-e: -k
-key = 5
-word: HELLO THERE

output:"

./cipher -k 5 "HELLO THERE"

echo exit code: $?


echo "
Test 3
input:
-e: -e
-key = 4.r
-word: HELLOTHERE

output:"

./cipher -e 4.r HELLOTHERE

echo exit code: $?



#valid input

echo "
Test 4
input:
-e: decryption
-key = 3
-word: TIETSHSSSCEMSAEIAREG

output:"

./cipher -d 3 TIETSHSSSCEMSAEIAREG

echo exit code: $?

echo "
Test 5
input:
-e: encryption
-key = 5
-word: THISISASECRETMESSAGE

output:"

./cipher -e 5 THISISASECRETMESSAGE

echo exit code: $?

echo "
Test 6
input:
-e: encryption
-key = 3
-word: THISISASECRETMESSAGE

output:"

./cipher -e 3 THISISASECRETMESSAGE

echo exit code: $?


echo "
Test 7
input:
-e: encryption
-key = 10
-word: THISISASECRETMESSAGE

output:"

./cipher -e 10 THISISASECRETMESSAGE

echo exit code: $?

echo "
Test 8
input:
-d: decryption
-key = 5
-word: TESHSCSAIAREGSSEMEIT

output:"

./cipher -d 5 TESHSCSAIAREGSSEMEIT

echo exit code: $?


echo "
Test 9
input:
-d: decryption
-key = 3
-word: TIETSHSSSCEMSAEIAREG

output:"

./cipher -d 3 TIETSHSSSCEMSAEIAREG

echo exit code: $?


echo "
Test 10
input:
-e: encryption
-key = 5
-word: THIS IS A SECRET MESSAGE

output:"

./cipher -e 10 "THIS IS A SECRET MESSAGE"

echo exit code: $?

echo "
Test 11
input:
-d: decryption
-key = 5
-word: "TAH  TISSESIER C"

output:"

./cipher -d 5 "TAH  TISSESIER C"

echo exit code: $?



else echo "It looks like cipher.c is not a file in the current directory"
fi

