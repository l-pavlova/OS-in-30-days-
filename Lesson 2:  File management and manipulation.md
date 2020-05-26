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
-```tar
  -c create arcive
  -x extract
  -caf -create Auto format, Files specified
  ```
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
https://github.com/l-pavlova/OS-in-30-days-/blob/master/Lesson%202:%20tasks2.md
