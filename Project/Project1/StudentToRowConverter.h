#include "IValueConverter.h"
#include "Student.h"
#include <iomanip>
#include "Utils.h"

class Array;
using std::setw;
class StudentToRowConverter : public IValueConverter {
public:
    StudentToRowConverter() {}
public:
    string convert(Student*, vector<int> widths);
    string toString();
};