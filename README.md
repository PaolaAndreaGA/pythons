# 0x15. C - Simple Shell

## Description.
A Unix shell is a command-line interpreter or shell that provides a command-line
user interface for Unix-like operating systems. It is used by the operating
system to control the execution of the system using shell scripts.
This program provides a user interface that simulates a command interpreter,
generating standard outputs such as sh or bash.

---
## Instructions

To have this shell emulator follow the steps below.

* Use any of the following commands to clone the repository.
```sh
git@github.com:lahincapie/simple_shell.git
```
```sh
git@github.com:PaolaAndreaGA/simple_shell.git
```
```sh
git@github.com:angelikrussi/simple_shell.git
```

* To compile the program use the following command.
```sh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
---

## Examples

* To use the terminal in an interactive mode:

##### Entry
```sh
% ./hsh
$: ls
```
##### Output
```sh
README.md		checker.c		mandatory.c		prompt.c		shell.c
$:
```
##### Entry
```sh
% ./hsh
$: ls -l
```
##### Output
```sh
total 296
-rw-r--r--  1 lahincapie  admin   5123 Aug 24 14:09 README.md
-rw-r--r--  1 lahincapie  admin   1640 Aug 23 07:53 checker.c
-rw-r--r--  1 lahincapie  admin    962 Aug 21 21:45 exe.c
-rwxr-xr-x  1 lahincapie  admin  51368 Aug 24 11:17 hsh
-rw-r--r--  1 lahincapie  admin    630 Aug 21 21:58 mandatory.c
$:
```

* To use the terminal in non-interactive mode.

##### Entry
```sh
% echo "/bin/ls" | ./hsh
```

##### Output
```sh
README.md		checker.c		mandatory.c		prompt.c		shell.c
%:
```
##### Entry
```sh
% echo "/bin/ls -l" | ./hsh
```

##### Output
```sh
total 296
-rw-r--r--  1 lahincapie  admin   5123 Aug 24 14:09 README.md
-rw-r--r--  1 lahincapie  admin   1640 Aug 23 07:53 checker.c
-rw-r--r--  1 lahincapie  admin    962 Aug 21 21:45 exe.c
-rwxr-xr-x  1 lahincapie  admin  51368 Aug 24 11:17 hsh
-rw-r--r--  1 lahincapie  admin    630 Aug 21 21:58 mandatory.c
%:
```

## Files

File | Description
---|---
[shell.h] | Header.
[shell.c] | entry point and executes the shell.
[support.c] | Helper function.
[prompt.c] | Prompt declaration.
[checker.c] | Mandatory structure.
[mandatory.c] | Mandatory Function.
[path.c] | route search functions.
[exe.c] | execution functions.

---

## Requirements

* Allowed editors: vi, vim, emacs
* All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the * options -Wall -Werror -Wextra -pedantic -std=gnu89
* All your files should end with a new line
* A README.md file, at the root of the folder of the project is mandatory
* Your code should use the Betty style. It will be checked using betty-style.* pl and betty-doc.pl
* Your shell should not have any memory leaks
* No more than 5 functions per file
* All your header files should be include guarded
* Use system calls only when you need to (why?)

---
## Project objectives
### Tasks mandatory.

0. README, man, AUTHORS
    * Write a README
    * Write a man for your shell.
    * You should have an AUTHORS file at the root of your repository, listing
    all individuals having contributed content to the repository. Format,
    see Docker.

1. Betty would be proud
    Write a beautiful code that passes the Betty checks.

2. Simple shell 0.1
    Write a UNIX command line interpreter.
        * Usage: simple_shell
    Your Shell should:
        * Display a prompt and wait for the user to type a command. A command
	line always ends with a new line.
        * The prompt is displayed again each time a command has been executed.
        * The command lines are simple, no semicolons, no pipes, no redirections
	or any other advanced features.
        * The command lines are made only of one word. No arguments will be
	passed to programs.
        * If an executable cannot be found, print an error message and display
	the prompt again.
        * Handle errors.
        * You have to handle the “end of file” condition (Ctrl+D)
    You don’t have to:
        * use the PATH
        * implement built-ins
        * handle special characters : ", ', `, \, *, &, #
        * be able to move the cursor
        * handle commands with arguments.

3. Simple shell 0.2
    Simple shell 0.1 +
        * Handle command lines with arguments

4. Simple shell 0.3
    Simple shell 0.2 +
        * Handle the PATH
        * fork must not be called if the command doesn’t exist

5. Simple shell 0.4
    Simple shell 0.3 +
        * Implement the exit built-in, that exits the shell
        * Usage: exit
        * You don’t have to handle any argument to the built-in exit

6. Simple shell 1.0
    Simple shell 0.4 +
        * Implement the env built-in, that prints the current environment

7. What happens when you type `ls -l *.c` in the shell
    Write a blog post describing step by step what happens when you type ls -l
 *.c and hit Enter in a shell. Try to explain every step you know of, going in
as much details as you can, give examples and draw diagrams when needed. You
 should merge your previous knowledge of the shell with the specifics of how it
 works under the hoods (including syscalls).
        * Have at least one picture, at the top of the blog post
        * Publish your blog post on Medium or LinkedIn
        * Share your blog post at least on LinkedIn
        * Only one blog post by team
        * The blog post must be done and published before the first deadline
 (it will be part of the manual review)
        * Please, remember that these blogs must be written in English to
 further your technical ability in a variety of settings
    When done, please add all urls below (blog post, LinkedIn post, etc.)

---
## Authors
* **Paola García** - [PaolaAndreaGA](https://github.com/PaolaAndreaGA)
* **Estefanía Russi** - [angelikrussi](https://github.com/angelikrussi)
* **Alejandra Hincapie** - [lahincapie](https://github.com/lahincapie)