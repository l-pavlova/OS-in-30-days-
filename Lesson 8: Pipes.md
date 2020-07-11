# Pipes #

- read doesn't care for null terminators, read(fd, "abc\0defg",9) will read the whole thing, if we try to printf it, only the first charc before the null term will show up, however the buffer has everything inside. Read only cares about end of file!

- Pipes: a pipe that u can just write and read from, defined with 2 fd-s.

- ls /proc/3450/fd -l -if we create a pipe we can check it's fd by checking the pid

- dup - gets the first free fd and passes it to the pipe 
```dup(pipefd[1]);```
```dup2(pipefd[0], 0);```
- always close unused ends, following operations cannot be completed otherwise!
- if a fd is closed in the parent, its children won't inherit it at all.
- ctrl +d === END OF FILE

- errno - global variable contains error number(obv)




