#include <string>
#include "Dominios.h"
#include "Entidades.h"

#ifndef TESTES_H
#define TESTES_H

using namespace std;



template<class T>
class TUD {
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
        TUD(string valorValido, string valorInvalido);
        virtual ~TUD(){};
        static const int SUCESSO = 0;
        static const int FALHA = -1;
        int run();
};

template<class T>
TUD<T>::TUD(string valorValido, string valorInvalido)
    : VALOR_VALIDO{valorValido}, VALOR_INVALIDO{valorInvalido}
{}


template<class T>
inline void TUD<T>::setUp(){
    unidade = new T();
    estado = SUCESSO;
}

template<class T>
inline void TUD<T>::tearDown(){
    delete unidade;
}

template<class T>
void TUD<T>::testarCenarioSucesso(){
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
void TUD<T>::testarCenarioFalha(){
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
int TUD<T>::run(){
    setUp();
    testarCenarioSucesso();
    testarCenarioFalha();
    tearDown();
    return estado;
}


class TUCapacidade: public TUD<Capacidade> {
    public:
        TUCapacidade();
};


class TUCargo: public TUD<Cargo> {
    public:
        TUCargo();
};



class TUClassificacao: public TUD<Classificacao> {
    public:
        TUClassificacao();
};



class TUCodigo: public TUD<Codigo> {
    public:
        TUCodigo();

};



class TUData: public TUD<Data> {
    public:
        TUData();

};


class TUEmail: public TUD<Email> {
    public:
        TUEmail();

};


class TUHorario: public TUD<Horario> {
    public:
        TUHorario();

};


class TUMatricula: public TUD<Matricula> {
    public:
        TUMatricula();

};


class TUNome: public TUD<Nome> {
    public:
        TUNome();

};


class TUSenha: public TUD<Senha> {
    public:
        TUSenha();

};

class TUTelefone: public TUD<Telefone> {
    public:
        TUTelefone();

};


class TUTipo: public TUD<Tipo> {
    public:
        TUTipo();

};



template<class T>
class TUE {
    private:
        void setUp();
        void tearDown();
        virtual void testarCenarioSucesso() = 0;

    protected:
        T *unidade;
        int estado;

    public:
        virtual ~TUE(){};
        static const int SUCESSO = 0;
        static const int FALHA = -1;
        int run();
};



template<class T>
inline void TUE<T>::setUp(){
    unidade = new T();
    estado = SUCESSO;
}


template<class T>
inline void TUE<T>::tearDown(){
    delete unidade;
}


template<class T>
int TUE<T>::run(){
    setUp();
    testarCenarioSucesso();
    tearDown();
    return estado;
}




class TUParticipante: public TUE<Participante> {
    private:
        static const string VALORES_VALIDOS[];
        void testarCenarioSucesso() override;
};


class TUPeca: public TUE<Peca> {
    private:
        static const string VALORES_VALIDOS[];
        void testarCenarioSucesso() override;
};


class TUSessao: public TUE<Sessao> {
    private:
        static const string VALORES_VALIDOS[];
        void testarCenarioSucesso() override;
};


class TUSala: public TUE<Sala> {
    private:
        static const string VALORES_VALIDOS[];
        void testarCenarioSucesso() override;
};

#endif
