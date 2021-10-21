import java.util.*;
import java.io.*;

class AVGMAT
{
    static FastScanner sc = new FastScanner();    
    static PrintWriter out = new PrintWriter(System.out);
    
    public static void solve() throws IOException {
        int n = sc.nextInt(), m = sc.nextInt();
        Integer[][] mat = new Integer[n][m];
        Integer[][][][] dp = new Integer[2][n][m][n + m - 1];
        for(int i = 0; i < n; i++) {
            String s = sc.next();
            for(int j = 0; j < m; j++) {
                Arrays.fill(dp[0][i][j], 0);
                Arrays.fill(dp[1][i][j], 0);
                mat[i][j] = s.charAt(j) == '1' ? 1 : 0;
            }
        }
        Integer[] ans = new Integer[n + m - 1];
        Arrays.fill(ans, 0);
        for(int rep = 0; rep < 2; rep++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if(i > 0) {
                        for(int k = 1; k <= i + j; k++) {
                            dp[rep][i][j][k] = dp[rep][i - 1][j][k - 1];
                        }
                    }
                    for (int k = 0; k <= j; k++) {
                        dp[rep][i][j][j - k] += mat[i][k] == 1 ? 1 : 0;
                    }
                    if(mat[i][j] == 1) {
                        for (int k = 0; k <= i + j; k++) {
                            ans[k] += dp[rep][i][j][k];
                        }
                        if(rep == 1) {
                            for (int k = 0; k <= i; k++) {
                                ans[i - k] -= mat[k][j] == 1 ? 1 : 0;
                            }                            
                            for (int k = 0; k <= j; k++) {
                                ans[j - k] -= mat[i][k] == 1 ? 1 : 0;
                            }
                        }
                    }
                }
            }
            if(rep == 0) {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m / 2; j++) {
                        Integer t = mat[i][j];
                        mat[i][j] = mat[i][m - 1 - j];
                        mat[i][m - 1 - j] = t;
                    }
                }
            }
        }
        for(int i = 1; i <= n + m - 2; i++) {
            out.print(ans[i] + " ");
        }
        out.println();
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