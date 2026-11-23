#include <cstdint>
#include <string> 

namespace cli {

// Defining struct that contains default values for ip and port 
struct Options {
    std::uint16_t port = 9005;
    std::string ip = "127.0.0.1";
};

// Function to parse the CLI arguments
Options parse_cli_args(int argc, char* argv[]);

}
