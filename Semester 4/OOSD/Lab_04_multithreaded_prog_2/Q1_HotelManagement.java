class Hotel {
    private int available;

    public Hotel(int total) {
        this.available = total;
    }

    public synchronized void book(String name) {
        while (available == 0) {
            System.out.println(name + " is waiting. No rooms available.");
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        available--;
        System.out.println(name + " booked a room. Rooms left: " + available);
    }

    public synchronized void release(String name) {
        available++;
        System.out.println(name + " released a room. Rooms available: " + available);

        notifyAll();
    }
}

class Book extends Thread {
    private Hotel hotel;
    private String name;

    public Book(Hotel hotel, String name) {
        this.hotel = hotel;
        this.name = name;
    }

    @Override
    public void run() {
        hotel.book(name);
    }
}

class Release extends Thread {
    private Hotel hotel;
    private String name;

    public Release(Hotel hotel, String name) {
        this.hotel = hotel;
        this.name = name;
    }

    @Override
    public void run() {
        try {
            Thread.sleep((long) (Math.random() * 5000));
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        hotel.release(name);
    }
}

public class Q1_HotelManagement {
    public static void main(String[] args) {

        Hotel hotel = new Hotel(3);

        Book c1 = new Book(hotel, "Customer 1");
        Book c2 = new Book(hotel, "Customer 2");
        Book c3 = new Book(hotel, "Customer 3");
        Book c4 = new Book(hotel, "Customer 4");
        Book c5 = new Book(hotel, "Customer 5");

        Release r1 = new Release(hotel, "Customer 1");
        Release r2 = new Release(hotel, "Customer 2");

        c1.start();
        c2.start();
        c3.start();
        c4.start();
        c5.start();

        r1.start();
        r2.start();
    }
}
