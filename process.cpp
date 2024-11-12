#include <iostream>
#include "process.h"

using namespace std;

void Process::planProcess()
{
    cout << "this is planning process" << endl;
    my_map.map_Info();
    cout << "planning success" << endl;
}