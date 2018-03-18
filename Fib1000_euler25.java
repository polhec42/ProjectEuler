import java.math.*;

public class Fib1000_euler25{
	public static void main(String[] args) {
		
		long startTime = System.currentTimeMillis();

		for(int i = 100; i < 20000; i++){
			String s = String.valueOf(fib(i));
			//System.out.println(s);
			if(s.length() >= 1000){
				System.out.println(i);
				break;
			}
		}

		long stopTime = System.currentTimeMillis();

		System.out.println((stopTime - startTime) + " ms");

	}
	private static BigInteger fib(int n){
		BigInteger a = BigInteger.ONE;
		BigInteger b = BigInteger.ONE;

		int stevec = 2;
		BigInteger tp = BigInteger.ZERO;

		while(stevec < n){
			tp = b;
			b = a.add(b);
			a = tp;
			stevec++;
		}

		return b;
	}
}