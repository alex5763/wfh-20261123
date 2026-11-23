#include <iostream>
#include <unistd.h>

class UniqueSocket {
    public: 
       explicit UniqueSocket(); // Constructor 
       ~UniqueSocket(); // Destructor
       bool is_open();
    private: 
       int SocketHandle; 
};
