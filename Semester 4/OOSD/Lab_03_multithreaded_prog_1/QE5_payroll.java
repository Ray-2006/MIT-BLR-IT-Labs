class EmployeePayroll implements Runnable {
    private String empName;
    private double baseSalary;

    EmployeePayroll(String empName, double baseSalary) {
        this.empName = empName;
        this.baseSalary = baseSalary;
    }

    @Override
    public void run() {
        try { Thread.sleep(1000); } catch (InterruptedException e) {}
        double hra = baseSalary * 0.2;
        double da = baseSalary * 0.1;
        double total = baseSalary + hra + da;
        System.out.println(empName + " salary calculated: " + total);
    }
}

public class QE5_payroll {
    public static void main(String[] args) {
        Thread e1 = new Thread(new EmployeePayroll("John", 50000));
        Thread e2 = new Thread(new EmployeePayroll("Mary", 60000));
        Thread e3 = new Thread(new EmployeePayroll("David", 55000));

        e1.start();
        e2.start();
        e3.start();
    }
}
