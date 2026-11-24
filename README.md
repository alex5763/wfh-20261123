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
    - With the CMake documentation and some googling I set up the project in a way to create two executables, client and server, and link a static library with shared utilities between them 
    - Currently, both the client and server are bare bones applications that parse input arguments for port and ip, even though server doesn't really need an ip and it is just client who does, but for simplicity, I just made both have the same inputs. 
    - I feel like I have a better understanding of what is going on with linking different libraries
        - The most notable thing that I took away from this exercise is how linking libraries to the executables makes the functions and classes available for use in the other classes and functions, before I didn't really understand why we were always linking specific libraries to specific targets, but now I see it is to have access to those libraries classes, functions, etc. 
- After some research on parsing CLI arguemnts through C++ executables, I was able to find a way to parse CLI arguments with just C++, so that is the method that I am going through. 
    - Setting up the files was a little difficult especially the relationship between header files and the implementation files, after getting the input parser stood up I spent some time reading through the cpp references and some the sections on classes and header files on the learncpp.com site. 
- I used Gemini to help me break down the different steps that I should be trying to complete this exercise in, they are listed below. I was only able to complete the input parser and very limited start on creating a wrapper for the POSIX sockets. 
    - It was very helpful to get an idea of what I needed to do especially since the context I was using with Gemini I told it to not write any code so I wouldn't be tempted to copy anything. 
    - Admittedly, this made progress extremely slow, but I got to slow down a bit and really read on classes, constructors, destructors, member variables, member functions, and how they are defined between headers and implementation files
    - I have previous experience with raw pointers from my early college years, but this is my first time using smart pointers, so I was experimenting with when a `unique_ptr` calls its destructor after it leaves its scope. T
        - this can be seen in the `./build/ChatApp` executable which only contains the contents of `main_test.cpp` 
    - It is interesting how `unique_ptr` allows for you to define a single instance of that pointer, so that you can't accidentally make another
    - I can see how this is very useful when using sockets as you want to be very careful about creating/destroying them

#### Some notes for future research 
- I really need to get a better handle on the basics of C++, since without that it makes it really challenging to understand things like sockets and network compunction
- I spent the majority of my day looking up things like: "how to define a class", "how to write if statements", "basic error handling", which really hindered my ability to learn more about sockets and build out this chat application more
- Although there is not much tangible progress in this repo, I feel like I have a better idea of what I don't know and how to target my research in the future

 
### Next Steps
- Create a connection / session object (currently in progress) 
- Resolve address and open a listening socket (server side) 
- Accept one client and read raw bytes (server side) 
- Connect from the client and send one line 
- Echo back and close cleanly 
- Frame messages by delimiter 
- Add interactive typing loop on the client 
- Track multiple clients and broadcast messages

# Work from home 2026-11-24
Today I am mainly reading up on C++ through the "Professional C++" by Marc Gregoire. Below are some of the topics that I read about.
- Preprocessor directives
    - Covered `#include`, `#ifdef`, `#ifndef`, and `#pragma`
- Namespaces
    - Namespaces are used to naming conflicts between different pieces of code and 3rd party libraries
    - You are able to nest namespaces like `namespace namespace1::namespace2::namespace3 { }`, but only after C++17 otherwise you would need to do `namespace namespace1 { namespace namespace2 { namespace namespace3 { }}}`
    - Like classes, namespaces can help define the polymorphic structure of a given program
        - I originally thought that most programs used inheritance to define its polymorphism, but namespaces can assist in that or the structure can be primarily defined by namespaces, which is how the framework defines its polymorphism
    - the `using` keyword can be used to define the namespace that a given file or class is using
        - You should never use this in a header file since any code that is including this header will be forced to also use that namespace and can cause problems
    - You can also define namespace alias like `namespace MyFTP = MyLib::Networking::FTP;`
