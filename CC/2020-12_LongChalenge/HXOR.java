   import java.util.*;
import java.io.*;

public class HXOR
{
    static Reader sc = new Reader();
    static PrintWriter out = new PrintWriter(System.out); 
    
	public void solve() throws IOException {
		int n, x;
		n = sc.nextInt();
		x = sc.nextInt();
		int X = x;
		int cnt[] = new int[30];
		int a[] = new int[n];
		for(int i = 0; i < n - 1; i++){
			a[i] = sc.nextInt();
			char bin[] = Integer.toBinaryString(a[i]).toCharArray();
			int len = bin.length;
			for(int j = 0; j < len / 2; j++){
				char temp = bin[j];
				bin[j] = bin[len - 1 - j];
				bin[len - 1 - j] = temp;
			}
			int num = 0;
			for(int j = len - 1; j >= 0; j--){
				if(bin[j] == '1'){
					if(cnt[j] == 1){
						cnt[j] = 0;
						bin[j] = '0';
					}else if(x > 0){
						x--;
						cnt[j] = 1;
						bin[j] = '0';
					}else{
						num += (1 << j);
					}
				}
			}
			a[i] = num;
		}
		a[n - 1] = sc.nextInt();

		for(int i = 0; i < 30; i++){
			if(cnt[i] == 1){
				a[n - 1] ^= (1 << i);
			}
		}

		if(x % 2 == 1 && (x == X || n == 2)){
			a[n - 1] ^= 1;
			a[n - 2] ^= 1;
		}

		for(int i = 0; i < n; i++){
			out.print(a[i] + " ");
		}

		out.println();
		out.flush();
	}

    public static void main(String [] args) throws IOException {
	    // System.setIn(new FileInputStream(new File("in")));
        // System.setOut(new PrintStream(new File("out")));
    	int t;
    	t = sc.nextInt();
    	while(t-- > 0){
	        new HXOR().solve();
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