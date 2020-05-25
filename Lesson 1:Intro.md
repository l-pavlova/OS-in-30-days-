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

- ```su``` – change user ID (or become superuser)

-``` su -, su -l, su --login``` – provide environment

- ```sudo``` – execute a command as another user

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
