#ifndef CONTAINER_H
#define CONTAINER_H
#include <string>
#include <unordered_map>
#include "Dominios.h"
#include "Entidades.h"

using namespace std;





class ContainerParticipante {
    public:
        typedef unordered_map<string, Participante*> cmap;
        static ContainerParticipante* getInstancia();
        bool incluir(Participante* participante);
        bool remover(string key);
        Participante* pesquisar(string key);
        bool atualizar(Participante* participante);
        cmap getMap(){return container;};

    private:
        cmap container;
        static ContainerParticipante *instancia;
        ContainerParticipante(){};
};



class ContainerPeca {
    public:
        typedef unordered_map<string, Peca*> cmap;
        static ContainerPeca* getInstancia();
        bool incluir(Peca* peca);
        bool remover(string key);
        Peca* pesquisar(string key);
        bool atualizar(Peca* peca);
        cmap getMap(){return container;};

    private:
        cmap container;
        static ContainerPeca *instancia;
        ContainerPeca(){};
};



class ContainerSessao {
    public:
        typedef unordered_map<string, Sessao*> cmap;
        static ContainerSessao* getInstancia();
        bool incluir(Sessao* sessao, string peca, string sala);
        bool remover(string key);
        Sessao* pesquisar(string key);
        bool atualizar(Sessao* sessao);
        cmap getMap(){return container;};

    private:
        cmap container;
        static ContainerSessao *instancia;
        ContainerSessao(){};
};



class ContainerSala {
    public:
        typedef unordered_map<string, Sala*> cmap;
        static ContainerSala* getInstancia();
        bool incluir(Sala* sala);
        bool remover(string key);
        Sala* pesquisar(string key);
        bool atualizar(Sala* sala);
        cmap getMap(){return container;};

    private:
        cmap container;
        static ContainerSala *instancia;
        ContainerSala(){};
};




class Peca2Participante {
    private:
        typedef unordered_multimap<string, string> map;
        map container;
        static Peca2Participante *instancia;

    public:
        static Peca2Participante* getInstancia();
        bool incluir(string peca, string participante);
        void removerPeca(string peca);
        void removerParticipante(string participante);
        int contar(string peca);
};


class Peca2Sessao {
    private:
        typedef unordered_multimap<string, string> map;
        map container;
        static Peca2Sessao *instancia;

    public:
        static Peca2Sessao* getInstancia();
        bool incluir(string peca, string sessao);
        void removerPeca(string peca);
        void removerSessao(string sessao);
        int contar(string peca);
};



#endif // CONTAINER_H
