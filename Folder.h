
#pragma once
#include <iostream>
#include <windows.h>
#include <string>




//Create the folder
void createFolder(std::string& str);
//void createFolder(char* a);

//Delete the folder
void deleteFolder(std::string& str);

//Rename the folder 
bool renameFolder(std::string& str);

//Remove folder
bool moveFolder(std::string& str);