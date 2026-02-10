public class Q2b_nondupe_combo {
    public static void main(String[] args) {
        for (int a = 1; a <= 9; a++){
            for (int b = 1; b <= 9; b++){
                if (b == a) continue;
                for (int c = 1; c <= 9; c++){
                    if (c == a || c == b) continue;
                    for (int d = 1; d <= 9; d++){
                        if (d == a || d == b || d == c) continue;
                        System.out.println("" + a + b + c + d);
                    }
                }
            }
        }
    }
}