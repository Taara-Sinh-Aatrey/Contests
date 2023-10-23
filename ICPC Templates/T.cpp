/*
https://cp-algorithms.com/graph/2SAT.html
https://codeforces.com/blog/entry/92977

https://codeforces.com/contest/1702/submission/163658953

Let 2-sat equation be E

Each vertex resembles a true or not true literal

For each clause (a V b) in E, where ‘a’ and ‘b’ are literals, 
create a directed edge from ‘-a’ to ‘b‘ and from ‘-b’ to ‘a’. 
These edges mean that if ‘a’ is not true, then ‘b’ must be true 
and vice-versa. That is, there exists a directed edge (x, y) in G 
iff there exists a clause (-x V y) in E

Also (a V b) means that -a => b and -b => a

-> If G contains a path from a to b, then it also contains a path from -b to -a .
Let the path from a to b be a -> P1 -> P2 -> ....... -> Pk -> b.
Now, by construction of G, if there’s an edge (X, Y), then there’s also an edge (-Y, -X).
Hence, the edges (-b, -Pk), (-Pk, -Pk-1), ....., (-P2, -P1), (-P1, -a). 
Hence, there is a path from -b to -a

-> E cannot be solved if x and -x can be reached from one another



if you are asked to solve (x1 xor x2) and (x2 xor x3) and .....so on
Replace (x1 xor x2) with (x1 or x2) and (-x1 or -x2) and apply 2-sat

Additional:
https://www.iitg.ac.in/deepkesh/CS301/assignment-2/2sat.pdf
https://docs.google.com/presentation/d/1DRKuACmchPcDKQuE2UxK_h28FvdJ9E3uQbhYe2l-OXA/edit?usp=sharing



a V b : (-a => b) ^ (-b => a)
IF `A` THEN `B`
So if you look at the logical/truhh table of implication,
then you will realize that it is false only if a => b and `a` is true
and `b` is false
And since we want the entire CNF form to be true, we have 
replaced the OR conditions with implications

Hence, if there is an edge a => b, and a is true then, b must also be true 
but if a is false, then b can be either false or true

And therefore if we have a path from x to -x, then x must be false, 
coz otherwise putting an early variable to false, doesn't restrict the 
forward variables


* Path from x cannot exist to both y and -y
x => y
x => -y

(-x V y) => x => y and -y => -x
(x V y) => x => -y and -y => x
*/

class SAT2 {
public:
    int n;
    vector<vector<int>> adj, adj_t;
    vector<bool> used;
    vector<int> order, comp;
    vector<bool> assignment;
    SAT2(int n): n(n) {
        adj.resize(n);
        adj_t.resize(n);
    };
    void dfs1(int v) {
        used[v] = true;
        for (int u : adj[v]) {
            if (!used[u])
                dfs1(u);
        }
        order.push_back(v);
    }

    void dfs2(int v, int cl) {
        comp[v] = cl;
        for (int u : adj_t[v]) {
            if (comp[u] == -1)
                dfs2(u, cl);
        }
    }

    bool solve_2SAT() {
        order.clear();
        used.assign(n, false);
        for (int i = 0; i < n; ++i) {
            if (!used[i])
                dfs1(i);
        }

        comp.assign(n, -1);
        for (int i = 0, j = 0; i < n; ++i) {
            int v = order[n - i - 1];
            if (comp[v] == -1)
                dfs2(v, j++);
        }

        assignment.assign(n / 2, false);
        for (int i = 0; i < n; i += 2) {
            if (comp[i] == comp[i + 1])
                return false;
            assignment[i / 2] = comp[i] > comp[i + 1];
        }
        return true;
    }

    // keep `a` and `b` 0-based
    void add_disjunction(int a, bool na, int b, bool nb) {
        // na and nb signify whether a and b are to be negated
        a = 2 * a ^ na;
        b = 2 * b ^ nb;
        int neg_a = a ^ 1;
        int neg_b = b ^ 1;
        adj[neg_a].push_back(b);
        adj[neg_b].push_back(a);
        adj_t[b].push_back(neg_a);
        adj_t[a].push_back(neg_b);
    }
};
