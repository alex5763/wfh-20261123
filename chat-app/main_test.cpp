#include "UniqueSocket.h"
#include <memory>

int main() {
    std::cout << "Entering the main function and defining unique pointer in if statement " << "\n";
    if (true){
        std::cout << "Inside if statement" << "\n";
        std::unique_ptr<UniqueSocket> testSocket = std::make_unique<UniqueSocket>(); 
    }
    std::cout << "Outside of if statement, should be outside of scope for the unique pointer and should see destructor get called" << "\n";
}
