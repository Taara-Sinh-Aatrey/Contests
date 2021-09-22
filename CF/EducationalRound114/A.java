import java.util.*;
import java.io.*;

public class A
{
    static FastScanner sc = new FastScanner();    
    static PrintWriter out = new PrintWriter(System.out);
    
    public static void solve() throws IOException {
        int n = sc.nextInt();
        for (int i = 1; i <= n; i++) {
            for(int j = 0; j < i; j++) {
                out.print('(');
            }
            for(int j = 0; j < i; j++) {
                out.print(')');
            }
            for(int j = i; j < n; j++) {
                out.print("()");
            }
            out.println();
        }
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