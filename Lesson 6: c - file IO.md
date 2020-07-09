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
flags:
- O_RDONLY - open file only for reading
- O_RDWR - open file for reading and writing
- O_WRONLY - open file for writing only
- O_CREAT - create file if it doesn't exist on opening it
- O_TRUNC - overwrite the existing content in the file it wasn't empty
- S_URUSR -give the file user perms for reading, alternatively give them with numbers 00700 all user perms, 00600 - read write, 00400 - read, 00200 - write
```
if( fd1 == -1 ){
err(1, "file couldn't open for reading sry");
}//always add checks for those
```

```int close(int fd);``` - just close connection with file by passing the file descriptor 

```lseek(fd, 0, SEEK_SET) ``` - set the file descriptor to go to the beginning of a file after using it for sth to go through the file already.
```lseek(fd1, -1, SEEK_CUR); ``` - set the fd one position back from the current one
```SEEK_END - sets to the end of the file```

- printf
- fprintf(File*stream,...), works like err();

- err(int exitcode, string msg) -terminates the program
- errx(int exitcode, string msg) - for user errs
- warn(string msg);
- warnx(string msg);
- Global var errno - gets set when sth breaks and exits, give info about the error.

Predefined types with their size in their name
- uint16_t -unsigned int from 0 to 32,767
- uint32_t
- uint64_t

- stat - system call, displays info about files
- struct stat - default struct 

### structs ### 
- like in c++
```
struct test {
  char a;
  int b;
}
int main() {
  struct test firstStruct;
  firstStruct.a;
  firstStruct.b;
}
//we can also type def it not to have to write the whole struct thing every time
typedef struct test {
  char a;
  int b;
} test

struct test {
  char a;
  int b;
 } __attribute((packed)) // this attribute makes it so that the fs doesn't put some spacesq it's memory efficient but it's hard for the processor
```
### stat ###
- very useful, gives info about a file passed, 
stat(filepath, &buff); //where buff is a struct stat type
it's properties are accessed like :
- buff.st_mode - file type, those can be checked later with S_ISREG, S_ISDIR (see man 7 inode)
- buff.st_uid - user id of owner
- buff.st_size,
- buff.st_atim - access time,
- buff.st_nlink -number of hardlinks to the file
