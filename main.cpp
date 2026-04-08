#include <iostream>
#include "Livro.hpp"
#include "Usuario.hpp"

using namespace std;

int main() {

    //  Objeto na stack
    Livro livroStack("A revolução dos Bichos", 1945, "Geroge Orwell");

    //  Objeto na heap
    Livro* livroHeap = new Livro("Moby Dick", 1851, "Herman Melville");

    //  Usuario
    Usuario usuario;

    // Adicionando itens
    usuario.adicionarItem(&livroStack);
    usuario.adicionarItem(livroHeap);

    // Listando (polimorfismo)
    usuario.listarItens();

    // Liberando memória (heap)
    usuario.liberarMemoria();

    return 0;
}