- Variables
    - variables in C++ are stongly typed (i.e. they have a specific type)
    - Use the `std::numerical_limits` from the `<limits>` header to define limits for different variable types
    - Uniform initializers, introduced in C++11, are the standard way to initialize variables
        - Zero initializers, i.e. `int num { 0 };` or `int num {};` are how to initialize variables to zero. Otherwise something like `int num;` would initialize `num` to whatever is in memory
    - Casting
        - There are 3 ways to cast: examples casting from float to int
            1. holdover from C, not recommended but often used; `int i1 { (int)myFloat };`
            2. This is rarely used; `int i2 { int(myFloat) };`
            3. Recommended and most explicit: `int i3 { static_cast<int>(myFloat) };`
        - Explicit casting is preferable as implicit casting can lead to potential for loss of data, especially when going between non-compatible types like floats and ints
        - It is okay to implicitly cast if you know that left and right hand side types are fully compatible
    - Floating point numbers
        - Special floating point numbers: +/- infinity and NaN
            - To check for NaN use `std::isnan()` and to check for infinity use `std::isinf()`
            - You can get these values through the `std::numeric_limits` by using `numeric_limits<double>::infinity`.
    - Operators
        - There are many different operators mainly arithmetic and bitwise operations
        - C++ evaluates expressions from left to right 
        - The order of precedence for operations is as follows:
            1. Arithmetic multiplication, division, and modulus
            2. Arithmetic addition and subtraction
            3. Bitwise operations
        - A better list of precedence is as follows:
            1. `++ --` (postfix)
            2. `++ --` (prefix)
            3. `* / %`
            4. `+ -`
            5. `<< >>`
            6. `&` (bitwise AND)
            7. `^` (bitwise XOR)
            8. `|` (bitwise OR)
            9. `= += -= *= /= %= &= |= ^= <<= >>=`
    - Enumerations
        - Enumerations solve the problem with constant values since you can perform operations on them if you were to set constants up for each value.
        - This is solved with *strongly typed enumeration types*
        - To define an enumeration we can do something like `enum class PieceType { King, Queen, Rook, Pawn };` and can be used like `PieceType piece { PieceType piece { PieceType::King };`
        - Under the hood, all values within an enumeration are assigned integer values, so for the above example `King = 0`, `Queen = 1`, etc.
            - Although the compiler assigns numbers to the items in an enumeration they are **not** automatically converted to integers making the following illegal: `if (PieceType::Queen == 2) { ... }`
            - These values are assigned by starting the first item in the enum at `0` and incrementing by 1 for each subsequent value
            - You can assign specific integer values to items in an enum, but if you don't assign a number the next item will be the previous items number + 1. i.e. if we said `enum class PieceType { King, Queen, Rook = 10, Pawn };`, then the integers assigned by the compiler would be `[0, 1, 10, 11]`.
        - The enumeration value names are not automatically exported to the enclosing scope
            - This means that they cannot clash with other names already defined in the parent scope
    - Structs
        - Structs are simpler than classes, they basically define an object with different values, example below.
        ```cpp
        struct Employee {
            char firstName;
            char lastName;
            int employeeNumber;
        }
        ```
        - You can access the variables of a struct using the `.` operator.
    - Conditional statements
        - If/else statements
            - A cascading if statement is an if statement with `else if`'s
            - If statements can have initalizers in them they are defined as below
            ```cpp
            if (<initalizer>; <conditional_expression>) {
                <if_body>
            } else if (<else_if_expression>) {
                <else_if_body>
            } else {
                <else_body>
            }
            ```
            - Importantly, the intializer is only available in the scope of the if statement
        - Switch case
            - The cases for this statement must be convertible to an integer type
            - One important thing about C++ switch statements is that once a case is hit and the code within the case is executed the switch case is not automatically executed without a `break`
                - If a case is hit and it doesn't have a `break`, then it will continue down the switch statement and hit all of the other true cases and execute this code, this is called *fallthrough*
                - Most compilers will warn you about fallthrough, but if it is intentional, then you can include the attribute `[[ fallthrough ]]` to suppress the compiler warnings.

I continued reading through the books introduction section and got the section on strings. The sections that I read that I don't really have additional inputs on is the section on attributes, cstyle arrays, vectors, structured bindings, loops, and initializer lists as they were all very straight forward and I have read about them before. I did spend quite a bit of time with each section and did some googling for additional information on all of these topics to make sure that I understood them. I would say that I am getting a lot of good basic information about C++ and this is a really good refresher that I have been needing for a while. I only used C++ in college briefly, so these introductory topics have been very helpful to go through. This book does a really good job for someone who has used C++ in the past and needs a refresher on the basics and then gets into real world examples and a lot of stuff that most C++ books don't have that I have seen. I would recommend this book to someone starting out who has experience with other languages and needs a good intro into using C++ in a professional environment. 
        
