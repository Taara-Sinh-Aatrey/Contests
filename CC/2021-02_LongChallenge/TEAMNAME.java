import java.util.*;
import java.io.*;

class TEAMNAME
{
    static FastScanner sc = new FastScanner();	
	static PrintWriter out = new PrintWriter(System.out);
    
	public static void solve() throws IOException {
		int n = sc.nextInt();
		int cnt[] = new int[26];
		int bad[][] = new int[26][26];
		String s[] = new String[n];
		Set<String>[] st = (Set<String>[]) new TreeSet[26]; 
		for(int i = 0; i < 26; i++) {
			st[i] = new TreeSet<String>();
		}
		for(int i = 0; i < n; i++) {
			s[i] = sc.next();
			String t = "";
			for(int j = 1; j < s[i].length(); j++) {
				t += s[i].charAt(j);
			}
			cnt[s[i].charAt(0) - 'a']++;
			st[s[i].charAt(0) - 'a'].add(t);
		}
		for(int i = 0; i < 26; i++) {
			for(String t: st[i]) {
				for(int j = 0; j < 26; j++) {
					if(st[j].contains(t)) {
						bad[i][j]++;
					}
				}
			}
		}
		int ans = n * n;
		for(int i = 0; i < n; i++) {
			String t = "";
			for(int j = 1; j < s[i].length(); j++) {
				t += s[i].charAt(j);
			}
			int first = s[i].charAt(0) - 'a';
			for(int j = 0; j < 26; j++) {
				if(st[j].contains(t)) {
					ans -= cnt[j];
				} else {
					ans -= bad[first][j];
				}
			}
		}
		out.println(ans);
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