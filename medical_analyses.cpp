// medical_analyses.cpp : Defines the entry point for the console application.
//

#include "ui.h"
#include <crtdbg.h>

void myApplication() {
	person P("Maxim Tudor");
	ui app(P);
	app.run();
}

int main() {
	myApplication();
	_CrtDumpMemoryLeaks();
    return 0;
}

