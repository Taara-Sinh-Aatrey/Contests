import java.util.*;
import java.io.*;

public class C
{
    static FastScanner sc = new FastScanner();    
    static PrintWriter out = new PrintWriter(System.out);
    
    public static void solve() throws IOException {
        int n = sc.nextInt();
        Long[] a = new Long[n];
        long sum = 0;
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextLong();
            sum += a[i];
        }
        Arrays.sort(a);
        int m = sc.nextInt();
        while(m-- > 0) {
            Long x = sc.nextLong(), y = sc.nextLong();
            int idx = Arrays.binarySearch(a, x);
            if(idx < 0) idx = -(idx + 1);
            Long ans = Long.MAX_VALUE;
            if(idx < n)
                ans = Math.min(ans, Math.max(0, y - (sum - a[idx])));
            if(idx > 0)
                ans = Math.min(ans, x - a[idx - 1] + Math.max(0, y - (sum - a[idx - 1])));
            out.println(ans);
        }
    }

    public static void main(String [] args) throws IOException {
        int t = 1;
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