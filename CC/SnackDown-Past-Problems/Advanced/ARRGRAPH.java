import java.util.*;
import java.io.*;

class ARRGRAPH
{
    public static int gcd(int a, int b) {
        if(b == 0) return a;
        return gcd(b, a % b);
    }
    
    public static ArrayList<Integer> primes;
    
    static FastScanner sc = new FastScanner();    
    static PrintWriter out = new PrintWriter(System.out);
    
    public static void solve() throws IOException {
        int n = sc.nextInt();
        Integer a[] = new Integer[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int[] taken = new int[n];
        Arrays.fill(taken, 0);
        taken[0] = 1;
        int cnt = 1;
        while(true) {
            int found = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if(taken[i] == 1 && taken[j] == 0 && gcd(a[i], a[j]) == 1) {
                        taken[j] = 1;
                        found = 1;
                        cnt++;
                    }
                }
            }
            if(found == 0) {
                break;
            }
        }
        if(cnt == n) {
            out.println(0);
            for (Integer x : a) {
                out.print(x + " ");
            }
            out.println();
        }
        else {
            out.println(1);
            if(a[n - 1] == 47) {
                a[n - 1] = 43;
            }
            else {
                a[n - 1] = 47;    
            }
            for (int i = 0; i < n; i++) {
                out.print(a[i] + " ");
            }
            out.println();
        }
    }

    public static void main(String [] args) throws IOException {
        primes = new ArrayList<Integer>();
        for (int p = 2; p <= 50; p++) {
            boolean ok = true;
            for (int x = 2; x < p; x++) {
                if(p % x == 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) primes.add(p);
        }
        int t = 1;
        t = sc.nextInt();
        while(t-- > 0) {
            solve();
        }
        out.flush();
    }
    
    static class FastScanner {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");
        String next() {
            while (!st.hasMoreTokens())
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            return st.nextToken();
        }
        
        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }
 
} 