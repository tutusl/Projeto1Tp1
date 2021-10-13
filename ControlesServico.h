#ifndef CONTROLES_SERVICO_H
#define CONTROLES_SERVICO_H

#include "Dominios.h"
#include "Entidades.h"
#include "Interfaces.h"



class CntrServicoAutenticacao: public IServicoAutenticacao {
    public:
        bool autenticar(Matricula* matricula, Senha* senha) override;

};


class CntrServicoParticipante: public IServicoParticipante {
    public:
        bool descadastrar(Matricula *matricula) override;
        bool alterar(Matricula *matricula) override;
        void visualizar(Matricula *matricula) override;
        bool cadastrar(Participante* participante) override;
};


class CntrServicoPeca: public IServicoPeca {
    public:
        bool incluir(Peca *peca) override;
        bool excluir(Codigo *codigo) override;
        bool editar(Peca *peca) override;
        void visualizar(Codigo *codigo) override;
        void listar() override;
};


class CntrServicoSessao: public IServicoSessao {
    public:
        bool incluir(Sessao *sessao) override;
        bool excluir(Codigo *codigo) override;
        bool editar(Sessao *sessao) override;
        void visualizar(Codigo *codigo) override;
        void listar() override;
};


class CntrServicoSala: public IServicoSala {
    public:
        bool incluir(Sala *sala) override;
        bool excluir(Codigo *codigo) override;
        bool editar(Sala *sala) override;
        void visualizar(Codigo *codigo) override;
        void listar() override;
};

#endif // CONTROLES_SERVICO_H
