#include "Files.h"

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
void deleteFile(char *a) {
	//char oldF[256];
	char oldF1[256];
	//std::cin >> oldF;
	std::cin >> oldF1;
	std::string combined = std::string(a) + oldF1;
	const char* result = combined.c_str();
	//std::getline(cin, b);
	remove(result);

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

bool testCF(std::string str) {
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