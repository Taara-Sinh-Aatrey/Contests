for x in a b c d e f; do
    echo $x
    ./prob < $x.txt > $x.out &
done
wait