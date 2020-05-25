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

**Filesystem hard links**
- a directory entry that references the same inode as another
directory entry
- can’t span filesystems
- can’t create hard links to non-existent file
- can’t reference directories
- do not occupy storage space (i.e. blocks)
- ```ln [option]...``` target link_name
- ```ls -i```- -inode print the index number of each file

**Filesystem symbolic links**
- a file that references another file via path and name
- can reference directories
- can span filesystems
- can reference non-existent files
- ```ln -s ``` target link_name
- occupy space
- symlink / soft link
```df, du, stat```
- ```df``` Report disk space usage per filesystem
- ```-h``` human readable output
- ```-i``` list inode information instead of block usage
- ```-T``` include filesystem type
- ```--si``` use powers of 1000 instead of 1024
- ``` -P``` use the POSIX output format
- ``` du``` Report disk usage per file and directory
- ``` -h``` human readable sizes
- ``` -s``` summarize, only display total for each argument
- ``` -x``` do not include files on a different filesystem
- ``` --si ```use powers of 1000 instead of 1024
- ``` stat dir1```display file or file system status
- ``` -L``` follow links
- ``` -c``` --format
**File extensions and content**
- file extensions are just part of the file name
- some applications may care about extensions
- ```file``` - reports the type of file by examining the file contents
- /usr/share/file/magic.mgc

**Displaying text files**
- ``` cat ```- concatenate files and print on the standard output
- ``` more ```
- ``` less ```
- ``` head ``` show top ten from file
- ``` tail ```show last ten from file
- ``` tail -f```
- ``` -n```

**Displaying binary files**
- displaying raw binary data may corrupt the display terminal
- ```strings``` - displays ASCII text inside binary files
- ```xxd``` - displays HEX and ASCII dump of file, important for file proscessing in c too
- clear
**```xargs```**
By default xargs reads items from standard input as separated by blanks and executes a command once for each argument. 
- ```xargs [options] [command [initial-arguments]]```
- delimited by blanks or newlines
- executes the command (/bin/echo)
- one or more times
- with any initial-arguments
- followed by items read from standard input
- -0, --null
- -I
- -n
examples:
In the following example standard input is piped to xargs and the mkdir command is run for each argument, creating three folders.
```
echo 'one two three' | xargs mkdir
ls
one two three
```
In the following example files older than two weeks in the temp folder are found and then piped to the xargs command which runs the rm command on each file and removes them.

```find /tmp -mtime +14 | xargs rm```
**xargs v exec**

The find command supports the -exec option that allows arbitrary commands to be performed on found files. The following are equivalent.
```
find ./foo -type f -name "*.txt" -exec rm {} \; 
find ./foo -type f -name "*.txt" | xargs rm
```

**Searching the filesystem**
- machine-readable
- ```find [options] [starting-point] [expression]```
- global/positional options
- -o, -a (default)
- actions
- ```-print vs -print0 vs -printf``` is for displaying files per the contents of the mailcap file,
- ```-ls``` list directory constents 
- ```-exec```  The  exec()  family of functions replaces the current process image with a new process  image.
- ```find /foo -name bar -print```

**Archiving & compressing** 
- archiving
- tar
- cpio
- compressing
- compress
- gzip
- bzip2
- lzma
- xz

**Archives with tar**

