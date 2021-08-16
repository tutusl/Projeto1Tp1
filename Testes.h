#include <string>
#include "Dominios.h"

#ifndef TESTES_H
#define TESTES_H

using namespace std;




template<class T>
class TU {
    private:
        const string VALOR_VALIDO;
        const string VALOR_INVALIDO;
        T *unidade;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();

    public:
        TU(string valorValido, string valorInvalido);
        virtual ~TU(){};
        static const int SUCESSO = 0;
        static const int FALHA = -1;
        int run();
};

template<class T>
TU<T>::TU(string valorValido, string valorInvalido)
    : VALOR_VALIDO{valorValido}, VALOR_INVALIDO{valorInvalido}
{}


template<class T>
inline void TU<T>::setUp(){
    unidade = new T();
    estado = SUCESSO;
}

template<class T>
inline void TU<T>::tearDown(){
    delete unidade;
}

template<class T>
void TU<T>::testarCenarioSucesso(){
    try{
        unidade->setValor(VALOR_VALIDO);
        if (unidade->getValor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &exc){
        estado = FALHA;
    }
}

template<class T>
void TU<T>::testarCenarioFalha(){
    try{
        unidade->setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &exc){
        if (unidade->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    }
}


template<class T>
int TU<T>::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}


class TUCapacidade: public TU<Capacidade> {
    public:
        TUCapacidade();
};


class TUCargo: public TU<Cargo> {
    public:
        TUCargo();
};



class TUClassificacao: public TU<Classificacao> {
    public:
        TUClassificacao();
};



class TUCodigo: public TU<Codigo> {
    public:
        TUCodigo();

};



class TUData: public TU<Data> {
    public:
        TUData();

};


class TUEmail: public TU<Email> {
    public:
        TUEmail();

};


class TUHorario: public TU<Horario> {
    public:
        TUHorario();

};


class TUMatricula: public TU<Matricula> {
    public:
        TUMatricula();

};


class TUNome: public TU<Nome> {
    public:
        TUNome();

};


class TUSenha: public TU<Senha> {
    public:
        TUSenha();

};

class TUTelefone: public TU<Telefone> {
    public:
        TUTelefone();

};


class TUTipo: public TU<Tipo> {
    public:
        TUTipo();

};


#endif
