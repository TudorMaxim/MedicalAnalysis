#include "ui.h"
using namespace std;

void ui::menu() {
	cout << "Welcome to my medical analysis manager!\n";
	cout << "Your options are: \n";
	cout << "\t 0 - exit\n";
	cout << "\t 1 - add a new analysis\n";
	cout << "\t 2 - list all the analysis\n";
	cout << "\t 3 - show if the person is healthy\n";
	cout << "\t 4 - save to file analysis newer than a given date\n";
}

void ui::setUp() {
	pers.addAnalysis(make_shared <BMI>("2018.03.20", 18.5));
	pers.addAnalysis(make_shared <BP>("2018.05.13", 80, 65));
}
void ui::addBMI() {
	string date;
	cout << "Give the date: ";
	cin >> date;
	double val;
	cout << "Give the real value: ";
	cin >> val;
	pers.addAnalysis(make_shared <BMI>(date, val));
}
void ui::addBP() {
	string date;
	cout << "Give the date: ";
	cin >> date;
	double sV, dV;
	cout << "Give the systolic value: ";
	cin >> sV;
	cout << "Give the diastolic value: ";
	cin >> dV;
	pers.addAnalysis(make_shared <BP>(date, sV, dV));
}

void ui::add() {
	string analysis;
	cout << "What type of analysis do you waant to add? ";
	cin >> analysis;
	if (analysis == "BMI") this->addBMI();
	else if (analysis == "BP") this->addBP();
	else cout << "Invalid type of analysis!\n";
}

void ui::list() {
	cout << "The person has the following analysis: \n";
	for (auto it : pers.getAllAnalysis()) {
		cout << it->toString() << "\n";
	}
}

void ui::isHealthy() {
	int mo;
	cout << "Give a month: ";
	cin >> mo;
	if (this->pers.isHealthy(mo) == true) {
		cout << "The person is healthy!\n";
	}
	else cout << "The person is not healthy!\n";
}


void ui::saveToFile() {
	string fileName = "analysis.txt";
	string date;
	cout << "Give a date: ";
	cin >> date;
	this->pers.writeToFile(fileName, date);
}

void ui::run() {
	this->setUp();
	this->menu();
	while (1) {
		cout << "Give an option: ";
		int option;
		cin >> option;
		if (option == 0) break;
		else if (option == 1) this->add();
		else if (option == 2) this->list();
		else if (option == 3) this->isHealthy();
		else if (option == 4) this->saveToFile();
		else cout << "Invalid option!\n";
	}
}