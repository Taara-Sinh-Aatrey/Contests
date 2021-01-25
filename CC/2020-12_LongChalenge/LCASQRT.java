import java.util.*;
import java.io.*;

class solution
{
    static Reader sc = new Reader();
    static PrintWriter out = new PrintWriter(System.out); 
    static int n, p, ans;
    static int mxN = 500001;
    static ArrayList<ArrayList<Integer> > g = new ArrayList<ArrayList<Integer> >(mxN); 
    static int[] a = new int[mxN]; 
    static int[] b = new int[mxN]; 
    static int[] c = new int[mxN]; 
    static int[] sum = new int[mxN]; 

    public static int dfs(int u, int par){
    	sum[u] = 0;
    	for(int v: g.get(u)){
			if(dfs(v, u) == 1){
    			sum[u] += sum[v];
    			sum[u] %= p;
    		}else{
    			return 0;
    		}
    	}

    	int cur = (a[u] * a[u]) % p;

    	for(int v: g.get(u)){
			cur += (sum[v] * ((sum[u] - sum[v] + p) % p)) % p;
			cur %= p;
    	}
    	cur += (2 * ((a[u] * sum[u]) % p)) % p;
    	cur %= p;
    	sum[u] += a[u];
    	sum[u] %= p;
    	// out.println(u + " " + sum[u] + " " + cur);
    	if(cur != c[u]) {
    		return 0;
    	}
    	return 1;
    }

    public static void set_value(int idx){
    	if(idx > n){
    		// for(int i = 1; i <= n; i++){
    		// 	out.print(a[i] + " ");
    		// }
    		// out.println();
    		if(dfs(1, -1) == 1){
    			if(ans == 0){
    				for(int i = 1; i <= n; i++){
    					b[i] = a[i];
    				}
    			}
    			ans++;
    		}
    		// out.println();
    		// out.println(x);
    		return;
    	}
    	for(int i = 0; i < p; i++){
    		a[idx] = i;
    		set_value(idx + 1);
    	}
    }
    
	public static void solve() throws IOException {
	    n = sc.nextInt();
	    p = sc.nextInt();
	    ans = 0;

	    for(int i = 1; i <= n; i++) g.get(i).clear();
	    for(int i = 2; i <= n; i++) g.get(sc.nextInt()).add(i);
	    for(int i = 1; i <= n; i++) c[i] = sc.nextInt();

	    set_value(1);

	    out.println(ans);
	    if(ans > 0){
	    	for(int i = 1; i <= n; i++){
	    		out.print(b[i] + " ");
	    	}
	    	out.println();
	    }else{
	    	out.println(-1);
	    }

		out.flush();
	}

    public static void main(String [] args) throws IOException {
    	for(int i = 0; i < mxN; i++){
    		g.add(new ArrayList<Integer>());
    	}

    	int t;
    	t = sc.nextInt();
    	while(t-- > 0)
	        solution.solve();
    }

    static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}
	
	static class Reader 
	{ 
		final private int BUFFER_SIZE = 1 << 16; 
		private DataInputStream din; 
		private byte[] buffer; 
		private int bufferPointer, bytesRead; 

		public Reader() 
		{ 
			din = new DataInputStream(System.in); 
			buffer = new byte[BUFFER_SIZE]; 
			bufferPointer = bytesRead = 0; 
		} 

		public Reader(String file_name) throws IOException 
		{ 
			din = new DataInputStream(new FileInputStream(file_name)); 
			buffer = new byte[BUFFER_SIZE]; 
			bufferPointer = bytesRead = 0; 
		} 

		public String readLine() throws IOException 
		{ 
			byte[] buf = new byte[64]; // line length 
			int cnt = 0, c; 
			while ((c = read()) != -1) 
			{ 
				if (c == '\n') 
					break; 
				buf[cnt++] = (byte) c; 
			} 
			return new String(buf, 0, cnt); 
		} 

		public int nextInt() throws IOException 
		{ 
			int ret = 0; 
			byte c = read(); 
			while (c <= ' ') 
				c = read(); 
			boolean neg = (c == '-'); 
			if (neg) 
				c = read(); 
			do
			{ 
				ret = ret * 10 + c - '0'; 
			} while ((c = read()) >= '0' && c <= '9'); 

			if (neg) 
				return -ret; 
			return ret; 
		} 

		public long nextLong() throws IOException 
		{ 
			long ret = 0; 
			byte c = read(); 
			while (c <= ' ') 
				c = read(); 
			boolean neg = (c == '-'); 
			if (neg) 
				c = read(); 
			do { 
				ret = ret * 10 + c - '0'; 
			} 
			while ((c = read()) >= '0' && c <= '9'); 
			if (neg) 
				return -ret; 
			return ret; 
		} 

		public double nextDouble() throws IOException 
		{ 
			double ret = 0, div = 1; 
			byte c = read(); 
			while (c <= ' ') 
				c = read(); 
			boolean neg = (c == '-'); 
			if (neg) 
				c = read(); 

			do { 
				ret = ret * 10 + c - '0'; 
			} 
			while ((c = read()) >= '0' && c <= '9'); 

			if (c == '.') 
			{ 
				while ((c = read()) >= '0' && c <= '9') 
				{ 
					ret += (c - '0') / (div *= 10); 
				} 
			} 

			if (neg) 
				return -ret; 
			return ret; 
		} 

		private void fillBuffer() throws IOException 
		{ 
			bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE); 
			if (bytesRead == -1) 
				buffer[0] = -1; 
		} 

		private byte read() throws IOException 
		{ 
			if (bufferPointer == bytesRead) 
				fillBuffer(); 
			return buffer[bufferPointer++]; 
		} 

		public void close() throws IOException 
		{ 
			if (din == null) 
				return; 
			din.close(); 
		} 
	} 
}