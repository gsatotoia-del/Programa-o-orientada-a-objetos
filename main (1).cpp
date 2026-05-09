#include <iostream>
#include <stdexcept>
#include "complexo.hpp"

int main() {
    std::cout << "=== Demonstracao da classe Complexo ===\n\n";

    // ── Construtores ─────────────────────────────────────────────────────────
    Complexo c0;                  // padrão: 0 + 0i
    Complexo c1(3.0, 4.0);       // 3 + 4i
    Complexo c2(1.0, -2.0);      // 1 - 2i
    Complexo c3(c1);             // cópia de c1

    std::cout << "c0 = " << c0 << "\n";
    std::cout << "c1 = " << c1 << "\n";
    std::cout << "c2 = " << c2 << "\n";
    std::cout << "c3 (copia de c1) = " << c3 << "\n\n";

    // ── Operadores aritméticos ────────────────────────────────────────────────
    std::cout << "--- Aritmetica ---\n";
    std::cout << "c1 + c2 = " << (c1 + c2) << "\n";
    std::cout << "c1 - c2 = " << (c1 - c2) << "\n";
    std::cout << "c1 * c2 = " << (c1 * c2) << "\n";
    std::cout << "c1 / c2 = " << (c1 / c2) << "\n\n";

    // ── Operadores com escalar ────────────────────────────────────────────────
    std::cout << "--- Com escalares ---\n";
    std::cout << "c1 + 2.0 = " << (c1 + 2.0) << "\n";
    std::cout << "2.0 + c1 = " << (2.0 + c1) << "\n";
    std::cout << "c1 * 3.0 = " << (c1 * 3.0) << "\n";
    std::cout << "5.0 / c2 = " << (5.0 / c2) << "\n\n";

    // ── Operadores de atribuição composta ─────────────────────────────────────
    std::cout << "--- Atribuicao composta ---\n";
    Complexo tmp(2.0, 1.0);
    std::cout << "tmp = " << tmp << "\n";
    tmp += c1;  std::cout << "tmp += c1 -> " << tmp << "\n";
    tmp -= c2;  std::cout << "tmp -= c2 -> " << tmp << "\n";
    tmp *= c2;  std::cout << "tmp *= c2 -> " << tmp << "\n";
    tmp /= c2;  std::cout << "tmp /= c2 -> " << tmp << "\n\n";

    // ── Operadores de comparação ──────────────────────────────────────────────
    std::cout << "--- Comparacao ---\n";
    Complexo c4(3.0, 4.0);
    std::cout << "c1 == c4 (ambos 3+4i)? " << (c1 == c4 ? "sim" : "nao") << "\n";
    std::cout << "c1 != c2?              " << (c1 != c2 ? "sim" : "nao") << "\n\n";

    // ── Incremento e decremento ───────────────────────────────────────────────
    std::cout << "--- Incremento / Decremento ---\n";
    Complexo c5(1.0, 1.0);
    std::cout << "c5 = " << c5 << "\n";
    std::cout << "++c5 = " << ++c5 << "\n";
    std::cout << "c5++ = " << c5++ << "  (retorna antes)\n";
    std::cout << "c5 apos c5++ = " << c5 << "\n";
    std::cout << "--c5 = " << --c5 << "\n";
    std::cout << "c5-- = " << c5-- << "  (retorna antes)\n";
    std::cout << "c5 apos c5-- = " << c5 << "\n\n";

    // ── Operadores unários ────────────────────────────────────────────────────
    std::cout << "--- Unarios ---\n";
    std::cout << "-c1 (negacao)  = " << -c1 << "\n";
    std::cout << "~c1 (conjugado)= " << ~c1 << "\n\n";

    // ── Módulo (conversão para double) ────────────────────────────────────────
    std::cout << "--- Modulo ---\n";
    std::cout << "|c1| = " << static_cast<double>(c1) << "  (esperado: 5)\n\n";

    // ── Entrada padrão ────────────────────────────────────────────────────────
    std::cout << "--- Entrada (formato: parte_real parte_imaginaria) ---\n";
    std::cout << "Digite um numero complexo (ex: 2 3): ";
    Complexo cInput;
    std::cin >> cInput;
    std::cout << "Voce digitou: " << cInput << "\n";
    std::cout << "Modulo: " << static_cast<double>(cInput) << "\n\n";

    // ── Tratamento de exceção (divisão por zero) ──────────────────────────────
    std::cout << "--- Excecao: divisao por zero ---\n";
    try {
        Complexo zero;
        Complexo resultado = c1 / zero;
    } catch (const std::domain_error& e) {
        std::cout << "Capturado: " << e.what() << "\n";
    }

    std::cout << "\n=== Fim da demonstracao ===\n";
    return 0;
}
