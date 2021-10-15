#include <unordered_map>
#include "ControlesServico.h"
#include "container.h"

using namespace std;

bool CntrServicoAutenticacao::autenticar(Matricula* matricula, Senha* senha){
    ContainerParticipante* cp = ContainerParticipante::getInstancia();
    Participante *participante = cp->pesquisar(matricula->getValor());

    if (participante == nullptr){
        return false;
    }
    else{
        if (participante->getSenha().getValor() == senha->getValor()){
            return true;
        }
        else{
            return false;
        }
    }
}

bool CntrServicoParticipante::descadastrar(Matricula *matricula){
    ContainerParticipante* cp = ContainerParticipante::getInstancia();

    return cp->remover(matricula->getValor());
}

bool CntrServicoParticipante::alterar(Participante *participante){
    ContainerParticipante* cp = ContainerParticipante::getInstancia();

    if (cp->atualizar(participante)){
        return true;
    }
    else{
        return false;
    }
}

bool CntrServicoParticipante::cadastrar(Participante *participante){
    ContainerParticipante* cp = ContainerParticipante::getInstancia();
    return(cp->incluir(participante));
}


bool CntrServicoParticipante::cadastrarEmPeca(Matricula *matricula, string peca){
    Peca2Participante *relacao = Peca2Participante::getInstancia();
    return relacao->incluir(matricula->getValor(), peca);
}


///////////////////////////////////////////////////////
/////////////   Peca    ///////////////////////////////


bool CntrServicoPeca::incluir(Peca *peca){
    ContainerPeca* cp = ContainerPeca::getInstancia();
	return cp -> incluir(peca);
}

bool CntrServicoPeca::excluir(Codigo *codigo){
    ContainerPeca* cp = ContainerPeca::getInstancia();

	return cp->remover(codigo->getValor());
}

bool CntrServicoPeca::editar(Peca *peca){
    ContainerPeca* cp = ContainerPeca::getInstancia();
    if (cp->pesquisar(peca->getIdentificador().getValor()) == nullptr){
        return false;
    }
    return cp->atualizar(peca);
}

string CntrServicoPeca::visualizar(Codigo *codigo){
    ContainerPeca* cp = ContainerPeca::getInstancia();
    Peca* peca = cp->pesquisar(codigo->getValor());

    string saida = "Identificador: ";
    saida += peca->getIdentificador().getValor();
    saida += "\nNome: ";
    saida += peca->getNome().getValor();
    saida += "\nTipo: ";
    saida += peca->getTipo().getValor();
    saida += "\nClassificacao: ";
    saida += peca->getClassificacao().getValor();
    return saida;
}


string CntrServicoPeca::listar(){
    ContainerPeca *cp = ContainerPeca::getInstancia();
    ContainerPeca::cmap mp = cp->getMap();
    string saida = "Codigos de pecas:";
    for(ContainerPeca::cmap::iterator i=mp.begin();i!=mp.end();i++) {
        saida += "\n";
        saida += i->first;
    }
    return saida;
}

///////////////////////////////////////////////////////
/////////////   Sessao    /////////////////////////////

bool CntrServicoSessao::incluir(Sessao *sessao, string peca, string sala){
    ContainerSessao* cs = ContainerSessao::getInstancia();
    return cs-> incluir(sessao, peca, sala);
}

bool CntrServicoSessao::excluir(Codigo *codigo){
    ContainerSessao* cs = ContainerSessao::getInstancia();

    return cs-> remover(codigo->getValor());
}

bool CntrServicoSessao::editar(Sessao *sessao){
    ContainerSessao* cs = ContainerSessao::getInstancia();
    if (cs->pesquisar(sessao->getIdentificador().getValor()) == nullptr){
        return false;
    }
    return cs->atualizar(sessao);
}

string CntrServicoSessao::visualizar(Codigo *codigo){
    ContainerSessao* cs = ContainerSessao::getInstancia();
    Sessao* sessao = cs->pesquisar(codigo->getValor());

    string saida = "Identificador: ";
    saida += sessao->getIdentificador().getValor();
    saida += "\nData: ";
    saida += sessao->getData().getValor();
    saida += "\nHorario: ";
    saida += sessao->getHorario().getValor();
    return saida;
}


string CntrServicoSessao::listar(){
    ContainerSessao *cp = ContainerSessao::getInstancia();
    ContainerSessao::cmap mp = cp->getMap();
    string saida = "Codigos de pecas:";
    for(ContainerSessao::cmap::iterator i=mp.begin();i!=mp.end();i++) {
        saida += "\n";
        saida += i->first;
    }
    return saida;
}

///////////////////////////////////////////////////////
/////////////   Sala    ///////////////////////////////

bool CntrServicoSala::incluir(Sala *sala){
    ContainerSala* cs = ContainerSala::getInstancia();
    return cs-> incluir(sala);
}

bool CntrServicoSala::excluir(Codigo *codigo){
    ContainerSala* cs = ContainerSala::getInstancia();

    return cs-> remover(codigo->getValor());
}

bool CntrServicoSala::editar(Sala *sala){
    ContainerSala* cs = ContainerSala::getInstancia();
    if (cs->pesquisar(sala->getIdentificador().getValor()) == nullptr){
        return false;
    }
    return cs->atualizar(sala);
}

string CntrServicoSala::visualizar(Codigo *codigo){
    ContainerSala* cs = ContainerSala::getInstancia();
    Sala* sala = cs->pesquisar(codigo->getValor());

    string saida = "Identificador: ";
    saida += sala->getIdentificador().getValor();
    saida += "\nNome: ";
    saida += sala->getNome().getValor();
    saida += "\nCapacidade: ";
    saida += sala->getCapacidade().getValor();
    return saida;
}


string CntrServicoSala::listar(){
    ContainerSala *cp = ContainerSala::getInstancia();
    ContainerSala::cmap mp = cp->getMap();
    string saida = "Codigos de pecas:";
    for(ContainerSala::cmap::iterator i=mp.begin();i!=mp.end();i++) {
        saida += "\n";
        saida += i->first;
    }
    return saida;
}
