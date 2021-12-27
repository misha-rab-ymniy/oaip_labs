#include <iostream>
#include <string>

using namespace std;

struct ATC {
	string date;
	string code;
	string town;
	int time;
	int stuff;
	string phone_number;
};

int check()
{
	while (true) {
		int n;
		cin >> n;

		if (cin.fail() || cin.peek() != '\n' || n <= 0) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Invalid value entered. Please try again. \n";
		}
		else {
			return n;
		}
	}
}

ATC* AddStruct(ATC* atc, int& amount) {
	ATC* newatc = new ATC[amount];
	for (int j = 0; j < amount - 1; j++) {
		newatc[j] = atc[j];
	}
	delete[] atc;
	atc = newatc;
	return atc;
}

void Check(string& s) {
	while ((s.size() == 1 || s.size() != 8 || s.size() != 10) && (s[2] != '/' || s[5] != '/' || s[3] < '0' || 
		s[3] > '1' || s[0] < '0' || s[0] > '3' || s[6] < '0' || s[6] > '2')) {
		cout << "Incorrect input. Try again... \n";
		cin >> s;
	}
}

void EnterStruct(ATC*& atc, int& amount) {
	while (true) {
		++amount;
		atc = AddStruct(atc, amount);
		cout << "Number of ATC: " << amount << '\n';
		cout << "Date (MM/DD/YY): ";
		cin >> atc[amount - 1].date;
		Check(atc[amount - 1].date);
		cout << "Code: ";
		cin >> atc[amount-1].code;
		cout << "Town: ";
		cin >> atc[amount-1].town;
		cin.get();
		cout << "Time: ";
		atc[amount-1].time = check();
		cin.get();
		cout << "Stuff: ";
		atc[amount-1].stuff = check();
		cin.get();
		cout << "Phone number: ";
		cin >> atc[amount-1].phone_number;
		cout << "Do you want continue enter (yes/no): ";
		string s;
		cin >> s;
		if (s != "yes") {
			return;
		}
	}
}

void FindTown(ATC* atc, const int& amount) {
	string town;
	cout << "Enter town: ";
	cin >> town;
	size_t num_town = 0;
	for (int j = 0; j < amount; ++j) {
		if (atc[j].town == town) {
			++num_town;
		}
	}
	if (num_town) {
		int* towns = new int[num_town];
		for (int j = 0, i = 0; j < amount; ++j) {
			if (atc[j].town == town) {
				towns[i] = j;
				++i;
			}
		}
		for (int i = 0; i < num_town; ++i) {
			int cost = atc[towns[i]].time * atc[towns[i]].stuff;
			for (int j = i + 1; j < num_town; ++j) {
				int cost1 = atc[towns[j]].time * atc[towns[j]].stuff;
				if (cost < cost1) {
					int tmp = towns[i];
					towns[i] = towns[j];
					towns[j] = tmp;
					cost = cost1;
				}
			}
		}
		for (int j = 0; j < num_town; ++j) {
			cout << "Number ATC: " << towns[j] + 1 << '\n';
			cout << "Time: " << atc[towns[j]].time << '\n';
			cout << "Cost: " << atc[towns[j]].time * atc[towns[j]].stuff << '\n';
		}
	}
	else {
		cout << "Town no find.\n";
	}
	
}

void Dellete(ATC*& atc, int& amount, const int& i) {
	amount -= 1;
	ATC* newatc = new ATC[amount];
	bool del = true;
	for (int j = 0, k = 0; k < amount + 1; ++j, ++k) {
		if (j == i && del) {
			del = false;
			--j;
			continue;
		}
		newatc[j] = atc[k];
	}
	delete[] atc;
	atc = newatc;
}

void Print(ATC*& atc, const int& amount) {
	for (int j = 0; j < amount; ++j) {
		cout << "Number of ATC: " << j + 1 << '\n';
		cout << "Date: " << atc[j].date << '\n';;
		cout << "Code: " << atc[j].code << '\n';;
		cout << "Town: " << atc[j].town << '\n';;
		cout << "Time: " << atc[j].time << '\n';
		cout << "Stuff: " << atc[j].stuff << '\n';;
		cout << "Phone number: " << atc[j].phone_number << '\n';
	}
}

void ChooseFunc(ATC*& atc, int& amount) {
	bool enter = true;
	string s;
	while (enter) {
		cout << "Choose the function: \n" << "1. Delete (del)" << '\n' << "2. Stop programm (stop)" << '\n' << "3. Print all ATC (print)" << '\n';
		cout << "4. FindTown (find)\n" << "5. Add ATC (add)" << '\n';
		cin >> s;
		system("cls");
		if (s == "del") {
			if (amount == 0) {
				cout << "No ATC was added" << '\n';
			}
			else {
				int i;
				cout << "Choose the number: ";
				cin >> i;
				while (i > amount || i < 1) {
					cout << "Incorrect value. Try again...\n";
					cin >> i;
				}
				Dellete(atc, amount, i - 1);
				cout << "ATC number " << i << " correctly deleted.\n";
			}
		}
		else if (s == "print") {
			if (amount == 0) {
				cout << "No ATC was added" << '\n';
			}
			else {
				Print(atc, amount);
			}
		}
		else if (s == "stop") {
			return;
		}
		else if (s == "find") {
			if (amount == 0) {
				cout << "No ATC was added" << '\n';
			}
			else {
				FindTown(atc, amount);
			}
		}
		else if (s == "add") {
			EnterStruct(atc, amount);
		}
		else cout << "Incorrect value. Try again... \n";
	}
}

int main() {
	ATC* atc = new ATC[0];
	int amount = 0;
	//EnterStruct(atc, amount);
	//FindTown(atc, amount);
	ChooseFunc(atc, amount);
}