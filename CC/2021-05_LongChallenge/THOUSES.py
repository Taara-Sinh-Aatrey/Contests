from collections import deque

t = int(input())
for _ in range(t):

    n, x = list(map(int, input().split()))
    g = [[] for i in range(n)]

    for __ in range(n - 1):
        u, v = list(map(int, input().split()))
        u = u - 1
        v = v - 1
        g[u].append(v)
        g[v].append(u)

    p = [-1 for i in range(n)]
    vis = [False for i in range(n)]
    ans = [1 for i in range(n)]
    l = [0 for i in range(n)]
    stack = []
    stack.append(0)
    q = deque()

    while(len(stack)):
        u = stack[-1]
        stack.pop()
        vis[u] = True

        child = 0
        for v in g[u]:
            if not vis[v]:
                child += 1
                p[v] = u
                stack.append(v)
        if child == 0:
            q.append(u)

    while len(q):
        u = q.popleft()

        child = []
        for v in g[u]:
            if v != p[u]:
                child.append(ans[v])
        child.sort()
        child.reverse()
        multiplier = 1
        for val in child:
            ans[u] += multiplier * val
            multiplier += 1

        if u != 0:
            par = p[u]
            l[par] += 1
            if l[par] == len(g[par]) and par == 0:
                q.append(par)
            elif l[par] == len(g[par]) - 1 and par != 0:
                q.append(par)

    mod = 1000000007
    ans[0] *= x
    ans[0] = ans[0] % mod
    print(ans[0])