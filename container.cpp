#include "container.h"

ContainerParticipante* ContainerParticipante::instancia = nullptr;
ContainerPeca* ContainerPeca::instancia = nullptr;
ContainerSessao* ContainerSessao::instancia = nullptr;
ContainerSala* ContainerSala::instancia = nullptr;
Peca2Participante* Peca2Participante::instancia = nullptr;
Peca2Sessao* Peca2Sessao::instancia = nullptr;

//////////////////////////////////////////////////////////

ContainerParticipante* ContainerParticipante::getInstancia(){
    if(instancia == nullptr)
        instancia = new ContainerParticipante();
    return instancia;
}


ContainerPeca* ContainerPeca::getInstancia(){
    if(instancia == nullptr)
        instancia = new ContainerPeca();
    return instancia;
}


ContainerSessao* ContainerSessao::getInstancia(){
    if(instancia == nullptr)
        instancia = new ContainerSessao();
    return instancia;
}


ContainerSala* ContainerSala::getInstancia(){
    if(instancia == nullptr)
        instancia = new ContainerSala();
    return instancia;
}


Peca2Participante* Peca2Participante::getInstancia(){
    if(instancia == nullptr)
        instancia = new Peca2Participante();
    return instancia;
}


Peca2Sessao* Peca2Sessao::getInstancia(){
    if(instancia == nullptr)
        instancia = new Peca2Sessao();
    return instancia;
}
///////////////////////////////////////////////////////
/////////////   Participante    ///////////////////////

bool ContainerParticipante::incluir(Participante* participante){
    bool valor = true;
    string key = participante->getMatricula().getValor();
    if(container.count(key) < 1)
        container[key] = *participante;
    else
        valor = false;
    return valor;
}


bool ContainerParticipante::remover(string key){
    Peca2Participante *relacao = Peca2Participante::getInstancia();
    relacao->removerParticipante(key);
    if(container.erase(key) == 1)
        return true;
    else
        return false;
}


Participante* ContainerParticipante::pesquisar(string key){
    Participante* ptr = nullptr;
    if(container.count(key) == 1)
        ptr = &container[key];
    return ptr;
}


bool ContainerParticipante::atualizar(Participante* participante){
    string key = participante->getMatricula().getValor();
    container[key] = *participante;
    return true;
}

///////////////////////////////////////////////////////
/////////////   Peca    ///////////////////////////////

bool ContainerPeca::incluir(Peca* peca){
    bool valor = true;
    string key = peca->getIdentificador().getValor();
    if(container.count(key) < 1)
        container[key] = *peca;
    else
        valor = false;
    return valor;
}


bool ContainerPeca::remover(string key){
    Peca2Participante *r1 = Peca2Participante::getInstancia();
    Peca2Sessao *r2 = Peca2Sessao::getInstancia();
    r1->removerPeca(key);
    r2->removerPeca(key);
    if(container.erase(key) == 1)
        return true;
    else
        return false;
}


Peca* ContainerPeca::pesquisar(string key){
    Peca* ptr = nullptr;
    if(container.count(key) == 1)
        ptr = &container[key];
    return ptr;
}


bool ContainerPeca::atualizar(Peca* peca){
    string key = peca->getIdentificador().getValor();
    container[key] = *peca;
    return true;
}


int ContainerPeca::contar(string key){
    return container.count(key);
}



///////////////////////////////////////////////////////
/////////////   Sessao    /////////////////////////////

bool ContainerSessao::incluir(Sessao* sessao, string peca, string sala){
    Peca2Sessao *relacao = Peca2Sessao::getInstancia();
    string key = sessao->getIdentificador().getValor();
    if(!(relacao->incluir(peca, key)))
        return false;

    bool valor = true;;
    if(container.count(key) < 1)
        container[key] = *sessao;
    else
        valor = false;
    return valor;
}


bool ContainerSessao::remover(string key){
    Peca2Sessao *relacao = Peca2Sessao::getInstancia();
    relacao->removerSessao(key);
    if(container.erase(key) == 1)
        return true;
    else
        return false;
}


Sessao* ContainerSessao::pesquisar(string key){
    Sessao* ptr = nullptr;
    if(container.count(key) == 1)
        ptr = &container[key];
    return ptr;
}


bool ContainerSessao::atualizar(Sessao* sessao){
    string key = sessao->getIdentificador().getValor();
    container[key] = *sessao;
    return true;
}





///////////////////////////////////////////////////////
/////////////   Sala    ///////////////////////////////

bool ContainerSala::incluir(Sala* sala){
    bool valor = true;
    string key = sala->getIdentificador().getValor();
    if(container.count(key) < 1)
        container[key] = *sala;
    else
        valor = false;
    return valor;
}


bool ContainerSala::remover(string key){
    if(container.erase(key) == 1)
        return true;
    else
        return false;
}


Sala* ContainerSala::pesquisar(string key){
    Sala* ptr = nullptr;
    if(container.count(key) == 1)
        ptr = &container[key];
    return ptr;
}


bool ContainerSala::atualizar(Sala* sala){
    string key = sala->getIdentificador().getValor();
    container[key] = *sala;
    return true;
}


///////////////////////////////////////////////////////
/////////////   Peca2Participante    //////////////////

bool Peca2Participante::incluir(string peca, string participante){
    bool valor = true;
    ContainerPeca *cp = ContainerPeca::getInstancia();
    if(cp->contar(peca) == 0)
        return false;
    if(container.count(peca) <= 10)
        container.insert({{peca, participante}});
    else
        valor = false;
    return valor;
}


void Peca2Participante::removerPeca(string peca){
    container.erase(peca);
}


void Peca2Participante::removerParticipante(string participante){
    for(map::iterator i=container.begin(); i!=container.end(); i++){
        if(i->second == participante){
            container.erase(i);
            break;
        }
    }
}


int Peca2Participante::contar(string peca){
    return container.count(peca);
}

///////////////////////////////////////////////////////
/////////////  Peca2Sessao    /////////////////////////

bool Peca2Sessao::incluir(string peca, string sessao){
    bool valor = true;
    ContainerPeca *cp = ContainerPeca::getInstancia();
    if(cp->contar(peca) == 0)
        return false;
    if(container.count(peca) <= 5)
        container.insert({{peca, sessao}});
    else
        valor = false;
    return valor;
}


void Peca2Sessao::removerPeca(string peca){
    container.erase(peca);
}


void Peca2Sessao::removerSessao(string sessao){
    for(map::iterator i=container.begin(); i!=container.end(); i++){
        if(i->second == sessao){
            container.erase(i);
            return;
        }
    }
}


int Peca2Sessao::contar(string peca){
    return container.count(peca);
}
