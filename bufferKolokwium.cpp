#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <typeinfo>
#include <iterator>

using namespace std;

/*
Zadanie 1
*/
class Buffer {
public:
	Buffer(string i, int m) : id(i), max(m) {}
	~Buffer() = default;
	virtual void add(string toAdd) {
		for (int i = 0; i < vec.size(); i++) {
			if (vec[i].first == toAdd) {
				int counter = vec[i].second;
				vec[i].second = ++counter;
				return;
			}
		}
		if (vec.size() + 1 > max) throw runtime_error("Brak miejsca w buforze");
		else	vec.push_back(make_pair(toAdd, 1));
	}
	void remove(string toRem) {
		int pos = -1;
		for (int i = 0; i < vec.size(); i++) {
			if (vec[i].first == toRem) {
				pos = i;
				break;
			}
		}
		if (pos < 0) throw runtime_error("Brak podanego lancucha w buforze");
		else {
			if (vec[pos].second > 1) {
				vec[pos].second = vec[pos].second - 1;
			}
			else {
				vec.erase(vec.begin() + pos);
			}
		}
	}
	void clear() {
		if (vec.empty()) throw runtime_error("Nie ma co czyscic");
		else vec.clear();
	}
	void show() {
		if (vec.empty()) throw runtime_error("Bufor pusty");
		else {
			for (int i = 0; i < vec.size(); i++) {
				cout << vec[i].first << " " << vec[i].second << endl;
			}
		}
	}
protected:
	string id;
	int max;
	vector<pair<string, int>> vec;
};
/*
Zadanie 2
*/
class Little_Buffer : public Buffer{
public:
	Little_Buffer(string i, int m, int l) : Buffer(i, m), l(l) {}
	~Little_Buffer() = default;
	void add(string toAdd) {
		if (toAdd.length()-1 >= l) throw runtime_error("Za dlugi lancuch znakow");
		else {
			Buffer::add(toAdd);
			how_many++;

		}
	}
	void operator-(string toRem) {
		int pos = -1;
		for (int i = 0; i < vec.size(); i++) {
			if (vec[i].first == toRem) {
				pos = i;
				break;
			}
		}
		if (pos < 0) throw runtime_error("Brak podanego lancucha w buforze");
		else {
				vec.erase(vec.begin() + pos);
		}
	}
	int getHowMany() { return how_many; }
private:
	int l;
	int how_many = 0;
};

/*
Zadanie 3
*/
void task3() {
	cout << "Zadanie 3" << endl;
	Little_Buffer obj("bufor123", 5, 3);
	ifstream file("file.txt");
	string row;
	while (getline(file, row)) {
		string tmp = "";
		vector<string> input;
		for (int i = 0; i < row.length(); i++) {
			if (!isspace(row[i])) {
				tmp += row[i];
				if (isspace(row[i + 1]) || (i + 1 == row.length())) {
					input.push_back(tmp);
					tmp = "";
				}
			}
		}
		switch (input[0][0])
		{
		case 'a':
			try {
				obj.add(input[1]);
			}
			catch (exception& e) {
				cout << e.what() << " : " << input[1] << endl;
			}
			break;
		case 'r':
			try {
				obj.remove(input[1]);
			}
			catch (exception& e) {
				cout << e.what() << " : " << input[1] << endl;
			}
			break;
		case 's':
			try {
				obj.show();
			}
			catch (exception& e) {
				cout << e.what() << endl;
			}
			break;
		case 'c':
			try {
				obj.clear();
			}
			catch (exception& e) {
				cout << e.what() << endl;
			}
			break;
		case '-':
			try {
				obj - input[1];
			}
			catch (exception& e) {
				cout << e.what() << " : " << input[1] << endl;
			}
			break;
		default:
			cout << "Zla operacja" << endl;
			break;
		}
	}
	file.close();
	cout << "Lacznie wykonano " << obj.getHowMany() << " operacji dodawania" << endl;
/*
	bool end = false;
	cout << "Prosze podac operacje do wykonania na bufforze. W celu zakonczenia prosze wybrac e." << endl;
	while (!end) {
		char op;
		cin >> op;
		switch (op) {
		case 'a': {
			cout << "Prosze podac text" << endl;
			string txt;
			cin >> txt;
			try {
				obj.add(txt);
			}
			catch (exception& e) {
				cout << e.what() << " : " << txt << endl;
			}
			break;
		}
		case 'r': {
			cout << "Prosze podac wartosc do usuniecia" << endl;
			string txt; cin >> txt;
			try {
				obj.remove(txt);
			}
			catch (exception& e) {
				cout << e.what() << " : " << txt << endl;
			}
			break; 
		}
		case 's': {
			try {
				obj.show();
			}
			catch (exception& e) {
				cout << e.what() << endl;
			}
			break;
		}
		case 'c': {
			try {
				obj.clear();
			}
			catch (exception& e) {
				cout << e.what() << endl;
			}
		}
		case '-': {
			cout << "Prosze podac wartosc do usuniecia" << endl;
			string txt; cin >> txt;
			try {
				obj - txt;
			}
			catch (exception& e) {
				cout << e.what() << " : " << txt << endl;
			}
			
			break;
		}
		case 'e': {
			end = true;
			break;
		}
		default: {
			cout << "Zla operacja" << endl;
			break;
		}
		}
	}
	cout << "Lacznie wykonano " << obj.getHowMany() << " operacji dodawania" << endl;*/
}
/*
Zadanie 4
*/
class Kontener {
public:
	Kontener() = default;
	~Kontener() = default;

