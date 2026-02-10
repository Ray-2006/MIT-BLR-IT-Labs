public class Q2a_dupe_combo {
    public static void main(String[] args) {
        for (int a = 1; a <= 9; a++){
            for (int b = 1; b <= 9; b++){
                for (int c = 1; c <= 9; c++){
                    for (int d = 1; d <= 9; d++){
                        System.out.println("" + a + b + c + d);
                    }
                }
            }
        }
    }
}