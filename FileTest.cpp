#include "base.h"
#include <chrono>
#include <stdlib.h>
extern std::string arg_input_trace;
extern std::string arg_output_trace;
using namespace std;


void FileTest(void)
{
    ifstream in_file;
    char address[13];

    in_file.open(arg_input_trace, ios::in);
    if (in_file.fail())
    {
        cout << "Open ERROR! Please Check the Path and Name, and Input again!" << endl;
        cout << "try to open file: " << arg_input_trace << endl;
        exit(-1);
    }

#ifdef OUTPUT
    int i_line_proceded = 0;
    ofstream out_put;
    out_put.open("test.log", ios::out);
#endif // OUTPUT

#ifdef TRACE
    ofstream trace;
    char tracepath[100];
    trace.open(arg_output_trace, ios::out);
    char dimmaddr[20];
#endif

    std::chrono::steady_clock clk;
    auto start = clk.now();
    while (!in_file.eof())
    {
        bool is_hit = false;
        in_file.getline(address, 13);
        uint32_t strtoulNum = strtoul(address + 2, NULL, 16);
#ifdef __GNUC__
        bool __attribute__((unused)) is_success = GetHitNum(address,strtoulNum, &is_hit); //in case of the warning of "Wunused-but-set-variable"
#endif
#ifndef __GNUC__
        bool is_success = GetHitNum(address);
#endif
        assert(is_success);
        // cout << is_hit << endl;
#ifdef OUTPUT
        i_line_proceded++;
        out_put << i_line_proceded << endl;
        cout << address << endl;

#endif // OUTPUT

#ifdef TRACE
        if (!is_hit)
        {
            sprintf(dimmaddr, "0x%08lx", (long unsigned int)((strtoulNum) & 0xffffffff));
            if (address[0] == 's')
            {
                trace << dimmaddr << " W" << '\n';
            }
            else
            {
                trace << dimmaddr << " R" << '\n';
            }
        }
#endif

    }
    auto end = clk.now();
    printf("Time elapsed in host = %fms\n",((end-start).count()/1e6));

#ifdef OUTPUT
    out_put.close();
#endif // OUTPUT
#ifdef TRACE
    trace.close();
#endif
    in_file.close();
    GetHitRate();
}
