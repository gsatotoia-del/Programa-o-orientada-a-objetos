#pragma once
#include <iostream>
#include <cmath>
#include <stdexcept>

class Complexo {
private:
    double real;
    double imag;

public:
    // ─── Construtores ────────────────────────────────────────────────────────
    Complexo() : real(0.0), imag(0.0) {}
    Complexo(double r, double i = 0.0) : real(r), imag(i) {}
    Complexo(const Complexo&) = default;

    // ─── Getters ─────────────────────────────────────────────────────────────
    double getReal() const { return real; }
    double getImag() const { return imag; }

    // ─── Operadores aritméticos binários ─────────────────────────────────────
    Complexo operator+(const Complexo& o) const {
        return Complexo(real + o.real, imag + o.imag);
    }
    Complexo operator-(const Complexo& o) const {
        return Complexo(real - o.real, imag - o.imag);
    }
    Complexo operator*(const Complexo& o) const {
        // (a+bi)(c+di) = (ac-bd) + (ad+bc)i
        return Complexo(real * o.real - imag * o.imag,
                        real * o.imag + imag * o.real);
    }
    Complexo operator/(const Complexo& o) const {
        double den = o.real * o.real + o.imag * o.imag;
        if (den == 0.0)
            throw std::domain_error("Divisao por complexo nulo");
        return Complexo((real * o.real + imag * o.imag) / den,
                        (imag * o.real - real * o.imag) / den);
    }

    // ─── Operadores com escalares (membro) ───────────────────────────────────
    Complexo operator+(double d) const { return Complexo(real + d, imag); }
    Complexo operator-(double d) const { return Complexo(real - d, imag); }
    Complexo operator*(double d) const { return Complexo(real * d, imag * d); }
    Complexo operator/(double d) const {
        if (d == 0.0)
            throw std::domain_error("Divisao por escalar nulo");
        return Complexo(real / d, imag / d);
    }

    // ─── Operadores de atribuição composta ───────────────────────────────────
    Complexo& operator+=(const Complexo& o) { real += o.real; imag += o.imag; return *this; }
    Complexo& operator-=(const Complexo& o) { real -= o.real; imag -= o.imag; return *this; }
    Complexo& operator*=(const Complexo& o) { *this = *this * o; return *this; }
    Complexo& operator/=(const Complexo& o) { *this = *this / o; return *this; }

    Complexo& operator+=(double d) { real += d; return *this; }
    Complexo& operator-=(double d) { real -= d; return *this; }
    Complexo& operator*=(double d) { real *= d; imag *= d; return *this; }
    Complexo& operator/=(double d) {
        if (d == 0.0) throw std::domain_error("Divisao por escalar nulo");
        real /= d; imag /= d; return *this;
    }

    // ─── Operadores de comparação ─────────────────────────────────────────────
    bool operator==(const Complexo& o) const {
        return real == o.real && imag == o.imag;
    }
    bool operator!=(const Complexo& o) const { return !(*this == o); }

    // ─── Incremento e decremento (sobre a parte real) ─────────────────────────
    // Pré-incremento
    Complexo& operator++() { ++real; return *this; }
    Complexo& operator--() { --real; return *this; }
    // Pós-incremento
    Complexo operator++(int) { Complexo tmp(*this); ++real; return tmp; }
    Complexo operator--(int) { Complexo tmp(*this); --real; return tmp; }

    // ─── Operadores unários ───────────────────────────────────────────────────
    Complexo operator-() const { return Complexo(-real, -imag); }   // negação
    Complexo operator~() const { return Complexo(real, -imag); }    // conjugado

    // ─── Conversão para double (módulo) ──────────────────────────────────────
    explicit operator double() const { return std::sqrt(real * real + imag * imag); }

    // ─── Operadores de entrada/saída (friend) ────────────────────────────────
    friend std::ostream& operator<<(std::ostream& os, const Complexo& c);
    friend std::istream& operator>>(std::istream& is, Complexo& c);

    // ─── Operadores com escalar à esquerda (friend) ──────────────────────────
    friend Complexo operator+(double d, const Complexo& c);
    friend Complexo operator-(double d, const Complexo& c);
    friend Complexo operator*(double d, const Complexo& c);
    friend Complexo operator/(double d, const Complexo& c);
};

// ─── Definições das funções friend ───────────────────────────────────────────

inline std::ostream& operator<<(std::ostream& os, const Complexo& c) {
    os << c.real;
    if (c.imag >= 0) os << " + " << c.imag << "i";
    else             os << " - " << -c.imag << "i";
    return os;
}

inline std::istream& operator>>(std::istream& is, Complexo& c) {
    // Formato esperado: a b  (parte real e imaginária separadas por espaço)
    is >> c.real >> c.imag;
    return is;
}

inline Complexo operator+(double d, const Complexo& c) { return Complexo(d + c.real, c.imag); }
inline Complexo operator-(double d, const Complexo& c) { return Complexo(d - c.real, -c.imag); }
inline Complexo operator*(double d, const Complexo& c) { return Complexo(d * c.real, d * c.imag); }
inline Complexo operator/(double d, const Complexo& c) {
    double den = c.real * c.real + c.imag * c.imag;
    if (den == 0.0) throw std::domain_error("Divisao por complexo nulo");
    return Complexo(d * c.real / den, -d * c.imag / den);
}
