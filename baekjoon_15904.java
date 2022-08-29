// UCPC는 무엇의 약자일까? / baekjoon_15904.java
// https://www.acmicpc.net/problem/15904
import java.io.*;
import java.util.*;

public class Main {
	
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		String s = br.readLine();
		
		int cnt = 1;
		
		for(int i = 0; i < s.length(); i++) {
			if(s.charAt(i) == 'U' && cnt == 1) {
				cnt++;
			}
			else if(s.charAt(i) == 'C' && (cnt == 2 || cnt ==4)) {
				cnt++;
			}
			
			else if(s.charAt(i) == 'P' && cnt == 3) {
				cnt++;
			}
		}
		

		if(cnt == 5) {
			System.out.println("I love UCPC");
		}
		else {
			System.out.println("I hate UCPC");
		}
		bw.close();
		br.close();
	}

}
