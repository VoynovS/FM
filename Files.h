#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>


//Creating a file
void createFile(std::string& str);

//Deleting a file
void deleteFile(std::string& str);

//Renaming a file
void renameFile(std::string str);

//Writing to a file
void writeFile(std::string str);

//Reading from a file
void readFile(std::string str);

//Test creating a file
bool testCFl(std::string str);

//Moving a file
bool moveFile(std::string& str);