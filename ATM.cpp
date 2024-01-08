#include <iostream> //for input and output operations
#include <fstream>  // for file manipulation
using namespace std;
struct account{   // structure for different values like account_number etc
int account_number; // will be entered by user
int account_no; //will be initialized from file
int pin_code; // will be entered by user
int pin; // will be intialized from file
double Balance; // will be intialized from file
double new_balance; // after withdrawl and depositing money remaning balance will be held here
double amount;// amount user wants to withdraw or deposit
};
int main()
{
    account acnt;
    bool found = false; // it will be used in double checking account number and pin 
    int choice; // used to choose one of 3 options withdraw,deposit and finding remaining balance


    cout << "Please Enter Your Account Number\n";
    cin >> acnt.account_number; //user enters account number for confirmation
    cout << "Please Enter Your Pin Code\n";
    cin >> acnt.pin_code; //user entering pin code for confirmation
    ifstream file("accounts.txt"); // opening file in reading or input mode
    if (file.fail()) // if file fails to open program will come to end
    {
        cout << "Could not open the file";
        return 0;
    }
    while (file >> acnt.account_no >> acnt.pin >> acnt.Balance) // whitespace will work as delimiters assigning each value from file to 
    //respective variables
    {
        if (acnt.account_number == acnt.account_no && acnt.pin_code == acnt.pin)//confirming account number and pin by matching entered by user 
        //to that of what file holds
        {
            found = true; // will cause rest of program to work
        }
    }
    file.close(); //closing file it can be opened later
    while (found)
    {
        cout << "Welcome to your Chase Account\n";
        cout << "Please Choose one of the following options\n";
        cout << "Enter 1 to Deposit Money\n";
        cout << "Enter 2 to Withdraw Money\n";
        cout << "Enter 3 to Find Remaining Balance\n";
        cin >> choice;// user enters respective number for desired operation 
        switch (choice)
        {
        case 1:
            cout << "How much money would you like to deposit?\n";
            cin >> acnt.amount; // asking about amount user wants to deposit
            acnt.Balance += acnt.amount;// changing balance
            acnt.new_balance = acnt.Balance;// will be used to write updated data to file
            cout << "Your New Balance is " << acnt.Balance << endl; // shows new balance
            cout<<"Thank you for using our services ";
            break;

        case 2:
            cout << "How much money would you like to Withdraw\n";
            cin >> acnt.amount; // asking for amount user wants to withdraw
            acnt.Balance -= acnt.amount; // changing balance
            acnt.new_balance = acnt.Balance; //will be used to update file data
            cout << "Your New Balance is " << acnt.Balance << endl; //shows new balance
            cout<<"Thank you for using our services ";
            break;

        case 3:
            cout << "Your Balance is " << acnt.Balance << endl; //shows remaining balance
            cout<<"Thank you for using our services ";
            return 0; // will bring program to end as no need of change in file is needed 

        default:
            cout << "Invalid Input"; // will be shown if user enters any other number than 1,2 or 3
            break;
        }
        found = false;
    }
    file.open("accounts.txt"); // opening file again
    ofstream file2("accounts2.txt"); //opening another file in writing or output mode
    file2<<acnt.account_no<<" "<<acnt.pin<<" "<<acnt.new_balance; //writing new balance to file number 2
    file.close(); // closing first file
    file2.close(); // closing second file
    remove("accounts.txt"); // removing first file
    rename("accounts2.txt","accounts.txt"); // renaming files to have orginal file with new balance 
    return 0;
}
