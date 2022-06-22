#pragma once
#include <string>;
#include <vector>;
#include <fstream>;
#include <iostream>

using namespace std;


void display_file(string);

vector<string> split(string, char sep = ' ');

bool is_valid_symbol(string, int);
bool check_first_symbol(string, int);

bool isKeyword(string, vector <string>);
bool isidentifier(string);