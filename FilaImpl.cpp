/** ******************************************************************
 TAD Fila
 Estrutura de Dados I
****************************************************************** */

#include <sstream>
#include "Fila.h"
#include <iostream>

using namespace std;

Fila::~Fila() {}

Fila::Fila() {}

Fila::Fila(int max) {
    this->fila = new int(max);
    this->tamanhoMaximoFila = max;
    this->tamanhoAtual = 0;
    this->inicio = -1;
    this->fim = -1;
}

bool Fila::estaVazia() {
    return this->tamanhoAtual == 0;
}

bool Fila::estaCheia() {
    return this->tamanhoAtual == this->tamanhoMaximoFila;
}

int Fila::tamFila() {
    return this->tamanhoAtual;
}

/**
 * INSERE UM ELEMENTO NA FILA.

 * Antes de inserir:
 *   - verifica se a fila não está lotada.
 *   - se estiver lotada, retorna -1.

 * Depois de inserir:
 *   - retorna a posição onde o elemento foi inserido.
 */

int Fila::insereElemento(int valor) {
    if (this->estaCheia()) {
        return -1;
    }
    this->fim = (this->fim + 1) % this->tamanhoMaximoFila;
    if (this->inicio == -1) { //primeiro elemento
        this->inicio = 0;
    }
    this->fila[fim] = valor;
    this->tamanhoAtual++;
    return this->fim;
}

/**
 * EXTRAI O PROXIMO ELEMENTO A SER ATENDIDO (PRIMEIRO DA FILA).
 * Retorna o valor do elemento.
 * Obs: se esvaziar a fila (tamanho=0) retorne "inicio" e "fim" para -1.
 */
int Fila::removeElemento() {
    if (this->estaVazia()) {
        this->inicio = -1;
        this->fim = -1;
        return -1;
    }
    int valor;
    valor = this->fila[inicio];
    this->fila[inicio] = -1;
    this->inicio = (this->inicio + 1) % this->tamanhoMaximoFila;
    this->tamanhoAtual--;
    if (estaVazia()) {
        this->inicio = -1;
        this->fim = -1;
    }
    return valor;
}


/**
 * VERIFICA EM QUAL POSICAO DA FILA SE ENCONTRA DETERMINADO ITEM.
 * Retira da Fila original, IMPRIME, insere em uma fila auxiliar. Faça isso até esvaziar a fila.
 * Depois, retorne os elementos para a fila original
 */
string Fila::imprimir() {

    Fila aux(this->tamanhoAtual);
    int qde = this->tamanhoAtual;
    int elemento, ret;
    stringstream ss;
    ss << "[ ";
    while(qde > 0) {
        elemento = this->removeElemento();
        ss << elemento << " ";
        ret = aux.insereElemento(elemento);
        qde--;
    }
    qde = aux.tamanhoAtual;
    while(qde > 0){
        elemento = aux.removeElemento();
        ret = this->insereElemento(elemento);
        qde--;
    }
    ss << "]";
    return ss.str();
}

/**
 * VERIFICA EM QUAL POSIÇ˜O DA FILA SE ENCONTRA DETERMINADO ITEM.
 * Retira da Fila original, compara, insere em uma fila auxiliar.
 * Depois, retorne os elementos para a fila original respeitando a ordem original
 * Caso nao encontre, retorna -1 (nao esta' na fila ou a fila esta' vazia).
 */
int Fila::getPosicaoItem(int valor) {
    Fila aux(this->tamanhoAtual);
    int elemento, cont = 0, resposta = -1;
    //utilizo o while para percorrer toda a fila
    while(this->tamanhoAtual > 0){
        //contador para indicar a posicao do elemento
        cont = cont+1;
        //extraio o elemento
        elemento = this->removeElemento();
        //verifico se o elemento é igual ao valor digitado pelo usuario
        if(elemento == valor) {
            //utilizo a resposta para receber o cont porque caso nao encontre o elemento ele retorna -1;
            resposta = cont;
            /* Coloquei o print de quando encontra o elemento dentro do método para que quando haja mais de um
             * elemento dentro da fila ele possa mostrar as posicoes*/
            cout <<"\nO elemento está na fila na posição " << resposta << endl;
        }
        //coloco o elemento na pilha auxiliar
        aux.insereElemento(elemento);
    }
    //preenche a pilha principal
    while(aux.tamanhoAtual > 0){
        elemento = aux.removeElemento();
        this->insereElemento(elemento);
    }
    return resposta;

}

/** futuramente, mudar para um método de ordenação mais eficiente **/
void Fila::ordenaOrdemCrescente() {
    Fila aux(this->tamanhoAtual);
    Fila ordenada (this->tamanhoAtual);
    int elem;
    while(this->tamanhoAtual > 0) {
        int menor = this->removeElemento();
        //retira o menor, e coloca numa Fila ordenada até acabar os elementos da Fila principal"
        while(this->tamanhoAtual > 0){
            elem = this->removeElemento();
            //ve se o elemento é menor que o "menor atual"
            if(elem < menor){
                //se o elemento for maior que a res
                aux.insereElemento(menor);
                menor = elem;
            }
            else{
                aux.insereElemento(elem);
            }
        }
        //restaura a fila
        while(aux.tamanhoAtual > 0){
            elem = aux.removeElemento();
            //condicional para deixar a restaurar fila "principal", tirando um elemento por iteração (o elemento menor)
            this->insereElemento(elem);
        }
        //adiciona a fila de ordenadas
        ordenada.insereElemento(menor);
    }
    //passando da fila ordenada para a fila "principal"
    while(ordenada.tamanhoAtual > 0){
        int valor = ordenada.removeElemento();
        this->insereElemento(valor);
    }
}


int Fila::front() {
    Fila aux(this->tamanhoAtual);
    int elem;
    //extrai o primeiro elemento
    elem = this->removeElemento();
    cout << "\nO primeiro elemento da fila é o número " << elem << "";
    //guarda o elemento na fila auxiliar
    aux.insereElemento(elem);
    //retira os outros elementos e insire na auxiliar
    while(this->tamanhoAtual > 0){
        elem = this->removeElemento();
        aux.insereElemento(elem);
    }
    //retorna os valor da fila auxiliar para fila principal
    while(aux.tamanhoAtual > 0){
        elem = aux.removeElemento();
        this->insereElemento(elem);
    }
    return 0;
}


int Fila::back() {
    Fila aux(this->tamanhoAtual);
    int elem;
    //percorre o vetor  e extrai os elementos e coloca na fila auxiliar
    while(this->tamanhoAtual > 0){
        elem = this->removeElemento();
        aux.insereElemento(elem);
    }
    //print do último elemento
    cout << "\nO último elemento da fila é o número " << elem << "";
    //retorna os valores para fila principal
    while(aux.tamanhoAtual > 0){
        elem = aux.removeElemento();
        this->insereElemento(elem);
    }
    return 0;
}

