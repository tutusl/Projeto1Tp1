#include <string>
#include "Dominios.h"

#ifndef TESTES_H
#define TESTES_H

using namespace std;

////////
//////// Não prefiro
//////// Solução mais proxima ao que o professor falou. Não usa template, e é a que precisa de
//////// mais código reescrito
////////

class TU {
    private:
        virtual void setUp() = 0;                   //
        virtual void tearDown() = 0;                // Esses metodos tem que ser definidos
        virtual void testarCenarioSucesso() = 0;    // em cada classe filha
        virtual void testarCenarioFalha() = 0;      //

    protected:
        int estado;

    public:
        static const int SUCESSO = 0;
        static const int FALHA = -1;
        int run();
};

class TUCapacidade: public TU {
    private:
        Capacidade *unidade;
        static const string VALOR_VALIDO = "100";
        static const string VALOR_INVALIDO = "50";
        void setUp() override;                      //
        void tearDown() override;                   // Metodos que tem que ser definidos
        void testarCenarioSucesso() override;       // por essa classe
        void testarCenarioFalha() override;         //
};



////////
//////// Não prefiro
//////// Solução básica com template. Ainda tem código reescrito, mas menos
//////// que a anterior
////////

template<class T>
class TU {
    private:
        void setUp();
        void tearDown();
        virtual void testarCenarioSucesso() = 0;    // Esse metodos tem que ser definidos
        virtual void testarCenarioFalha() = 0;      // em cada classe filha

    protected:
        int estado;
        T *unidade;

    public:
        static const int SUCESSO = 0;
        static const int FALHA = -1;
        int run();
};

class TUCapacidade: public TU<Capacidade> {
    private:
        static const string VALOR_VALIDO = "100";
        static const string VALOR_INVALIDO = "50";
        void testarCenarioSucesso() override;       // Metodos que tem que ser definidos
        void testarCenarioFalha() override;         // por essa classe
};



////////
//////// Eu prefiro
//////// Das duas soluções que eu prefiro, essa usa menos gambiarra, mas
//////// os valores valido e invalido não são atributos de classe
////////

template<class T>
class TU {
    private:
        const string VALOR_VALIDO;
        const string VALOR_INVALIDO;
        T *unidade;
        int estado;
        void setUp();                               //
        void tearDown();                            // Esses metodos so serão definidos uma vez
        void testarCenarioSucesso();                // no header
        void testarCenarioFalha();                  //

    public:
        TU (string valorValido, string valorInvalido)
            : VALOR_VALIDO(valorValido), VALOR_INVALIDO(valorInvalid) {}
        static const int SUCESSO = 0;
        static const int FALHA = -1;
        int run();
};

class TUCapacidade: public TU<Capacidade> {
    public:
        Capacidade (string valorValido="100", string valorInvalido="50")
            : TU (valorValido, valorInvalido) {}
};




////////
//////// Eu prefiro
//////// Das duas soluções que eu prefiro, essa tem mais gambiarra,
//////// mas os valores valido e invalido sao atributos de classe
////////

template<class T>
class TU {
    private:
        T *unidade;
        int estado;
        void setUp();                               //
        void tearDown();                            //
        void testarCenarioSucesso();                //
        void testarCenarioFalha();                  //

    public:
        static const int SUCESSO = 0;
        static const int FALHA = -1;
        int run();
};

template<class T, class U>
void TU<T, U>::testarCenarioSucesso(){
    try{
        unidade->setValor(U::VALOR_VALIDO);         // Essa é a gambiarra.
        if (unidade->getValor() != U::VALOR_VALIDO) //
            estado = FALHA;
    }
    catch(invalid_argument &exc){
        estado = FALHA;
    }
}

class TUCapacidade: TU<Capacidade, TUCapacidade> {
    private:
        static const string VALOR_VALIDO = "100";
        static const string VALOR_INVALIDO = "50";
};










//Ignore isso
/*
template<class T>
class TU {
    private:
        T *unidade;
        int estado;
        void setUp();
        void tearDown();
        void testarCenarioSucesso();
        void testarCenarioFalha();

    public:
        static const int SUCESSO = 0;
        static const int FALHA = -1;
        int run();
};


template <class T>
void TU<T>::setUp(){
    unidade = new T();
    estado = SUCESSO;
}


template <class T>
int TU<T>::run(){
    cout << "teste";
}


class TUCapacidade: public TU<Capacidade> {
    private:
}

*/








#endif
