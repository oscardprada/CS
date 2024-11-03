#include <iostream>

void overlap_function(int* arr1, int* arr2){
    bool overlap = false;
    
    if ((arr2[0] < arr1[2]) && (arr2[1] < arr1[3]) && (arr1[0] < arr2[2]) && (arr1[1] < arr2[3])){
        overlap = true;
    }
    
std::cout << overlap;
}

int main(){
    int rectangle1[4];
    int rectangle2[4];
    
        std::cout << "Type the coordenates of the first rectangle [x1, y1, x2, y2]:\n";
        for (int i = 0; i <= 3; i++) {
        std::cin >> rectangle1[i];
        }
        
        std::cout << "\nType the coordenates of the second rectangle:\n";
        for (int i = 0; i <= 3; i++) {
        std::cin >> rectangle2[i];
        }
        
        std::cout << "\n";
        overlap_function(rectangle1, rectangle2);

}
