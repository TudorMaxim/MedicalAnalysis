#pragma once
#include <iostream>
#include <fstream>
#include <string>

class analysis {
protected:
	std::string date;
public:
	analysis(std::string d);
	virtual ~analysis() {}

	std::string getDate() const;

	virtual bool isResultOk() const = 0;
	virtual std::string toString() const = 0;
};