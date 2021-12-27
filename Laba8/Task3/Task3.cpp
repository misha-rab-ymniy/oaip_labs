#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <filesystem>

using namespace std;

class BUSINF {
private:
	string num;
	string type;
	string place;
	string time_start;
	string time_end;
public:
	friend void ReadFile(BUSINF*& bus, int& amount);
	friend void Print(BUSINF*& bus, const int& amount);
	friend void Dellete(BUSINF*& bus, int& amount, const int& i);
	friend void Correct(BUSINF*& bus, const int& amount, const int& i);
	friend void FindFastBus(BUSINF* bus, const int& amount);
	friend void EnterStruct(BUSINF*& bus, int& amount);
	friend int SumByte(BUSINF*& bus, int i);
};

void DeleteAll(BUSINF*& bus, int& amount);
BUSINF* AddStruct(BUSINF*& bus, int& amount);
void ChooseFunc(BUSINF*& bus, int& amount);
void Check(string& s);
int StrToInt(string time);
void solve();

//char* operator+= (char* a, string s);

int main()
{
	solve();
}

void solve() {
	ios_base::sync_with_stdio(false);
	BUSINF* bus = new BUSINF[0];
	//flight* fly = (flight*)calloc(0, sizeof(flight));
	int amount = 0;
	ReadFile(bus, amount);
	ChooseFunc(bus, amount);
}

void ChooseFunc(BUSINF*& bus, int& amount) {
	string s;
	while (true) {
		cout << "Choose the function: \n" << "1. Delete (del)\n" << "2. Delete all (dell)\n" << "3. Stop programm (stop)" << '\n';
		cout << "4. Print all routes (print)\n" << "5. Correct routes (cor)\n" << "6. Add routes (add)\n" << "7. Find fast bus (find)\n";
		cin >> s;
		system("cls");
		if (s == "del") {
			if (amount == 0) {
				cout << "No route was added" << '\n';
			}
			else {
				int i;
				cout << "Choose the number: ";
				cin >> i; 
				while (i > amount || i < 1) {
					cout << "Incorrect value. Try again...\n";
					cin >> i;
				}
				Dellete(bus, amount, i - 1);
				cout << "Route number " << i << " correctly deleted.\n";
			}
		}
		else if (s == "dell") {
			if (amount == 0) {
				cout << "No route was added" << '\n';
			}
			else {
				DeleteAll(bus, amount);
				cout << "Routes correctly deleted.\n";
			}
		}
		else if (s == "print") {
			if (amount == 0) {
				cout << "No route was added" << '\n';
			}
			else {
				Print(bus, amount);
			}
		}
		else if (s == "stop") {
			return;
		}
		else if (s == "cor") {
			if (amount == 0) {
				cout << "No route was added" << '\n';
			}
			else {
				int i;
				cout << "Choose the number: ";
				cin >> i;
				while (i > amount || i < 1) {
					cout << "Incorrect value. Try again...\n";
					cin >> i;
				}
				Correct(bus, amount, i - 1);
				cout << "Route number corrected.\n";
			}
		}
		else if (s == "find") {
			if (amount == 0) {
				cout << "No route was added" << '\n';
			}
			else {
				FindFastBus(bus, amount);
			}
		}
		else if (s == "add") {
			EnterStruct(bus, amount);
		}
		else cout << "Incorrect value. Try again... \n";
	}
}

void Dellete(BUSINF*& bus, int& amount, const int& i) {
	//string path = "file.txt";
	ofstream fout;
	fout.open("file.txt", ios::in | ios::out | ios::binary);
	int byte = SumByte(bus, i);
	std::filesystem::resize_file("file.txt", byte);
	fout.seekp(byte, ios_base::beg);
	for (size_t f = i + 1; f < amount; ++f)
	{
		fout << bus[f].num << '\n';
		fout << bus[f].type << '\n';
		fout << bus[f].place << '\n';
		fout << bus[f].time_start << '\n';
		fout << bus[f].time_end << '\n';
	}
	--amount;
	//flight* newfly = (flight*)calloc(amount, sizeof(flight));
	BUSINF* newbus = new BUSINF[amount];
	bool del = true;
	for (int j = 0, k = 0; k < amount + 1; ++j, ++k) {
		if (j == i && del) {
			del = false;
			--j;
			continue;
		}
		newbus[j] = bus[k];
	}

	//free(fly);
	delete[] bus;
	bus = newbus;
	
	//fout << '\n';
}

