#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int countConsonants(const string& word) {
	int count = 0;
	for (char c : word) {
		if (isalpha(c) && !strchr("БВГДЖЗЙКЛМНПРСТФХЦЧШЩбвгджзйклмнпрстфхцчшщ", c)) {
			count++;
		}
	}
	return count;
}

int main() {
	setlocale(LC_ALL, "Ru");
	ifstream fin("File1.txt");
	ofstream fout("File2.txt");
	string str;
	while (!fin.eof()) {
		str = "";
		getline(fin, str);
		if (count(str.begin(), str.end(), ' ') == 0) {
			fout << str << endl;
		}
	}
	ifstream fin1("File2.txt");
	int maxConsonants = 0;
	int wordNumber = 0;
	int maxConsonantsWordNumber = 0;
	int i = 0;
	while (!fin1.eof()) {
		str = "";
		getline(fin1, str);
		++i;
		int consonantsCount = countConsonants(str);
		if (consonantsCount > maxConsonants) {
			maxConsonants = consonantsCount;
			maxConsonantsWordNumber = i;
		}
	}
	cout << "Слово с наибольшим количеством согласных букв находится под номером: " << maxConsonantsWordNumber;
}