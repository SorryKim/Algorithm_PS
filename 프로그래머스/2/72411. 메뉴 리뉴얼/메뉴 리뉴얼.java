import java.util.*;

class Solution {
    
    static Map<String, Integer> map;
    static List<String> list;
    
    // 코스요리 조합을 만드는 함수
    static void Func(int idx, StringBuilder sb, String order) {
        for (int i = idx; i < order.length(); i++) {
            sb.append(order.charAt(i));
            map.put(sb.toString(), map.getOrDefault(sb.toString(), 0) + 1);
            Func(i + 1, sb, order);
            sb.deleteCharAt(sb.length() - 1);
        }
    }
    
    static void Solve(int num) {
        int maxV = 0;
        
        // num 길이의 조합 중 최대 주문 횟수 구하기
        for (String key : map.keySet()) {
            if (key.length() != num) continue;
            maxV = Math.max(maxV, map.get(key));
        }
        
        // 최소 2번 이상 주문된 경우에만 후보에 추가
        if (maxV < 2) return;
        
        for (String key : map.keySet()) {
            if (key.length() == num && map.get(key) == maxV) {
                list.add(key);
            }
        }
        
    }
    
    public String[] solution(String[] orders, int[] course) {
        map = new HashMap<>();
        list = new ArrayList<>();
        
        // 각 주문 문자열을 알파벳 순으로 정렬한 후 조합 생성
        for (String order : orders) {
            char[] arr = order.toCharArray();
            Arrays.sort(arr);
            String sortedOrder = new String(arr);
            Func(0, new StringBuilder(), sortedOrder);
        }
        
        // 각 course 길이에 대해 후보 선정
        for (int num : course) {
            Solve(num);
        }
        
        Collections.sort(list);
        return list.toArray(new String[0]);
    }
}
