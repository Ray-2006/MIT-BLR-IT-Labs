/*
library management system where multiple users attempt to boroow book consurrently. Lib has limited number of copies of a book. if no copies avail, user thread must wait.
Once book is returned, waiting threads are notified. 
*/
class Library {
    private int copies;

    public Library(int copies) {
        this.copies = copies;
    }

    public synchronized void borrowBook(String user) throws InterruptedException {
        while (copies == 0) {
            System.out.println(user + " is waiting for a book...");
            wait();
        }
        copies--;
        System.out.println(user + " borrowed a book. Copies left: " + copies);
    }

    public synchronized void returnBook(String user) {
        copies++;
        System.out.println(user + " returned a book. Copies left: " + copies);
        notifyAll();
    }
}

class User extends Thread {
    private Library library;
    private String name;

    public User(Library lib, String name) {
        this.library = lib;
        this.name = name;
    }

    public void run() {
        try {
            library.borrowBook(name);
            Thread.sleep(1000);
            library.returnBook(name);
        } catch (InterruptedException e) { e.printStackTrace(); }
    }
}

public class QE4_library {
    public static void main(String[] args) {
        Library lib = new Library(2);
        for (int i = 1; i <= 5; i++) {
            new User(lib, "User-" + i).start();
        }
    }
}
