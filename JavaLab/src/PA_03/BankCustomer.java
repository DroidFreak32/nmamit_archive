package PA_03;

import java.util.Scanner;

class customer {
    double balance;
    private String name;
    private Long accno;

    customer(String s, long a) {
        name = s;
        accno = a;
        balance = 0;
    }

    void display() {
        System.out.println("\nName = " + name + "\nAccount No. = "
                + accno + "\nBalance = " + balance);
    }
}

class account extends customer {
    Double intrst_rt;
    private String acc_type;

    account(String s, long accno, String at) {
        super(s, accno);
        acc_type = at;
    }

    void Deposit(double amt) {
        balance += amt;
    }

    void Withdraw(double amt) {
        if ((balance - amt) <= 0)
            System.out.println("Amount for withdraw is less than balance");
        else
            balance = balance - amt;
    }

    double GetBalance() {
        return (balance);
    }

    void display() {
        super.display();
        System.out.println("Account Type = " + acc_type);
    }
}

public class BankCustomer {
    public static void main(String[] args) {
        boolean flag = true;
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the name of customer");
        String name = s.nextLine();
        System.out.println("Enter the account number");
        long acc = s.nextInt();
        System.out.println("Enter the account type");
        s.nextLine();
        String acct = s.nextLine();
        account a1 = new account(name, acc, acct);
        while (flag) {
            System.out.println("\nPress:\n1:Deposit\n2:Withdraw\n3:GetBalance\n4:display\n5:exit");
            System.out.println("Enter option");
            int c = s.nextInt();
            switch (c) {
                case 1:
                    System.out.println("Enter the amount");
                    double amount = s.nextDouble();
                    a1.Deposit(amount);
                    break;
                case 2:
                    System.out.println("Enter the amount to be withdrawn");
                    double at = s.nextInt();
                    a1.Withdraw(at);
                    break;
                case 3:
                    double b = a1.GetBalance();
                    System.out.println("Balance = " + b);
                    break;
                case 4:
                    a1.display();
                    break;
                case 5:
                    flag = false;
            }
        }
    }
}
