//Program Tools
//It is the header file that contains all the methods we need in the program.

#include <iostream>
//This header file covers the operations of string statements.
#include <string>

#include <fileapifromapp.h> //Adding for TCHAR
#include <WinNls.h> //Adding for WideCharToMultiByte

//Header files required for vector usage
#include <vector>
#include <sstream>

using namespace std;




//The method used to separate the text with the specified token
string SplitStr(string str, string delimiter)
{
	//Chooses from the beginning of the post to the token value.
	std::string token = str.substr(0, str.find(delimiter)); // token is "text" < text.txt
	return token;//returns the selected value.
}

//The method used to write text to a txt file.
void WriteTxt(string filename, string _binfull,string encodeType) {
	filename = SplitStr(filename, ".txt");//We get the incoming file name without extension.
	/*
	Using the filename and the format to be translated, we create the desired translated txt file 
	with its new name, if we have this file, then we update it.
	*/
	ofstream fileWrite(filename + "_"+encodeType+".txt");
	if (fileWrite.is_open()) {//We open the relevant file.

		fileWrite << _binfull; //We write the incoming text to our new txt file (We are updating.)
		fileWrite.close();//We close our new txt file securely.
	}
}
//Method used to delete spaces at the beginning and end of text variables
string trim(const string& str)
{
	size_t first = str.find_first_not_of(' ');//Select without spaces in the first character of text variable(if any).
	first = str.find_first_not_of('\n'); //Remove the bottom line value of the first character of the text variable(if any).
	if (string::npos == first)//npos is a static member constant value with the greatest possible value for an element of type size_t.
	{
		return str;//If the text variable has the largest possible value, we don't need to look at the end.
	}
	size_t last = str.find_last_not_of(' ');//Select without spaces in the last character of text variable(if any).
	last = str.find_last_not_of('\n');//Remove the bottom line value of the last character of the text variable(if any).
	return str.substr(first, (last - first + 1));//We choose the appropriate text variable that has come to the format we want and achieve the method to its purpose.
}
//The method used to return the ascii equivalent of the text in the text variables.
void conStrToBin(string str, string fileuploadname)
{

	int n = str.length();//We find the length of the incoming text variable.
	cout << "\nThe original string is:\n" << str << endl;//We show the original version of the incoming text variable first.
	cout << "\nAscii value of string is:\n";
	//Then we start the process to show the ascii equivalent

	string bin_full;//The variable where we will combine all the translated ascii values and find the full ascii equivalent of the text variable.
	for (int i = 0; i <= n; i++)//We start a loop from the beginning (0) to variable length to select all characters of the text variable.
	{
	
		// We define a variable to keep the index value of each character of the text variable.
		int val = int(str[i]);

		/*The part where the text variable starts to be converted to Ascii*/

		string bin = "";//The variable to keep ascii characters part by section
		
		while (val > 0) //If the character indexes are greater than 0, the loop should continue.
		{
			(val % 2) ? bin.push_back('1') ://If the value of val is divided by two, the ascii of that character is one
				bin.push_back('0');//If the value of val cannot be divided by two, the ascii of that character is 0.
			val /= 2;
		}
		reverse(bin.begin(), bin.end());//Inversion of the ascii value group


		cout << bin << " ";//Printing the ascii value group with a space at the end
		bin_full += bin + " ";//Transferring all ascii to the variable to be kept by leaving a space at the end of the ascii value group.
	}
	cout << "\n"; cout << "\n";//get to the bottom line before and after
	

	//It is the method that will be written to the txt file.We run our method by specifying the text document name, all of the binary characters, format type, ie ascii.
	//In this way, we print the ascii code equivalent of the text that comes to our txt document.
	WriteTxt(fileuploadname,bin_full,"ascii");//Running the method to be written to the txt file to save the Ascii codes.
	
};


//It is a method that converts Char type variables to String type variables.
std::string ConCharToStr(TCHAR* STR)
{
	//Maps a UTF-16 (wide character) string to a new character string. The new character string is not necessarily from a multibyte character set.
	int iLen = WideCharToMultiByte(CP_ACP, 0, STR, -1, NULL, 0, NULL, NULL);
	char* chRtn = new char[iLen * sizeof(char)];
	WideCharToMultiByte(CP_ACP, 0, STR, -1, chRtn, iLen, NULL, NULL);
	std::string str(chRtn);
	delete chRtn;
	return str;
}

//It is a method that finds and separates the txt file name in a string value and returns it.
//Ex: C:\Users\enesk\Documents\data\text2.txt   >   text2.txt
string justFileName(string str) { 

	string filename;//The variable we will keep the file name we will find.
	std::stringstream test(str);//The text flow of the incoming string variable is created.
	std::string segment;//The variable specifying the row.
	std::vector<std::string> seglist;//The part that holds the lines. Line list vector.

	while (std::getline(test, segment, '\\'))//Bring the entire line (segment) up to the '\\' character.
		                                     //It does this until all the lines are gone
	{
		seglist.push_back(segment);//Inserts the data as the last element of the seglis vector.
	}
	filename = seglist[seglist.size()-1];//The last element of the vector contains the file name. We take the last element from the list
	//Thus, we get the file name. Ex: text2.txt
	return filename;
}

