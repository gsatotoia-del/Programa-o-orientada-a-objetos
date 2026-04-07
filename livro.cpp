#include "livro.hpp"
#include <iostream>

Livro::Livro(string titulo, int ano, string autor)
    : Item(titulo, ano) {
    this->autor = autor;
}

void Livro::exibirInfo() const {
    Item::exibirInfo();
    cout << "Autor: " << autor << endl;
}