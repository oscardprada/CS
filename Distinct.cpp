#include <iostream>
#include <vector>
#include <unordered_map>

std::string kthDistinct(std::vector<std::string>& arr, int k) {
    std::unordered_map<std::string, int> count;
    for (const auto& s : arr) {
        ++count[s];
    }
    for (const auto& s : arr) {
        if (count[s] == 1 && --k == 0) {
            return s;
        }
    }
    return "";
}

int main() {
    int k;
    int size;

    std::cout << "How many elements would you like to input?: ";
    std::cin >> size;

    std::vector<std::string> V(size);
    for(int i =0;i<size;i++){
    std::cin>>V[i];
    }
    
    std::cout << "\nType the value of k: ";
    std::cin >> k;
    std::cout << kthDistinct(V, k) << '\n';

    return 0;
}
