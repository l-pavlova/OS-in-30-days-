# Pipes #
- Exec - runs the program we tell it to run, replaces the current program with the one we passed but keeps the same environment, the file-descriptors and the general state of the current process are copied in the new one.
- Fork - creates a copy of the current process, a child htat inherits it's file descriptors and continies execution from where we were in the parent.
- If we are in the child the int pid is 0, then we are in the child process, if its > 1 then we are in the parent, if it's less than failed to fork //int pit = fork()

- Wait - waits for sth in the child process(usually wait for the child to die), Alternatively parent dies before child, the child is orphan for a short time and another process becomes parent of the orphan(that is usually the process init)
