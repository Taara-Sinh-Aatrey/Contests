import java.util.*;
import java.io.*;

class STROPERS
{
    static Reader sc = new Reader();
    static PrintWriter out = new PrintWriter(System.out); 
    static Long mod = 10000000000007L;

    static Long add(Long x, Long y){
    	return (x + y) % mod;
    }

    static Long sub(Long x, Long y){
    	return (x - y + mod) % mod;
    }
    
	public static void solve() throws IOException {
	    char s[] = sc.next().toCharArray();
	    int n = s.length;
	    long p = 104729;
	    int a[] = new int[n];
	    for(int i = 0; i < n; i++){
	    	a[i] = s[i] - '0';
	    }
    	Long hash[] = new Long[n];
    	Set<Long> st = new TreeSet<Long>(); 

	    for(int i = 0; i < n; i++){
	    	long p_pow = 1, cur = 0;
	    	int x0 = -1, x1 = -1, cnt = 0;
	    	for(int j = i; j < n; j++){
	    		// out.println("i = " + i + " j = " + j + " val = " + a[j] + " x0 = " + x0 + " x1 = " + x1);
	    		hash[j] = (1 + a[j]) * p_pow;
	    		if(a[j] == 1){
	    			cnt++;
	    			if(x0 == -1){
	    				x0 = j;
	    			}else if(x1 == -1){
	    				x1 = j;
	    			}
	    		}else{
	    			if(cnt % 2 == 0 && cnt >= 2){
	    				if(x1 - x0 == 1){
	    					hash[x0] /= 2;
		    				cur = sub(cur, hash[x0]);
		    				x0++;
		    				x1++;
		    				hash[j] *= 2;
	    				}else{
	    					hash[x0] /= 2;
		    				cur = sub(cur, hash[x0]);
		    				cur = add(cur, hash[x0 + 1]);
		    				hash[x0 + 1] *= 2;
		    				x0++;
		    				hash[x1] /= 2;
		    				cur = sub(cur, hash[x1]);
		    				x1++;
		    				hash[j] *= 2;
	    				}
	    			}else if(cnt % 2 == 1 && cnt >= 2){
	    				hash[x1] /= 2;
	    				cur = sub(cur, hash[x1]);
	    				x1++;
	    				hash[j] *= 2;
	    			}
	    		}
	    		cur = add(cur, hash[j]);
	    		// out.println(cur);
	    		st.add(cur);
	    		p_pow = (p_pow * p) % mod;
	    		
	    	}
	    }
	    out.println(st.size());


		out.flush();
	}

    public static void main(String [] args) throws IOException {
    	int t = sc.nextInt();
	    while(t-- > 0){
	        STROPERS.solve();
	    }
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
			byte[] buf = new byte[1200]; // line length 
			int cnt = 0;
			byte c;
			c = read();
			while (c <= ' ') 
				c = read(); 
			while (c > ' ') 
			{ 
				buf[cnt++] = c;
				c = read(); 
			} 
			return new String(buf, 0, cnt); 
		} 

		public String next() throws IOException 
		{ 
			byte[] buf = new byte[1200]; // line length 
			int cnt = 0;
			byte c;
			c = read();
			while (c <= ' ') 
				c = read(); 
			while (c > ' ') 
			{ 
				buf[cnt++] = c;
				c = read(); 
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