# Pipes #
- Exec - runs the program we tell it to run, replaces the current program with the one we passed but keeps the same environment, the file-descriptors and the general state of the current process are copied in the new one.

Man 3 exec 
```
execl("/bin/ls", "ls", "/etc", "/bin", (char*) NULL); //the null terminator is important bc the arguments are like param[], basically passes arguments to the command until the terminator is passed

execlp - will try to find the command without the absolute path
execl("ls", char* args[];

execlp("sleep", "name", "100", NULL);
```


- Fork - creates a copy of the current process, a child htat inherits it's file descriptors and continies execution from where we were in the parent.
- If we are in the child the int pid is 0, then we are in the child process, if its > 1 then we are in the parent, if it's less than failed to fork 
```
int pid = fork();
```

- Wait - waits for sth in the child process(usually wait for the child to die), Alternatively parent dies before child, the child is orphan for a short time and another process becomes parent of the orphan(that is usually the process init, and that one waits for the child process or doesn't at all).
The child process leaves some state in the os in case the parent wants to know what happened. 
When the child has died, it waits for the parent to read what happened to it, while the parent is still alive, the child is a zombie. When the parent dies too, the child becomes a zombie orphan and is cleared immediately.
wait(int buff);
```
int pid=fork();
if(pid == 0) {
  execlp("sleep","sleep", "100", NULL);
} else {
  wait(&buff);
  if(WIFEXITED(buff)) { //from man 2 wait
    printf("exited normally with: %d\n", WEXITSTATUS(buff));
  } else if(WIFSIGNALED(buff)) {
    printf("exited with signal %d\n", WTERMSIG(buff));
  }
```


