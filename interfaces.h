#include "Dominios.h"
#include "Entidades.h"

class IServicoAutenticacao;
class IServicoParticipante;
class IServicoPeca;
class IServicoSala;
class IServicoSessao;


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
        virtual void executar(Matricula*) = 0;
        virtual void executar() = 0;
        virtual void setCntrServicoPeca(IServicoPeca*) = 0;
        virtual void setCntrServicoSessao(IServicoSessao*) = 0;
        virtual void setCntrServicoSala(IServicoSala*) = 0;
        virtual ~IApresentacaoPSS(){};

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


class IServicoPeca{
    public:
        virtual bool incluir(Peca*) = 0;
        virtual bool excluir(Codigo*) = 0;
        virtual bool editar(Peca*) = 0;
        virtual bool listar(Peca*) = 0;

};


class IServicoSessao{
    public:
        virtual bool incluir(Sessao*) = 0;
        virtual bool excluir(Codigo*) = 0;
        virtual bool editar(Sessao*) = 0;
        virtual bool listar(Sessão*) = 0;

};

class IServicoSala{
    public:
        virtual bool incluir(Sala*) = 0;
        virtual bool excluir(Codigo*) = 0;
        virtual bool editar(Sala*) = 0;
        virtual bool listar(Sala*) = 0;

};
