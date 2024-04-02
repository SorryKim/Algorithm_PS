import java.util.*;


class Solution {
    // 최솟값을 찾는 메소드
    public static int findMin(int[] array) {
        if (array.length == 0) {
            throw new IllegalArgumentException("배열의 길이가 0입니다.");
        }

        int min = array[0]; // 배열의 첫 번째 요소를 최솟값으로 초기화

        // 배열의 모든 요소를 반복하면서 최솟값을 찾음
        for (int i = 1; i < array.length; i++) {
            if (array[i] < min) {
                min = array[i];
            }
        }

        return min;
    }
    
    public int[] solution(int[] arr) {
        int[] answer = new int[arr.length - 1];
        int value = findMin(arr);
        
        if(arr.length >= 2){
            int idx = 0;
            for(int num : arr){
                if(num == value)
                    continue;
                answer[idx] = num;
                idx++;
            }
        }else{
            answer = new int[1];
            answer[0] = -1;
        }
        
        
        return answer;
    }
}