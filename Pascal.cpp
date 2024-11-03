#include <iostream>

void pt_row(int i) {
    int row[i + 1];
    row[0] = 1;
    
    for (int k = 1; k <= i; ++k) {
        row[k] = row[k-1] * (i - k + 1) / k;
    }
    for (int k = 0; k <= i; ++k) {
        std::cout << row[k] << " ";
    }
}

int main() {
    int row_i;
    std::cout << "Type the row index:\n";
    std::cin >> row_i;
    std::cout << "\nThe row number " << row_i << " of the Pascal's triangle is:\n";
    pt_row(row_i);
    return 0;
}