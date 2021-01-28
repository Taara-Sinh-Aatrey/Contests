import java.util.*;
import java.io.*;

public class VACCINE1
{

	int d1, v1, d2, v2, p;

	public void solve(){
		Scanner sc = new Scanner(System.in);
		d1 = sc.nextInt();
		v1 = sc.nextInt();
		d2 = sc.nextInt();
		v2 = sc.nextInt();
		p = sc.nextInt();
		if(d1 > d2){
			int t = d1;
			d1 = d2;
			d2 = t;
			t = v1;
			v1 = v2;
			v2 = t;
		}
		int ans = d1 - 1;
		int days = Math.min((p + v1 - 1) / v1, d2 - d1);
		ans += days;
		p -= days * v1;
		if(p > 0){
			ans += (p + v1 + v2 - 1) / (v1 + v2);
		}
		System.out.println(ans);
	}

    public static void main(String [] args) throws IOException {
        // System.setIn(new FileInputStream(new File("in")));
        // System.setOut(new PrintStream(new File("out")));
        new VACCINE1().solve();
    }
}