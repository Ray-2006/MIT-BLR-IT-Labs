class OrderProcess implements Runnable {
    private int orderNumber;

    public OrderProcess(int orderNumber) {
        this.orderNumber = orderNumber;
    }

    public void run() {
        System.out.println("Order: " + orderNumber + " thread: " + Thread.currentThread().getName());
        try {
            System.out.println("Order: " + orderNumber + " validated");
            Thread.sleep(2000);
            System.out.println("Processing payment for: " + orderNumber);
            Thread.sleep(3000);
            System.out.println("Payment successful for: " + orderNumber);
            Thread.sleep(2500);
            System.out.println("Order: " + orderNumber + " shipped");
            Thread.sleep(2500);
            System.out.println("Order: " + orderNumber + " delivered");
        } catch (InterruptedException e) {
            System.out.println("Order interrupted for " + orderNumber);
        }
    }
}

public class Q2_onlineOrders {
    public static void main(String[] args) {
        new Thread(new OrderProcess(1234)).start();
        new Thread(new OrderProcess(1600)).start();
    }
}