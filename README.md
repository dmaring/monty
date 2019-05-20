# Monty Language Interpreter
Monty 0.98 is an interpreter for Monty bytecode files. The data is saved on a stack and uses built-in commands to manipulate it.
______________________________________________________________________________


## Usage
______________________________________________________________________________

All files should be compiled with > gcc -Wall -Werror -Wextra -pedantic *.c -o monty.

> monty file

## Example:

### Structure of a Monty bytecode file:

>  push 1
> 
>  push 2
> 
>  push 3
> 
> pall
>
> pint

### Output

>  3
> 
>  2
>
> 1
> 
>  3
