#include <stdexcept>
#include <iostream>
#include <regex>
#include "Dominios.h"
#include "Testes.h"

using namespace std;


template<class T>
void test(){
    T *teste = new T();
    switch(teste->run()){
        case T::SUCESSO:
            cout << " Sucesso\n";
            break;
        case T::FALHA:
            cout << " Falha\n";
            break;
    }
    delete teste;
}


int main()
{
    // Testes de unidade

    cout << "Capacidade";
    test<TUCapacidade>();

    cout << "Cargo";
    test<TUCargo>();

    cout << "Classificacao";
    test<TUClassificacao>();

    cout << "Codigo";
    test<TUCodigo>();

    cout << "Data";
    test<TUData>();

    cout << "Email";
    test<TUEmail>();

    cout << "Horario";
    test<TUHorario>();

    cout << "Matricula";
    test<TUMatricula>();

    cout << "Nome";
    test<TUNome>();

    cout << "Senha";
    test<TUSenha>();

    cout << "Telefone";
    test<TUTelefone>();

    cout << "Tipo";
    test<TUTipo>();

    return 0;
}


