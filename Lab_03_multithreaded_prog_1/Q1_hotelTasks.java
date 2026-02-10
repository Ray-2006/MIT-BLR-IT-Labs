class HotelTasks implements Runnable {
    private String task;
    private int duration;

    HotelTasks(String task, int duration) {
        this.task = task;
        this.duration = duration;
    }

    @Override
    public void run() {
        System.out.println(task + " is being carried by " + Thread.currentThread().getName());
        try {
            Thread.sleep(duration);
            System.out.println(task + " completed!");

        } catch (InterruptedException e) {
            System.out.println(task + " interrupted");
        }
    }
}

public class Q1_hotelTasks {
    public static void main(String[] args) {

        new Thread(new HotelTasks("Room Cleaning", 1000)).start();
        new Thread(new HotelTasks("Food Delivery", 2000)).start();
        new Thread(new HotelTasks("Room Maintenance", 3000)).start();
    }
}