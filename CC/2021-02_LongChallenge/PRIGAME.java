import java.util.*;
import java.io.*;

class PRIGAME
{
    static FastScanner sc = new FastScanner();	
	static PrintWriter out = new PrintWriter(System.out);

	static int N = 1000001;

	static int cnt[] = new int[N];
	static boolean prime[] = new boolean[N];
	public static void sieve() {
	    prime[0] = prime[1] = false;
	    cnt[0] = 0; cnt[1] = 0;
	    for(int i = 2; i < N; i++) {
	    	prime[i] = true;
	    }
	    for(int i = 2; i < N; i++) {
	    	cnt[i] = cnt[i - 1];
	    	if(prime[i]) {
	    		cnt[i]++;
	    		for(int j = 2 * i; j < N; j += i) {
	    			prime[j] = false;
	    		}
	    	}
	    }
	}
    
	public static void solve() throws IOException {
		int x = sc.nextInt();
		int y = sc.nextInt();
		out.println(y >= cnt[x] ? "Chef" : "Divyam");
	}

    public static void main(String [] args) throws IOException {
    	sieve();
    	int t = 1;
    	t = sc.nextInt();
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