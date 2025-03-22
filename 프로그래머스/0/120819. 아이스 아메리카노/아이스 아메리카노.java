class Solution {
    public int[] solution(int money) {
        int cnt = money / 5500;
        int charge = money % 5500;
        return new int[]{cnt, charge};
    }
}