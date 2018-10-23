#include "person.h"

void person::addAnalysis(std::shared_ptr <analysis> a) {
	this->repo.push_back(a);
}
std::vector <std::shared_ptr <analysis> > person::getAllAnalysis() {
	return this->repo;
}

std::vector <std::shared_ptr <analysis> > person::getAnalysisByMonth(int month) {
	std::vector <std::shared_ptr <analysis> > V;
	return V;
}

bool person::isHealthy(int month) {
	for (auto a : this->getAllAnalysis()) {
		int mo = stoi(a->getDate().substr(5, 2));
		if (mo == month || mo + 1 == month) {
			if (a->isResultOk() == false) return false;
		}
	}
	return true;
}

std::vector <std::shared_ptr <analysis> > person::getAnalysisNewerThan(std::string date) {
	std::vector <std::shared_ptr <analysis> > V;
	std::vector <std::shared_ptr <analysis> > A = this->getAllAnalysis();
	std::copy_if(A.begin(), A.end(), std::back_inserter(V),
		[date](std::shared_ptr <analysis> a) {
			return a->getDate() > date;
		}
	);
	return V;
}


void person::writeToFile(std::string fileName, std::string date) {
	std::ofstream fout(fileName);
	std::vector <std::shared_ptr <analysis> > V = this->getAnalysisNewerThan(date);
	std::sort(V.begin(), V.end(), cmp());
	for (auto it : V) {
		fout << it->toString() << "\n";
	}
}