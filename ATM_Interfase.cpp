#include <iostream>
#include <string>

class BankAccount {
public:
    std::string name;
    std::string userName;
    std::string password;
    std::string accountNo;
    float balance = 0.0f;
    int transactions = 0;
    std::string transactionHistory = "";

    void registerUser() {
        std::cout << "\nEnter Your Name - ";
        std::cin >> name;
        std::cout << "\nEnter Your Username - ";
        std::cin >> userName;
        std::cout << "\nEnter Your Password - ";
        std::cin >> password;
        std::cout << "\nEnter Your Account Number - ";
        std::cin >> accountNo;
        std::cout << "\nRegistration completed..kindly login";
    }

    bool login() {
        bool isLogin = false;
        while (!isLogin) {
            std::string Username;
            std::cout << "\nEnter Your Username - ";
            std::cin >> Username;
            if (Username == userName) {
                while (!isLogin) {
                    std::string Password;
                    std::cout << "\nEnter Your Password - ";
                    std::cin >> Password;
                    if (Password == password) {
                        std::cout << "\nLogin successful!!";
                        isLogin = true;
                    }
                    else {
                        std::cout << "\nIncorrect Password";
                    }
                }
            }
            else {
                std::cout << "\nUsername not found";
            }
        }
        return isLogin;
    }

    void withdraw() {
        float amount;
        std::cout << "\nEnter amount to withdraw - ";
        std::cin >> amount;
        if (balance >= amount) {
            transactions++;
            balance -= amount;
            std::cout << "\nWithdraw Successfully";
            std::string str = std::to_string(amount) + " Rs Withdrawn\n";
            transactionHistory += str;
        }
        else {
            std::cout << "\nInsufficient Balance";
        }
    }

    void deposit() {
        float amount;
        std::cout << "\nEnter amount to deposit - ";
        std::cin >> amount;
        if (amount <= 100000.0f) {
            transactions++;
            balance += amount;
            std::cout << "\nSuccessfully Deposited";
            std::string str = std::to_string(amount) + " Rs deposited\n";
            transactionHistory += str;
        }
        else {
            std::cout << "\nSorry...Limit is 100000.00";
        }
    }

    void transfer() {
        std::string receipent;
        std::cout << "\nEnter Receipent's Name - ";
        std::cin >> receipent;
        float amount;
        std::cout << "\nEnter amount to transfer - ";
        std::cin >> amount;
        if (balance >= amount) {
            if (amount <= 50000.0f) {
                transactions++;
                balance -= amount;
                std::cout << "\nSuccessfully Transferred to " << receipent;
                std::cout << "\nYour Balance is: " << balance << " Rs\n";
                std::string str = std::to_string(amount) + " Rs transferred to " + receipent + "\n";
                transactionHistory += str;
            }
            else {
                std::cout << "\nSorry...Limit is 50000.00";
            }
        }
        else {
            std::cout << "\nInsufficient Balance";
        }
    }

    void checkBalance() {
        std::cout << "\n" << balance << " Rs\n";
    }

    void transHistory() {
        if (transactions == 0) {
            std::cout << "\nEmpty";
        }
        else {
            std::cout << "\n" << transactionHistory;
        }
    }
};

int main() {
    std::cout << "\nWELCOME ATM SYSTEM\n";
    std::cout << "1.Register \n2.Exit\n";
    std::cout << "Enter Your Choice - ";
    int choice;
    std::cin >> choice;
    if (choice == 1) {
        BankAccount b;
        b.registerUser();
        while (true) {
            std::cout << "\n1.Login \n2.Exit\n";
            std::cout << "Enter Your Choice - ";
            int ch;
            std::cin >> ch;
            if (ch == 1) {
                if (b.login()) {
                    std::cout << "\n\nWELCOME BACK " << b.name << "\n";
                    bool isFinished = false;
                    while (!isFinished) {
                        std::cout << "\n1.Withdraw \n2.Deposit \n3.Transfer \n4.Check Balance \n5.Transaction History \n6.Exit\n";
                        std::cout << "\nEnter Your Choice - ";
                        int c;
                        std::cin >> c;
                        switch (c) {
                        case 1:
                            b.withdraw();
                            break;
                        case 2:
                            b.deposit();
                            break;
                        case 3:
                            b.transfer();
                            break;
                        case 4:
                            b.checkBalance();
                            break;
                        case 5:
                            b.transHistory();
                            break;
                        case 6:
                            isFinished = true;
                            break;
                        }
                    }
                }
            }
            else {
                break;
            }
        }
    }
    else {
        return 0;
    }
}
