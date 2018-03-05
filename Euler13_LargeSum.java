import java.util.Scanner;
import java.io.*;

public class Euler13_LargeSum{
	public static void main(String[] args) throws IOException{
		
		Scanner sc = new Scanner(new File("vhod_euler19.txt"));

		int[][] matrika = new int[100][50];
		int[] vsote = new int[50];

		int vrstica = 0;

		//Ta koda poskrbi da podatke preberemo iz datoteke v matriko
		while(sc.hasNextLine()){
			
			String stevilo = sc.nextLine();

			String[] tabela = stevilo.split("");

			for(int i = 0; i < tabela.length; i++){
				matrika[vrstica][i] = Integer.parseInt(tabela[i]);
				vsote[i] += matrika[vrstica][i];
			}

			vrstica++;

		}

		System.out.println(izracun(vsote));
		
	}

	private static String izracun(int[] vsote){

		int carry = 0;
		//Način da pretopimo vsote v števila, saj uporabljamo desetiški sistem
		//Tuki notri so recimo cifre 53, ki jih rastavimo na 3 in 5 naprej (carry)
		for(int i = 49; i > -1; i--){
			
			int tp = (vsote[i] + carry) % 10;

			carry = (vsote[i] - tp + carry) / 10;

			vsote[i] = tp;
		}

		//Carry je dvomesten, tako da moramo potem dobiti še 8 prvih cifer
		String ostaleCifre = "";
		for(int i = 0; i <= 7; i++){
			ostaleCifre = ostaleCifre.concat(Integer.toString(vsote[i]));
		}

		return String.format("%d%s%n", carry, ostaleCifre);
	}	
}
