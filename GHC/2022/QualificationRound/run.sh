compile sol
for x in a b c d e; do
    echo $x
    ./sol.out < $x > $x.out &
done
wait