#include "UniqueSocket.h"

UniqueSocket::UniqueSocket() {
    std::cout << "Constructing the UniqueSocket" << "\n";
    this->SocketHandle = -1;
}

UniqueSocket::~UniqueSocket() {
    std::cout << "Destructing the UniqueSocket" << "\n";
}

bool UniqueSocket::is_open(){
    if (this->SocketHandle != -1) {
        return true;
    }
    return false;
}
