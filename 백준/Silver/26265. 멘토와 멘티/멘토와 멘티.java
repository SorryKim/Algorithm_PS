import java.io.*;
import java.util.*;

public class Main {

    static int N;
    static List<Pair> list;

    public static class Pair implements Comparable<Pair> {
        String mento, menti;

        Pair(String a, String b) {
            mento = a;
            menti = b;
        }

        @Override
        public int compareTo(Pair other) {
            if (this.mento.equals(other.mento)) {
                return other.menti.compareTo(this.menti);
            }
            return this.mento.compareTo(other.mento);
        }
    }

    public static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        N = Integer.parseInt(br.readLine());
        list = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            String a = st.nextToken();
            String b = st.nextToken();
            list.add(new Pair(a, b));
        }

    }

    public static void solve() {
        Collections.sort(list);
        for (Pair pair : list) {
            System.out.println(pair.mento + " " + pair.menti);
        }
    }

    public static void main(String[] args) throws IOException {
        input();
        solve();
    }
}