#include "Folder.h"
#include <iostream>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <fstream>



bool testCFo(std::string str) {
	char oldF1[256] = "/1.txt";
	std::string combined = std::string(str) + oldF1;
	const char* result = combined.c_str();
	std::ofstream f;
	f.open(combined);
	if (f.is_open()) {
		system("pause");
		f.close();
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


//Create the folder
/*void createFolder(char* a) {

	std::string str;
	getline(std::cin, str);
	std::string combined = std::string(a) + str;
	CreateDirectoryA(combined.c_str(), NULL);
}*/

void createFolder(std::string& str) {

	std::string str1;
	getline(std::cin, str1);
	std::string combined = std::string(str) + str1;
	CreateDirectoryA(combined.c_str(), NULL);
}

//Delete the folder
void deleteFolder(std::string& str) {
	std::string str1;
	getline(std::cin, str1);
	std::string combined = std::string(str) + str1;
	RemoveDirectoryA(combined.c_str());
}

//Rename the folder 
bool renameFolder(std::string& str) {
	std::cout << "Enter the folder name: ";
	std::string oldF1;
	getline(std::cin, oldF1);
	std::string combined = std::string(str) + oldF1;
	const char* result = combined.c_str();
	if (testCFo(combined) == 0) {
		std::cout << "There is no such folder!\n";
		system("pause");
		return 0;
	}
	std::string newF1;
	std::cout << "Enter a new folder name: ";
	getline(std::cin, newF1);
	std::string combined2 = std::string(str) + newF1;
	const char* result2 = combined2.c_str();
	if (rename(result, result2) == 0)
		std::cout << "Folder renamed!" << std::endl;
	else
		std::cout << "Folder not renamed!" << std::endl;
	return 0;
}

//Move folder
bool moveFolder(std::string& str) {
	char last;
	char a = { '/' };
	char b = { '\\' };
	std::string oldF1;
	std::string newF;

	std::cout << "Enter the folder name: ";
	getline(std::cin, oldF1); //Nushna proverka
	std::string combined = std::string(str) + oldF1;
	const char* result = combined.c_str();
	if (testCFo(combined) == 0) {
		std::cout << "There is no such folder!\n";
		system("pause");
		return 0;
	}

	std::cout << "Enter the path to move the folder to: ";
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
		if (testCFo(newF) != 0) {
			if (str != newF) {
				MoveFileA(result, result2);
				if (MoveFileA(result, result2) == 0)
					std::cout << "Folder removed: " << result2 << std::endl;
				else
					std::cout << "Folder not removed." << std::endl;

			}
			else
				std::cout << "Folder not removed!";
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

