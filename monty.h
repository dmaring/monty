#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **head, unsigned int line_number);
} instruction_t;


/**
 * struct global_struct_s -
 * @linenum: linenumber as integer
 * @line: pointer to string
 * @arglist: double pointer to list of line tokenized
 *
 * Description: global structure to hold common informatin
 */
typedef struct global_struct_s
{
        char *line;
        unsigned int linenumber;
	char **arg_list;
} global_struct_t;

extern global_struct_t *global_struct;


/* main_helpers.c */
void (*get_op_func(char *s))(stack_t **head, unsigned int linenumber);

/* str_helpers.c */
int _strlen(char *s);
void rm_nl(char **lineptr);
int wordcount(char *str);
char **strtow(char *str);

/* str_helpers_2.c */
int _atoi(int *num, char *s);
int _isnum(char c);

/* global_helpers.c */
global_struct_t *create_global_struct(unsigned int linenumber, char *line);
void free_global_struct(global_struct_t *ptr);

/* ll_helpers_1.c */
stack_t *add_dnodeint_end(stack_t **head, const int n);
void free_all(stack_t *head, char *line, FILE *fp);

/* ll_helpers_2.c */
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *get_dnodeint_at_index(stack_t *head, unsigned int index);
stack_t *insert_dnodeint_at_index(stack_t **h, unsigned int idx, int n);
void delete_dnodeint_at_index(stack_t **head, unsigned int index);
size_t dlistint_len(const stack_t *h);

/* op_helpers_1 */
void op_push(stack_t **head, unsigned int line_number);
void op_pall(stack_t **h, unsigned int line_number);
void op_pop(stack_t **head, unsigned int line_number);
void op_pint(stack_t **head, unsigned int line_number);
void op_nop(stack_t **head, unsigned int line_number);

/* op_helpers_2 */
void op_add(stack_t **head, unsigned int line_number);
void op_div(stack_t **head, unsigned int line_number);
void op_sub(stack_t **head, unsigned int line_number);
void op_mod(stack_t **head, unsigned int line_number);
void op_mul(stack_t **head, unsigned int line_number);

#endif