void DeleteAll(BUSINF*& bus, int& amount) {
	delete[] bus;
	bus = new BUSINF[0];
	amount = 0;
	string path = "file.txt";
	ofstream fout;
	fout.open(path);
}

void ReadFile(BUSINF*& bus, int& amount) {
	string path = "file.txt";
	ifstream fin;
	fin.open(path, ios_base::app);
	string s;
	int i = -1;
	while (!fin.eof()) {
		if (i == 0) {
			++amount;
			bus = AddStruct(bus, amount);
			bus[amount - 1].num = s;
		}
		else if (i == 1) {
			bus[amount - 1].type = s;
		}
		else if (i == 2) {
			bus[amount - 1].place = s;
		}
		else if (i == 3) {
			bus[amount - 1].time_start = s;
		}
		else if (i == 4) {
			bus[amount - 1].time_end = s;
			i = -1;
		}
		getline(fin, s);
		++i;
	}
}

BUSINF* AddStruct(BUSINF*& bus, int& amount) {
	//flight* newfly = (flight*)calloc(amount, sizeof(flight));
	BUSINF* newbus = new BUSINF[amount];
	for (int j = 0; j < amount - 1; j++) {
		newbus[j] = bus[j];
	}
	//free(fly);
	delete[] bus;
	bus = newbus;
	return bus;
}

void Print(BUSINF*& bus, const int& amount) {
	for (int j = 0; j < amount; ++j) {
		cout << "Number of route: " << j + 1 << '\n';
		cout << "Bus number: " << bus[j].num << '\n';
		cout << "Type: " << bus[j].type << '\n';
		cout << "Place: " << bus[j].place << '\n';
		cout << "Time start: " << bus[j].time_start << '\n';
		cout << "Time end: " << bus[j].time_end << '\n';
	}
}

int SumByte(BUSINF*& bus, int i) {
	int sum = 0;
	for (int j = 0; j < i; ++j) {
		sum += bus[j].num.size();
		sum += bus[j].type.size();
		sum += bus[j].place.size();
		sum += bus[j].time_start.size();
		sum += bus[j].time_end.size();
		sum += 10;
	}
	return sum;
}

//char* operator+= (char* a, string s) {
//	for (int i = 0; i < s.size(); ++i) {
//		a[i] = s[i];
//	}
//	a[s.size()] = 0;
//	return a;
//}

