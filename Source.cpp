#include <iostream>
#include <windows.h>
#include <string>
#include "Folder.h"
#include "Test.h"
#include "Files.h"
#include "Check.h"
using namespace std;

int main() {
	
	cout << "Welcome to the File Manager.\nRules for using the file manager:\n";
	cout << "1. To get started, write down the path to the folder.\n";
	cout << "2. Syntax for writing a path using an example: c:/folder/ and name.txt\n";
	cout << "3. Enter the command to execute: add folder/file, delete folder/file, \nrename folder/file,  move folder/file, reading a file, writing to a file.\n";
	cout << "4. Follow the on-screen instructions.\n";
	cout << "5. To exit, enter the command : exit.\n";
	system("pause");
		
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
			cout << "Are you sure? 1 - yes, 2 - no\n";
			cin >> num;
			if (num == 1)
				return 0;
			else
				if (num == 2)
					continue;
				else
					continue;
		}
		
		if (num < 12 && num > 0 && num != 11) {
			system("cls");
			cout << "Enter path to folder:\n";
			getline(cin, path);
			last = path[path.length() - 1];
			system("pause");
			if (last != a && last != b) {
				cout << "THE specified path does not exist.\n";
				system("pause");
				continue;
			}
		}
		else 
			continue;

		
			

		switch (num) {
			case 1:
			if (testCFl(path) != 0) {
				createFolder(path);
				system("pause");
			}
			else {
				cout << "The specified path does not exist.\n";
				system("pause");
			}
			break;

			case 2:
			if (testCFl(path) != 0) {				
				createFile(path);
				system("pause");
			}
			else {
				cout << "The specified path does not exist.\n";
				system("pause");
			}
			break;

			case 3:
			if (testCFl(path) != 0) {
				deleteFolder(path);
				system("pause");
			}
			else {
				cout << "The specified path does not exist.\n";
				system("pause");
			}
			break;
								
			case 4:
				if (testCFl(path) != 0) {
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
			case 8:
				if (testCFl(path) != 0) {
					renameFile(path);
					system("pause");
				}
				else {
					cout << "The specified path does not exist.\n";
					system("pause");
				}
				break;
			case 9:
				if (testCFl(path) != 0) {
					writeFile(path);
					system("pause");
				}
				else {
					cout << "The specified path does not exist.\n";
					system("pause");
				}
				break;
			case 10:
				if (testCFl(path) != 0) {
					readFile(path);
					system("pause");
				}
				else {
					cout << "The specified path does not exist.\n";
					system("pause");
				}
				break;

			case 11:
				cout << "Are you sure? 1 - yes, 2 - no\n";
				cin >> num;
				if (num == 1)
					return 0;
				else
					continue;

			default:
				cout << "Command not found. Try again\n";
				system("pause");
			break;								
		}		
	} while (num != 11);
	return 0;
}