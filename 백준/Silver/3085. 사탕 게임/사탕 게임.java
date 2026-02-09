import java.io.*;

public class Main {

    static int N;
    static char[][] board;

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        board = new char[N][N];

        for(int i = 0; i < N; i++){
            String s = br.readLine();
            for(int j = 0; j < N; j++){
                board[i][j] = s.charAt(j);
            }
        }
    }

    static void swap(int x1, int y1, int x2, int y2){
        char temp = board[x1][y1];
        board[x1][y1] = board[x2][y2];
        board[x2][y2] = temp;
    }

    static int check(){

        int result = 0;
        
        // 행 체크
        for(int i = 0; i < N; i++){
            int cnt = 1;
            for(int j = 1; j < N; j++){
                if(board[i][j] == board[i][j - 1]) cnt++;
                else cnt = 1;
                result = Math.max(result, cnt);
            }
        }

        // 열 체크
        for(int j = 0; j < N; j++){
            int cnt = 1;
            for(int i = 1; i < N; i++){
                if(board[i][j] == board[i - 1][j]) cnt++;
                else cnt = 1;
                result = Math.max(result, cnt);
            }
        }

        return result;
    }

    static int solve(){
        int ans = 0;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){

                // 1. 오른쪽
                if(j + 1 < N){
                    swap(i, j, i, j + 1);
                    ans = Math.max(ans, check());
                    swap(i, j, i, j + 1);
                }

                // 2. 아래쪽
                if(i + 1 < N){
                    swap(i, j, i + 1, j);
                    ans = Math.max(ans, check());
                    swap(i, j, i + 1, j);
                }
            }
        }
        return ans; 
    }

    public static void main(String[] args) throws Exception {
        input();
        System.out.println(solve());
    }
}
