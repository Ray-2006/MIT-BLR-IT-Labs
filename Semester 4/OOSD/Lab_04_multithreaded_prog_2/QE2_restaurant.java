/* restaurant table reservation system using multithreading. Limited no. of tables. multiple customer threads attempt to reserve concurrently. if no table avail, cust thread must wait.
   when table is freed, waiting cust must be notified and alllowed to rserve a table.
*/

class Restaurant {
    private int availableTables;

    public Restaurant(int tables) {
        this.availableTables = tables;
    }

    public synchronized void reserveTable(String customer) throws InterruptedException {
        while (availableTables == 0) {
            System.out.println(customer + " is waiting for a table...");
            wait();
        }
        availableTables--;
        System.out.println(customer + " reserved a table. Tables left: " + availableTables);
    }

    public synchronized void freeTable(String customer) {
        availableTables++;
        System.out.println(customer + " freed a table. Tables left: " + availableTables);
        notifyAll();
    }
}

class Customer extends Thread {
    private Restaurant restaurant;
    private String name;

    public Customer(Restaurant r, String name) {
        this.restaurant = r;
        this.name = name;
    }

    public void run() {
        try {
            restaurant.reserveTable(name);
            Thread.sleep(2000);
            restaurant.freeTable(name);
        } catch (InterruptedException e) { e.printStackTrace(); }
    }
}

public class QE2_restaurant {
    public static void main(String[] args) {
        Restaurant r = new Restaurant(2);
        for (int i = 1; i <= 5; i++) {
            new Customer(r, "Customer-" + i).start();
        }
    }
}
