#include <iostream>

// int main() {
//   while (1) {
//     int a, b;
//     std::cin >> a >> b;
//     std::cout << (a + b) << std::endl;
//   }
// }

int main(){
    int a, b;
    while(std::cin >> a >> b){
        int result = a + b;
        std::cout << result << std::endl;
    }
    return 0;
}