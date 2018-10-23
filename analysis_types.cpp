#include "analysis_types.h"

bool BMI::isResultOk() const {
	return this->value >= 18.5 && this->value <= 25;
}

std::string BMI::toString() const {
	std::string s = "BMI,";
	s += this->getDate();
	s += ",";
	s += std::to_string(this->value);
	s += ",";
	if (this->isResultOk()) s += "ok";
	else s += "bad";
	return s;
}

bool BP::isResultOk() const {
	return this->systolicValue >= 90 && this->systolicValue <= 119 && this->diastolicValue >= 60 && this->diastolicValue <= 79;
}

std::string BP::toString() const {
	std::string s = "BP,";
	s += this->getDate();
	s += ",";
	s += std::to_string(this->systolicValue);
	s += ",";
	s += std::to_string(this->diastolicValue);
	s += ",";
	if (this->isResultOk()) s += "ok";
	else s += "bad";
	return s;
}