# InMemoryDB with Transaction Support
## Description
This program implements an in-memory key-value database with transaction support. The database allows updates to prevent dirty writes, which is crucial for applications dealing with sensitive data like money transfers. The database supports basic operations such as begin_transaction(), put(key, value), get(key), commit(), and rollback().

## Setup Instructions
### Prerequisites
* A C++ compiler (e.g., g++)
* Git (for cloning the repository)
### Steps to Setup on Local Machine
Clone the repository: Open your terminal and run the following command to clone the repository:
```
git clone <your-repository-url>
```
Navigate to the repository directory:
```
cd <path-to-your-repository>
```
Add the source files: Ensure the following files are in your repository:

```
InMemoryDB.h
InMemoryDB.cpp
main.cpp
```
Compile the program: Use the following command to compile the program:

```
g++ -o InMemoryDB main.cpp InMemoryDB.cpp
```

Run the executable: After compiling, run the program with:

```
./InMemoryDB
```

The program will output the results of various operations on the in-memory database, demonstrating the functionality of transactions, commits, and rollbacks. Feel free to conduct your own testing in the main file.

## Future Improvements

This assignment is a good exercise and provides a solid foundation in understanding how transactions work within an in-memory database. To make this assignment an "official" assignment for the course, it may be beneficial to provide more detailed instructions regarding program specifications, particularly around testing and how we are expected to go about error handling (like what text should we print out in this specific case of failure, etc.). Including specific test cases and potentially a way to test our code across different programming languages would be awesome (though probably difficult, so including testing cases for us to implement is sufficient for this). Additionally, I think this assignment could be improved overall by adding a more comprehensive description of what the program does/how it works, further context behind the assignment, and ultimately its importance as I believe this would help students better appreciate the real-world applications and relevance of this assignment.
