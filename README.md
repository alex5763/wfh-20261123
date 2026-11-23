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


### What I accomplished today 
- Read through the cmake documentation on setting up a basic cmake project
    - With the CMake documentation and some googleing I set up the project in a way to create two executables, client and server, and link a static library with shared utilties between them 
    - Currently, both the client and server are bare bones applications that parse input arguments for port and ip, even though server doesn't really need an ip and it is just client who does, but for simplicity, I just made both have the same inputs. 
    - I feel like I have a better understanding of what is going on with linking different libraies
        - The most notable thing that I took away from this exercies is how linking libraires to the executables makes the functions and classes avaiable for use in the other classes and functions, before I didn't really understand why we were always linking specific libraries to specific targets, but now I see it is to have access to those libraries classes, functions, etc. 
- After some reaserch on parsing CLI arguemnts through C++ executables, I was able to find a way to parse CLI arguments with just C++, so that is the method that I am going through. 
    - Setting up the files was a little difficult especially the relationship between header files and the implementation files, after getting the input parser stood up I spent some time reading through the cpp references and some the sections on classes and header files on the learncpp.com site. 
- I used Gemini to help me break down the different steps that I should be trying to complete this exercies in, they are listed below. I was only able to complete the input parser and very limited start on creating a wrapper for the POSIX sockets. 
    - It was very helpful to get an idea of what I needed to do especially since the context I was using with Gemini I told it to not write any code so I wouldn't be tempted to copy anything. 
    - Admittedly, this made progress extremely slow, but I got to slow down a bit and really read on classes, constructors, destructors, member variables, member functions, and how they are defined between headers and implementation files
    - I have previous experience with raw pointers from my early college years, but this is my first time using smart pointers, so I was experimenting with when a `unique_ptr` calls its destructor after it leaves its scope. T
        - this can be seen in the `./build/ChatApp` executable which only contains the contents of `main_test.cpp` 
    - It is interesting how `unique_ptr` allows for you to define a single instance of that pointer, so that you can't accidentally make another
    - I can see how this is very useful when using sockets as you want to be very carful about creating/destroying them

#### Some notes for future research 
- I really need to get a better handle on the basics of C++, since wihtout that it makes it really challening to understand things like sockets and network communction
- I spent the majority of my day looking up things like: "how to define a class", "how to write if statments", "basic error handling", which really hindered my ability to learn more about sockets and build out this chat application more
- Although there is not much tangible progress in this repo, I feel like I have a better idea of what I don't know and how to target my research in the future

 
### Next Steps
- Create a connection / session object (currently in progress) 
- Resolve address and open a listening socket (server side) 
- Accept one client and read raw bytes (server side) 
- Connect from the client and send one line 
- Echo back and close cleanly 
- Frame messages by delimiter 
- Add interactive typing loop on the client 
- Track multiple clients and boradcast messages 
