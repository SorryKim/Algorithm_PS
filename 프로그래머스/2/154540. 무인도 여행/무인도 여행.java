import java.util.*;

class Pair {
    int x, y;

    public Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class Solution {
    public int[] solution(String[] maps) {
        List<Integer> list = new ArrayList<>();
        int[] moveX = {1, -1, 0, 0}; // 이동 가능한 방향 (동, 서, 남, 북)
        int[] moveY = {0, 0, 1, -1};
        
        int W = maps[0].length(); // 맵의 너비
        int H = maps.length;      // 맵의 높이
        boolean[][] visited = new boolean[H][W]; // 방문 여부 확인
        
        // 맵을 순회
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                char now = maps[i].charAt(j);
                
                if (now == 'X' || visited[i][j]) // 벽이거나 이미 방문한 경우
                    continue;
                
                int sum = 0; // 영역의 숫자를 합산할 변수
                Queue<Pair> q = new LinkedList<>();
                
                // 처음 시작하는 지점 방문 표시 및 큐에 삽입
                visited[i][j] = true;
                q.add(new Pair(j, i));
                
                while (!q.isEmpty()) {
                    Pair current = q.poll();
                    int nowX = current.x;
                    int nowY = current.y;
                    
                    // 현재 위치의 숫자를 더함
                    sum += maps[nowY].charAt(nowX) - '0';
                    
                    // 네 방향 탐색 (동, 서, 남, 북)
                    for (int k = 0; k < 4; k++) {
                        int nextX = nowX + moveX[k];
                        int nextY = nowY + moveY[k];
                        
                        // 범위 내에 있고, 방문하지 않았으며, 'X'가 아닌 경우에만 큐에 추가
                        if (nextX >= 0 && nextX < W && nextY >= 0 && nextY < H) {
                            if (!visited[nextY][nextX] && maps[nextY].charAt(nextX) != 'X') {
                                visited[nextY][nextX] = true; // 방문 처리
                                q.add(new Pair(nextX, nextY));
                            }
                        }
                    }
                }
                list.add(sum); // 탐색이 끝난 후 합산한 값을 리스트에 추가
            }
        }
        
        // 합산한 값을 오름차순으로 정렬
        Collections.sort(list);
        
        // list가 비어 있는 경우 (탐색 결과가 없을 때) 처리
        if (list.isEmpty()) {
            return new int[]{-1}; // 예를 들어 탐색 가능한 영역이 없다면 -1을 반환
        }

        // List<Integer>를 int[]로 변환
        int[] answer = new int[list.size()];
        for (int i = 0; i < list.size(); i++) {
            answer[i] = list.get(i);
        }
        
        return answer;
    }
}
