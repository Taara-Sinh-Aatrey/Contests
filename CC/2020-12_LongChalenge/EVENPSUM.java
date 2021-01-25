import java.util.*;
import java.io.*;

public class EVENPSUM
{
	static FastScanner sc = new FastScanner();
	public void solve(){
		long a, b;
		a = sc.nextLong();
		b = sc.nextLong();
		long ans = (a / 2) * (b / 2);
		a++;
		b++;
		ans += (a / 2) * (b / 2);
		System.out.println(ans);
	}

    public static void main(String [] args) throws IOException {
    	int t;
    	t = sc.nextInt();
    	while(t-- > 0)
	        new EVENPSUM().solve();
    }

    static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}
	
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}
}