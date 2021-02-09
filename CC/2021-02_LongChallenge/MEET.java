import java.util.*;
import java.io.*;

class MEET
{
    static FastScanner sc = new FastScanner();	
	static PrintWriter out = new PrintWriter(System.out);

	public static int read_time() {
		String a = sc.next(), b = sc.next();
		a = "" + a.charAt(0) + a.charAt(1) + a.charAt(3) + a.charAt(4);
		int A = Integer.parseInt(a);
		if(b.equals("AM") && A >= 1200) {
			A -= 1200;
		}
		if(b.equals("PM") && A < 1200) {
			A += 1200;
		}
		return A;
	}
    
	public static void solve() throws IOException {
		int a = read_time();
		int q = sc.nextInt();
		while(q-- > 0) {
			int l = read_time(), r = read_time();
			if(l <= a && a <= r) {
				out.print("1");
			} else {
				out.print("0");
			}
		}
		out.println();
		out.flush();
	}

    public static void main(String [] args) throws IOException {
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