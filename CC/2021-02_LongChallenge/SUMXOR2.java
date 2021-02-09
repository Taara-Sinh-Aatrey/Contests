import java.util.*;
import java.io.*;

class sol
{
    static FastScanner sc = new FastScanner();	
	static PrintWriter out = new PrintWriter(System.out);

	static Long mod = 998244353;
	static Long MAX = 200001;
	Long fac[] = new Long fac[MAX];
	Long inv[] = new Long inv[MAX];

	public static Long Pow(Long a, Long b) {
	    Long res = 1;
	    while(b > 0) {
	        if(b & 1) res = res * a % mod;
	        a = a * a % mod;
	        b >>= 1;
	    }
	    return res;
	}

	public static Long NCR(int N, int R) {
		if(R > N) {
			return 0;
		}
		return fac[N] * inv[R] % mod * inv[N - R] % mod;
	}
    
	public static void solve() throws IOException {
		int n = sc.nextInt();
		int cnt[] = new int[30];
		Long ans[] = new Long[n + 1];

		fac[0] = 1; inv[0] = 1;

		for(int i = 1; i <= n; i++) {

			fac[i] = (i * fac[i - 1]) % mod;
			inv[i] = Pow(fac[i], mod - 2);

			int num = sc.nextInt();
			for(int j = 0; j < 30; j++) {
				if(num >> j & 1) {
					cnt[j]++;
				}
			}
		}

		for(int b = 0; b < 30; b++) {
			int k = cnt[b];
			
		}
	}

    public static void main(String [] args) throws IOException {
	    // System.setIn(new FileInputStream(new File("in")));
        // System.setOut(new PrintStream(new File("out")));
    	int t = 1;
    	// t = sc.nextInt();
    	while(t-- > 0) { 
    		solve();
    	}
    	out.flush();
    }

    static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
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