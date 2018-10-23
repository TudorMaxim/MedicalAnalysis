#include "person.h"

class ui {
private:
	person& pers;
public:
	ui(person& p) : pers(p) {}
	~ui() {}

	void setUp();
	void menu();
	void run();
	void add();
	void addBMI();
	void addBP();
	void list();
	void isHealthy();
	void saveToFile();
};