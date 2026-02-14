class CustomerOrder implements Runnable {
    private String customerName;

    CustomerOrder(String customerName) {
        this.customerName = customerName;
    }

    @Override
    public void run() {
        System.out.println(customerName + " placed an order.");
        try { Thread.sleep(500); } catch (InterruptedException e) {}
        System.out.println(customerName + " order is being prepared.");
        try { Thread.sleep(500); } catch (InterruptedException e) {}
        System.out.println(customerName + " order is ready to serve!");
    }
}

public class QE3_restaurant {
    public static void main(String[] args) {
        Thread c1 = new Thread(new CustomerOrder("Alice"));
        Thread c2 = new Thread(new CustomerOrder("Bob"));
        Thread c3 = new Thread(new CustomerOrder("Charlie"));

        c1.start();
        c2.start();
        c3.start();
    }
}
