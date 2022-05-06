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
		f.close();
		remove(result);
		return false;
	}
}


void createFolder(std::string& str) {
	std::cout << "Enter name the folder: ";
	std::string str1;
	getline(std::cin, str1);
	std::string combined = std::string(str) + str1;
	const char* result = combined.c_str();
	CreateDirectoryA(combined.c_str(), NULL);
	std::ofstream fO;
	fO.open(result);
	if (fO.is_open()) {
		fO.close();
		std::cout << "Folder created!\n";
	}
	else {
		fO.close();
		std::cout << "Folder not created!";
	}
}
//Delete the folder
void deleteFolder(std::string& str) {
	std::cout << "Enter the folder name: ";
	std::string str1;
	getline(std::cin, str1);
	std::string combined = std::string(str) + str1;
	const char* result = combined.c_str();
	RemoveDirectoryA(combined.c_str());
	std::ofstream fO;
	fO.open(result);
	if (fO.is_open()) {
		fO.close();
		std::cout << "Folder not deleted!\n";
		std::cout << "There is no such folder or there are files inside the folder.\n";
		std::cout << "You can delete a folder if it is empty\n";
		system("pause");
	}
	else {
		fO.close();
		std::cout << "Folder deleted!\n";
	}
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
		std::cout << "Folder renamed!\n" << std::endl;
	else
		std::cout << "Folder not renamed!\n" << std::endl;
	return 0;
}

//Move folder
bool moveFolder(std::string& str) {
	char last;
	char a = { '/' };
	char b = { '\\' };
	std::string oldF1;
	std::string newF;
	std::string combined = std::string(str) + oldF1;
	const char* result = combined.c_str();
	std::cout << "Enter the folder name: ";
	getline(std::cin, oldF1); //Nushna proverka
	if (testCFo(combined) == 0) {
		std::cout << "There is no such folder!\n";
		system("pause");
		return 0;
	}
	std::cout << "Enter the path to move the folder to: ";
	getline(std::cin, newF);
	last = newF[newF.length() - 1];
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
					std::cout << "Folder not removed.\n" << std::endl;

			}
			else
				std::cout << "Folder not removed!\n";
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

