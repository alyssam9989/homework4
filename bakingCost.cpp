#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

int main() {
	const int MAX_TITLE_WIDTH = 20;
	const string FILE_NAME = "report.txt";

	cout << "==============================================\n";
	cout << " ---Welcome to my Baking Cost Calculator--- ";
	cout << "\n==============================================\n\n";

	string recipeName;
	int numberOfDesserts = 0;
	double costPerDessert = 0.00;
	double totalCost = 0.00;
	int choice;
	ofstream reportFile(FILE_NAME);
	ifstream inFile(FILE_NAME);

	do {
		cout << "\n--- Menu ---\n";
		cout << "1. Add a baking report\n";
		cout << "2. View baking report\n";
		cout << "3. Recommend baking level\n";
		cout << "4. Quit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		while (cin.fail() || choice < 1 || choice > 4) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Invalid choice. Enter 1-4: ";
			cin >> choice;
		}

	switch (choice) {
	
	case 1:
		cin.ignore();

		cout << "Enter the name of your recipe: ";
		getline(cin, recipeName);

		do {
			cout << "Enter the quantity you plan to bake: ";
			cin >> numberOfDesserts;
			if (cin.fail() || numberOfDesserts <= 0) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid input. Enter a positive number.\n";
			}
		} while (numberOfDesserts <= 0);

		cout << "Enter the cost per dessert quantity ($): ";
		cin >> costPerDessert;

		totalCost = numberOfDesserts * costPerDessert;

		cout << fixed << setprecision(2);
		cout << "\nSummary:\n";
		cout << left << setw(MAX_TITLE_WIDTH) << "Recipe Name: " << recipeName << endl;
		cout << left << setw(MAX_TITLE_WIDTH) << "Quantity: " << numberOfDesserts << endl;
		cout << left << setw(MAX_TITLE_WIDTH) << "Cost per dessert: " << "$" << costPerDessert << endl;
		cout << left << setw(MAX_TITLE_WIDTH) << "Total Cost: " << "$" << totalCost << endl;

		
		if (reportFile) {
			reportFile << fixed << setprecision(2);
			reportFile << "Recipe Name: " << recipeName << endl;
			reportFile << "Quantity: " << numberOfDesserts << endl;
			reportFile << "Total Cost: $" << totalCost << endl;
			reportFile.close();
			cout << "Report saved to '" << FILE_NAME << "'.\n";
		}
		else {
			cout << "Error: Could not create '" << FILE_NAME << "'.\n";
		}
		break;

	case 2:
		cout << "\n--- Viewing Baking Report ---\n";
		
		if (inFile) {
			string line;
			while (getline(inFile, line)) {
				cout << line << endl;
			}
			inFile.close();
		}
		else {
			cout << "No report found. Add a session first.\n";
		}
		break;

	case 3:
		if (totalCost > 50 && numberOfDesserts < 10) {
			cout << "Recommendation: Bake more to save money per dessert.\n";
		}
		else if (totalCost <= 50 && numberOfDesserts >= 10) {
			cout << "Recommendation: You're baking efficiently!\n";
		}
		else {
			cout << "Recommendation: Keep baking!\n";
		}
		break;

	case 4:
		cout << "Exiting program. Goodbye!\n";
		break;

	}

	} while (choice != 4);

	return 0;
 }