void Correct(BUSINF*& bus, const int& amount, const int& i) {
	system("cls");
	//FILE* fp;
	//errno_t e;
	//e = fopen_s(&fp, "file.txt", "r+b");
	string path = "file.txt";
	ofstream fout;
	fout.open(path, ios::in | ios::out | ios::binary);
	int byte = SumByte(bus, i);
	cout << "Number of route: " << i + 1 << '\n';
	cout << "\x1b[7mBus number: " << bus[i].num << "\x1b[0m" << '\n';
	cout << "Type: " << bus[i].type << '\n';
	cout << "Place: " << bus[i].place << '\n';
	cout << "Time start: " << bus[i].time_start << '\n';
	cout << "Time end: " << bus[i].time_end << '\n';
	cout << "Exit." << '\n';
	size_t j = 0;
	bool changes = false, stop = false;
	while (!stop)
	{
		switch (_getch()) {
		case 80://down
			changes = true; 
			if (j == 5) {
				j = 0;
			}
			else {
				++j;
			}
			break;
		case 72://up
			changes = true; 
			if (j == 0) {
				j = 5;
			}
			else {
				--j;
			}
			break;
		case 13:
			changes = true;
			switch (j) {
			case 0:
				cin >> bus[i].num;
				//fout << bus[i].num <<'\n';
				/*char k[20];
				k += bus[i].num;
				k[bus[i].num.size()] = '\n';
				fseek(fp, byte, SEEK_SET);
				fputs(k, fp);*/
				//fputs('\n', fp);
				//fwrite(&buffer, sizeof(char), bus[i].num.size(),fp);
				cin.get();
				break;
			case 1:
				cin >> bus[i].type;
				cin.get();
				break;
			case 2:
				cin >> bus[i].place;
				cin.get();
				break;
			case 3:
				cin >> bus[i].time_start;
				Check(bus[i].time_start);
				cin.get();
				break;
			case 4:
				cin >> bus[i].time_end;
				Check(bus[i].time_end);
				cin.get();
				break;
			case 5:
				stop = true;
				break;
			}
			break;
		}

		if (changes) {
			/*system("cls");
			cout << "Number of route: " << i + 1 << '\n';*/
			switch (j) {
			case 0:
				system("cls");
				cout << "Number of route: " << i + 1 << '\n'; 
				cout << "\x1b[7mBus number: " << bus[i].num << "\x1b[0m" << '\n';
				cout << "Type: " << bus[i].type << '\n';
				cout << "Place: " << bus[i].place << '\n';
				cout << "Time start: " << bus[i].time_start << '\n';
				cout << "Time end: " << bus[i].time_end << '\n';
				cout << "Exit." << '\n';
				break;
			case 1:
				system("cls");
				cout << "Number of route: " << i + 1 << '\n';
				cout << "Bus number: " << bus[i].num << '\n';
				cout << "\x1b[7mType: " << bus[i].type << "\x1b[0m" << '\n';
				cout << "Place: " << bus[i].place << '\n';
				cout << "Time start: " << bus[i].time_start << '\n';
				cout << "Time end: " << bus[i].time_end << '\n';
				cout << "Exit." << '\n';
				break;
			case 2:
				system("cls");
				cout << "Number of route: " << i + 1 << '\n';
				cout << "Bus number: " << bus[i].num << '\n';
				cout << "Type: " << bus[i].type << '\n';
				cout << "\x1b[7mPlace: " << bus[i].place << "\x1b[0m" << '\n';
				cout << "Time start: " << bus[i].time_start << '\n';
				cout << "Time end: " << bus[i].time_end << '\n';
				cout << "Exit." << '\n';
				break;
			case 3:
				system("cls");
				cout << "Number of route: " << i + 1 << '\n';
				cout << "Bus number: " << bus[i].num << '\n';
				cout << "Type: " << bus[i].type << '\n';
				cout << "Place: " << bus[i].place << '\n';
				cout << "\x1b[7mTime start: " << bus[i].time_start << "\x1b[0m" << '\n';
				cout << "Time end: " << bus[i].time_end << '\n';
				cout << "Exit." << '\n';
				break;
			case 4:
				system("cls");
				cout << "Number of route: " << i + 1 << '\n';
				cout << "Bus number: " << bus[i].num << '\n';
				cout << "Type: " << bus[i].type << '\n';
				cout << "Place: " << bus[i].place << '\n';
				cout << "Time start: " << bus[i].time_start << '\n';
				cout << "\x1b[7mTime end: " << bus[i].time_end << "\x1b[0m" << '\n';
				cout << "Exit." << '\n';
				break;
			case 5:
				system("cls");
				cout << "Number of route: " << i + 1 << '\n';
				cout << "Bus number: " << bus[i].num << '\n';
				cout << "Type: " << bus[i].type << '\n';
				cout << "Place: " << bus[i].place << '\n';
				cout << "Time start: " << bus[i].time_start << '\n';
				cout << "Time end: " << bus[i].time_end << '\n';
				cout << "\x1b[7mExit." << "\x1b[0m" << '\n';
				break;
			}
		}
		changes = false;

		Sleep(5);
	}

	filesystem::resize_file("file.txt", byte);

	//string path = "file.txt";
	//ofstream fout;
	//fout.open(path);
	//bus[i - 1].time_end += '\n';
	fout.seekp(byte, ios_base::beg);
	for (size_t f = i; f < amount; ++f)
	{
		//fout << '\n';
		fout << bus[f].num << '\n';
		fout << bus[f].type << '\n';
		fout << bus[f].place << '\n';
		fout << bus[f].time_start << '\n';
		fout << bus[f].time_end << '\n';
	}
	//fout << '\n';
}

