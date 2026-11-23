# Work From Home 2026-11-23 
This  repo contains all things that I did while wfh on November 23, 2026. 

## Project 1 Command line chat application
The goal of this project is to learn about sockets and create a command line chat application using sockets alongside a client-server paradigm. 

### Running the application
To build the chat-app applicaiton, run the following cmake commands from the `./chat-app/` directory. 

```cmake
cmake -S ./ -B build/
cmake --build build
``` 

To run the application navigate to either the client or server executables (./build/src/client/client.exe or ./build/src/server/server.exe) and pass in the following flags, otherwise, the default values will be set. If unknown flags are passed they will be ignored. 

| Full Flag | Short Form | Input Type | Default     |
| --------- | ---------- | ---------- | ----------- |
| --port    | -p         | `uint16_t` | `9005`      | 
| --host-ip | -i         | `String`   | "127.0.0.1" |


### Things done that should be expanded upon once I have completed the project
- Read through the cmake documentation on setting up a basic cmake project
    - With the CMake documentation and some googleing I set up the project in a way to create two executables, client and server, and link a static library with shared utilties between them 
    - Currently, both the client and server are bare bones applications that parse input arguments for port and ip, even though server doesn't really need an ip and it is just client who does, but for simplicity, I just made both have the same inputs. 
- After some reaserch on parsing CLI arguemnts through C++ executables, I was able to find a way to parse CLI arguments with just C++, so that is the method that I am going through. 
    - I am still a little uncertain on setting up the header files, but I will likely look more into that as I go through creating the client and server classes. 
 
### Next Steps
- Create a connection / session object
- Resolve address and open a listening socket (server side) 
- Accept one client and read raw bytes (server side) 
- Connect from the client and send one line 
- Echo back and close cleanly 
- Frame messages by delimiter 
- Add interactive typing loop on the client 
- Track multiple clients and boradcast messages 
