// This program uses a loop to write and read values to a file.
#include <iostream> // Header File for Keyboard/Screen
#include <fstream>  // Needed to use files
#include <string>   // Need for String Input  

using namespace std;

// Function prototype
void saveInfo();
void displayInfo();

int main()
{
	int choice;           // Menu choice
	do {
		system("cls");   //Clear Screen Display the menu
		cout << "\n Sales Report\n\n";
		cout << "1. Save Info\n";
		cout << "2. Display Info\n";
		cout << "3. Quit the Program\n\n";
		cout << "Enter your choice: ";

		// Validate the menu selection
		while (!(cin >> choice) || (choice < 1 || choice > 3))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter 1, 2, or 3: ";
		}
		// Process the user's choice
		if (choice != 3)
		{
			switch (choice)
			{
			case 1: saveInfo();  // Call function write
				break;
			case 2:displayInfo();   // Call function read
				break;
			}
		}
	} while (choice != 3); // Loop again if 3 not selected
	cout << "\n\nEnter ot End....";
	return 0;
}

/******************************************
* This function Writes data to the file. *
******************************************/
void  saveInfo()
{
	double sales;
	string name;
	ofstream outFile;
	outFile.open("Sales.txt", ios::app);

	system("cls");
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Enter Name: ";
	getline(cin, name);
	cout << "Enter the sales for the day: ";

	while (!(cin >> sales) || (sales < 0))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), 'n');
		cout << "Please enter a Number: ";
	}

	outFile << name << "," << sales << endl;

	outFile.close();
	//ADD YOUR CODE 
	cout << "Data Written ";
	cin.get(); cin.get();
}


/*******************************************
* This function reades data from the File.*
*******************************************/
void displayInfo()
{
	double sales = 0.0;
	string name;
	fstream inFile;

	inFile.open("Sales.txt");

	if (inFile.is_open())
	{
		system("cls");
		cout << endl << endl << "Sales Report" << endl;
		cout << "------------" << endl;
		getline(inFile, name, ',');
		inFile >> sales;
		inFile.ignore(1);

		while (!inFile.eof())
		{
			cout << "Name: " << name << endl;
			cout << "Sales: " << sales << endl << endl;
			getline(inFile, name, ',');
			inFile >> sales;
			inFile.ignore(1);
		}
	}
	else
	{

		cout << "No File to Open\n";

	}
	inFile.close();
	cout<< "\n\n";
	cout << "Data Read\n ";
	cout << "Press ENTER to Continue";
	
	cin.get();
	cin.get();

}
