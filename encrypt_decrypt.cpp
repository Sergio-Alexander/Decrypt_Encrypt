#include <iostream>;
#include <string>;
#include <fstream>;
using namespace std;


//function prototypes
void encrypt();
void decrypt();

string myFile = "imconfused.txt";
char code;
int unlock;

int main()
{
	// declaring the variables
	char option;
	string menu;
	char message[50];

	cout << "Enter a message" << endl;
	cin >> message; //asking the user for a message

	fstream myFile;
	myFile.open("imconfused.txt", ios::out);//opening the text file
	if (myFile.is_open())//if the text file is open
	{
		myFile << message; //inputting the message in the text file
		myFile.close(); // closing the text file
	}
	
	

	menu = "1. Encrypt Message, 2.Decrypt Message, 3. Exit ";

	cout << menu << endl;
	cin >> option;



	cin.ignore();

	while (option != '3') // loop to keep asking the user which option he/she would like to do. It will keep asking the user until the user preses 3
	{

		switch (option)
		{
		case '1': encrypt(); // option 1 will encrypt the message
			break;
		case '2': decrypt(); // option 2 will decrypt the message
			break;
		default: cout << "invalid" << endl; // if the user doesn't input 1, 2, or 3, the system will say invalid
		}
		cout << menu << endl;
		cin >> option;
		cin.ignore();
	}
	return 0;
}

void encrypt()//function definition for encrypt
{
	fstream filein, fileout;

	cout << "Encode Number: ";
	cin >> unlock; //asking the user for a number to complicate the text

	filein.open(myFile, ios::in); // opening the file
	fileout.open("encrypted.txt", ios::out); // opening the file

	while (filein >> code)
	{
		int temp = (code + unlock); // adding a code to complicate the text
		fileout << (char)temp;
	}

	filein.close(); // closing the file
	fileout.close(); // closing the file
}

void decrypt() // function definition for decrypt
{
	cout << "Decode Number: ";
	cin >> unlock; //asking the user for the same code

	fstream filein, fileout;
	filein.open("encrypted.txt", ios::in); // opening the file
	fileout.open("decrypt.txt", ios::out); // opening the file

	while (filein >> code) 
	{
		int temp = (code - unlock); // removing the code so that text will return back to it's original
		fileout << (char)temp;
	}

	filein.close(); // closing the file
	fileout.close(); // closing the file
}