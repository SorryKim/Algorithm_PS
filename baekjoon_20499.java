// Darius님 한타 안 함?/ baekjoon_20499.java
// https://www.acmicpc.net/problem/20499

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;



public class Main {

	static String s;
	static String[] array;

	public static void Input() throws IOException{

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		s = br.readLine();
		array = s.split("/");

		br.close();

	}



	static void Solve() {
		int K = Integer.parseInt(array[0]);
		int D = Integer.parseInt(array[1]);
		int A = Integer.parseInt(array[2]);

		if(K + A < D || D == 0)
			System.out.println("hasu");
		else
			System.out.println("gosu");
	}

	public static void main(String[] args) throws Exception {
		Input();
		Solve();
	}

}
