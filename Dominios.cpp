#include <stdexcept>
#include "Dominios.h"

using namespace std;

const regex Codigo::FORMATO {"[A-Z]{2}[0-9]{4}"};
const regex Horario::FORMATO {"([01][0-9]|2[0-3]):(00|15|30|45)"};
const regex Matricula::FORMATO {"[0-9]{5}"};
const regex Data::FORMATO {"(0[1-9]|[12][0-9]|3[01])\\/(0[1-9]|1[0-2])\\/([2-9][0-9]{3})"};
const regex Email::FORMATO {"[A-Za-z0-9!#$%&'*+-/=?^_`{|}~]{1,64}()[@][A-Za-z0-9!#$%&'*+-/=?^_`{|}~]{1,255}"};
const regex Nome::FORMATO {"([A-Z]\\.?([A-Za-z]+\\.?|[A-Za-z]*)\\s?)+"};
const regex Senha::FORMATO {"(?=.*\\d)(?=.*[A-Z])(?=.*[a-z])(?=.*[!@#$%&?])([^\\s]){8}"};
//const regex Telefone::FORMATO {"\\((11|12|13|14|15|16|17|18|19|21|22|24|27|28|32|33|34|35|37|38|41|42|43|44|45|46|47|48|49|51|53|54|55|61|62|63|64|65|66|67|68|69|71|73|74|75|77|79|81|82|83|84|85|86|87|88|89|91|92|93|94|95|96|97|98|99)\\)\\-(?!0{9})[\\d]{9}"};
const regex Telefone::FORMATO {"\\(([14689][1-9]|2[12478]|3[2-578]|5[13-5]|7[13-579])\\)\\-(?!0{9})[\\d]{9}"};


/////////////////////////////////////////////////



void Capacidade::validar(int valor){

    switch (valor){
        case ACEITOS[0]:
        case ACEITOS[1]:
        case ACEITOS[2]:
        case ACEITOS[3]:
        case ACEITOS[4]:
            break;
        default:
            throw invalid_argument("Capacidade invalida");
    }

}



void Codigo::validar(string valor){
    if (!regex_match(valor, FORMATO))
        throw invalid_argument("Codigo invalido");
}
/////////////////////////////////////////////////////////////////



//Capacidade::Capacidade(int cap){
//    setCap(cap);
//}
//
//
//
//void Capacidade::setCap(int cap){
//    switch (cap){
//        case ACEITOS[0]:
//        case ACEITOS[1]:
//        case ACEITOS[2]:
//        case ACEITOS[3]:
//        case ACEITOS[4]:
//            this->cap = cap;
//        default:
//            throw invalid_argument("Capacidade invalida");
//    }
//}






Cargo::Cargo(string cargo){
    setCargo(cargo);
}

void Cargo::validar(string cargo){

    if(!(cargo.compare("ator") == PALAVRA_IGUAL || cargo.compare("figurinista") == PALAVRA_IGUAL
    || cargo.compare("cenografo") == PALAVRA_IGUAL || cargo.compare("maquiador") == PALAVRA_IGUAL
    || cargo.compare("sonoplasta") == PALAVRA_IGUAL || cargo.compare("iluminador") == PALAVRA_IGUAL)){
        throw invalid_argument("Cargo invalido (O cargo deve ser digitado sem acentos e em minusculo)");
    }
}

void Cargo::setCargo(string cargo){
    validar(cargo);
    this->cargo = cargo;
}

Classificacao::Classificacao(string classificacao){
    setClassificacao(classificacao);
}


void Classificacao::validar(string classificacao){
    if(!(classificacao.compare("livre") == CLASSIFICACAO_IGUAL || classificacao.compare("10") == CLASSIFICACAO_IGUAL
    || classificacao.compare("12") == CLASSIFICACAO_IGUAL || classificacao.compare("14") == CLASSIFICACAO_IGUAL
    || classificacao.compare("16") == CLASSIFICACAO_IGUAL || classificacao.compare("18") == CLASSIFICACAO_IGUAL)){
        throw invalid_argument("A classificacao inserida nao faz parte das classificacoes indicadas");
    }

}

void Classificacao::setClassificacao(string classificacao){
    validar(classificacao);
    this->classificacao = classificacao;
}





//Codigo::Codigo(string cod){
//    setCod(cod);
//}
//
//
//
//void Codigo::setCod(string cod){
//    if (regex_match(cod, FORMATO))
//        this->cod = cod;
//    else
//        throw invalid_argument("Codigo invalido");
//}


Data::Data(string dat){
    setDat(dat);
}


