// 어린 왕자 / baekjoon_1004.java
// https://www.acmicpc.net/problem/1004

import java.io.*;
import java.util.*;

public class Main {
	
	public static boolean check(int x1, int y1, int x2, int y2, int r) {
		
		double d1 = Math.pow(x1 -x2, 2);
		double d2 = Math.pow(y1 -y2, 2);
		
		double value = Math.sqrt(d1 + d2);
		return value < (double)r;
	}
	
	public static void main(String[] args) throws IOException{
		
		// input
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		
		int T = Integer.parseInt(br.readLine());
		
		while(T != 0) {
			T--;
			st = new StringTokenizer(br.readLine());
			int x1 = Integer.parseInt(st.nextToken());
			int y1 = Integer.parseInt(st.nextToken());
			int x2 = Integer.parseInt(st.nextToken());
			int y2 = Integer.parseInt(st.nextToken());
			int n = Integer.parseInt(br.readLine());
			
			int cnt = 0;
			for(int i = 0; i < n; i++) {
				st = new StringTokenizer(br.readLine());
				int x = Integer.parseInt(st.nextToken());
				int y = Integer.parseInt(st.nextToken());
				int r = Integer.parseInt(st.nextToken());
				
				boolean b1 = check(x1,y1,x,y,r);
				boolean b2 = check(x2,y2,x,y,r);
				
				if(!(b1 && b2) && (b1 || b2))
					cnt++;
				
			}
			
			System.out.println(cnt);
		}
		
		bw.close();
		br.close();
	}

}
