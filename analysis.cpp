#include "analysis.h"

analysis::analysis(std::string d) : date(d) {}

std::string analysis::getDate() const {
	return this->date;
}