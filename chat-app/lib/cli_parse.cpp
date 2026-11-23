#include "cli_parse.h"

#include <string_view>
#include <stdexcept>

namespace cli {

Options parse_cli_args(int argc, char* argv[]) {
    // Defining return struct, able to do this because `Options` is defined in the cli namespace, otherwise would need to do cli::Options 
    Options opts;

    // Using preincrement, so that we increment before evaluation
    for (int i = 0; i < argc; ++i) {
        std::string_view arg = argv[i];

        // Checking for port arugument and validating range so can static cast. Static cast is prefered here because we are casting between primitives
        if ((arg == "-p" || arg == "--port") && i+1 < argc) {
            // pre-incrementing to get the argument and not the flag 
            int parsed = std::stoi(argv[++i]);    
            if (parsed < 1 || parsed > 65535) {
                throw std::out_of_range("Port must be between 1 and 65535.");
            }
            opts.port = static_cast<std::uint16_t>(parsed);
        }
        else if ((arg == "-i" || arg == "--host-ip") && i+1 < argc) {
            opts.ip = arg[++i];
        }
    }
    return opts;
}
} // namespace cli