- manipulates .tar files (tarballs)
- used for backup and transfer of files
- tar cvf foo.tar ./foo/*
- GNU tar supports built-in compression methods
- -a, --auto-compress
- .tar (tarball)
- records file and directory structure
- includes metadata about the file: date, timestamps,
ownership, permissions, etc.
XZ Utils
- xz
- .xz
- unxz / xzcat / xz -d
- compression format of choice

Tasks
https://github.com/l-pavlova/OS-in-30-days-/blob/master/tasks2.md

# Lesson 3:Text processing

**File redirection**

- ```cmd >file``` redirects stdout to a file
- ```cmd 2>file``` redirects stderr to a file (overwrite)
- ```cmd 2>/dev/null``` discard stderr of cmd
- ```cmd <file``` pass file to stdin of cmd
```cmd <EEOL \n line1 \n line2 \n EOL``` pass file to stdin of cmd
- ```{cmd1; cmd2;}>file ```
- ```cmd1|cmd2``` pass stdout of cmd1 to stdin of cmd2
- ```cmd1 2>&1 |cmd2 ``` stdout and stderr
- ```cmd |tee file``` redirect stdout to a file and print it to the screen

examples:
-``` sort < /etc/passwd```
-``` echo 100000 > /proc/sys/fs/file-max```
-``` ls -alR /proc/ 2> /dev/null```
-``` ls -R /proc/ > output 2>&1```
-``` ls -R /proc/ &> output```

summary:
```
- < STDIN from a file
- > STDOUT to a file (overwrite)
- >> STDOUT to a file (append)
- 2> STDERR to a file (overwrite)
- 2>> STDERR to a file (append)
- &> both STDOUT and STDERR
```
**Piping commands together**
- ls -al | less
- cut -d: -f6 /etc/passwd|sort|uniq -c|sort -rn
- redirection and piping can be combined
- usually used for feeding STDERR into the pipeline along with STDOUT

**Combining files and merging text**
- ```cat - concatenate files
- ```paste ```- merges text from multiple files
            -s option to merge files serially
            - uses tabs as default delimiter
- ```wc``` - print line, word, and byte counts for each file

       -c, --bytes - print the byte counts
       
       -m, --chars - print the character counts
       
       -l, --lines - print the newline counts
       
       -w, --words - print the word counts

- ```cut``` - extracts sections from each line of files

- ```grep``` searches for patterns within files

         -n shows line numbers
         
         -A NUM prints match and NUM lines after match
         
         -B NUM prints match and preceding NUM lines
         
         -C NUM prints match and NUM lines before and after
         
         -i performs case insensitive match
                  
         -v inverts match; prints what doesn’t match
         
         --color highlight matched string in color
                 
         
**The streaming editor**
 - ```sed``` - stream editor for filtering and transforming textq, usually the output of another program,  often used to automate edits on many files quickly, small and very efficient
 
           -i option for in place edits with modern versions
           
-```tr a-z A-Z``` translates one set of characters into another(Replacing text characters with tr)
               squeeze collapses duplicate characters
               ```tr -s '\n'```
               deletes a set of characters
               ```tr -d '\000'```

**Text processing with awk**
- ```awk``` - pattern scanning and processing language
- splits lines into fields (like cut)
- regex pattern matching (like grep)
- math operations, control statements, variables,IO

examples:

    -  awk '{ print $1 }' 
    -  awk -F ':' '$1 ~ "foo" { print $2 }'
    -  awk '$1 != 1 { print $2 }'
    -  awk '{ sum += $1 } END { print sum }'
    -  awk -v "foo=${BAR}" '....'
   
**Text sorting**
- ```sort``` sorts text, can sort on different columns

      -  -k, --key=KEYDEF
      -  -t, --field-separator=SEP
     
- by default sorts in lexicographical order aka  1, 2, 234, 265, 29, 3, 4, 5
- can be told to sort numerically (-n) aka 1, 2, 3, 4, 5, 29, 234, 265
- can merge and sort multiple files simultaneously
- can sort in reverse order -r
- often used to prepare input for the uniq command

**Duplicate removal utility**
- ```uniq``` - removes duplicate adjacent lines from sorted text
-  -c - prefixes each line of output with a number indicating number of occurrences

**Filename matching**
- many commands take a list of filenames as arguments
- wildcard patterns,  “file globbing”

**Wildcard patterns**
- ? - matches any single character
- * - matches anything (any number of characters)
- [...] - character classes
- the - character denotes a range
- examples: [abcd2345] [a-d2-5] [a-gA-Z0-5]

**Brace expansion**
- allows generation of arbitrary strings
- similar to wildcards, but target files or directories don’t need to exist
- {m,n,o,on} expands to: m, n, o and on
- b{a,o,u,e,i}g expands to: bag, bog, bug, beg, big
- can be combined with wildcards; brace expansion occurs before globbing

**General quoting rules**

- metacharacters \ ? ( )-executes first the comand inside $-gets value of variable ... * % { } [ ]
- backslash \ - supresses one character, that character doesn't get read e.g new line
- double Quotes " " runs string as code, notices $ and ``
- single Quotes ' ' runs string without special characters

**Nesting commands**

- command substitution - substitutes output of command in place of “embedded” command-
- `command` - do not use
- $(command) - preferred method

**Multiple and multi-line commands**

- entering multiple commands on one command line
- separate commands with a semi-colon ;
- entering multi-line commands
- use backslash \
- line wrapping / continuation
**Regular expressions**

- Regular Expressions (REs) provide a mechanism to select specific strings from one or more lines of text
- grep, sed, perl, …
- man 7 regex
- most characters, letters and numbers match themselves
- special characters are matchable
- . matches any single character
- specify where the match must occur with anchors

- \t tab
- \n newline/line feed
- \r carriage return
- \f form feed
- \c control characters
- \x character in hex
- . any single character

**RE anchors**

- ^RE anchor RE at start of line
- RE$ anchor RE at end of line
- \<RE anchor RE at start of word
- RE\> anchor RE at end of word

**RE character classes**

- Character classes, [...], match any single character in the list
- RE [0123456789] matches any single digit
- Some predefined character classes
- [:alnum:] [:alpha:] [:cntrl:] [:digit:]
- [:lower:] [:punct:] [:space:] [:upper:]
- The - character denotes a range
- RE [[:alnum:]] equivalent to [0-9A-Za-z]

**RE character classes examples**
- grep [[:upper:]] /etc/passwd
- egrep '^[rb]' /etc/passwd
- egrep '^[^rb]' /etc/passwd

**RE quantifiers**
- Control the number of times a preceding RE is allowed to match
- * match 0 or more times
- + match 1 or more times
- ? match 0 or 1 times
- {n} match exactly n times
- {n,} match at least n times
- {n,m} match at least n but not more than m times

      egrep '^[stu].{14}$' /usr/share/dict/words
      egrep '^[aeiou].{9}ion$' /usr/share/dict/words
      egrep '^c.{15,}$' /usr/share/dict/words
      egrep '^n.{6,10}c$' /usr/share/dict/words
**RE parenthesis**

- (RE) creating a new atom
- (RE)\n non-zero digit - storing values
- (RE1|RE2) alternation: RE1 or RE2
- abc{3} vs. (abc){3}
   ```$ cat file```
Parenthesis allow you to store matched patterns.
```$ sed -r 's/(.)\1/\[\1\1\]/g' file```
Parenthesis a[ll]ow you to store matched
pa[tt]erns.
```egrep '(dog|cat)' file```

**Text editing**

vi / vim
- vi The Visual Editor
- :help
Basic vi
- Insert Mode:  i keystrokes are inserted into the document
- Command Mode:  esc keystrokes are interpreted as commands
- hjkl up down left right
- i a [ESC] x dd
- Saving & exiting
- :w safe
- :q quit
- :wq safe and quit
- :wq!

               -c - characters
               
               -f - fields
               
               -d - delimiter (TAB)
               
 most useful on structured input (text with columns), cannot change order (𝑁 ≤ 𝑀)
