import java.io.*;
import java.util.*;

public class Main {

    static int N, answer;


    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        answer = 0;
        int[][] board = new int[N][N];

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        DFS(0, board);

        System.out.println(answer); 
    }

    static void DFS(int depth, int[][] board){
        if(depth == 5){
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                    answer = Math.max(answer, board[i][j]);
                }
            }

            return;
        }

        for(int i = 0; i < 4; i++){
            int[][] temp = new int[N][N];
            for(int j = 0; j < N; j++){
                temp[j] = board[j].clone();
            }
            Move(i, temp);
            DFS(depth + 1, temp);
        }

    }

    static void Move(int dir, int[][] board) {
        switch (dir) {
            case 0:
                MoveUp(board);
                break;
            case 1:
                MoveRight(board);
                break;
            case 2:
                MoveDown(board);
                break;
            case 3:
                MoveLeft(board);
                break;
        }
    }

    static void MoveUp(int[][] board) {
        for (int j = 0; j < N; j++) {
            int index = 0;
            int prev = 0;
            for (int i = 0; i < N; i++) {
                if (board[i][j] != 0) {
                    if (prev == board[i][j]) {
                        board[index - 1][j] = prev * 2;
                        prev = 0;
                        board[i][j] = 0;
                    } else {
                        prev = board[i][j];
                        if (index != i) {
                            board[index][j] = board[i][j];
                            board[i][j] = 0;
                        }
                        index++;
                    }
                }
            }
        }
    }

    static void MoveDown(int[][] board) {
        for (int j = 0; j < N; j++) {
            int index = N - 1;
            int prev = 0;
            for (int i = N - 1; i >= 0; i--) {
                if (board[i][j] != 0) {
                    if (prev == board[i][j]) {
                        board[index + 1][j] = prev * 2;
                        prev = 0;
                        board[i][j] = 0;
                    } else {
                        prev = board[i][j];
                        if (index != i) {
                            board[index][j] = board[i][j];
                            board[i][j] = 0;
                        }
                        index--;
                    }
                }
            }
        }
    }

    static void MoveLeft(int[][] board) {
        for (int i = 0; i < N; i++) {
            int index = 0;
            int prev = 0;
            for (int j = 0; j < N; j++) {
                if (board[i][j] != 0) {
                    if (prev == board[i][j]) {
                        board[i][index - 1] = prev * 2;
                        prev = 0;
                        board[i][j] = 0;
                    } else {
                        prev = board[i][j];
                        if (index != j) {
                            board[i][index] = board[i][j];
                            board[i][j] = 0;
                        }
                        index++;
                    }
                }
            }
        }
    }

    static void MoveRight(int[][] board) {
        for (int i = 0; i < N; i++) {
            int index = N - 1;
            int prev = 0;
            for (int j = N - 1; j >= 0; j--) {
                if (board[i][j] != 0) {
                    if (prev == board[i][j]) {
                        board[i][index + 1] = prev * 2;
                        prev = 0;
                        board[i][j] = 0;
                    } else {
                        prev = board[i][j];
                        if (index != j) {
                            board[i][index] = board[i][j];
                            board[i][j] = 0;
                        }
                        index--;
                    }
                }
            }
        }
    }
    
}
