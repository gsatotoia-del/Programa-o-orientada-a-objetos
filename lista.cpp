#include <iostream>
int main () {
}
// Definição do TAD NODE
struct Node {
    int valor;
    Node* proximo;
};

class ListaEncadeada {
private:
    Node* cabeca;

public:
    ListaEncadeada() : cabeca(nullptr) {}

    // Verifica se a lista está vazia
    bool estaVazia() {
        return cabeca == nullptr;
    }

    // Insere um item no final da lista
    void inserirFim(int item) {
        Node* novo = new Node{item, nullptr};
        if (estaVazia()) {
            cabeca = novo;
        } else {
            Node* atual = cabeca;
            while (atual->proximo != nullptr) {
                atual = atual->proximo;
            }
            atual->proximo = novo;
        }
    }

    // Remove o i-ésimo item da lista
    void removerI(int i) {
        if (estaVazia() || i < 0) return;
        
        Node* temp = cabeca;

        if (i == 0) {
            cabeca = cabeca->proximo;
            delete temp;
            return;
        }

        for (int j = 0; temp != nullptr && j < i - 1; j++) {
            temp = temp->proximo;
        }

        if (temp == nullptr || temp->proximo == nullptr) return;

        Node* proximoNode = temp->proximo->proximo;
        delete temp->proximo;
        temp->proximo = proximoNode;
    }

    // Verifica se um item está presente na lista
    bool contem(int item) {
        Node* atual = cabeca;
        while (atual != nullptr) {
            if (atual->valor == item) return true;
            atual = atual->proximo;
        }
        return false;
    }
};