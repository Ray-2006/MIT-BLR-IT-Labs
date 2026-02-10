class Room {
    Integer priceobj, dayobj;
    Double serviceobj, billobj;

    Room(int price, int days) {
        priceobj = Integer.valueOf(price);
        dayobj = Integer.valueOf(days);
        serviceobj = Double.valueOf(this.service());
        billobj = Double.valueOf(this.totaltarrif());
    }

    public double service() {
        int days = dayobj.intValue();
        int price = priceobj.intValue();
        return 0.25 * days * price;
    }

    public double totaltarrif() {
        int days = dayobj.intValue();
        int price = priceobj.intValue();
        double service = serviceobj.doubleValue();
        return (days * price) + service;
    }

    public void totalbill() {
        System.out.println("------ Total Bill ------");
        System.out.println("Room price: $" + priceobj.intValue());
        System.out.println("Number of days: " + dayobj.intValue());
        System.out.println("Service Charge: $" + serviceobj.doubleValue());
        System.out.println("------------------------");
        System.out.println("Total Tarrif: $" + billobj.doubleValue());
    }
}

public class Q1_hotelBilling_wrapper {
    public static void main(String[] args) {
        Room r1 = new Room(23000, 3);
        r1.totalbill();

        System.out.println();

        Room r2 = new Room(6000, 6);
        r2.totalbill();
    }
}
