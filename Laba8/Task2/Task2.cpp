#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <conio.h>

using namespace std;

struct flight {
	char num[50];
	char type[50];
	char town[50];
	char time[6];
};

flight* AddStruct(flight* fly, int& amount) {
	flight* newfly = (flight*)calloc(amount, sizeof(flight));
	//flight* newfly = new flight[amount];
	for (int j = 0; j < amount - 1; j++) {
		newfly[j] = fly[j];
	}
	free(fly);
	//delete[] fly;
	fly = newfly;
	return fly;
}

char* operator+= (char* a, string s) {
	for (int i = 0; i < s.size(); ++i) {
		a[i] = s[i];
	}
	a[s.size()] = 0;
	return a;
}

void Dellete(flight*& fly, int& amount, const int& i) {
	amount -= 1;
	flight* newfly = (flight*)calloc(amount, sizeof(flight));
	//flight* newfly = new flight[amount];
	bool del = true;
	for (int j = 0, k = 0; k < amount + 1; ++j, ++k) {
		if (j == i && del) {
			del = false;
			--j;
			continue;
		}
		newfly[j] = fly[k];
	}

	free(fly);
	//delete[] fly;
	fly = newfly;
	string path = "file.txt";
	ofstream fout;
	fout.open(path);
	for (size_t i = 0; i < amount; ++i)
	{
		fout << fly[i].num << '\n';
		fout << fly[i].type << '\n';
		fout << fly[i].town << '\n';
		fout << fly[i].time << '\n';
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

void EnterStruct(flight*& fly, int& amount) {
	string path = "file.txt";
	ofstream fout;
	fout.open(path, ios_base::app);
	while (true) {
		++amount;
		fly = AddStruct(fly, amount);
		//fly = (flight*)realloc(fly, amount * sizeof(flight));
		cout << "Number of flight: " << amount << '\n';
		cout << "Aircraft number: ";
		cin >> fly[amount - 1].num;
		fout << fly[amount - 1].num << '\n';
		cout << "Type: ";
		cin >> fly[amount - 1].type;
		fout << fly[amount - 1].type << '\n';
		cout << "Town: ";
		cin >> fly[amount - 1].town;
		fout << fly[amount - 1].town << '\n';
		cout << "Time (00:00): ";
		string c;
		cin >> c;
		//cin >> fly[amount - 1].time;
		Check(c); 
		fly[amount - 1].time += c;
		fout << fly[amount - 1].time << '\n';
		cout << "Do you want continue enter (yes/no): ";
		string s;
		cin >> s;
		if (s != "yes") {
			return;
		}
	}
}

void Print(flight*& fly, const int& amount) {
	for (int j = 0; j < amount; ++j) {
		cout << "Number of flight: " << j + 1 << '\n';
		cout << "Aircraft number: " << fly[j].num << '\n';
		cout << "Type: " << fly[j].type << '\n';
		cout << "Town: " << fly[j].town << '\n';
		cout << "Time: " << fly[j].time << '\n';
	}
}

void DeleteAll(flight*& fly, int& amount) {
	free(fly);
	//delete[] fly;
	fly = new flight[0];
	amount = 0;
	string path = "file.txt";
	ofstream fout;
	fout.open(path);
}

void Correct(flight*& fly, const int& amount, const int& i) {
	ios_base::sync_with_stdio(false);
	system("cls");
	cout << "Number of flight: " << i + 1 << '\n';
	cout << "\x1b[7mAircraft number: " << fly[i].num << "\x1b[0m" << '\n';
	cout << "Type: " << fly[i].type << '\n';
	cout << "Town: " << fly[i].town << '\n';
	cout << "Time: " << fly[i].time << '\n';
	cout << "Exit." << '\n';
	size_t j = 0;
	bool changes = false, stop = false;
	while (!stop)
	{
		switch (_getch()) {
		case 80:
			changes = true;
			//cout << "down";
			if (j == 4) {
				j = 0;
			}
			else {
				++j;
			}
			break;
		case 72:
			changes = true;
			//cout << "up";
			if (j == 0) {
				j = 4;
			}
			else {
				--j;
			}
			break;
		case 13:
			changes = true;
			switch (j) {
			case 0:
				cin >> fly[i].num;
				cin.get();
				break;
			case 1:
				cin >> fly[i].type;
				cin.get();
				break;
			case 2:
				cin >> fly[i].town;
				cin.get();
				break;
			case 3:
				cin >> fly[i].time;
				cin.get();
				break;
			case 4:
				stop = true;
			}
		}
		if (changes) {
			system("cls");
			cout << "Number of flight: " << i + 1 << '\n';
			switch (j) {
			case 0:
				cout << "\x1b[7mAircraft number: " << fly[i].num << "\x1b[0m" << '\n';
				cout << "Type: " << fly[i].type << '\n';
				cout << "Town: " << fly[i].town << '\n';
				cout << "Time: " << fly[i].time << '\n';
				cout << "Exit." << '\n';
				break;
			case 1:
				cout << "Aircraft number: " << fly[i].num << '\n';
				cout << "\x1b[7mType: " << fly[i].type << "\x1b[0m" << '\n';
				cout << "Town: " << fly[i].town << '\n';
				cout << "Time: " << fly[i].time << '\n';
				cout << "Exit." << '\n';
				break;
			case 2:
				cout << "Aircraft number: " << fly[i].num << '\n';
				cout << "Type: " << fly[i].type << '\n';
				cout << "\x1b[7mTown: " << fly[i].town << "\x1b[0m" << '\n';
				cout << "Time: " << fly[i].time << '\n';
				cout << "Exit." << '\n';
				break;
			case 3:
				cout << "Aircraft number: " << fly[i].num << '\n';
				cout << "Type: " << fly[i].type << '\n';
				cout << "Town: " << fly[i].town << '\n';
				cout << "\x1b[7mTime: " << fly[i].time << "\x1b[0m" << '\n';
				cout << "Exit." << '\n';
				break;
			case 4:
				cout << "Aircraft number: " << fly[i].num << '\n';
				cout << "Type: " << fly[i].type << '\n';
				cout << "Town: " << fly[i].town << '\n';
				cout << "Time: " << fly[i].time << '\n';
				cout << "\x1b[7mExit." << "\x1b[0m" << '\n';
			}
		}
		changes = false;

		Sleep(1000 / 200);
	}
	string path = "file.txt";
	ofstream fout;
	fout.open(path);
	for (size_t i = 0; i < amount; ++i)
	{
		fout << fly[i].num << '\n';
		fout << fly[i].type << '\n';
		fout << fly[i].town << '\n';
		fout << fly[i].time << '\n';
	}
}

int StrToInt(flight* fly, const int& i) {
	int itime = 0, n = 1000;
	int size;
	for(size = 0; fly[i].time[size]; ++size)
	for (int j = 0; j < size; ++j){
		if (fly[i].time[j] == ':') {
			continue;
		}
		itime += (fly[i].time[j] - '0') * n;
		n /= 10;
	}
	return itime;
}

void FindTown(flight* fly, const int& amount) {
	string town;
	cout << "Enter town: ";
	cin >> town;
	size_t num_town = 0;
	for (int j = 0; j < amount; ++j) {
		if (fly[j].town == town) {
			++num_town;
		}
	}
	if (num_town) {
		int* towns = new int[num_town];
		for (int j = 0, i = 0; j < amount; ++j) {
			if (fly[j].town == town) {
				towns[i] = j;
				++i;
			}
		}
		for (int i = 0; i < num_town; ++i) {
			int itime = StrToInt(fly, towns[i]);
			for (int j = i + 1; j < num_town; ++j) {
				int itime1 = StrToInt(fly, towns[j]);
				if (itime > itime1) {
					int tmp = towns[i];
					towns[i] = towns[j];
					towns[j] = tmp;
					itime = itime1;
				}
			}
		}
		for (int j = 0; j < num_town; ++j) {
			cout << "Number flight: " << towns[j] + 1 << '\n';
			cout << "Aircraft number: " << fly[towns[j]].num << '\n';
			cout << "Type: " << fly[towns[j]].type << '\n';
			cout << "Time: " << fly[towns[j]].time << '\n';
		}
	}
	else {
		cout << "Town not founded\n";
	}
}

void ChooseFunc(flight*& fly, int& amount) {
	string s;
	while (true) {
		cout << "Choose the function: \n" << "1. Delete (del)\n" << "2. Delete all (dell)\n" << "3. Stop programm (stop)" << '\n';
		cout << "4. Print all flight (print)\n" << "5. Correct fligths (cor)\n" << "6. Add flight (add)\n" << "7. Find town (find)\n";
		cin >> s;
		system("cls");
		if (s == "del") {
			if (amount == 0) {
				cout << "No flight was added" << '\n';
			}
			else {
				int i;
				cout << "Choose the number: ";
				cin >> i;
				while (i > amount || i < 1) {
					cout << "Incorrect value. Try again...\n";
					cin >> i;
				}
				Dellete(fly, amount, i - 1);
				cout << "Flight number " << i << " correctly deleted.\n";
			}
		}
		else if (s == "dell") {
			if (amount == 0) {
				cout << "No flight was added" << '\n';
			}
			else {
				DeleteAll(fly, amount);
				cout << "Flights correctly deleted.\n";
			}
		}
		else if (s == "print") {
			if (amount == 0) {
				cout << "No flight was added" << '\n';
			}
			else {
				Print(fly, amount);
			}
		}
		else if (s == "stop") {
			return;
		}
		else if (s == "cor") {
			if (amount == 0) {
				cout << "No flight was added" << '\n';
			}
			else {
				int i;
				cout << "Choose the number: ";
				cin >> i;
				while (i < 1 || i > amount) {
					cout << "Incorrect value. Try again... \n";
					cin >> i;
				}
				Correct(fly, amount, i - 1);
				cout << "Flight number corrected.\n";
			}
		}
		else if (s == "find") {
			if (amount == 0) {
				cout << "No flight was added" << '\n';
			}
			else {
				FindTown(fly, amount);
			}
		}
		else if (s == "add") {
			EnterStruct(fly, amount);
		}
		else cout << "Incorrect value. Try again... \n";
	}
}

void ReadFile(flight*& fly, int& amount) {
	string path = "file.txt";
	ifstream fin;
	fin.open(path, ios_base::app);
	string s;
	int i = -1;
	while (!fin.eof()) {
		if (i == 0) {
			++amount;
			fly = AddStruct(fly, amount);
			fly[amount - 1].num += s;
		}
		else if (i == 1) {
			fly[amount - 1].type += s;
		}
		else if (i == 2) {
			fly[amount - 1].town += s;
		}
		else if (i == 3) {
			fly[amount - 1].time += s;
			i = -1;
		}
		getline(fin, s);
		++i;
	}
}

int main()
{
	//flight* fly = new flight[0];
	flight* fly = (flight*)calloc(0, sizeof(flight));
	int amount = 0;
	ReadFile(fly, amount);
	ChooseFunc(fly, amount);
}