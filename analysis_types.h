#include "analysis.h"

class BMI : public analysis {
private:
	double value;
public:
	BMI(std::string d, double v) : analysis(d), value(v) {}
	~BMI() {} ;

	bool isResultOk() const override;
	std::string toString() const override;
};


class BP : public analysis {
private:
	int systolicValue;
	int diastolicValue;
public:
	BP(std::string d, int sV, int dV) : analysis(d), systolicValue(sV), diastolicValue(dV) {}
	~BP() {};

	bool isResultOk() const override;
	std::string toString() const override;
};