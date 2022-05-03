#include "Folder.h"
#include <iostream>
#include <windows.h>
#include <string>
#include <stdio.h>




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


/*void createFolder(std::string& str) {

	CreateDirectoryA(str.c_str(), NULL);
}*/

//Delete the folder
void deleteFolder(std::string& str) {
	std::string str1;
	getline(std::cin, str1);
	std::string combined = std::string(str) + str1;
	RemoveDirectoryA(combined.c_str());
}

//Rename the folder 
void renameFolder() {
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
		std::cout << "Folder not renamed!" << std::endl;

}

//Remove folder RABOTAET
	/*void removeFolder(char oldF[], char newF[]) {


		if (oldF == newF) {
			MoveFileA(oldF, newF);
			if (MoveFileA(oldF, newF) == 0)
				std::cout << "Folder removed." << std::endl;
			else
				std::cout << "Folder not removed." << std::endl;

		}
		else
			std::cout << "Folder not removed";
	}*/

//Remove folder
void moveFolder() {
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
}