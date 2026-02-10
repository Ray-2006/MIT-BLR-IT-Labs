interface Series {
    int getNext();

    void reset();

    void setStart(int x);
}

class ByTwos implements Series {
    int start;
    int current;

    ByTwos(int start) {
        this.start = start;
        this.current = start;
    }

    public int getNext() {
        int temp = current;
        current += 2;
        return temp;
    }

    public void reset() {
        current = start;
    }

    public void setStart(int x) {
        start = x;
        current = x;
    }
}

public class Q4_byTwos {
    public static void main(String[] args) {
        ByTwos s = new ByTwos(0);

        System.out.println(s.getNext());
        System.out.println(s.getNext());
        System.out.println(s.getNext());

        s.reset();
        System.out.println("After reset:");
        System.out.println(s.getNext());

        s.setStart(10);
        System.out.println("After setting new start:");
        System.out.println(s.getNext());
        System.out.println(s.getNext());
    }
}