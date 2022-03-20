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
    int tamanhoAtual;
    int tamanhoMaximoFila;
    int inicio;
    int fim; //marcador de fim da fila

public:
    Fila();
    Fila(int max);
    ~Fila();
    bool estaCheia();
    bool estaVazia();
    int insereElemento(int valor);
    int removeElemento();
    string imprimir();
    int tamFila();
    int getPosicaoItem(int valor);
    void ordenaOrdemCrescente();
    int front(); /** informa o elem do inicio da fila */
    int back();  /** informa o elem do final da fila */
};

#endif
