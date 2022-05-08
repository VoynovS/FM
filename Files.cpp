#include "Files.h"
#include <fstream>


void createFile(std::string& str) {
	std::cout << "Enter name the file: ";
	std::string oldF1;
	getline(std::cin, oldF1);	
	std::string combined = std::string(str) + oldF1;
	const char* result = combined.c_str();
	std::ofstream f;
	f.open(combined);
	if (f.is_open()) {
		f.close();
		std::cout << "File created!\n";
	}
	else {
		f.close(); 
		std::cout << "File not created!\n";

	}
	
}

//Delete file
void deleteFile(std::string& str) {
	std::cout << "Enter name the file: ";
	std::string oldF1; //Nujhna proverka
	getline(std::cin, oldF1);
	std::string combined = std::string(str) + oldF1;
	const char* result = combined.c_str();
	remove(result);
	std::ofstream check;
	check.open(result, std::ios::in);
	if (check.is_open())
		std::cout << "File not deleted\n";
	else
		std::cout << "File deleted\n";
	
}

//Rename file
void renameFile(std::string str){
	std::cout << "Enter the file name: ";
	std::string oldF1;
	getline(std::cin, oldF1);
	std::string combined = std::string(str) + oldF1;
	const char* result = combined.c_str();
	std::ifstream f;
	f.open(result);
	if (f.is_open()) {
		f.close();
		std::string newF1;
		std::cout << "Enter a new file name: ";
		getline(std::cin, newF1);
		std::string combined2 = std::string(str) + newF1;
		const char* result2 = combined2.c_str();
		if (rename(result, result2) == 0)
			std::cout << "File renamed!" << std::endl;
		else
			std::cout << "File not renamed!" << std::endl;
	}
	else {
		
		f.close();
		std::cout << "There is no such file!\n";
		system("pause");
	}
}
//Rename file


//Writing to a file
void writeFile(std::string str) {
	std::cout << "Enter the file name: ";
	std::string oldF1;
	getline(std::cin, oldF1);	
	std::string combined = std::string(str) + oldF1;
	const char* result = combined.c_str();
	std::ifstream wF; 
	std::ofstream wF1;
	wF.open(result);
	if (wF.is_open()) {
		wF.close();
		wF1.open(result, std::ios::app);
		std::cout << "File is opened\nEnter the changes in the file: ";
		std::string str;
		getline(std::cin, str);
		wF1 << str; 
		wF1 << std::endl;
		std::cout << "Changes have been made\n";
		wF.close();
	}
	else {
		wF.close();
		std::cout << "File opening error or no such file!\n";
	}
	
}

//Reading from a file
void readFile(std::string str) {
	std::cout << "Enter the file name: ";
	std::string oldF1;
	getline(std::cin, oldF1);	
	std::string combined = std::string(str) + oldF1;
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
		rF.close();
	}
	else {
		rF.close();
		std::cout << "File opening error\n";
	}	
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
		remove(result);
		return true;
	}
	else {
		f.close();
		remove(result);
		return false;
	}
}


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
		std::cout << "Enter the path to move the file to: ";
		getline(std::cin, newF);
		last = newF[newF.length() - 1];
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