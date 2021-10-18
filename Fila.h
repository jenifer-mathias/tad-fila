//Arquivo de cabeçalho (Interface)
/** ******************************************************************
 TAD Fila
 Estrutura de Dados I
****************************************************************** */

#ifndef TAD_FILA_H
#define TAD_FILA_H

#include <string>

using namespace std ;

class Fila {

private:
    //atributos
    int * fila; //ponteiro é um link para um END de MEM
    int tamanho; //qde de elem na fila
    int tamanhoMax;
    int ini; //marcador de inicio da Fila
    int fim; //marcador de fim da fila

public:
    Fila();
    Fila(int max);
    ~Fila();
    bool cheia();
    bool vazia();
    int inserir(int valor);
    int extrair();
    string imprimir();
    int tamFila();


    //IMPLEMENTAR
    int posicaoDoIntem(int valor); //retorna a posicao na fila, se existir
    void ordenar(); //ordena em ordem crescente os elementos da fila
    int front(); //informa o elem do inicio da fila
    int back(); //informa o elem do final da fila
};

#endif
