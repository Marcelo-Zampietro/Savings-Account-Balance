#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    const int ARRAY_SIZE = 23; 
    int bank[ARRAY_SIZE];   // Array for bank records
    int count = 0;             // Loop counter variable
    double withdrawals[10];        // array for withdrawals
    double deposits[10];           // array for deposits
    double interestRate;
    double balance = 0;         // keeps track of total balance
    int numberMonths;
    double monthlyAccounting;   // for the loop to keep track of monthly expenses
    double totalDeposit = 0;        // keeps track of total money deposited
    double totalWithdrawal = 0;     // keeps track of total money withdrawn
    double totalInterest = 0;          // keeps track of total interest
    ifstream inputFile;        // Input file stream object

    // Open the file.
    inputFile.open("SavingsAccountBalanceSpaces.txt");

    // Read the numbers from the file into the array.
    while (count < ARRAY_SIZE && inputFile >> bank[count]) {
        count++;
    }

    // Close the file.
    inputFile.close();

    interestRate = bank[0];                     // yearly interest rate
    double monthlyRate = (interestRate / 12)/100;     // monthly interest rate
    balance += bank[1];                          // current balance
    numberMonths = bank[2];                     // number of deposit and withdrawal months
    
    // Odd Numbers are going to be deposits
    deposits[0] = bank[3];
    deposits[1] = bank[5];
    deposits[2] = bank[7];
    deposits[3] = bank[9];
    deposits[4] = bank[11];
    deposits[5] = bank[13];
    deposits[6] = bank[15];
    deposits[7] = bank[17];
    deposits[8] = bank[19];
    deposits[9] = bank[21];

    // Even numbers are going to be withdrawals
    withdrawals[0] = bank[4];
    withdrawals[1] = bank[6];
    withdrawals[2] = bank[8];
    withdrawals[3] = bank[10];
    withdrawals[4] = bank[12];
    withdrawals[5] = bank[14];
    withdrawals[6] = bank[16];
    withdrawals[7] = bank[18];
    withdrawals[8] = bank[20];
    withdrawals[9] = bank[22];

    // Loop calculating interest
    for (int i = 0; i < 10; i++)
    {
        monthlyAccounting = deposits[i] - withdrawals[i];   // monthly expenditures
        balance += monthlyAccounting;                       // adding it to balance but not with interest
        totalInterest += balance * monthlyRate;             // keeps track of monthly interest
        balance += balance * monthlyRate;                   // the final balance with interest accrued per month
        cout << "The balance for month #" << i+1  << " is: " << balance << endl;
    }
    cout << "Total with interest: " << balance << endl;

    // loop calculating total deposited
    for (int i = 0; i < 10; i++)
    {
        totalDeposit += deposits[i];
    }
    cout << "Total deposited: " << totalDeposit << endl;

    // loop calculating total withdrawn
    for (int i = 0; i < 10; i++)
    {
        totalWithdrawal += withdrawals[i];
    }
    cout << "Total withdrawn: " << totalWithdrawal << endl;
    cout << "Total Interest Accrued: " << totalInterest << endl;
}