int StrToInt(string time) {
	int itime = 0, n = 1000;
	for (int j = 0; j < time.size(); ++j) {
		if (time[j] == ':') {
			continue;
		}
		itime += (time[j] - '0') * n;
		n /= 10;
	}
	return itime;
}

void FindFastBus(BUSINF* bus, const int& amount) {
	string time, place;
	cout << "Enter place: ";
	cin >> place;
	cout << "Enter time: ";
	cin >> time;
	Check(time);
	size_t num_town = 0;
	int itime = StrToInt(time);
	for (int j = 0; j < amount; ++j) {
		int itime1 = StrToInt(bus[j].time_end);
		if (itime1 < itime && place == bus[j].place) {
			++num_town;
		}
	}

	int* towns = new int[num_town];
	for (int j = 0, i = 0; j < amount; ++j) {
		int itime1 = StrToInt(bus[j].time_end);
		if (itime1 < itime && place == bus[j].place) {
			towns[i] = j;
			++i;
		}
	}

	for (int j = 0; j < num_town; ++j) {
		cout << "Number route: " << towns[j] + 1 << '\n';
		cout << "Bus number: " << bus[towns[j]].num << '\n';
		cout << "Place: " << bus[towns[j]].place << '\n';
		cout << "Type: " << bus[towns[j]].type << '\n';
		cout << "Time start: " << bus[towns[j]].time_start << '\n';
		cout << "Time end: " << bus[towns[j]].time_end << '\n';
	}
}

void Check(string& s) {
	while (true) {
		if (s.size() != 6 && (s[2] != ':' || s[0] < '0' || s[0] > '2' || s[3] < '0' || s[3] > '5')) {
			cout << "Invalid value intered. Try again...\n";
			cin >> s;
		}
		else if (s[0] == '2' && (s[1] < '0' || s[1] > '3' || s[3] < '0' || s[3] > '5')) {
			cout << "Invalid value intered. Try again...\n";
			cin >> s;
		}
		else {
			return;
		}
	}
}

void EnterStruct(BUSINF*& bus, int& amount) {
	string path = "file.txt";
	ofstream fout;
	fout.open(path, ios_base::app);
	while (true) {
		++amount;
		bus = AddStruct(bus, amount);
		//fly = (flight*)realloc(fly, amount * sizeof(flight));
		cout << "Number of route: " << amount << '\n';
		cout << "Bus number: ";
		cin >> bus[amount - 1].num;
		fout << bus[amount - 1].num << '\n';
		cout << "Type: ";
		cin >> bus[amount - 1].type;
		fout << bus[amount - 1].type << '\n';
		cout << "Place: ";
		cin >> bus[amount - 1].place;
		fout << bus[amount - 1].place << '\n';
		cout << "Time start (00:00): ";
		cin >> bus[amount - 1].time_start;
		Check(bus[amount - 1].time_start);
		fout << bus[amount - 1].time_start << '\n';
		cout << "Time end (00:00): ";
		cin >> bus[amount - 1].time_end;
		Check(bus[amount - 1].time_end);
		fout << bus[amount - 1].time_end << '\n';
		cout << "Do you want continue enter (yes/no): ";
		string s;
		cin >> s;
		if (s != "yes") {
			return;
		}
	}
}