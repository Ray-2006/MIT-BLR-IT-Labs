/*
implement parking lot management system using multithreading. It has fixed number of parking slots and multiple vehicles attempt to park simultaneously. If no slots avail, 
vehicle must wait. When slot is freed, notify the waiting vehicles.
*/

class ParkingLot {
    private int slots;

    public ParkingLot(int slots) {
        this.slots = slots;
    }

    public synchronized void parkVehicle(String vehicle) throws InterruptedException {
        while (slots == 0) {
            System.out.println(vehicle + " is waiting for a slot...");
            wait();
        }
        slots--;
        System.out.println(vehicle + " parked. Slots left: " + slots);
    }

    public synchronized void leaveSlot(String vehicle) {
        slots++;
        System.out.println(vehicle + " left. Slots left: " + slots);
        notifyAll();
    }
}

class Vehicle extends Thread {
    private ParkingLot lot;
    private String name;

    public Vehicle(ParkingLot lot, String name) {
        this.lot = lot;
        this.name = name;
    }

    public void run() {
        try {
            lot.parkVehicle(name);
            Thread.sleep(1500);
            lot.leaveSlot(name);
        } catch (InterruptedException e) { e.printStackTrace(); }
    }
}

public class QE3_parking {
    public static void main(String[] args) {
        ParkingLot lot = new ParkingLot(3);
        for (int i = 1; i <= 6; i++) {
            new Vehicle(lot, "Vehicle-" + i).start();
        }
    }
}
