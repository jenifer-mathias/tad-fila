/** ******************************************************************
 TAD Fila
 Estrutura de Dados I
****************************************************************** */

#include <iostream>
#include "Fila.h"

using namespace std;

int main() {

    cout << "\n              Iniciando a execução ... \n\n";
    cout << "Primeiramente, informe o tamanho do vetor para criarmos a fila: ";
    int tam;
    cin >> tam;
    int opc;
    Fila fila(tam); //criação da Fila

    cout << "\n\n\n";
    cout << "\n---------------------------------------------------------------";
    cout << "\n                        TAD FILA";
    cout << "\n (esta fila só aceita números inteiros maiores do que zero)";
    cout << "\n---------------------------------------------------------------";

    do {
        cout << "\n\n________________________   MENU   _____________________________\n";
        cout << "\n0 - sair";
        cout << "\n1 - inserir na fila (enqueue)";
        cout << "\n2 - remover da fila (dequeue)";
        cout << "\n3 - imprimir a fila";
        cout << "\n4 - verificar se um item está na fila";
        cout << "\n5 - tamanho da fila";
        cout << "\n6 - ordenar a fila";
        cout << "\n7 - primeiro elemento da fila";
        cout << "\n8 - último elemento da fila";
        cout << "\n\n_______________________________________________________________\n";

        cout << "\n\nInforme sua opção: ";
        cin >> opc;

        switch (opc) {
            case 0: {
                cout << "\n Agradecemos a participação!";
                cout << "\n\n ~~~~ Fim da execucao! ~~~~\n\n";
                break;
            }

            case 1: {
                int dado = -1;
                cout << "\nInforme o valor do dado: ";
                cin >> dado;
                int x = fila.insereElemento(dado);
                if (x == -1) {
                    cout << "\nA fila já está cheia!";
                } else if (x == -2) {
                    cout << "\nEste elemento já está na fila!";
                } else {
                    cout << "\nElemento adicionado com sucesso na posição " << x << " da fila.";
                }
                break;
            }

            case 2: {
                int x = fila.removeElemento();
                if (x == -1) {
                    cout << "\nA fila está vazia!";
                } else {
                    cout << "\nElemento " << x << " foi removido com sucesso." << endl;
                }
                break;
            }

            case 3: {
                cout << fila.imprimir();
                break;
            }

            case 4: {
                int elem;
                cout << "\nQual elemento deseja procurar na fila? ";
                cin >> elem;
                int res = fila.getPosicaoItem(elem);
                if (res == -1) {
                    cout << "\nElemento não está na fila!";
                }
                break;
            }

            case 5: {
                cout << "\nTamanho da fila: " << fila.tamFila() << endl;
                break;
            }

            case 6: {
                fila.ordenaOrdemCrescente();
                cout << "\nFila ordenada\n" << fila.imprimir();
                break;
            }

            case 7: {
                fila.front();
                break;
            }

            case 8: {
                fila.back();
                break;
            }

            default: {
                cout << "\nOpção inválida.";
                break;
            }
        }
    } while (opc != 0);
}
