#include <iostream>
using namespace std;

int programmingChallenge16()
{
	double annualInterest;
	double startingBalance;
	double accountLifetime;

	double totalWithdrawn = 0;
	double accumulatedInterest = 0;

	cout << "What is the annual interest rate? \n";
	cin >> annualInterest;
	cin.ignore();

	cout << "What is the starting balance of this account? \n";
	cin >> startingBalance;
	cin.ignore();

	cout << "How long was the account open for (how many months)? \n";
	cin >> accountLifetime;
	cin.ignore();

	for (int months = 1; months < accountLifetime; months++)
	{
		// A 
		cout << "Month " << months << endl;
		double deposit;
		cout << "How much was deposited this month? \n";
		cin >> deposit;
		cin.ignore();
		if (deposit < 0)
		{
			cout << "Account has been closed\n";
			break;
		}
		startingBalance += deposit;

		// B
		double withdrawn;
		cout << "How much was withdrawn? \n";
		cin >> withdrawn;
		cin.ignore();
		if (withdrawn < 0)
		{
			cout << "Account has been closed\n";
			break;
		}
		startingBalance -= withdrawn;
		totalWithdrawn += withdrawn;

		// C
		double monthlyInterest = annualInterest / 12;
		double interestPerMonth;
		interestPerMonth = startingBalance * monthlyInterest;
		accumulatedInterest += interestPerMonth;			// Total Interest over the entire for loop
		startingBalance += interestPerMonth;
	}
	cout << "The ending balance is: " << startingBalance << endl;
	cout << "The amount withdrawn is: " << totalWithdrawn << endl;
	cout << "Total Interest earned: " << accumulatedInterest << endl;
	return 0;
}