#pragma once

#include <iostream>
#include <unordered_map>
#include <vector>
#include <chrono>
#include <thread>
#include <map>
#include <string>
#include <exception>
#include <sstream>
#include <fstream>
#include "Student.h"
#include "AttributesEnum.h"

class StudentToRowConverter;

using namespace std;

namespace Utils {
	class String {
	public:
		// Tokenizer
		static vector<string> split(string, string);
		static string convertNumberToString(int);
		static int maxString(vector<string> v);
	};

	class File {
	public:
		static unordered_map<string,vector<vector<string>>> readAddress(string);
		static vector<string> readFile(string );
	};

	class Array {
	public:
		static vector<int> maxLengthOfAttribute(shared_ptr<Student>);
		static vector<vector<string>> convert2DArray(shared_ptr<Student>);
		static vector<string> attributeList(shared_ptr<Student>, int);
	};

	class Console {
	public:
		static void loading();
	};
}