void Data::setDat(string dat){
    if (!regex_match(dat, FORMATO))
        throw invalid_argument("Data invalida.");

    constexpr int MESES_C_30_DIAS[4] = {4, 6, 9, 11};
    bool valida = true;
    int dia, mes, ano;
    dia = stoi(dat.substr(0, 2));
    mes = stoi(dat.substr(3, 2));
    ano = stoi(dat.substr(6, 4));
    bool ano_bissexto = (ano % 400 == 0) || (ano % 100 != 0 && ano % 4 == 0);

    if (mes == 2 && (dia > 29 || (!ano_bissexto && dia == 29)))
        valida &= false;

    if (dia == 31){
        switch (mes){
            case MESES_C_30_DIAS[0]:
            case MESES_C_30_DIAS[1]:
            case MESES_C_30_DIAS[2]:
            case MESES_C_30_DIAS[3]:
                valida &= false;
                break;
            default:
                break;
        }
    }

    if (valida)
        this->dat = dat;
    else
        throw invalid_argument("Data invalida.");
}

Email::Email(string email){
    setEmail(email);
}

void Email::validar(string email){
    if(!regex_match(email, FORMATO)){
        throw invalid_argument("Formato invalido");
    }

    bool pontoSequencia;
    const int TAMANHO_EMAIL = email.length();
    int i;

    for(i = 0; i < TAMANHO_EMAIL - 1; i++){
        if(email[i] == '.' && email[i + 1] == '.'){
            pontoSequencia = true;
        }
    }
    if(pontoSequencia){
        throw invalid_argument("Caractere '.' usado em sequencia");
    }
    else{
        char caractere;

        if (email[0] == '.'){
            throw invalid_argument("Caractere '.' iniciando e-mail");
        }
        else if (email[TAMANHO_EMAIL - 1] == '.'){
            throw invalid_argument("Caractere '.' finalizando e-mail");
        }
        else{
            i = 0;
            do{
                caractere = email[i];
                i++;
            }while(caractere != '@');

            if(email[i - 2] == '.' || email[i] == '.'){
                throw invalid_argument("Caractere '.' em posicao invalida");
            }
        }
    }


}

void Email::setEmail(string email){
    validar(email);
    this->email = email;
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

Matricula::Matricula(string matricula){
    setMatricula(matricula);
}

void Matricula::validar(string matricula){
    if (!regex_match(matricula, FORMATO)){
        throw invalid_argument("Somente sao validos digitos(0-9) no formato XXXXX");
    }
    else{
        int i, j;
        bool flag = false;

        for(i = 0; i < matricula.length() - 1; i++){
            for(j = i + 1; j < matricula.length(); j++){
                if (matricula[i] == matricula[j]){
                    flag = true;
                    break;
                }
            }
        }

        if(flag == true){
            throw invalid_argument("Digito duplicado");
        }
    }
}

void Matricula::setMatricula(string matricula){
    validar(matricula);
    this->matricula = matricula;
}


//Metodos de Nome

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

//Metodos Senha

Senha::Senha (string senha)
{
    setSenha(senha);
}
void Senha::setSenha(string senha)
{
    bool charRepetido = false;

    for (long long unsigned int i=0; i<senha.size(); i++)
    {
        for (long long unsigned int j=0; j<senha.size()-i-1; j++)
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

//Metodos Telefone

Telefone::Telefone (string numeroTelefone)
{
    setTelefone(numeroTelefone);
}
void Telefone::setTelefone(string numeroTelefone)
{
    if (regex_match(numeroTelefone, FORMATO))
        this->numeroTelefone = numeroTelefone;
    else
        throw invalid_argument("Numero de telefone invalido");
}
string Telefone::getTelefone()
{
    return numeroTelefone;
}

//Metodos Tipo

Tipo::Tipo (string tipo)
{
    setTipo(tipo);
}
void Tipo::setTipo(string tipo)
{
    if(tipo.compare("auto") == 0){
        this->tipo = tipo;
    }
    else if(tipo.compare("comedia") == 0){
        this->tipo = tipo;
    }
    else if(tipo.compare("drama") == 0){
        this->tipo = tipo;
    }
    else if(tipo.compare("farsa") == 0){
        this->tipo = tipo;
    }
    else if(tipo.compare("melodrama") == 0){
        this->tipo = tipo;
    }
    else if(tipo.compare("monologo") == 0){
        this->tipo = tipo;
    }
    else if(tipo.compare("musical") == 0) {
        this->tipo = tipo;
    }
    else if(tipo.compare("opera") == 0){
        this->tipo = tipo;
    }
    else if(tipo.compare("revista") == 0){
        this->tipo = tipo;
    }
    else{
        throw invalid_argument("Tipo invalido (O tipo deve ser digitado sem acentos e em minusculo)");
    }

}
string Tipo::getTipo()
{
    return tipo;
}
