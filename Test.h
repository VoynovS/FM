#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>
#include <stdio.h> 



//Rename folder ++
/*void renameF(char oldF[], char oldF1[], char newF[], char newF1[]) {
	newF = oldF;
	std::cout << oldF << std::endl << newF << std::endl;
	if (oldF == newF) {
		std::string combined = std::string(oldF) + oldF1;
		const char* result = combined.c_str();
		std::string combined2 = std::string(newF) + newF1;
		const char* result2 = combined2.c_str();

		if (rename(result, result2) == 0)
			std::cout << "Folder renamed!" << std::endl;
		else
			std::cout << "Folder not renamed1." << std::endl;
	}
	else
		std::cout << "Folder not renamed" << std::endl;

} */

//RenameFolder ++
/*void renameFolder(std::string& a) {
	char oldF[256];
	std::cin >> oldF;
	char oldF1[256];
	char newF1[256];

	std::cin >> oldF1;
	std::cin >> newF1;

	std::string combined = std::string(oldF) + oldF1;
	const char* result = combined.c_str();
	std::string combined2 = std::string(oldF) + newF1;
	const char* result2 = combined2.c_str();
	std::cout << result << std::endl << result2 << std::endl;
	if (rename(result, result2) == 0)
		std::cout << "Folder renamed!" << std::endl;
	else
		std::cout << "Folder not renamed1." << std::endl;

}*/

//Move folder ++
/*void removeF() {
	char oldF[256];
	char oldF1[256];
	char newF[256];

	std::cin >> oldF;

	std::cin >> oldF1;
	std::cin >> newF;

	std::string combined = std::string(oldF) + oldF1;
	const char* result = combined.c_str();
	std::string combined2 = std::string(newF) + oldF1;
	const char* result2 = combined2.c_str();


	if (oldF != newF) {
		MoveFileA(result, result2);
		if (MoveFileA(result, result2) == 0)
			std::cout << "Folder removed: " << result2 << std::endl;
		else
			std::cout << "Folder not removed." << std::endl;

	}
	else
		std::cout << "Folder not removed!";
}*/

//Create files
void createFl() {
	char oldF[256];
	char oldF1[256];
	

	std::cin >> oldF;
	std::cin >> oldF1;

	std::string combined = std::string(oldF) + oldF1;
	const char* result = combined.c_str();
		
	std::ofstream f;
	f.open(result);
	f.close();
}

//Delete files
void deleteFl() {
	char oldF[256];
	char oldF1[256];

	std::cin >> oldF;
	std::cin >> oldF1;

	std::string combined = std::string(oldF) + oldF1;
	const char* result = combined.c_str();

	//std::getline(cin, b);

	remove(result);
	
}

//Rename files
void renameFl() {
	char oldF[256];
	std::cin >> oldF;
	char oldF1[256];
	char newF1[256];

	std::cin >> oldF1;
	std::cin >> newF1;

	std::string combined = std::string(oldF) + oldF1;
	const char* result = combined.c_str();
	std::string combined2 = std::string(oldF) + newF1;
	const char* result2 = combined2.c_str();

	if (rename(result, result2) == 0)
		std::cout << "File renamed!" << std::endl;
	else
		std::cout << "File not renamed1." << std::endl;

}
//Move Files
void moveFl() {
	char oldF[256];
	std::cin >> oldF;
	char oldF1[256];
	char newF[256];

	std::cin >> oldF1;
	std::cin >> newF;

	std::string combined = std::string(oldF) + oldF1;
	const char* result = combined.c_str();
	std::string combined2 = std::string(newF) + oldF1;
	const char* result2 = combined2.c_str();

	if (MoveFileA(result, result2) == 0)
		std::cout << "File moved!" << std::endl;
	else
		std::cout << "File not moved1." << std::endl;

}

//Writing to a file
void writeFl() {

	char oldF[256];
	char oldF1[256];

	std::cin >> oldF;
	std::cin >> oldF1;
	std::cin.ignore();

	std::string combined = std::string(oldF) + oldF1;
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
void readFl() {
	char oldF[256];
	char oldF1[256];

	std::cin >> oldF;
	std::cin >> oldF1;

	std::string combined = std::string(oldF) + oldF1;
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

