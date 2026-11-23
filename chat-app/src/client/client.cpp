#include "cli_parse.h"

#include <iostream>

int main(int argc, char* argv[]) {
    
    // Parsing CLI arguments using the shared library and catching errors 
    try {
        cli::Options opts = cli::parse_cli_args(argc, argv);
        std::cout << "Running on: " << opts.ip << ":" << opts.port << "\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Argument error: " << e.what() << "\n";
        return 1;
    }
    return 0;
}
