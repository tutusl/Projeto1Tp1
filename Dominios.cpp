#include <stdexcept>
#include "Dominios.h"

using namespace std;

const regex Codigo::FORMATO {"[A-Z]{2}[0-9]{4}"};
const regex Horario::FORMATO {"([01][0-9]|2[0-3]):(00|15|30|45)"};
const regex Nome::FORMATO {"([A-Z]\.?([A-Za-z]+\.?|[A-Za-z]*)\s?)+"};
const regex Senha::FORMATO {"(?=.*\d)(?=.*[A-Z])(?=.*[a-z])(?=.*[!@#$%&?])([^\s]){8}"};


//talvez colocar try-catch
Capacidade::Capacidade(int cap){
    setCap(cap);
}



void Capacidade::setCap(int cap){
    switch (cap){
        case ACEITOS[0]:
        case ACEITOS[1]:
        case ACEITOS[2]:
        case ACEITOS[3]:
        case ACEITOS[4]:
            this->cap = cap;
        default:
            throw invalid_argument("Capacidade invalida");
    }
}

Cargo::Cargo(string cargo){
    setCargo(cargo);
}

void Cargo::setCargo(string cargo){

    if(cargo.compare("ator") == 0){
        this->cargo = cargo;
    }
    else if(cargo.compare("cenografo") == 0){
        this->cargo = cargo;
    }
    else if(cargo.compare("figurinista") == 0){
        this->cargo = cargo;
    }
    else if(cargo.compare("maquiador") == 0){
        this->cargo = cargo;
    }
    else if(cargo.compare("sonoplasta") == 0){
        this->cargo = cargo;
    }
    else if(cargo.compare("iluminador") == 0){
        this->cargo = cargo;
    }
    else{
        throw invalid_argument("Cargo invalido (O cargo deve ser digitado sem acentos e em minusculo)");
    }
}

Classificacao::Classificacao(string classificacao){
    setClassificacao(classificacao);
}

void Classificacao::setClassificacao(string classificacao){
    if(classificacao.compare("livre") == 0){
        this->classificacao = classificacao;
    }
    else if(classificacao.compare("10") == 0){
        this->classificacao = classificacao;
    }
    else if(classificacao.compare("12") == 0){
        this->classificacao = classificacao;
    }
    else if(classificacao.compare("14") == 0){
        this->classificacao = classificacao;
    }
    else if(classificacao.compare("16") == 0){
        this->classificacao = classificacao;
    }
    else if(classificacao.compare("18") == 0){
        this->classificacao = classificacao;
    }
    else{
        throw invalid_argument("A classificacao inserida nao faz parte das classificacoes indicadas");
    }
}





//talvez colocar try-catch
Codigo::Codigo(string cod){
    setCod(cod);
}



void Codigo::setCod(string cod){
    if (regex_match(cod, FORMATO))
        this->cod = cod;
    else
        throw invalid_argument("Codigo invalido");
}




//talvez colocar try-catch
Horario::Horario(string hor){
    setHor(hor);
}


void Horario::setHor(string hor){
    if (regex_match(hor, FORMATO))
        this->hor = hor;
    else
        throw invalid_argument("Horario invalido");
}

//M�todos de Nome

Nome::Nome(string nome)
{
        setNome(nome);
}

void Nome::setNome(string nome)
{
    if (nome.size() < 5)
        throw length_error("Nome invalido (nome muito pequeno)");
    else if (nome.size() > 20)
        throw length_error("Nome invalido (nome muito grande)");
    else
        if (regex_match(nome, FORMATO))
                this->nome = nome;
        else
                throw invalid_argument("Nome invalido (formato nao suportado)");
}

string Nome::getNome()
{
    return nome;
}

//M�todos Senha

Senha::Senha (string senha)
{
    setSenha(senha);
}
void Senha::setSenha(string senha)
{
    bool charRepetido = false;

    for (int i=0; i<senha.size(); i++)
    {
        for (int j=0; j<senha.size()-i-1; j++)
        {
            if (senha[i] == senha[i+j+1])
                charRepetido = true;
        }
    }

    if (charRepetido == false && regex_match(senha, FORMATO))
            this->senha = senha;
    else
        throw invalid_argument("Senha invalida");
}
string Senha::getSenha()
{
    return senha;
}
