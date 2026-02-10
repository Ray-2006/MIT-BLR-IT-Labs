import java.util.*;

class InvalidDateException extends Exception {
    public InvalidDateException(String message) {
        super(message);
    }
}

class InvalidMonthException extends InvalidDateException {
    public InvalidMonthException(String message) {
        super(message);
    }
}

class currentDate {
    int day, month, year;

    public void createDate() throws InvalidDateException, InvalidMonthException {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter day: ");
        day = scanner.nextInt();
        System.out.print("Enter month: ");
        month = scanner.nextInt();
        System.out.print("Enter year: ");
        year = scanner.nextInt();
        scanner.close();

        if (month < 1 || month > 12) {
            throw new InvalidMonthException("Invalid month: " + month);
        }

        int[] daysInMonth = { 31, (isLeapYear(year) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        if (day < 1 || day > daysInMonth[month - 1]) {
            throw new InvalidDateException("Invalid day: " + day + " for month: " + month);
        }

    }

    private boolean isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    public void displayDate() {
        System.out.println("Date: " + day + "/" + month + "/" + year);
    }
}

public class Q5_currentDate {
    public static void main(String[] args) {
        currentDate date = new currentDate();
        try {
            date.createDate();
            date.displayDate();
        } catch (InvalidMonthException e) {
            System.out.println("Month Error: " + e.getMessage());
        } catch (InvalidDateException e) {
            System.out.println("Date Error: " + e.getMessage());
        }
    }
}