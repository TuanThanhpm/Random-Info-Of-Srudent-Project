#pragma once
#include <iostream>
#include <iomanip>
#include "Object.h"
#include "StudentToRowConverter.h"

using std::cout, std::endl;
using std::setw;

class Table : public Object {
public:
    vector<string> _headers;
    vector<int> _widths;
    vector<Student*> _data;
    IValueConverter* _converter;

public:
    Table(vector<string> headers, vector<int> widths, vector<Student*> objects, IValueConverter* converter);
    string toString();
    void display(fstream&);
    void writeFile(string);
};