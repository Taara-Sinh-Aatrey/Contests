for((i = 1; ; i++)); do
    # echo $i
    ./gen.out > in
    python himanshu.py < in > out
    ./COLGLF4.out < in > ok
    diff -w out ok || break
done