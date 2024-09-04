class Solution {
    public int[] solution(String[] park, String[] routes) {
        int W = park[0].length(); // 공원의 너비
        int H = park.length; // 공원의 높이
        int startX = 0, startY = 0; // 시작 좌표

        // 시작점(S) 찾기
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (park[i].charAt(j) == 'S') {
                    startX = i;
                    startY = j;
                }
            }
        }

        // 명령어 처리
        for (String route : routes) {
            String[] temp = route.split(" ");
            String direction = temp[0]; // 방향 (N, S, W, E)
            int num = Integer.parseInt(temp[1]); // 이동할 거리

            int nextX = startX;
            int nextY = startY;
            boolean flag = true; // 이동 가능한지 여부를 확인하는 플래그

            if (direction.equals("N")) {
                // 북쪽으로 이동
                for (int i = 1; i <= num; i++) {
                    if (nextX - 1 < 0 || park[nextX - 1].charAt(nextY) == 'X') {
                        flag = false;
                        break;
                    }
                    nextX--;
                }
            } else if (direction.equals("S")) {
                // 남쪽으로 이동
                for (int i = 1; i <= num; i++) {
                    if (nextX + 1 >= H || park[nextX + 1].charAt(nextY) == 'X') {
                        flag = false;
                        break;
                    }
                    nextX++;
                }
            } else if (direction.equals("W")) {
                // 서쪽으로 이동
                for (int i = 1; i <= num; i++) {
                    if (nextY - 1 < 0 || park[nextX].charAt(nextY - 1) == 'X') {
                        flag = false;
                        break;
                    }
                    nextY--;
                }
            } else if (direction.equals("E")) {
                // 동쪽으로 이동
                for (int i = 1; i <= num; i++) {
                    if (nextY + 1 >= W || park[nextX].charAt(nextY + 1) == 'X') {
                        flag = false;
                        break;
                    }
                    nextY++;
                }
            }

            // 경로가 유효하면 위치 업데이트
            if (flag) {
                startX = nextX;
                startY = nextY;
            }
        }

        // 최종 위치 반환
        return new int[]{startX, startY};
    }
}
