echo "make GNLDIR=$1 &&
	make clean GNLDIR=$1 &&
	make -C sender GNLDIR=../$1 &&
	make -C huge_sender GNLDIR=../$1" > build.sh
echo "sender/sender 1329 | ./test_gnl -test
huge_sender/huge_sender 10000000 | ./test_gnl -huge 10000000" > run.sh
