#include <iostream>

using namespace std;

class Fractions {
private:
    int numerator, denominator;

public:
    // Конструкторы
    Fractions() : numerator(1), denominator(1) {}

    Fractions(int a, int b) {
        if (b == 0) {
            cout << "Error: Denominator cannot be zero" << endl;
            numerator = 0;
            denominator = 1;
        }
        else {
            numerator = a;
            denominator = b;
        }
    }

    // Инициализация
    void init(int x, int y) {
        if (y == 0) {
            cout << "Error: Denominator cannot be zero" << endl;
            numerator = 0;
            denominator = 1;
        }
        else {
            numerator = x;
            denominator = y;
        }
    }

    // Вывод дроби
    void printFraction() const {
        cout << numerator << " / " << denominator << endl;
    }

    // Арифметические операции
    Fractions Sum(const Fractions& b) const {
        int num = numerator * b.denominator + b.numerator * denominator;
        int denom = denominator * b.denominator;
        return Fractions(num, denom);
    }

    Fractions Minus(const Fractions& b) const {
        int num = numerator * b.denominator - b.numerator * denominator;
        int denom = denominator * b.denominator;
        return Fractions(num, denom);
    }

    Fractions Multiplication(const Fractions& b) const {
        int num = numerator * b.numerator;
        int denom = denominator * b.denominator;
        return Fractions(num, denom);
    }

    Fractions Divide(const Fractions& b) const {
        if (b.numerator == 0) {
            cout << "Error: Cannot divide by zero." << endl;
            return Fractions(0, 1);
        }
        int num = numerator * b.denominator;
        int denom = denominator * b.numerator;
        return Fractions(num, denom);
    }

    // Сеттеры и геттеры
    void setNumerator(int a) {
        numerator = a;
    }

    void setDenominator(int b) {
        if (b == 0) {
            cout << "Error: Denominator cannot be zero" << endl;
            denominator = 1;
        }
        else {
            denominator = b;
        }
    }

    int getNumerator() const {
        return numerator;
    }

    int getDenominator() const {
        return denominator;
    }
};

int main() {
    Fractions frac1(2, 3);  // 2/3
    Fractions frac2(3, 5);  // 3/5

    Fractions result = frac1.Sum(frac2);
    result.printFraction();  // Вывод суммы дробей

    return 0;
}
