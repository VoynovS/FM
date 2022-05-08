
#pragma once
#include <iostream>
#include <windows.h>
#include <string>




//Creating a folder
void createFolder(std::string& str);

//Deleting a folder
void deleteFolder(std::string& str);

//Renaming a folder 
bool renameFolder(std::string& str);

//Removing a folder
bool moveFolder(std::string& str);