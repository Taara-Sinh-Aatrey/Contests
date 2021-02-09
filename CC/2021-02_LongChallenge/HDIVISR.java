import java.util.*;
import java.io.*;

class HDIVISR
{
    static FastScanner sc = new FastScanner();	
	static PrintWriter out = new PrintWriter(System.out);
    
	public static void solve() throws IOException {
		int n = sc.nextInt();
		for(int i = 10; i >= 1; i--) {
			if(n % i == 0) {
				out.print(i);
				break;
			}
		}
		out.flush();
	}

    public static void main(String [] args) throws IOException {
	    // System.setIn(new FileInputStream(new File("in")));
        // System.setOut(new PrintStream(new File("out")));
    	int t = 1;
    	// t = sc.nextInt();
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