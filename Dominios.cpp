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


void Dominio::setValor(string valor){
    validar(valor);
    this->valor = valor;
}


void Capacidade::validar(string valor){

    switch (stoi(valor)){
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



void Cargo::validar(string valor){
    if(valor == "ator" || valor == "figurinista" || valor == "cenografo" 
    || valor == "maquiador" || valor == "sonoplasta" || valor == "iluminador")
        throw invalid_argument("Cargo invalido (O cargo deve ser digitado sem acentos e em minusculo)");
}

void Classificacao::validar(string valor){
    if(valor == "livre" || valor == "10" || valor == "12" || valor == "14" || valor == "16" || valor == "18")
        throw invalid_argument("A classificacao inserida nao faz parte das classificacoes indicadas");
}

/*
void Cargo::validar(string valor){

    if(!(valor.compare("ator") == PALAVRA_IGUAL || valor.compare("figurinista") == PALAVRA_IGUAL
    || valor.compare("cenografo") == PALAVRA_IGUAL || valor.compare("maquiador") == PALAVRA_IGUAL
    || valor.compare("sonoplasta") == PALAVRA_IGUAL || valor.compare("iluminador") == PALAVRA_IGUAL)){
        throw invalid_argument("Cargo invalido (O cargo deve ser digitado sem acentos e em minusculo)");
    }
}

void Classificacao::validar(string valor){
    if(!(valor.compare("livre") == CLASSIFICACAO_IGUAL || valor.compare("10") == CLASSIFICACAO_IGUAL
    || valor.compare("12") == CLASSIFICACAO_IGUAL || valor.compare("14") == CLASSIFICACAO_IGUAL
    || valor.compare("16") == CLASSIFICACAO_IGUAL || valor.compare("18") == CLASSIFICACAO_IGUAL)){
        throw invalid_argument("A classificacao inserida nao faz parte das classificacoes indicadas");
    }

}

*/





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


void Codigo::validar(string valor){
    if (!regex_match(valor, FORMATO))
        throw invalid_argument("Codigo invalido");
}





void Data::validar(string valor){
    if (!regex_match(valor, FORMATO))
        throw invalid_argument("Data invalida.");

    constexpr int MESES_C_30_DIAS[4] = {4, 6, 9, 11};
    bool valida = true;
    int dia, mes, ano;
    dia = stoi(valor.substr(0, 2));
    mes = stoi(valor.substr(3, 2));
    ano = stoi(valor.substr(6, 4));
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

    if (!valida)
        throw invalid_argument("Data invalida.");
}



void Email::validar(string valor){
    if(!regex_match(valor, FORMATO)){
        throw invalid_argument("Formato invalido");
    }

    bool pontoSequencia;
    const int TAMANHO_EMAIL = valor.length();
    int i;

    for(i = 0; i < TAMANHO_EMAIL - 1; i++){
        if(valor[i] == '.' && valor[i + 1] == '.'){
            pontoSequencia = true;
        }
    }
    if(pontoSequencia){
        throw invalid_argument("Caractere '.' usado em sequencia");
    }
    else{
        char caractere;

        if (valor[0] == '.'){
            throw invalid_argument("Caractere '.' iniciando e-mail");
        }
        else if (valor[TAMANHO_EMAIL - 1] == '.'){
            throw invalid_argument("Caractere '.' finalizando e-mail");
        }
        else{
            i = 0;
            do{
                caractere = valor[i];
                i++;
            }while(caractere != '@');

            if(valor[i - 2] == '.' || valor[i] == '.'){
                throw invalid_argument("Caractere '.' em posicao invalida");
            }
        }
    }


}







void Horario::validar(string valor){
    if (!regex_match(valor, FORMATO))
        throw invalid_argument("Horario invalido");
}



void Matricula::validar(string valor){
    if (!regex_match(valor, FORMATO)){
        throw invalid_argument("Somente sao validos digitos(0-9) no formato XXXXX");
    }
    else{
        int i, j;
        bool flag = false;

        for(i = 0; i < valor.length() - 1; i++){
            for(j = i + 1; j < valor.length(); j++){
                if (valor[i] == valor[j]){
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





//Metodos de Nome



void Nome::validar(string valor)
{
    if (valor.size() < 5)
        throw length_error("Nome invalido (nome muito pequeno)");
    else if (valor.size() > 20)
        throw length_error("Nome invalido (nome muito grande)");
    else
        if (!regex_match(valor, FORMATO))
            throw invalid_argument("Nome invalido (formato nao suportado)");
}



//Metodos Senha


void Senha::validar(string valor)
{
    bool charRepetido = false;

    for (long long unsigned int i=0; i<valor.size(); i++)
    {
        for (long long unsigned int j=0; j<valor.size()-i-1; j++)
        {
            if (valor[i] == valor[i+j+1])
                charRepetido = true;
        }
    }

    if (!(charRepetido == false && regex_match(valor, FORMATO)))
        throw invalid_argument("Senha invalida");
}




//Metodos Telefone


void Telefone::validar(string valor)
{
    if (!regex_match(valor, FORMATO))
        throw invalid_argument("Numero de telefone invalido");
}


//Metodos Tipo


void Tipo::validar(string valor)
{
    if (!((valor.compare("auto") == 0)||(valor.compare("comedia") == 0)
        ||(valor.compare("drama") == 0)||(valor.compare("farsa") == 0)
        ||(valor.compare("melodrama") == 0)||(valor.compare("monologo") == 0)
        ||(valor.compare("musical") == 0)||(valor.compare("opera") == 0)
        ||(valor.compare("revista") == 0))){
            throw invalid_argument("Tipo invalido (O tipo deve ser digitado sem acentos e em minusculo)");
    }
}

