#include "analysis_types.h"
#include <memory>
#include <vector>
#include <algorithm>

class person {
private:
	std::string name;
	std::vector <std::shared_ptr <analysis> > repo;
public:
	person(std::string n) : name(n), repo(std::vector <std::shared_ptr <analysis> >()) {}
	~person() {};

	void addAnalysis(std::shared_ptr <analysis> a);
	std::vector <std::shared_ptr <analysis> > getAllAnalysis();
	std::vector <std::shared_ptr <analysis> > getAnalysisByMonth(int month);
	bool isHealthy(int month);
	std::vector <std::shared_ptr <analysis> >getAnalysisNewerThan(std::string date);
	void writeToFile(std::string fileName, std::string date);
	
};

class cmp {
public:
	bool operator () (std::shared_ptr <analysis> a, std::shared_ptr <analysis> b) {
		return a->getDate() > b->getDate();
	}
};