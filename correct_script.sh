#!/bin/bash

# faire tous les tests
declare -i nb=1
string=tests/test
make re
clear

while ((nb <= 29))
do
	echo "##################################################"
	echo ""
	final=$string$nb
	cat $string$nb
	./expert-system $final
	((nb++))
	read  -n 1
done


echo "##################################################"
echo ""
echo "# tests de <=>"
cat tests/test_double_inclusion
./expert-system tests/test_double_inclusion
read  -n 1

echo "##################################################"
echo ""
echo "# test incoherence input"
cat tests/test_incoherence
./expert-system tests/test_double_inclusion
read  -n 1

echo "##################################################"
echo ""
echo "# test cas indetermined"
cat tests/test_indetermined
./expert-system tests/test_double_inclusion
read  -n 1
