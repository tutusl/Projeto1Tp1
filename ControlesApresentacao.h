#ifndef CONTROLES_APRESENTACAO_H
#define CONTROLES_APRESENTACAO_H

#include "Dominios.h"
#include "Entidades.h"
#include "Interfaces.h"

class CntrApresentacaoAutenticacao: public IApresentacaoAutenticacao {
    private:
        IServicoAutenticacao *cntr;

    public:
        bool autenticar(Matricula *matricula) override;
        void setCntrServicoAutenticacao(IServicoAutenticacao *cntr) override {this->cntr = cntr;};

};


class CntrApresentacaoParticipante: public IApresentacaoParticipante {
    private:
        IServicoParticipante *cntr;

    public:
        bool cadastrar() override;
        void executar(Matricula *matricula) override;
        void setCntrServicoParticipante(IServicoParticipante *cntr) override {this->cntr = cntr;};
};


class CntrApresentacaoPSS: public IApresentacaoPSS {
    private:
        IServicoPeca *cntrPeca;
        IServicoSessao *cntrSessao;
        IServicoSala *cntrSala;

    public:
        void executar(Matricula *matricula) override;
        void executar() override;
        void setCntrServicoPeca(IServicoPeca *cntrPeca) override {this->cntrPeca = cntrPeca;};
        void setCntrServicoSessao(IServicoSessao *cntrSessao) override {this->cntrSessao = cntrSessao;};
        void setCntrServicoSala(IServicoSala *cntrSala) override {this->cntrSala = cntrSala;};
};


#endif // CONTROLES_APRESENTACAO_H
