#include <iostream>
int main () {}
#define MAX_SIZE 100 // Definindo o tamanho máximo da lista

class ListaArray {
private:
    int itens[MAX_SIZE];
    int tamanho;

public:
    ListaArray() : tamanho(0) {}

    // Verifica se a lista está vazia
    bool estaVazia() {
        return tamanho == 0;
    }

    // Insere um item no final da lista
    void inserirFim(int item) {
        if (tamanho < MAX_SIZE) {
            itens[tamanho++] = item;
        } else {
            std::cout << "Erro: Lista cheia!" << std::endl;
        }
    }

    // Remove o i-ésimo item da lista (considerando índice 0)
    void removerI(int i) {
        if (i < 0 || i >= tamanho) {
            std::cout << "Erro: Indice invalido!" << std::endl;
            return;
        }
        // Desloca os elementos para a esquerda para cobrir o buraco
        for (int j = i; j < tamanho - 1; j++) {
            itens[j] = itens[j + 1];
        }
        tamanho--;
    }

    // Verifica se um item está presente na lista
    bool contem(int item) {
        for (int i = 0; i < tamanho; i++) {
            if (itens[i] == item) return true;
        }
        return false;
    }
};