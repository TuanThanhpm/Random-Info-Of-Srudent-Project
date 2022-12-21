#include "Table.h"


Table::Table(vector<string> headers, vector<int> widths, vector<Student*> objects, IValueConverter* converter) {
    _headers = headers;
    _widths = widths;
    _data = objects;
    _converter = converter;
}
string Table::toString() {
    return "Table";
}

void Table::display(fstream& writer) {
    for (int i = 0; i < _headers.size(); i++) {
        writer << setw(_widths[i]) << _headers[i] << "|";
    }
    writer << endl;
    int sum = 0;
    for (auto& width : _widths)
        sum += width;
    sum += static_cast<int>(_headers.size());
    for (int i = 0; i < sum; i++) {
        writer << "=";
    }
    writer << endl;

    for (int i = 0; i < _data.size(); i++) {
        writer << setw(_widths[0]) << setfill('0') << i + 1 << "|";
        string line = _converter->convert(_data[i], _widths);
        writer << line << endl;
    }
}

void Table::writeFile(string filename) {
	fstream writer;
	writer.open(filename, ios::out);
	display(writer);
	writer.close();
}