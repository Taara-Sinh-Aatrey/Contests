import java.util.*;
import java.io.*;

public class VACCINE2
{
    static FastScanner sc = new FastScanner();

	public void solve(){
		int n, d;
		n = sc.nextInt();
		d = sc.nextInt();
		int atRisk = 0;
		for(int i = 0; i < n; i++){
			int age;
			age = sc.nextInt();
			if(age <= 9 || age >= 80){
				atRisk++;
			}
		}
		System.out.println((atRisk + d - 1) / d + (n - atRisk + d - 1) / d);
	}

    public static void main(String [] args) throws IOException {
	    // System.setIn(new FileInputStream(new File("in")));
        // System.setOut(new PrintStream(new File("out")));
    	int t;
    	t = sc.nextInt();
    	while(t-- > 0){
	        new VACCINE2().solve();
	    }
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