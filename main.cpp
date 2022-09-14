#include "base.h"
#include <string>
#include <vector>

int arg_cacheSize;
int arg_cacheLineSize;
int arg_placement_policy;
int arg_associativity;
int arg_replacement_policy;
int arg_write_policy;
std::string arg_input_trace;
std::string arg_output_trace;

int main(int argc, char ** argv)
{
	if(argc != 9) {
		printf("Input args not correct!");
		return -1;
	}
	std::vector<std::string> args(argv,argv+argc);

	arg_cacheSize = std::stoi(args[1]);
	arg_cacheLineSize = std::stoi(args[2]);
	arg_placement_policy = std::stoi(args[3]);
	arg_associativity = std::stoi(args[4]);
	arg_replacement_policy = std::stoi(args[5]);
	arg_write_policy = std::stoi(args[6]);
	arg_input_trace = args[7];
	arg_output_trace = args[8];


	char ch = '\0';


	InitVariables();
	GetInput(); // get input information
	CalcInfo();
	CreateCache();
	FileTest();
	PrintOutput(); // output the result

	return 0;
}
