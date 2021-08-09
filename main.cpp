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


    string str3 {"12:30"};
    string str4 {"24:00"};
    string str5 {"01:10"};

    //Codigo c1(str1);
    Horario h1(str3);

//    cout << c1.getCod() << '\n' << h1.getHor() << '\n';
//
//    try {
//        c1.setCod(str2);
//    }
//    catch (invalid_argument &exp){
//        cout << exp.what() << endl;
//    }

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


    //Testando Cargo
    Cargo cargo1("ator");
    cout << cargo1.getCargo() << endl;
    try {
        cargo1.setCargo("Cachorro");
    }
    catch (invalid_argument &exp){
        cout << exp.what() << endl;
    }

    cout << cargo1.getCargo() << endl;

    //Testando Nome
    Nome nome1("Arthur S. Jr. Lopes");
    try {
        nome1.setNome("Arthur Silva Lopes Aaaaaa");
    }
    catch(const length_error& err){
        cout << err.what() << endl;
    }
    try {
        nome1.setNome("Art");
    }
    catch(const length_error& err){
        cout << err.what() << endl;
    }
    try {
        nome1.setNome("Nome errado");
    }
    catch(const invalid_argument& err){
        cout << err.what() << endl;
    }
    cout << nome1.getNome() << endl;

    //Testando Senha

    Senha senha1("Aa0!bcde");
    cout << senha1.getSenha() << endl;
    try{
        senha1.setSenha("Aa0!acde");
    }
    catch(const invalid_argument& err){
        cout << err.what() << endl;
    }

    //Testando classificação

    Classificacao clas1("livre");
    cout << clas1.getClassificacao() << endl;
    try{
        clas1.setClassificacao("para criancas");
    }
    catch(const invalid_argument& exp){
        cout << exp.what() << endl;
    }
    cout << clas1.getClassificacao() << endl;
    try{
        clas1.setClassificacao("14");
    }
    catch(const invalid_argument& exp){
        cout << exp.what() << endl;
    }

    cout << clas1.getClassificacao() << endl;

    try{
        clas1.setClassificacao("livre");
    }
    catch(const invalid_argument& exp){
        cout << exp.what() << endl;
    }

    cout << clas1.getClassificacao() << endl;


    //Testando data

    string d1 {"29/02/2000"};
    string d2 {"31/04/2010"};
    string d3 {"31/05/1900"};
    string d4 {"31/02/2010"};
    string d5 {"31/4/2010"};

    Data data1("03/03/2019");

    try{
        data1.setDat(d1);
    }
    catch(invalid_argument &exp){
        cout << exp.what() << '\n';
    }

    try{
        data1.setDat(d2);
    }
    catch(invalid_argument &exp){
        cout << exp.what() << '\n';
    }

    try{
        data1.setDat(d3);
    }
    catch(invalid_argument &exp){
        cout << exp.what() << '\n';
    }

    try{
        data1.setDat(d4);
    }
    catch(invalid_argument &exp){
        cout << exp.what() << '\n';
    }

    try{
        data1.setDat(d5);
    }
    catch(invalid_argument &exp){
        cout << exp.what() << '\n';
    }

    cout << data1.getDat() << '\n';

    //Testando Telefone

    Telefone telefone1("(61)-142243465");
    //Telefone telefone1("(61)-000000000");

    try{
        //telefone1.setTelefone("(11)-123456789");
        telefone1.setTelefone("(61)-000000000");
    }
    catch(invalid_argument &exp){
        cout << exp.what() << endl;
    }
    try{
        telefone1.setTelefone("(20)-123456789");
    }
    catch(invalid_argument &exp){
        cout << exp.what() << endl;
    }
    cout << telefone1.getTelefone() << endl;

    //Testando Tipo

    Tipo tipo1("auto");

    try{
        tipo1.setTipo("comedia");
    }
    catch(invalid_argument &exp){
        cout << exp.what() << endl;
    }
    try{
        tipo1.setTipo("monólogo");
    }
    catch(invalid_argument &exp){
        cout << exp.what() << endl;
    }
    cout << tipo1.getTipo() << endl;

    //Testando matricula

    Matricula m1("12345");

    cout << m1.getMatricula() << endl;

    try{
        m1.setMatricula("12541");
    }
    catch(invalid_argument& exp){
        cout << exp.what() << endl;
    }
    cout << m1.getMatricula() << endl;
    try{
        m1.setMatricula("54896");
    }
    catch(invalid_argument& exp){
        cout << exp.what() << endl;
    }

    cout << m1.getMatricula() << endl;

    try{
        m1.setMatricula("113999");
    }
    catch(invalid_argument& exp){
        cout << exp.what() << endl;
    }

    cout << m1.getMatricula() << endl;

    //Testando email

    Email e1("h.t@g.c");

    cout << e1.getEmail() << endl;

    try{
        e1.setEmail("12541");
    }
    catch(invalid_argument& exp){
        cout << exp.what() << endl;
    }

    cout << e1.getEmail() << endl;

    try{
        e1.setEmail("h-~.com");
    }
    catch(invalid_argument& exp){
        cout << exp.what() << endl;
    }

    cout << e1.getEmail() << endl;

    try{
        e1.setEmail("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa@gmail.com");
    }
    catch(invalid_argument& exp){
        cout << exp.what() << endl;
    }

    cout << e1.getEmail() << endl;

    try{
        e1.setEmail("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz@gmail.com");
    }
    catch(invalid_argument& exp){
        cout << exp.what() << endl;
    }

    cout << e1.getEmail() << endl;

    try{
        e1.setEmail(".a@gmail.com");
    }
    catch(invalid_argument& exp){
        cout << exp.what() << endl;
    }

    try{
        e1.setEmail("a.@gmail.com");
    }
    catch(invalid_argument& exp){
        cout << exp.what() << endl;
    }

    try{
        e1.setEmail("a@.gmail.com");
    }
    catch(invalid_argument& exp){
        cout << exp.what() << endl;
    }

    try{
        e1.setEmail("a@gmail.com.");
    }
    catch(invalid_argument& exp){
        cout << exp.what() << endl;
    }

    try{
        e1.setEmail("a@gm..ail.com.");
    }
    catch(invalid_argument& exp){
        cout << exp.what() << endl;
    }

    try{
        e1.setEmail("a..@gmail.com.");
    }
    catch(invalid_argument& exp){
        cout << exp.what() << endl;
    }

    try{
        e1.setEmail("h.t@gmail.com");
    }
    catch(invalid_argument& exp){
        cout << exp.what() << endl;
    }

    cout << e1.getEmail() << endl;


    Codigo *cod1 = new Codigo;
    string str1 {"AB1234"};
    string str2 {"ab1234"};

    //cod1->setValor(str1);
    cout << cod1->getValor() <<'\n';

    try{
        cod1->setValor(str2);
    }
    catch (invalid_argument &exp) {
        cout << exp.what() << '\n';
    }

    cout << cod1->getValor() << '\n';

    return 0;
}


