// A → B / baekjoon_16953
// https://www.acmicpc.net/problem/16953

import java.io.*;
import java.util.*;
import java.lang.Math;

public class Main {

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int A = Integer.parseInt(st.nextToken());
		int B = Integer.parseInt(st.nextToken());
		int cnt = 1;
		boolean b = true;
		while(A != B) {
			if(A > B) {
				b = false;
				break;
			}
			else {
				if(B%2 == 0) {
					B /= 2;
					cnt++;
				}
				else if(B%10 == 1) {
					B--;
					B /= 10;
					cnt++;
				}
				else {
					b = false;
					break;
				}
			}
		}
		
		if(b)
			System.out.println(cnt);
		else
			System.out.println("-1");
		
		br.close();
		bw.close();
	}
	
}
