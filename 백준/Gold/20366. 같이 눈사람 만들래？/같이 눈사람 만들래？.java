import java.io.*;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.*;

public class Main {

	static int N;
	static int[] arr;
	
	static class SnowMan implements Comparable<SnowMan>{

		int idx1, idx2; // 사용 눈덩이 index
		int size;

		public SnowMan(int a, int b, int size){
			idx1 = a;
			idx2 = b;
			this.size = size;
		}

		public int compareTo(SnowMan other){
			return Integer.compare(this.size, other.size);
		}

	}

	static void Input() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		arr = new int[N];
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 0; i < N; i++){
			arr[i] = Integer.parseInt(st.nextToken());
		}
	}

	static long Solve(){

		long ans = Integer.MAX_VALUE;
		List<SnowMan> list = new ArrayList<>();

		for(int i = 0; i < N; i++){
			for(int j = i + 1; j < N; j++){
				list.add(new SnowMan(i, j, arr[i] + arr[j]));
			}
		}

		Collections.sort(list);

		for(int i = 1; i < list.size(); i++){

			SnowMan s1 = list.get(i - 1);
			SnowMan s2 = list.get(i);

			if(s1.idx1 == s2.idx1 || s1.idx1 == s2.idx2 || s1.idx2 == s2.idx1 || s1.idx2  == s2.idx2) continue;

			ans = Math.min(ans, Math.abs(s1.size - s2.size));
			if(ans == 0) return 0;

		}
		
		
		return ans;
	}

    public static void main(String[] args) throws Exception{
		
		Input();
		System.out.println(Solve());
	}

}