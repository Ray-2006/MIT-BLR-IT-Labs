class Hotel {
	private int available;

    public Hotel(int total) {
        this.available = total;
    }
    
    public synchronized void book(String name) {
        while (available == 0) {
            try {
                System.out.println(name + " is waiting for a room...");
                wait();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
        available--;
        System.out.println(name + " booked a room. Rooms left: " + available);
    }

    public synchronized void release(String name) {
        available++;
        System.out.println(name + " released a room. Rooms left: " + available);
        notifyAll();
    }
}

class Customer extends Thread {
    private Hotel hotel;
    private String name;

    public Customer(Hotel hotel, String name) {
        this.hotel = hotel;
        this.name = name;
    }

    public void run() {
        hotel.book(name);
        try {
            Thread.sleep((int)(Math.random() * 2000));
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
        hotel.release(name);
    }
}

public class Q1_HotelManagement {
    public static void main(String[] args) {
        Hotel hotel = new Hotel(3);
        for (int i = 1; i <= 5; i++) {
            new Customer(hotel, "Customer-" + i).start();
        }
    }
}
