for((i = 1; i < 100000; i++)); do
    echo $i
    ./gen.out > in
    ./brute.out < in > ok
    ./MNDIGSUM.out < in > out
    diff -w out ok || break
done