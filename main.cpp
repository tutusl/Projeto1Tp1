#include <stdexcept>
#include <iostream>
#include <regex>
#include "Dominios.h"
#include "Testes.h"

using namespace std;

void test(std::string str, std::regex reg){
    cout << str << '\n' << regex_match(str, reg) << '\n';
}


int main()
{
    TUCapacidade *t1 = new TUCapacidade();
    t1->run();

    return 0;
}