	void addToContainer(string id, Buffer* obj) {
		mapa.insert(make_pair(id, obj));
	}

	bool checkBufforId(string id) {
		bool check = false;
		for (auto it = mapa.begin(); it != mapa.end(); ++it) {
			if (it->first == id) {
				check = true; break;
			}
		}
		return check;
	}
	void operationOnBuffer(string id, char o) {
		
		switch (o) {
			case 'a': {
				string val;
				cout << "Prosze podac lancuch: ";
				cin >> val;
				try {
	;				mapa[id]->add(val);
				}
				catch (exception& e) {
					cout << e.what() << " : " << val << endl;
				}
				break;
			}
			case 's': {
				try {
					mapa[id]->show();
				}
				catch (exception& e) {
					cout << e.what() << endl;
				}
				break;
			}
			case 'r': {
				string val;
				cout << "Prosze podac lancuch: ";
				cin >> val;
				try {
					mapa[id]->remove(val);
				}
				catch (exception& e) {
					cout << e.what() << " : " << val << endl;
				}
				break;
			}
			case 'c': {
				try {
					mapa[id]->clear();
				}
				catch (exception& e) {
					cout << e.what() << endl;
				}
				break;
			}
			case '-': {
				if (typeid(*mapa[id]) == typeid(Little_Buffer)) {
					cout << "Prosze podac wartosc do usuniecia" << endl;
					string txt; cin >> txt;
					try {
						Little_Buffer* temp = dynamic_cast<Little_Buffer*>(mapa[id]);
						*temp - txt;
						mapa[id] = temp;
					}
					catch (exception& e) {
						cout << e.what() << " : " << txt << endl;
					}
				}
				else {
					cout << "Niewlasciwy typ buffera" << endl;
				}
				break;
			}
			default: {
				cout << "Zle polecenie" << endl;
				break;
			}
		}
	}

	void getHowMany(string id) {
		if (typeid(*mapa[id]) == typeid(Little_Buffer)) {
			Little_Buffer* tmp = dynamic_cast<Little_Buffer*>(mapa[id]);
			cout << "Lacznie wykonano " << tmp->getHowMany() << " operacji dodawania" << endl;
			delete tmp;
		}
	}

private:
	map<string, Buffer*> mapa;
};

void task4() {
	cout << "Zadanie 4" << endl;
	Kontener buffers;

	buffers.addToContainer("Buffer", new Buffer("b1", 5));
	buffers.addToContainer("Little1", new Little_Buffer("lb1", 3, 6));
	buffers.addToContainer("Little2", new Little_Buffer("lb2", 7, 2));

	while (true)
	{
		string id;
		cout << "Prosze podac klucz buffera. Aby zakonczyc prosze wpisac e." << endl;
		cin >> id;
		if (id == "e") break;
		if (buffers.checkBufforId(id)) {
			while (true) {
				char op;
				cout << "Prosze wybrac operacje, aby zakonczyc prosze wpisac e." << endl;
				cin >> op;
				if (op == 'e') break;
				buffers.operationOnBuffer(id, op);
			}
			buffers.getHowMany(id);
		}
		else {
			cout << "Niewlasciwe id buffora" << endl;
		}
	}
}
int main() {
	task3();
	task4();
	return 0;
}