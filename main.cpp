#include <iostream>
#include <string>

using namespace std;

bool valida_entrada(string);
bool valida_digito(string);

int main(){
    string cpf;
    /*INPUT BLOCK*/
    cout << "Digite seu CPF: ";
    cin >> cpf;
    /*INPUT BLOCK*/
    if (valida_entrada(cpf) && valida_digito(cpf))
        cout << "CPF válido\n";
    else
        cout << "CPF inválido\n";
}

bool valida_entrada(const string cpf){
    for(char const &c : cpf)
    {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

bool valida_digito(const string cpf){
    int cont, digito;
    int i, produto = 1;
    int first_digit = 0;
    int sec_digit;
    int soma;

    /*
     * Multiplica os 9 primeiros digitos pela sequencia decrescente de 10 à 2;
     * Soma o produto das multiplicações;
     * Calcula o penultimo digito e reseta a soma;
     */ 
    cont = 10;
    for (i = 0; i <= 8; i += 1, cont--){
        digito = (int)cpf[i] - 48; /*Os digito originalmente são char*/
        produto = cont * digito;
        soma += produto;
    }
    first_digit = 11 - (soma % 11);
    soma = 0;

    /*
     * Multiplica os 9 primeiros digitos e o penultimo pela sequencia decrescente de 11 à 2;
     * Soma o produto das multiplicações;
     * Calcula o ultimo digito;
     */ 
    cont = 11;
    for (i = 0; i <= 8; i += 1, cont--){
        digito = (int)cpf[i] - 48;
        produto = cont * digito;
        soma += produto;
    }
    soma += first_digit * 2;
    sec_digit = 11 - (soma % 11);

    /* Se o penultimo ou o ultimo digito for maior que dez, ele é definido como 0*/
    if (first_digit >= 10)
        first_digit = 0;
    if (sec_digit >= 10)
        sec_digit = 0;

    if ((int)cpf[9] - 48 == first_digit && (int)cpf[10] - 48 == sec_digit)
        return true;
    else
        return false;
}