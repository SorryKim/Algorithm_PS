import java.util.*;

public class Solution {

    static List<String> list = new ArrayList<>();
    static String str = "AEIOU";
    
    public static void DFS(String now, int cnt) {
        if (!now.isEmpty()) {
            list.add(now);
        }

        if (now.length() < cnt) {
            for (int i = 0; i < str.length(); i++) {
                DFS(now + str.charAt(i), cnt);
            }
        }
    }

    public static int solution(String word) {
        DFS("", 5);
        //Collections.sort(list);

        for (int i = 0; i < list.size(); i++) {
            if (list.get(i).equals(word)) {
                return i + 1;
            }
        }

        return 0;
    }
}
