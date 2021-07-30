#include <stdexcept>
#include <iostream>
#include <regex>
#include "Dominios.h"

using namespace std;

void test(std::string str, std::regex reg){
    cout << str << '\n' << regex_match(str, reg) << '\n';
}


int main()
{
/*
    Capacidade c1(100), c2(100);

    try {
        c1.setCap(150);
    }
    catch (invalid_argument &exp){
        cout << exp.what() << endl;
    }

    c1.setCap(200);
    cout << c1.getCap() << " " << c2.getCap() << endl;
*/
/*
    regex formato {"[A-Z]{2}[0-9]{4}"};
    string str1 {"AB1234"};
    string str2 {"XZ0987"};
    string str3 {"LM6578"};
    test(str1, formato);
    test(str2, formato);
    test(str3, formato);
*/

    string str1 {"AB1234"};
    string str2 {"ab1234"};
    string str3 {"12:30"};
    string str4 {"24:00"};
    string str5 {"01:10"};

    Codigo c1(str1);
    Horario h1(str3);

    cout << c1.getCod() << '\n' << h1.getHor() << '\n';

    try {
        c1.setCod(str2);
    }
    catch (invalid_argument &exp){
        cout << exp.what() << endl;
    }

    try {
        h1.setHor(str4);
    }
    catch (invalid_argument &exp){
        cout << exp.what() << endl;
    }

    try {
        h1.setHor(str5);
    }
    catch (invalid_argument &exp){
        cout << exp.what() << endl;
    }

    return 0;
}
