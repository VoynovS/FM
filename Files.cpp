#include "Files.h"
#include <fstream>
//Create file
/*void createFile(char* a) {
	//char oldF[256];
	char oldF1[256];
	//std::cin >> oldF;
	std::cin >> oldF1;
	std::string combined = std::string(a) + oldF1;
	const char* result = combined.c_str();
	std::ofstream f;
	f.open(result);
	f.close();
}*/

void createFile(std::string& str) {
	//char oldF[256];
	char oldF1[256];
	//std::cin >> oldF;
	std::cin >> oldF1;
	std::string combined = std::string(str) + oldF1;
	//const char* result = combined.c_str();
	std::ofstream f;
	f.open(combined);
	f.close();
}

//Delete file
void deleteFile(std::string& str) {
	//char oldF[256];
	char oldF1[256];
	//std::cin >> oldF;
	std::cin >> oldF1;
	std::string combined = std::string(str) + oldF1;
	const char* result = combined.c_str();
	//std::getline(cin, b);
	remove(result);
	std::ofstream check;
	check.open(result, std::ios::in);
	if (check.is_open())
		std::cout << "File not deleted\n";
	else
		std::cout << "File deleted\n";
	
}
//Rename file
void renameFile(char *a) {
	//char oldF[256];
	//std::cin >> oldF;
	char oldF1[256];
	char newF1[256];
	std::cin >> oldF1;
	std::cin >> newF1;
	std::string combined = std::string(a) + oldF1;
	const char* result = combined.c_str();
	std::string combined2 = std::string(a) + newF1;
	const char* result2 = combined2.c_str();
	if (rename(result, result2) == 0)
		std::cout << "File renamed!" << std::endl;
	else
		std::cout << "File not renamed." << std::endl;
}

//Writing to a file
void writeFile(char *a) {
	//char oldF[256];
	char oldF1[256];
	//std::cin >> oldF;
	std::cin >> oldF1;
	std::cin.ignore();
	std::string combined = std::string(a) + oldF1;
	const char* result = combined.c_str();
	std::ofstream wF;
	wF.open(result, std::ios::app);
	if (wF.is_open()) {
		std::cout << "File is opened\nEnter the changes in the file: ";
		std::string str;
		getline(std::cin, str);
		wF << str << "\n";
	}
	else
		std::cout << "File opening error\n";
	wF.close();
	std::cout << std::endl;
}

//Reading from a file
void readFile(char *a) {
	//char oldF[256];
	char oldF1[256];
	//std::cin >> oldF;
	std::cin >> oldF1;
	std::string combined = std::string(a) + oldF1;
	const char* result = combined.c_str();
	std::ifstream rF;
	rF.open(result);
	if (rF.is_open()) {
		std::cout << "File is opened\n";
		while (!rF.eof()) {
			std::string str;
			getline(rF, str);
			std::cout << str << std::endl;
		}
	}
	else
		std::cout << "File opening error\n";
	rF.close();
	std::cout << std::endl;
}

bool testCFl(std::string str) {
	char oldF1[256] = "1.txt";
	std::string combined = std::string(str) + oldF1;
	const char* result = combined.c_str();
	std::ofstream f;
	f.open(result);
	if (f.is_open()) {
		std::cout << "You are in the folder: " << str << std::endl;
		f.close();
		system("pause");
		remove(result);
		return true;
	}
	else {
		//std::cout << "There is no such folder!\n";
		f.close();
		remove(result);
		return false;
	}
}

//Test create file
/*bool testCF(char* a) {
	char oldF1[256] = "1.txt";


	//std::cin >> oldF;
	//std::cin >> oldF1;

	std::string combined = std::string(a) + oldF1;
	const char* result = combined.c_str();

	std::ofstream f;
	f.open(result);
	if (f.is_open()) {
		std::cout << "You are in the folder: " << a << std::endl;
		return true;
	}
	else {
		std::cout << "There is no such folder!\n";
		return false;
	}
	f.close();
}*/

bool moveFile(std::string& str) {
	char last;
	char a = { '/' };
	char b = { '\\' };
	std::string oldF1;
	std::string newF;

	std::cout << "Enter the file name: ";
	getline(std::cin, oldF1); //Nushna proverka
	std::string combined = std::string(str) + oldF1;
	const char* result = combined.c_str();

	std::fstream f;
	f.open(result, std::ios::in);
	if (f.is_open()) {
		f.close();
		system("pause");
		
		std::cout << "Enter the path to move the file to: ";
		getline(std::cin, newF);
		last = newF[newF.length() - 1];
		std::cout << last << std::endl; //del
		system("pause");
		std::string combined2 = std::string(newF) + oldF1;
		const char* result2 = combined2.c_str();
		//proverka 1
		if (last != a && last != b) {
			std::cout << "THE specified path does not exist.\n";
			system("pause");
			return 0;
		}
		else { //Proverka 2
			if (testCFl(newF) != 0) {
				if (str != newF) {
					MoveFileA(result, result2);
					if (MoveFileA(result, result2) == 0)
						std::cout << "File removed: \n" << result2 << std::endl;
					else
						std::cout << "File not removed.\n" << std::endl;

				}
				else
					std::cout << "File not removed!\n";
				return 0;
			}
			else {
				std::cout << "The specified path does not exist.\n";
				system("pause");
			}
			return 0;
		}
		return 0;
	}
	else {
		f.close();
		std::cout << "There is no such file!\n";
		return 0;
	}

}