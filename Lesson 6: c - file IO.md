# Intro to c #


- Compile a .c file with
``` gcc -std=c99 -Werror -Wall -Wpedantic -Wextra -o resultfile main.c ```
``` gcc file.c -o resultfile ``` is what is needed for the compilation itself, by default the result file if not specified is a.out
the other flags are added for error checks

- alternatively, copy the make file and compile with make, every file you compile should be in a seperate directory and named main.c and have a makefile in the same dir

```gcc -e ``` -only preprocess the code

- xxd command - shows the contents of a file in a binary format, helps with interpreting what happened during file reading/writing

# IO operations #

Establishing connection with file descriptors
```
int fd1 = open(const char *pathname, int flags);
int fd1 = open("random.txt", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWRUSR)
```
-open a file descriptor to file random.txt, for reading and writing, create if not existing overrite its content with trunc, and give user perms for reading and writing
```if( fd1 == -1 ){
err(1, "file couldn't open for reading sry");
}//always add checks for those
```

```int close(int fd);``` - just close connection with file by passing the file descriptor 

Predefined types with their size in their name
uint32_t
uint64_t
