# OS-in-30-days
learning os concepts for the os uni course from the start with me

# Lesson 1:Intro

BASH = Bourne-Again SHell

A shell is simply a macro processor that executes commands.

**Types of terminals**
- serial 

- virtual (TTY, PTY, PuTTY)

- GUI

- network login

**Login session info**
- User ID (UID)

- Group ID (GID)

- privileged user – root, UID 0
```
whoami 
```
- displays the username of the current user when this command is invoked.

- id
```
 tty
```
--The tty command will print the name of the device file that your pseudo-teletype slave is using to interface to the master. And that, effectively, is the number of your terminal window.

**Switching user**

- su – change user ID (or become superuser)

- su -, su -l, su --login – provide environment

- sudo – execute a command as another user

**Help**
```
 foo --help, foo -h
```
```
 man [section] foo
```
1 Executable programs or shell commands

2 System calls (functions provided by the kernel)

3 Library calls (functions within program libraries)

4 Special files (usually found in /dev)

5 File formats and conventions eg /etc/passwd

6 Games

7 Miscellaneous

8 System administration commands (usually only for root)

9 Kernel routines [Non standard]

- search through man pages for matches

- whatis (man -f) - manual page descriptions

- apropos (man -k) - search the manpage names and descriptions

- info

# Lesson 2: File management and manipulation

**Filesystem standard (FHS)**

- Guiding principles for each area of filesystem

- Predictable location of files and directories

- Provides uniformity across multiple Linux distributions

**Navigating the filesystem**

-  absolute vs. relative addressing
-  changing and displaying directories (cd, pwd)
- ```cd``` by itself or cd ~ will always put you in your home directory.
- ```cd``` . will leave you in the same directory you are currently in (i.e. your current directory won't change). 
- ```cd ~username``` will put you in username's home directory.
- ```cd dir``` (without a /) will put you in a subdirectory; for example, if you are in /usr, typing cd bin will put you in /usr/bin, while cd /bin puts you in /bin.
- ```cd ..``` will move you up one directory. So, if you are /usr/bin/tmp, cd .. moves you to /usr/bin, while cd ../.. moves you to /usr (i.e. up two levels).
- ```cd -``` will switch you to the previous directory. For example, if you are in /usr/bin/tmp, and go to /etc, you can type cd - to go back to /usr/bin/tmp. You can use this to toggle back and forth between two directories.

**Displaying directory contents**
- human-readable
- ls
- ```ls -a``` - show all files (including .hidden files)
- ```ls -l``` - long listings
- ```ls -d``` - show directories, not contents
- ```touch foo``` -command used to update the access date and/or modification date of a computer file or directory. 
- ```mkdir bar```
**File {group,}ownership**
- each file is owned by a specific UID and GID
- chown - change the user (UID) ownership
- only root can change ownership to another user
- ```chown foo:bar```
- ```chgrp``` - modify just the group (GID) ownership
- ```chown :bar```
- newly created files will usually be given GID ownership based
on the current active group of the person who creates the file
**File permissions**

*type of file*

- - - regular file
- b - block special file
- c - character special file
- d - directory
- l - symbolic link
- p - FIFO (named pipe)
- s - socket

*permision sets*
- user (owner)
- group (group owner)
- everyone else (other)
- symbolic representation rwxr-xr-x
- numeric representation 0755

**chmod**
- numeric notation ```chmod 0664 foo.txt```
- symbolic notation ```chmod u=rw,g=rw,o=r foo.txt```
- ```chmod -R ```
**umask**

- Default permissions for newly created filesystem objects
- files 666
- directories 777
- ```umask``` defines what permissions to withhold from the default
permissions

**Directory and file manipulation**
- ```mkdir foo```
- ```mkdir -p foo/bar``` -creates dir with all the parent dirs needed
- ```mkdir -m``` - mode=MODE set file mode (as in chmod), not a=rwx - umask
- ```rmdir``` removes dir
- ```cp``` copies from source to dest
- ```mv``` moves from source to dest
- ```rm``` 
- ```touch``` - mtime/atime
Tasks
