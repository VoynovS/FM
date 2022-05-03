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
void renameFile(char* a);

//Writing to a file
void writeFile(char* a);

//Reading from a file
void readFile(char* a);

//Test create file
//bool testCF(char* a);
bool testCF(std::string str);