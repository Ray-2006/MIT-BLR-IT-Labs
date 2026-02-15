class ChatUser implements Runnable {
    private String name;

    ChatUser(String name) {
        this.name = name;
    }

    @Override
    public void run() {
        for (int i = 1; i <= 3; i++) {
            System.out.println(name + " sent message " + i);
            try { Thread.sleep(500); } catch (InterruptedException e) {}
            System.out.println(name + " received reply for message " + i);
        }
    }
}

public class QE4_chatSystem {
    public static void main(String[] args) {
        Thread user1 = new Thread(new ChatUser("Alice"));
        Thread user2 = new Thread(new ChatUser("Bob"));
        Thread user3 = new Thread(new ChatUser("Charlie"));

        user1.start();
        user2.start();
        user3.start();
    }
}
