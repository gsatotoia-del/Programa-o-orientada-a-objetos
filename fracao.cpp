
#include <iostream>
int main() {
}
struct Fracao {
    int num; // Numerador
    int den; // Denominador

    // Construtor para facilitar a criação (denominador padrão é 1)
    Fracao(int n = 0, int d = 1) : num(n), den(d) {
        if (den == 0) {
            std::cerr << "Erro: Denominador nao pode ser zero. Definindo como 1." << std::endl;
            den = 1;
        }
    }
};

// --- Funções de Operação ---

// SOMA: (a/b) + (c/d) = (a*d + c*b) / (b*d)
Fracao somar(Fracao f1, Fracao f2) {
    return Fracao(f1.num * f2.den + f2.num * f1.den, f1.den * f2.den);
}
Fracao somar(Fracao f, int i) {
    return somar(f, Fracao(i, 1));
}

// SUBTRAÇÃO: (a/b) - (c/d) = (a*d - c*b) / (b*d)
Fracao subtrair(Fracao f1, Fracao f2) {
    return Fracao(f1.num * f2.den - f2.num * f1.den, f1.den * f2.den);
}
Fracao subtrair(Fracao f, int i) {
    return subtrair(f, Fracao(i, 1));
}

// MULTIPLICAÇÃO: (a/b) * (c/d) = (a*c) / (b*d)
Fracao multiplicar(Fracao f1, Fracao f2) {
    return Fracao(f1.num * f2.num, f1.den * f2.den);
}
Fracao multiplicar(Fracao f, int i) {
    return Fracao(f.num * i, f.den);
}

// DIVISÃO: (a/b) / (c/d) = (a*d) / (b*c)
Fracao dividir(Fracao f1, Fracao f2) {
    return Fracao(f1.num * f2.den, f1.den * f2.num);
}
Fracao dividir(Fracao f, int i) {
    return Fracao(f.num, f.den * i);
}

// Função auxiliar para exibir a fração
void imprimir(Fracao f) {
    std::cout << f.num << "/" << f.den << std::endl;
}

int main() {
    Fracao a(1, 2); // 1/2
    Fracao b(1, 3); // 1/3

    std::cout << "Soma (1/2 + 1/3): ";
    imprimir(somar(a, b));

    std::cout << "Soma com inteiro (1/2 + 2): ";
    imprimir(somar(a, 2));

    std::cout << "Multiplicacao (1/2 * 1/3): ";
    imprimir(multiplicar(a, b));

    return 0;
}