// 가운데를 말해요 / baekjoon_1655.java
// https://www.acmicpc.net/problem/1655

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Collections;
import java.util.PriorityQueue;

public class Main {

	public static PriorityQueue<Integer> pq1, pq2;
	public static int N;

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		N = Integer.parseInt(br.readLine());

		pq1 = new PriorityQueue<>(Collections.reverseOrder());
		pq2 = new PriorityQueue<>();

		for(int i = 0; i < N; i++) {

			int num = Integer.parseInt(br.readLine());

			if(pq1.isEmpty() || num <= pq1.peek())
				pq1.add(num);
			else
				pq2.add(num);


			while(pq1.size() >= pq2.size()) {
				int temp = pq1.poll();
				pq2.add(temp);
			}

			while (pq2.size() > pq1.size())
			{
				int temp = pq2.poll();
				pq1.add(temp);
			}

			bw.write(Integer.toString(pq1.peek()) + "\n");
		}

		br.close();
		bw.close();
	}

}
