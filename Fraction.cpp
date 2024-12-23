#include <iostream>
#include <stdexcept>

class Fraction {

  private: 
  int numerator;
  int denominator;

  void simplify() {
    int gcd = 0;
    for(int i = 1; i <= numerator || i <= denominator; i++) {
        if(numerator % i == 0 && denominator % i == 0)
            gcd = i;
    }
    numerator /= gcd;
    denominator /= gcd;
    if (denominator < 0) {
      numerator = -numerator;
      denominator = -denominator;
    }
  }

  public: Fraction(int num = 0, int den = 1) {
    if (den == 0) {
      throw std::invalid_argument("The denominator must be not zero");
    }
    numerator = num;
    denominator = den;
    simplify();
  }
  
  int GetNum() const {
    return numerator;
  }

  int GetDen() const {
    return denominator;
  }
  
  void SetNum(int num) {
    numerator = num;
    simplify();
  }

  void SetDen(int den) {
    if (den == 0) {
      throw std::invalid_argument("The denominator must be not zero");
    }
    denominator = den;
    simplify();
  }

  double ToDouble() const {
    return static_cast < double > (numerator) / denominator;
  }
  Fraction operator + (const Fraction & other) const {
    int num = numerator * other.denominator + other.numerator * denominator;
    int denom = denominator * other.denominator;
    return Fraction(num, denom);
  }
  Fraction operator - (const Fraction & other) const {
    int num = numerator * other.denominator - other.numerator * denominator;
    int denom = denominator * other.denominator;
    return Fraction(num, denom);
  }
  Fraction operator * (const Fraction & other) const {
    int num = numerator * other.numerator;
    int denom = denominator * other.denominator;
    return Fraction(num, denom);
  }
  Fraction operator / (const Fraction & other) const {
    if (other.numerator == 0) {
      throw std::invalid_argument("Undefined. (Division by 0).");
    }
    int num = numerator * other.denominator;
    int denom = denominator * other.numerator;
    return Fraction(num, denom);
  }

  Fraction & operator += (const Fraction & other) {
    * this = * this + other;
    return * this;
  }

  Fraction & operator -= (const Fraction & other) {
    * this = * this - other;
    return * this;
  }

  Fraction & operator *= (const Fraction & other) {
    * this = * this * other;
    return * this;
  }

  Fraction & operator /= (const Fraction & other) {
    * this = * this / other;
    return * this;
  }

  Fraction & operator = (const Fraction & other) {
    if (this != & other) {
      numerator = other.numerator;
      denominator = other.denominator;
    }
    return * this;
  }

  friend std::ostream & operator << (std::ostream & out,
    const Fraction & fraction) {
    out << fraction.numerator << "/" << fraction.denominator;
    return out;
  }

  friend std::istream & operator >> (std::istream & in, Fraction & fraction) {
    int num, den;
    char slash;

    in >> num >> slash >> den;

    if (slash != '/' || den == 0) {
      throw std::invalid_argument("Invalid fraction input.");
    }

    fraction = Fraction(num, den);
    return in;
  }
};

int main() {

  try {
    Fraction Fraction1(1, 2);
    Fraction Fraction2(1, 4);

    std::cout << "Fraction1: " << Fraction1 << "\n";
    std::cout << "Fraction2: " << Fraction2 << "\n";

    std::cout << "Fraction1 + Fraction2 = " << Fraction1 + Fraction2 << "\n";
    std::cout << "Fraction1 - Fraction2 = " << Fraction1 - Fraction2 << "\n";
    std::cout << "Fraction1 * Fraction2 = " << Fraction1 * Fraction2 << "\n";
    std::cout << "Fraction1 / Fraction2 = " << Fraction1 / Fraction2 << "\n";

    Fraction1 += Fraction2;
    std::cout << "Fraction1 += Fraction2, then Fraction1 = " << Fraction1 << "\n";

    Fraction1 -= Fraction2;
    std::cout << "Fraction1 -= Fraction2, then Fraction1 = " << Fraction1 << "\n";

    Fraction1 *= Fraction2;
    std::cout << "Fraction1 *= Fraction2, then Fraction1 = " << Fraction1 << "\n";

    Fraction1 /= Fraction2;
    std::cout << "Fractionf1 /= Fraction2, then Fraction1 = " << Fraction1 << "\n";

    std::cout << "Fraction1 converted to double: " << Fraction1.ToDouble() << "\n";

    Fraction Fraction3;
    std::cout << "Type a fraction (numerator/denominator): ";
    std::cin >> Fraction3;
    std::cout << "Fraction3 is: " << Fraction3 << "\n";
} 

catch (const std::exception & e) {
    std::cerr << "Error: " << e.what() << "\n";
  }

return 0;
}