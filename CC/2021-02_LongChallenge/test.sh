for((i = 1; ; i++)); do
	echo $i
	./gen.out > in
	java TEAMNAME < in > out
	./brute.out < in > ok
	diff -w out ok || break
done