#include <iostream>
using namespace std;

bool valida_entrada(const string cpf){
    for(char const &c : cpf)
    {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

bool valida_digito(const string cpf){
    int cont = 10;
    int i, produto = 1, n;
    int first_digit = 0;
    int sec_digit;

    for (i = 0; i <= 8; i += 1){
        n = (int)cpf[i] - 48;
        produto = cont * n;
        cont -= 1;
        first_digit += produto;
    }
    first_digit = 11 - (first_digit % 11);
    sec_digit = first_digit * 2;
    
    if (first_digit >= 10)
        first_digit = 0;
    if (sec_digit >= 10)
        sec_digit = 0;

    if ((int)cpf[9] - 48 == first_digit && (int)cpf[10] - 48 == sec_digit){
        return true;}
    else{
        return false;}
}