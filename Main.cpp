#include <iostream>
using namespace std;
#include"Task.h"

int main()
{
    Date d1{ 15,11,2007 };
    Time t1{ 1,12,22 };
    String m1{ "Somone's Birthday is Coming" };
    Task task1{ d1,t1,m1 };

    return 0;
}