# Lesson 4:Processes

- PID (Process ID) -identifies every process
- priority & nice value  [-20 highest priority,19 lowest] , default=0
- memory - every process has access to only certain memory, if it tries to access unavailable it gets killed
- security context - access privileges of the process 
- environment - shell and envrionment vars that proceses can access
- file handles (file descriptors) - A file descriptor is a number that uniquely identifies an open file in a computer's operating system. It describes a data resource, and how that resource may be accessed.

**Process creation**
- kernel -running processes are in the kernel
- init (PID 1) -when the os is started, the first process is initiated with PID 1
- child process gets created by a parent process with fork() or dup()
- ps & pstree -shows the processes
- fork() - creates exact copy of a process with a different PID, and had parent id PID of the process it was forked from, is called child process
- exec() - runs cmd in shell


**Process states**
- R running/runnable (on run queue)
- D uninterruptable sleep (usually IO)
- S interruptible sleep (waiting for an event to complete)
- T stopped, either by a job control signal or because it is being traced
- Z defunct (“zombie”) process, terminated but not reaped by its parent

**Viewing processes**
- ``` /proc```
- ``` ps``` shows processes for current session
- ``` ps -e``` shows all processes for all users logged in the machine right now
- ``` ps -ef```shows all process with security process id and parent process id
- ``` ps -u pesho```
- ``` ps -e -o user,pid``` -o for output columns
- ``` ps -u pesho -o pid=process,user=account``` for user pesho 
- ```ps aux```- shows metadata in unix format
- ``` ps -u pesho -o pid= -o user=```
- ``` BSD (aux) vs. SysV (aef)```
- ``` top, htop, atop``` -interactive, shows info about the os and its current state, the processes usually in S state

**Signals**
- special message that can be sent to a process, a way for processes to comunicate with each other
- signal handlers - callbacks for the last sent signal
- some signals cannot be caught or ignored and are processed by the kernel

**Signals**

- SIGHUP(1) 
- SIGINT(2) 
- SIGQUIT(3) 
- SIGKILL(9) -kill process
- SIGSEGV(11)
- SIGTERM(15) -terminate process
- SIGSTOP(19)

**Sending signals**
- ```kill <pid>``` -by default send SIGTERM(15)
- ```-l lists``` all supported signals
- ```kill``` -KILL <pid> or kill -9 <pid>
- ```killall <name>``` - sends to all processes from keyboard
- ```Ctrl-C``` - SIGINT(2)- stops process gently
- ```Ctrl-Z``` - SIGSTOP(19)-stops not so gently
  
**Job control** 
- suspend and resume
- kernel support & user interface
- running (in foreground)
- stopped
- running in background
- SIGSTOP & SIGCONT

- ```foo &``` - a process can be told to run in background from its first call 
- ```Ctrl-Z``` - SIGSTOP
- ```jobs``` - shows which processes are stopped in T state
- ```fg <id>``` -resumes process in foreground
- ```bg <id>``` -resumes process in background
