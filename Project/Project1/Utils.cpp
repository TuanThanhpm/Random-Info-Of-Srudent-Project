#include "Utils.h"

using namespace std;

/// <summary>
/// Split string by special value
/// </summary>
/// <param name="haystack">string type value</param>
/// <param name="needle">substring of haystack</param>
/// <returns>vector of substrings</returns>
vector<std::string> Utils::String:: split(string haystack, string needle) {
	vector<std::string> result;

	int startPos = 0;
	size_t foundPos = haystack.find(needle, startPos);

	while (foundPos != string::npos) {
		auto count = foundPos - startPos;
		string token = haystack.substr(startPos, count);
		result.push_back(token);

		startPos = foundPos + static_cast<int> (needle.length());
		foundPos = haystack.find(needle, startPos);
	}

	// the remaining
	string token = haystack.substr(startPos, haystack.length() - startPos);
	result.push_back(token);

	return result;
}

/// <summary>
/// convert number to string
/// </summary>
/// <param name="num">input value</param>
/// <returns>string type value</returns>
string Utils::String::convertNumberToString(int num) {
	stringstream ss;

	ss << num;
	string result = ss.str();
	return result;
}

/// <summary>
/// Find the max of value in vector
/// </summary>
/// <param name="v">vector of an attribute</param>
/// <returns>the maximum length of string in vector</returns>
int Utils::String::maxString(vector<string> v) {
	int result = INT_MIN;
	for (auto& it : v) {
		int length = static_cast<int> (it.size());
		result = max(length, result);
	}
	return result;
}

/// <summary>
/// Storing value in file into vector
/// </summary>
/// <param name="fileName">name of file</param>
/// <returns>vector which contains all values in file</returns>
vector<string> Utils::File::readFile(string fileName) {
	vector<string> result;

	fstream reader;

	reader.open(fileName, ios::in);
	if (!reader) {
		throw exception ("File is not exist!");
	}
	else {
		string buffer = "";
		while (!reader.eof()) {
			getline(reader, buffer);
			result.push_back(buffer);
		}
	}
	reader.close();

	return result;
}


/// <summary>
/// store elements formed by the combination of a key value and a mapped value. 
/// In this, key value is district and a mapped value is 2D Array which first column is Ward and the remaining column is Street
/// </summary>
/// <param name="fileName"></param>
/// <returns>unordered_map container</returns>
unordered_map<string, vector<vector<string>>> Utils::File::readAddress(string fileName) {
	unordered_map<string, vector<vector<string>>> mp;
	vector<vector<string>> arr(numberOfWard, vector<string>(numberOfStreet + 1, ""));

	fstream reader;
	reader.open(fileName, ios::in);
	if (!reader) {
		throw exception ("File is not exist!");
	}
	else {
		string buffer;
		while (!reader.eof()) {
			getline(reader, buffer, '\n');
			string district = buffer;
			for (int i = 0; i < numberOfWard; i++) {
				for (int j = 0; j < numberOfStreet + 1; j++) {
					if (j == numberOfStreet) {
						getline(reader, buffer, '\n');
					}
					else {
						getline(reader, buffer, '-');
					}
					arr[i][j] = buffer;
				}
			}
			mp[district] = arr;
		}
	}
	reader.close();
	return mp;
}

/// <summary>
/// convert list of Student to 2D string Array 
/// </summary>
/// <param name="s">Student type value</param>
/// <returns>2D string Array</returns>
vector<vector<string>> Utils::Array::convert2DArray(shared_ptr<Student> s) {
	vector<vector<string>> result(numberOfStudent, vector<string>(numberOfAttribute, ""));
	vector<Student*> list = s->getList();
	for (int i = 0; i < numberOfStudent; i++) {
		int index = numberOfAttribute - 1;
		result[i][index--] = list[i]->getGPA().toString();
		result[i][index--] = list[i]->getBirthday().toString();
		result[i][index--] = list[i]->getVNTel().toString();
		result[i][index--] = list[i]->getEmail().toString();
		result[i][index--] = list[i]->getAddress().toString();
		result[i][index--] = list[i]->getFullName().toString();
		result[i][index--] = list[i]->getID().toString();
	}
	return result;
}

/// <summary>
/// converting list of student to 1D string array based on each attribute
/// </summary>
/// <param name="s">Tudent type value</param>
/// <param name="index">the value of an attribute</param>
/// <returns>1D string array</returns>
vector<string> Utils::Array::attributeList(shared_ptr<Student> s,int index) {
	vector<vector<string>> list = Utils::Array::convert2DArray(s);
	vector<string> result;
	for (int i = 0; i < numberOfStudent; i++) {
		result.push_back(list[i][index]);
	}
	return result;
}

/// <summary>
/// max length of value in each attribute list
/// </summary>
/// <param name="s">Student type value</param>
/// <returns>vector of max length of each attribute</returns>
vector<int> Utils::Array::maxLengthOfAttribute(shared_ptr<Student> s) {
	vector<int> result;
	int num = 0;
	for (int i = 0; i < numberOfAttribute; i++) {
		vector<string> temp = Array::attributeList(s, i);
		num = String::maxString(temp) + 3;
		result.push_back(num);
	}
	return result;
}

/// <summary>
/// Initialize loading bar
/// </summary>
void Utils::Console::loading() {
	const char a = static_cast<char> (219);
	cout << setw(60) << right << "GENERATING " << numberOfStudent << " STUDENTS..." << endl;
	cout << setw(40) << right;
	for (int i = 1; i <= 40; i++)
	{
		cout << a;
		this_thread::sleep_for(chrono::milliseconds(50));
	}
	cout << endl << setw(65) << right << "COMPLETE" << endl;
}