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
    this->tamanhoMax = max; //TAM MAX da Fila
    this->tamanho = 0; //TAM atual da Fila
    this->ini = -1;
    this->fim = -1;
}

bool Fila::vazia() {
    return this->tamanho == 0;
}

bool Fila::cheia() {
    return this->tamanho == this->tamanhoMax;
}

int Fila::tamFila(){
    return this->tamanho;
}

/**
 * INSERE UM ELEMENTO NA FILA.

 * Antes de inserir:
 *   - verifica se a fila nao esta lotada.
 *   - se estiver lotada, retorna -1.

 * Depois de inserir:
 *   - retorna a posicao onde o elem foi inserido.
 */

int Fila::inserir(int valor) {
    if (this->cheia()) {
        return -1;
    }
    this->fim = (this->fim + 1) % this->tamanhoMax;
    if (this->ini == -1) { //primeiro elemento
        this->ini = 0;
    }
    this->fila[fim] = valor;
    this->tamanho++;
    return this->fim;
}

/**
 * EXTRAI O PROXIMO ELEMENTO A SER ATENDIDO (PRIMEIRO DA FILA).
 * Retorna o valor do elemento.
 * Obs: se esvaziar a fila (tamanho=0) retorne "ini" e "fim" para -1.
 */
int Fila::extrair() {
    if (this->vazia()) {
        this->ini = -1;
        this->fim = -1;
        return -1;
    }
    int valor;
    valor = this->fila[ini];
    this->fila[ini] = -1;
    this->ini = (this->ini + 1) % this->tamanhoMax;
    this->tamanho--;
    if (vazia()) {
        this->ini = -1;
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

    Fila aux(this->tamanho);
    int qde = this->tamanho;
    int elem, ret;
    stringstream ss;
    ss << "[ ";
    while(qde > 0){
        elem = this->extrair();
        ss << elem << " ";
        ret = aux.inserir(elem);
        qde--;
    }
    qde = aux.tamanho;
    while(qde > 0){
        elem = aux.extrair();
        ret = this->inserir(elem);
        qde--;
    }
    ss << "]";
    return ss.str();
}

/**
 * VERIFICA EM QUAL POSICAO DA FILA SE ENCONTRA DETERMINADO ITEM.
 * Retira da Fila original, compara, insere em uma fila auxiliar.
 * Depois, retorne os elementos para a fila original respeitando a ordem original
 * Caso nao encontre, retorna -1 (nao esta' na fila ou a fila esta' vazia).
 */
int Fila::posicaoDoIntem(int valor) {
    Fila aux(this->tamanho);
    int elem, cont=0, resposta= -1;
    //utilizo o while para percorrer toda a fila
    while(this->tamanho > 0){
        //contador para indicar a posicao do elemento
        cont = cont+1;
        //extraio o elemento
        elem = this->extrair();
        //verifico se o elemento é igual ao valor digitado pelo usuario
        if(elem == valor) {
            //utilizo a resposta para receber o cont porque caso nao encontre o elemento ele retorna -1;
            resposta = cont;
            /* Coloquei o print de quando encontra o elemento dentro do método para que quando haja mais de um
             * elemento dentro da fila ele possa mostrar as posicoes*/
            cout << "Elemento está na fila na posição " << resposta << endl;
        }
        //coloco o elemento na pilha auxiliar
        aux.inserir(elem);
    }
    //preenche a pilha principal
    while(aux.tamanho > 0){
        elem = aux.extrair();
        this->inserir(elem);
    }
    return resposta;

}

/** futuramente, mudar para um método de ordenação mais eficiente **/
void Fila::ordenar() {
    //=== IMPLEMENTAR
    Fila aux(this->tamanho);
    Fila ordenada (this->tamanho);
    int elem;
    while(this->tamanho >0)
    {
        int menor = this->extrair();
        //retira o menor, e coloca numa Fila ordenada até acabar os elementos da Fila principal"
        while(this->tamanho > 0){
            elem = this->extrair();
            //ve se o elemento é menor que o "menor atual"
            if(elem < menor){
                //se o elemento for maior que a res
                aux.inserir(menor);
                menor = elem;
            }
            else{
                aux.inserir(elem);
            }
        }
        //restaura a fila
        while(aux.tamanho > 0){
            elem = aux.extrair();
            //condicional para deixar a restaurar fila "principal", tirando um elemento por iteração (o elemento menor)
            this->inserir(elem);
        }
        //adiciona a fila de ordenadas
        ordenada.inserir(menor);
    }
    //passando da fila ordenada para a fila "principal"
    while(ordenada.tamanho>0){
        int valor = ordenada.extrair();
        this->inserir(valor);
    }
    return;
}


int Fila::front() {
    Fila aux(this->tamanho);
    int elem;
    //estrai o primeiro elemento
    elem = this->extrair();
    cout << "\nO primeiro elemento da fila é o número " << elem << "";
    //guarda o elemento na fila auxiliar
    aux.inserir(elem);
    //retira os outros elementos e insire na auxiliar
    while(this->tamanho > 0){
        elem = this->extrair();
        aux.inserir(elem);
    }
    //retorna os valor da fila auxiliar para fila principal
    while(aux.tamanho > 0){
        elem = aux.extrair();
        this->inserir(elem);
    }
    return 0;
}


int Fila::back() {
    Fila aux(this->tamanho);
    int elem;
    //percorre o vetor  e estrai os elementos e coloca na fila auxiliar
    while(this->tamanho > 0){
        elem = this->extrair();
        aux.inserir(elem);
    }
    //print do último elemento
    cout << "\nO último elemento da fila é o número " << elem << "";
    //retorna os valores para fila principal
    while(aux.tamanho > 0){
        elem = aux.extrair();
        this->inserir(elem);
    }
    return 0;
}

