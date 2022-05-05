#include <iostream>
#include <windows.h>
#include <string>
#include "Folder.h"
#include "Test.h"
#include "Files.h"
using namespace std;



int main() {
	setlocale(LC_ALL, "Russian");
	cout << "Welcome to the File Manager.\nRules for using the file manager:\n";
	cout << "1. To get started, write down the path to the folder.\n";
	cout << "2. Syntax for writing a path using an example: c:/folder/ and name.txt\n";
	cout << "3. Enter the command to execute: add folder/file, delete folder/file, \nrename folder/file,  move folder/file, reading a file, writing to a file.\n";
	cout << "4. Follow the on-screen instructions.\n";
	cout << "5. To exit, enter the command : exit.\n";
	system("pause");
	
	/*LPCSTR pcstr;
	string folder = "";
	pcstr = folder.c_str();*/
	int num;
	string path;
	char a = { '/' };
	char b = {'\\'};
	char last;
	do {
		system("cls");
		
		cout << "1. Create folder.\n";
		cout << "2. Create file.\n";
		cout << "3. Delete folder.\n";
		cout << "4. Delete file.\n";
		cout << "5. Move folder.\n";
		cout << "6. Move file.\n";
		cout << "7. Rename folder.\n";
		cout << "8. Rename file.\n";
		cout << "9. Writing to a file\n";
		cout << "10. Reading from a file\n";
		cout << "11. Exit.\n\n";
		cout << "Enter the command: ";

		cin >> num;
		cin.ignore();
		if (num == 11) {
			cout << "Are you sure? 1 - yes, 2 - no";
			cin >> num;
			if (num == 1)
				return 0;
			else
				if (num == 2)
					continue;
				else
					continue;
		}
	
		system("cls");
		cout << "Enter path to folder:\n";
		getline(cin, path);
		last = path[path.length() - 1];
		cout << last << endl; //del
		system("pause");
		if (last != a && last != b) {
			cout << "THE specified path does not exist.\n";
			system("pause");
			continue;
		}

		switch (num) {
			case 1:
			if (testCFl(path) != 0) {
				cout << "Enter name the folder: ";
				createFolder(path);
				cout << "Folder created!\n";
				system("pause");
			}
			else {
				cout << "The specified path does not exist.\n";
				system("pause");
			}
			break;

			case 2:
			if (testCFl(path) != 0) {
				cout << "Enter name the file: ";
				createFile(path);
				cout << "File created!\n";
				system("pause");
			}
			else {
				cout << "The specified path does not exist.\n";
				system("pause");
			}
			break;

			case 3:
			if (testCFl(path) != 0) {
				cout << "Enter the folder name: ";
				deleteFolder(path);
				cout << "Folder deleted!\n"; //Proverit'
				system("pause");
			}
			else {
				cout << "The specified path does not exist.\n";
				system("pause");
			}
			break;
								
			case 4:
				if (testCFl(path) != 0) {
					cout << "Enter name the file: ";
					deleteFile(path);
					system("pause");
				}
				else {
					cout << "The specified path does not exist.\n";
					system("pause");
				}
			break;

			case 5:
				if (testCFl(path) != 0) {
					
					moveFolder(path);
					system("pause");
				}
				else {
					cout << "The specified path does not exist.\n";
					system("pause");
				}
				break;
			case 6:
				if (testCFl(path) != 0) {

					moveFile(path);
					system("pause");
				}
				else {
					cout << "The specified path does not exist.\n";
					system("pause");
				}
				break;
			case 7:
				if (testCFl(path) != 0) {

					renameFolder(path);
					system("pause");
				}
				else {
					cout << "The specified path does not exist.\n";
					system("pause");
				}
				break;

			default:
				cout << "Command not found. Try again\n";
				system("pause");
			break;

			
				
				/*string qq = "cd M:";
				//string combined = string(qq) + path;
				const char* result = qq.c_str();
				system(result);
				string tt = "rmdir /s/q TEST/TEST1";
				const char* result2 = tt.c_str();
				system(result2);
				system("pause");*/
				
		}
		
	} while (num != 11);


	


	/*LPCSTR pcstr;
	string folder = "";
	pcstr = folder.c_str();

	getline(cin, folder);
	createFolder(folder);

	getline(cin, folder);
	deleteFolder(folder);*/
	/////////////////////////////////////////
	
	return 0;
}