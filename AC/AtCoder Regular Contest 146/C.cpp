let's count no of subsets such that
it has even no of elements and xor is 0

xor = 0
for every bit x,
no of element is our set having `x` bit set should be even


bit x,
a no of elements have x as set => a is even
b no of elements have x as unset => (a+b) is even, b is even

n bits
any bit x,
let's fix size = s
s C k => these k bit should be set and (s - k) should be unset
sC0 + sC2 + ...... sCs => 2^(s-1)
for every even size s,
we 2^(s-1)^n

2^(2^n)
2^4 = 16

2 =>0, 1, 2, 3
s = 2, s = 4
(2^1)^2 + (2^3)^2
4 + 64
68



