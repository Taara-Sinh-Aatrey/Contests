import java.util.*;
import java.io.*;

public class B
{
    static FastScanner sc = new FastScanner();    
    static PrintWriter out = new PrintWriter(System.out);
    
    public static void solve() throws IOException {
        int[] a = new int[3];
        for (int i = 0; i < 3; i++) {
            a[i] = sc.nextInt();
        }
        int m = sc.nextInt();
        Arrays.sort(a);
        int mn = a[2] - 1 - (a[0] + a[1]);
        int mx = a[0] + a[1] + a[2] - 3;
        out.println(mn <= m && m <= mx ? "YES" : "NO");
    }

    public static void main(String [] args) throws IOException {
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