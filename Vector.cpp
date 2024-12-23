#include <iostream>
#include <stdexcept>
#include <vector>

class Vector {
private:
    std::vector<double> elements;

public:
    Vector(size_t size = 0, double value = 0) : elements(size, value) {}

    Vector(const std::initializer_list<double>& list) : elements(list) {}

    Vector(const Vector& other) : elements(other.elements) {}

    Vector& operator=(const Vector& other) {
        if (this != &other) {
            elements = other.elements;
        }
        return *this;
    }

    double get(size_t index) const {
        if (index >= elements.size()) {
            throw std::out_of_range("The index is out of range");
        }
        return elements[index];
    }

    void set(size_t index, double value) {
        if (index >= elements.size()) {
            throw std::out_of_range("The index is out of range");
        }
        elements[index] = value;
    }

    size_t size() const {
        return elements.size();
    }

    Vector& operator+=(const Vector& other) {
        if (elements.size() != other.elements.size()) {
            throw std::invalid_argument("Vectors must have the same size");
        }
        for (size_t i = 0; i < elements.size(); ++i) {
            elements[i] += other.elements[i];
        }
        return *this;
    }

    Vector& operator-=(const Vector& other) {
        if (elements.size() != other.elements.size()) {
            throw std::invalid_argument("Vectors must have the same size");
        }
        for (size_t i = 0; i < elements.size(); ++i) {
            elements[i] -= other.elements[i];
        }
        return *this;
    }

    Vector operator+(const Vector& other) const {
        Vector result(*this);
        result += other;
        return result;
    }

    Vector operator-(const Vector& other) const {
        Vector result(*this);
        result -= other;
        return result;
    }

    double operator*(const Vector& other) const {
        if (elements.size() != other.elements.size()) {
            throw std::invalid_argument("Vectors must have the same size");
        }
        double result = 0;
        for (size_t i = 0; i < elements.size(); ++i) {
            result += elements[i] * other.elements[i];
        }
        return result;
    }

    Vector operator*(double scalar) const {
        Vector result(*this);
        for (auto& element : result.elements) {
            element *= scalar;
        }
        return result;
    }

    friend Vector operator*(double scalar, const Vector& vec) {
        return vec * scalar;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector& vec) {
        os << "[";
        for (size_t i = 0; i < vec.elements.size(); ++i) {
            os << vec.elements[i];
            if (i < vec.elements.size() - 1) {
                os << ", ";
            }
        }
        os << "]";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Vector& vec) {
        for (auto& element : vec.elements) {
            is >> element;
        }
        return is;
    }
};

int main() {
    Vector v1 = {1.0, 2.0, 3.0};
    Vector v2 = {4.0, 5.0, 6.0};
    Vector v3 = v1 + v2;
    Vector v4 = v1 - v2;
    double dotProduct = v1 * v2;
    Vector scaled = v1 * 2.0;

    std::cout << "v1: " << v1 << "\n";
    std::cout << "v2: " << v2 << "\n";
    std::cout << "v1 + v2: " << v3 << "\n";
    std::cout << "v1 - v2: " << v4 << "\n";
    std::cout << "Dot product: " << dotProduct << "\n";
    std::cout << "v1 * 2.0: " << scaled << "\n";

    return 0;
}