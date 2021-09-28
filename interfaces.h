#include "Dominios.h"
#include "Entidades.h"

class IServicoAutenticacao;
class IServicoParticipante;
class IServicoPSS;


class IApresentacaoAutenticacao {
    public:
        virtual bool autenticar(Matricula*) = 0;
        virtual void setCntrServicoAutenticacao(IServicoAutenticacao*) = 0;
        virtual ~IApresentacaoAutenticacao(){};
};



class IApresentacaoParticipante {
    public:
        virtual bool cadastrar() = 0;
        virtual void executar(Matricula*) = 0;
        virtual void setCntrServicoParticipante(IServicoParticipante*) = 0;
        virtual ~IApresentacaoParticipante(){};
};



class IApresentacaoPSS {
    public:

};



class IServicoAutenticacao {
    public:
        virtual bool autenticar(Matricula*, Senha*) = 0;
};



class IServicoParticipante {
    public:
        virtual bool descadastrar(Matricula*) = 0;
        virtual bool alterar(Participante*) = 0;
        virtual bool visualizar(Participante*) = 0;
};


class IServicoPSS {

};
