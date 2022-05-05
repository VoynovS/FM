#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>


//Create File
//void createFile(char* a);
void createFile(std::string& str);

//Delete file
void deleteFile(std::string& str);

//Move file
void renameFile(std::string str);

//Writing to a file
void writeFile(std::string str);

//Reading from a file
void readFile(std::string str);

//Test create file
//bool testCF(char* a);
bool testCFl(std::string str);

bool moveFile(std::string& str);