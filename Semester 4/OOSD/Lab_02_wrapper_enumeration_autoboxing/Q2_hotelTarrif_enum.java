import java.util.*;

enum roomType {
    STANDARD(20000),
    DELUXE(30000),
    SUITE(550000);

    private int tariff;

    roomType(int tariff) {
        this.tariff = tariff;
    }

    public int getPricePerNight() {
        return tariff;
    }

    public int calcCost(int nights) {
        return tariff * nights;
    }
}

public class Q2_hotelTarrif_enum {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        roomType room = roomType.STANDARD;
        System.out.print("1. STANDARD \n2. DELUXE \n3. SUITE\nSelect room type: ");
        int choice = sc.nextInt();
        switch (choice) {
            case 1:
                room = roomType.STANDARD;
                break;
            case 2:
                room = roomType.DELUXE;
                break;
            case 3:
                room = roomType.SUITE;
                break;
            default:
                System.out.println("Invalid choice, defaulting to STANDARD.");
        }
        System.out.print("Number of nights: ");
        int nights = sc.nextInt();

        System.out.println("Room Type: " + room);
        System.out.println("Price per night: $" + room.getPricePerNight());
        System.out.println("Total cost for " + nights + " nights: $" + room.calcCost(nights));
        sc.close();
    }
}