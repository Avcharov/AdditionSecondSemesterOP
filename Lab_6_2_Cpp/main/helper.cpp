#include "helper.h"


void display_file(string filename) 
{
	ifstream file(filename);
	string line;

	while (!file.eof())
	{
		getline(file, line);
		cout << line << endl;
	}
	file.close();
}

vector<string> split(string line, char sep) {
	vector<string> words;
	string temp_word = "";
	line += sep;
	for (int i = 0; i < line.length(); i++) {
		if (line[i] == sep) {
			if (temp_word.length() > 0) {
				words.push_back(temp_word);
			}
			temp_word = "";
		}
		else {
			temp_word += line[i];
		}
	}
	return words;
}

bool isKeyword(string to_check)
{
	vector <string> KEYWORDS = {
	"alignas", "decltype",	"namespace",	"struct",
	"alignof",	"default",	"new",	"switch",
	"and", "delete",	"noexcept",	"template",
	"and_eq", "do",	"not", "this",
	"asm",	"double", "not_eq", "thread_local",
	"auto",	"dynamic_cast",	"nullptr",	"throw",
	"bitand", "else",	"operator",	"true",
	"bitor", "enum", "or", "try", "break", "export",
	"private",	"typeid","case",	"extern",
	"protected",	"typename","catch",	"false",
	"public",	"union", "char",	"float",
	"register",	"unsigned", "char16_t",	"for",
	"reinterpret_cast",	"using", "char32_t",	"friend",
	"return",	"virtual", "class",	"goto",
	"short",	"void", "compl", "if",
	"signed",	"volatile", "const",	"inline",
	"sizeof",	"wchar_t", "constexpr",	"int",
	"static",	"while", "const_cast",	"long",
	"static_assertxor", "continue",	"mutable", "size_t",
	"static_cast", "xor_eq", "cin", "cout", "string", "endl"
	};

	bool flag = false;
	for (string temp : KEYWORDS)
	{
		if (!strcmp(to_check.c_str(), temp.c_str()))
		{
			flag = true;
		}
	}
	return flag;
}

bool check_first_symbol(string temp, int index)
{
	return (temp[index] >= 'a' && temp[index] <= 'z') ||
			(temp[index] >= 'A' && temp[index] <= 'Z') ||
			(temp[index] == '_');
}

bool is_valid_symbol(string temp, int index)
{
	return (temp[index] >= 'a' && temp[index] <= 'z') ||
			(temp[index] >= 'A' && temp[index] <= 'Z') ||
			(temp[index] >= '0' && temp[index] <= '9') ||
			(temp[index] == '_');
}

bool isidentifier(string to_check)
{
	int counter = 0;
	bool flag = false;

	if (!isKeyword(to_check))
	{
		if (check_first_symbol(to_check, 0))
		{
			counter++;
			for (int i = 1; i < to_check.length(); i++)
			{
				if (is_valid_symbol(to_check, i))
				{
					counter++;
				}
			}

			if (counter == to_check.length())
			{
				flag = true;
			}
		}
	}
	return flag;
}