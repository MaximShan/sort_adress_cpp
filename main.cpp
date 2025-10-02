#include <iostream>
#include <windows.h>
#include <string>
#include <fstream>

using namespace std;

class data_adress {
private:
	string city;
	string street;
	int house;
	int flat;
public:
	data_adress() : city(""), street(""), house(0), flat(0) {};

	void set_data(const string& c, const string& s, int& h, int& f) {
		city = c;
		street = s;
		house = h;
		flat = f;
	}

	string get_city() {
		return city;
	}

	void print() {
		cout << city << ", " << street << ", дом " << house << ", кв. " << flat << endl;
	}

	

};
void bobble_sort(data_adress* arr, int size);


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int size;
	ifstream file("in.txt");
	if (!file.is_open()) {
		cerr << "Неудалось открыть файл!" << endl;
		return 1;
	}
	file >> size;

	data_adress* adress = new data_adress[size];
	for (int i{}; i < size; i++) {
		string city, street;
		int house, flat;
		file >> city >> street >> house >> flat;

		adress[i].set_data(city, street, house, flat);
	};
	bobble_sort(adress, size);
	for (int i = 0; i < size; i++) {
		adress[i].print();
	}

	delete[] adress;
	return EXIT_SUCCESS;
}

void bobble_sort(data_adress* arr, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j].get_city() > arr[j + 1].get_city()) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}