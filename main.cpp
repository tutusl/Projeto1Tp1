#include <stdexcept>
#include <iostream>
#include <regex>
#include "Dominios.h"
#include "Entidades.h"
#include "Testes.h"

using namespace std;

template<class T>
void test(string unidade){
    cout << unidade;
    T *teste = new T();
    switch(teste->run()){
        case T::SUCESSO:
            cout << " Sucesso" << endl;
            break;
        case T::FALHA:
            cout << " Falha" << endl;
            break;
    }
    delete teste;
}

int main()
{
    // Testes de unidade

    cout << "Dominios:" << endl;

    test<TUCapacidade>("Capacidade");

    test<TUCargo>("Cargo");

    test<TUClassificacao>("Classificacao");

    test<TUCodigo>("Codigo");

    test<TUData>("Data");

    test<TUEmail>("Email");

    test<TUHorario>("Horario");

    test<TUMatricula>("Matricula");

    test<TUNome>("Nome");

    test<TUSenha>("Senha");

    test<TUTelefone>("Telefone");

    test<TUTipo>("Tipo");

    cout << endl << "Entidades:" << endl;

    test<TUParticipante>("Participante");

    test<TUPeca>("Peca");

    test<TUSessao>("Sessao");

    test<TUSala>("Sala");


    return 0;
}


