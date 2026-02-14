
class BankAccount {

    private int balance = 1000;

    public void deposit(int amount) {
        System.out.println(Thread.currentThread().getName() + " depositing " + amount);
        int newBalance = balance + amount;
        try {
            Thread.sleep(300);
        } catch (InterruptedException e) {
        }
        balance = newBalance;
        System.out.println("Balance after deposit: " + balance);
    }

    public void withdraw(int amount) {
        System.out.println(Thread.currentThread().getName() + " withdrawing " + amount);
        if (balance >= amount) {
            int newBalance = balance - amount;
            try {
                Thread.sleep(300);
            } catch (InterruptedException e) {
            }
            balance = newBalance;
            System.out.println("Balance after withdrawal: " + balance);
        } else {
            System.out.println("Insufficient funds!");
        }
    }
}

class Transaction implements Runnable {

    private BankAccount account;
    private String type;
    private int amount;

    Transaction(BankAccount account, String type, int amount) {
        this.account = account;
        this.type = type;
        this.amount = amount;
    }

    @Override
    public void run() {
        if (type.equals("deposit")) {
            account.deposit(amount);
        } else if (type.equals("withdraw")) {
            account.withdraw(amount);
        }
    }
}

public class QE6_bankAccount {

    public static void main(String[] args) {
        BankAccount account = new BankAccount();

        Thread t1 = new Thread(new Transaction(account, "deposit", 200), "Customer1");
        Thread t2 = new Thread(new Transaction(account, "withdraw", 150), "Customer2");
        Thread t3 = new Thread(new Transaction(account, "withdraw", 500), "Customer3");

        t1.start();
        t2.start();
        t3.start();
    }
}
