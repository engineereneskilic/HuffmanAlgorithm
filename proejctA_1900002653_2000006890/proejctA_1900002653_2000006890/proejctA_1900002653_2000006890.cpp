
/*
It is a header file that contains declarations of functions such as memory management, 
interaction with the environment, integer arithmetic, search, sort, and transform in the C standard library.
*/
#include <cstdlib>

//This headers file provides preprocessor order codes, a source file to be included in the program.

#include <iostream>
//This header file covers the operations of string statements.
#include <string>

//This header file is used for bit operations
#include <bitset>


//This header file contains queue operations.
#include <queue>

/*
This header file is an associated container that stores elements formed by 
combination of key value and a mapped value.
*/
#include <unordered_map>

//This header file covers file operations
#include <fstream>


//This header file is used to describe all functions of windows api.
#include <Windows.h>
#include <lmcons.h>


//Header files created for our program.
#include "tools.h"
#include "huffmanAlgorithm.h"

using namespace std;

const int char_value=999;

int main()
{

	int fileuploadDesktop; //Is the file containing the text the user wants to compress on the desktop?
	string fileuploadpath = "";//The path to the file containing the text the user wants to compress..
	string fileuploadname = "";//The name of the file containing the text that the user wants to compress.

	//string text = "Hey";
	
	std::string text;//Variable to contain text that the user wants to compress.
	char _text[char_value];//The variable to keep the values received from the user as character character
	string str_username;//Variable to keep the username of the device the user is using as a string.

	int getTextOption;//Required variable to decide whether to read in text or from file
	cout << "Enter Text (1) / Load From File (2):";
	cin >> getTextOption;//Will the program write the text that the user wants to compress or read from the file?
	system("cls"); // Clear console screen.

	if (getTextOption == 1) { // If the user wants to write herself/himself.

		std::string line; //stores the most recent line of input
		cout << "Enter Text:";
		std::getline(std::cin, line); //read entire lines at a time
		cin.getline(_text, char_value);//read entire lines at a time
		text = _text; //Pass from char variable to string variable
		
	}
	else { // If the user wants to read the text she/he wants to compress from the file
		
		int tryagain=0;

		do
		{
			
			cout << "Is your file on the desktop? Yes(1)/No(2):";
			cin >> fileuploadDesktop;//The user is informed where the file containing the text that she wants to compress is on the device
			system("cls"); // Clear console screen.


			if (fileuploadDesktop == 1) //If the file containing the text that the user wants to compress is on the desktop
			{
				//The username of the device used by the user is returned.
				TCHAR username[UNLEN + 1];
				DWORD username_len = UNLEN + 1;
				GetUserName(username, &username_len);

				str_username = ConCharToStr(username);//We convert the username of the device the user is using from tchar to string.

				cout << "Enter the file name (.txt):";
				cin >> fileuploadname;//We get the name of the file containing the text that the user wants to compress from the user.
				cout << '\n';

				//We created the path to the file containing the text that the user wants to compress.
				fileuploadpath = "C:\\Users\\" + str_username + "\\Desktop\\" + fileuploadname;

			}
			else { //If the file containing the text that the user wants to compress is in another location, we manually get the file path from the user.
				cout << "Enter the File Path:";
				cin >> fileuploadpath;//The full path of the file containing the text that the user wants to compress is taken manually.
				cout << '\n';

				fileuploadname = justFileName(fileuploadpath);//The file name is found from the path of the file containing the text that the user wants to compress.
			}


			ifstream reader(fileuploadpath);//The file containing the text that the user wants to compress is read by the reader.
			string line = "";//The line of the file containing the text that the user wants to compress.


			if (reader.is_open()) {//The opening status of the file containing the text that the user wants to compress.

				tryagain = 0;//The necessary variable for the system and the user to give the right to try again.

				while (getline(reader, line)) { //Line by line reading cycle of the file containing the text that the user wants to compress.
					text += line + '\n';//Reading the file containing the text that the user wants to compress, line by line and collecting it in the "text" variable
				}

				reader.close();//Safe close of the reader of the file containing the text that the user wants to compress.

				text = trim(text);//Clearing the text variable from the spaces at the beginning and the end and passing to the bottom line.
			}
			else {//Inability to open the file containing the text that the user wants to compress
				cout << "\nFile not found !\n";
				cout << "Do you want to try again? Yes(1)/No(2):";
				cin >> tryagain;//Getting a response from the user to find the file that contains the text that the user wants to compress.
				system("cls");// Clear console screen.
			}

			//It allows the user to stick to the loop when they want to find the file with the text they want to compress.
		} while (tryagain !=2 && tryagain !=0); // if user chooses no :  trytagain = 2 // if system asks for no trytagain = 0 
	
	}

	
	if (!text.empty()) {//If there is an article that the user wants to compress (if not empty)
		conStrToBin(text, fileuploadname);//To run the function of converting the text that the user wants to compress from string format to ascii format.
		buildHuffmanTree(text, fileuploadname); //Using the Huffman Algorithm, which we use to compress the text that the user wants to compress, to run the corresponding function for the compression process.

	}

	//End of the program

	cout << '\n';
	cout << '\n';
	cout << "\n Thank you for using our program...";
	cout << '\n';
	cout << '\n';
	return 0;
}