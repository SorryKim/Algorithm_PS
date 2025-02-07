import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        Map<String, Integer> wordCount = new HashMap<>();

        // 단어 입력 및 빈도수 저장
        for (int i = 0; i < N; i++) {
            String word = br.readLine();
            if (word.length() >= M) { // 길이가 M 이상인 단어만 저장
                wordCount.put(word, wordCount.getOrDefault(word, 0) + 1);
            }
        }

        // 리스트로 변환 후 정렬
        List<String> words = new ArrayList<>(wordCount.keySet());
        words.sort((a, b) -> {
            int freqCompare = Integer.compare(wordCount.get(b), wordCount.get(a)); // 빈도수 기준 내림차순
            if (freqCompare == 0) {
                int lengthCompare = Integer.compare(b.length(), a.length()); // 길이 기준 내림차순
                return (lengthCompare != 0) ? lengthCompare : a.compareTo(b); // 사전순 정렬 (오름차순)
            }
            return freqCompare;
        });

        // 결과 출력
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        for (String word : words) {
            bw.write(word);
            bw.newLine();
        }
        bw.flush();
        bw.close();
    }
}
