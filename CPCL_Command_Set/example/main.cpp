#include ".\inc\CPCL_Command_Set.h"
#include <iostream>

using namespace std;
#define main_cpp main

void output_debug(CPCL_Command_t cmd) {
	cout << cmd;
}

int main_cpp() {
	CPCL_cmd CPCL;
	CPCL.output_interface_callback = output_debug;
	string s = "13";
	Text t1("s");
	CPCL.add(t1);
	CPCL.Print();
	return 0;
}
