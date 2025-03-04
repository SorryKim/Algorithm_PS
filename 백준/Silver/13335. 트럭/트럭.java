import java.io.*;
import java.util.*;

public class Main {
    
    static class Truck {
        int weight, entryTime;

        public Truck(int weight, int entryTime) {
            this.weight = weight;
            this.entryTime = entryTime;
        }

    }
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int n = Integer.parseInt(st.nextToken());
        int w = Integer.parseInt(st.nextToken());
        int L = Integer.parseInt(st.nextToken());
        
        int[] trucks = new int[n];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) trucks[i] = Integer.parseInt(st.nextToken());
        
        Queue<Truck> bridge = new LinkedList<>();
        int time = 0;
        int sum = 0;
        int index = 0;
        
        while (index < n) {
            time++;
            
            // 먼저 진입한 트럭이 다리를 건넘
            if (!bridge.isEmpty() && time - bridge.peek().entryTime == w) {
                sum -= bridge.poll().weight;
            }
            
            // 무게와 수량 체크
            if (sum + trucks[index] <= L && bridge.size() < w) {
                bridge.offer(new Truck(trucks[index], time));
                sum += trucks[index];
                index++;
            }
        }
        
        // 마지막 트럭 추가
        System.out.println(time + w);
    }
}
