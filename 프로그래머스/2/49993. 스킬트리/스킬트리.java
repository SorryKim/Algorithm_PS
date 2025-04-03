import java.util.*;

class Solution {
    
    public static void clear(String skill, Map<Character, Boolean> table) {
        table.put(skill.charAt(0), true);
        for (int i = 1; i < skill.length(); i++) {
            table.put(skill.charAt(i), false);
        }
    }
    
    public int solution(String skill, String[] skill_trees) {
        int answer = 0;
        Map<Character, Boolean> table = new HashMap<>();

        table.put(skill.charAt(0), true);
        for (int i = 1; i < skill.length(); i++) {
            table.put(skill.charAt(i), false);
        }

        for (String now : skill_trees) {
            boolean flag = true;
            clear(skill, table);

            for (int i = 0; i < now.length(); i++) {
                char nowSkill = now.charAt(i);

                if (table.containsKey(nowSkill)) {
                    if (table.get(nowSkill)) {
                        for (int j = 0; j < skill.length(); j++) {
                            if (skill.charAt(j) == nowSkill) {
                                if (j + 1 < skill.length()) {
                                    table.put(skill.charAt(j + 1), true);
                                }
                            }
                        }
                    } else {
                        flag = false;
                        break;
                    }
                }
            }

            if (flag) {
                answer++;
            }
        }

        return answer;
    }
}

