import java.util.*;
import java.io.*;

public class Main {
    static int N;
    static int[] books;

    static void input() throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        books = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            books[i] = Integer.parseInt(st.nextToken());
        }
    }

    static int lowerBound(List<Integer> list, int key){

        int left = 0;
        int right = list.size();

        while(left < right){
            int mid = (left + right) / 2;
            if(list.get(mid) < key){
                left = mid + 1;
            }else{
                right = mid;
            }
        }

        return left;
    }

    static int upperBound(List<Integer> list, int key){
        int left = 0;
        int right = list.size();

        while(left < right){
            int mid = (left + right) / 2;

            if(list.get(mid) <= key){
                left = mid + 1;
            }else{
                right = mid;
            }
        }

        return left;
    }

    // LIS구하기
    static int solve() {

        ArrayList<Integer> list = new ArrayList<>();

        for (int i = 0; i < N; i++) {
        
            int book = books[i];
            int idx = lowerBound(list, book);

            if(idx == list.size()){
                list.add(book);
            }else{
                list.set(idx, book);
            }
            
        }

        return N - list.size(); // LIS 길이
    }

    public static void main(String[] args) throws IOException {
        
        input();
        System.out.println(solve());
    }
    
}
