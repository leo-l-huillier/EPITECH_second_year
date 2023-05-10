gcc -o tester tests/fonctional/tester.c


echo "________________[FONCTIONAL TEST]________________"

#echo "test help"

#./205IQ -h > tests/fonctional/1.1
#./tester tests/fonctional/1.1 tests/fonctional/test1.1 testHelp


echo "test one values"

./205IQ 100 15 > data

head -n 2 data > tests/fonctional/got/1.2
./tester tests/fonctional/got/1.2 tests/fonctional/expected/test1.2 test1.2

head -n 120 data | tail -n 10 > tests/fonctional/got/1.3
./tester tests/fonctional/got/1.3 tests/fonctional/expected/test1.3 test1.3

tail -n 2 data > tests/fonctional/got/1.4
./tester tests/fonctional/got/1.4 tests/fonctional/expected/test1.4 test1.4



echo "test two values"

./205IQ 100 24 90 > tests/fonctional/got/2.1
./tester tests/fonctional/got/2.1 tests/fonctional/expected/test2.1 test2.1



echo "test three values"

./205IQ 100 24 90 95 > tests/fonctional/got/3.1
./tester tests/fonctional/got/3.1 tests/fonctional/expected/test3.1 test3.1