import java.io.*;
import java.util.*;

public class Main {

	static int N, M;
	static int[] arr;

	static void Input() throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		arr = new int[N];
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < N; i++) arr[i] = Integer.parseInt(st.nextToken());
	}

	static int Solve(){
		int ans = 0;

		PriorityQueue<Integer> pq1 = new PriorityQueue<>(Collections.reverseOrder()); // 충전 오래걸리는 것부터 충전
		for(int i = 0; i < N; i++) pq1.add(arr[i]);

		PriorityQueue<Integer> pq2 = new PriorityQueue<>(); // 충전기
		for(int i = 0; i < M; i++) pq2.add(0);

		while(!pq1.isEmpty()){

			int time = pq1.poll(); // 충전에 걸리는 시간
			int code = pq2.poll(); // 현재 코드를 사용한 시간
			int temp = time + code;

			ans = Math.max(ans, temp); // 최소시간 체크
			pq2.add(temp);
		}

		return ans;
	}

    public static void main(String[] args) throws Exception{
		Input();
		System.out.println(Solve());
	}
		
}