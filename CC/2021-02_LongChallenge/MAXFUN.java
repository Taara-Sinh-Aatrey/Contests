import java.util.*;
import java.io.*;

class MAXFUN
{
    static FastScanner sc = new FastScanner();	
	static PrintWriter out = new PrintWriter(System.out);
    
	public static void solve() throws IOException {
		Long n = sc.nextLong();
		Long mn = Long.MAX_VALUE, mx = Long.MIN_VALUE;
		for(int i = 0; i < n; i++) {
			Long num = sc.nextLong();
			mn = Math.min(mn, num);
			mx = Math.max(mx, num);
		}
		out.println(2 * (mx - mn));
		out.flush();
	}

    public static void main(String [] args) throws IOException {
	    // System.setIn(new FileInputStream(new File("in")));
        // System.setOut(new PrintStream(new File("out")));
    	int t = 1;
    	t = sc.nextInt();
    	while(t-- > 0) { 
    		solve();
    	}
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