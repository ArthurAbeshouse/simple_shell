## Simple Shell
A simple Unix shell coded from scratch for the Low-level programming & Algorithm track at Holberton School, New Haven.

### Synopsis
In this repository you will find the code for simple shell that can interpret commands from the user. Sample commands that our simple shell supports include ```ls``` and ```pwd```. We've also created some built-in functions for use as well.

### Builtins
* ```exit``` exits shell (Usage: ```exit```)
* ```env``` prints environmental variables (Usage: ```env```)

### Description of what each file shows:
```
man_1_simple_shell ------------- man page for our simple shell
main.c ------------------------- shell starter
shell.h ________________________ holds prototypes of functions
_putchar.c ______________________ writes the character c to stdout
_realloc.c ______________________ reallocates memory block using malloc and free
_strcat.c _______________________ concatenates strings
_strcmp.c _______________________ compares two strings
_strcpy.c _______________________ copys the given string
_strdup.c _______________________ returns a pointer to a newly allocated space in memory
_strlen.c _______________________ Finds the length of a string
cmdhandler.c ____________________ handles paths and determines if a command exists
execute.c _______________________ executes the users command
filter.c ________________________ handles built-ins
puts.c __________________________ takes the string and prints to standard output
strwordcount.c __________________ counts the number of words
token.c _________________________ tokenizes a string and returns an array of tokens
```
## How to install
```
git clone https://github.com/ArthurAbeshouse/simple_shell.git
cd simple_shell
gcc  -Wall  -Werror  -Wextra  -pedantic  *.c  -o  hsh
```
## Authors :
* [Arthur Abeshouse](https://github.com/ArthurAbeshouse)
* [Tim Sninsky](https://github.com/modernfuthark)