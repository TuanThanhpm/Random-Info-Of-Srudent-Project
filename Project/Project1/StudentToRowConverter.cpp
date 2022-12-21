#include "StudentToRowConverter.h"


string StudentToRowConverter::convert(Student* student, vector<int> widths) {
    stringstream builder;
    builder << setw(widths[1]) << student->getID().toString() << "|"
        << setw(widths[2]) << student->getFullName().toString() << "|"
        << setw(widths[3]) << student->getAddress().toString() << "|"
        << setw(widths[4]) << student->getEmail().toString() << "|"
        << setw(widths[5]) << student->getVNTel().toString() << "|"
        << setw(widths[6]) << student->getBirthday().toString() << "|"
        << setw(widths[7]) << student->getGPA().toString() << "|";

    string result = builder.str();
    return result;
}

string StudentToRowConverter::toString() {
    return "StudentToRowConverter";
}