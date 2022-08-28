compile F_gen
compile F
javac F_brute.java
for((i = 1; ; i++)); do
    echo $i
    ./F_gen.out > in
    ./F.out < in > out
    java F_brute < in > ok
    diff -w out ok || break
done