import java.util.*;
import java.io.*;

class FROGS
{
    static FastScanner sc = new FastScanner();	
	static PrintWriter out = new PrintWriter(System.out);

	public static void solve() throws IOException {
		int n = sc.nextInt();
		int W[] = new int[n];
		int L[] = new int[n];
		int pos[] = new int[n];
		for(int i = 0; i < n; i++) {
			W[i] = sc.nextInt();
			pos[i] = i;
			W[i]--;
		}
		for(int i = 0; i < n; i++) {
			L[i] = sc.nextInt();
		}
		int i = 0, ans = 0;
		while(i < n) {
			int j = i + 1;
			while(j < n) {
				if(W[j] < W[i]) {
					break;
				}
				j++;
			}
			if(j == n) {
				i++;
				continue;
			}
			int w = W[i], l = L[i];
			int steps = (pos[j] + 1 - pos[i] + L[i] - 1) / L[i];
			ans += steps;
			int p = pos[i] + steps * L[i];
			for(int k = i; k < j; k++) {
				W[k] = W[k + 1];
				L[k] = L[k + 1];
				pos[k] = pos[k + 1];
			}
			pos[j] = p; W[j] = w; L[j] = l;
			for(int it1 = j; it1 < n; it1++) {
				for(int it2 = it1 + 1; it2 < n; it2++) {
					if(pos[it1] > pos[it2] || (pos[it1] == pos[it2] && W[it1] < W[it2])) {
						p = pos[it1]; w = W[it1]; l = L[it1];
						pos[it1] = pos[it2]; W[it1] = W[it2]; L[it1] = L[it2];
						pos[it2] = p; W[it2] = w; L[it2] = l;
					}
				}
			}
		}
		out.println(ans);
		out.flush();
	}

    public static void main(String [] args) throws IOException {
    	int t = sc.nextInt();
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