#ifndef HEADER_H
#define HEADER_H

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
char **strtow(char *str);
size_t print_dlistint(const stack_t *h);
size_t dlistint_len(const stack_t *h);
void op_push(stack_t **head, unsigned int line_number);
void op_pall(stack_t **h, unsigned int line_number);
int add_dnodeint_end(stack_t **head, const int line_number);
<<<<<<< HEAD
void free_all(stack_t *head, char *line, FILE *fp);
=======
void free_stack_t(stack_t *head);
>>>>>>> 6d544cda38ef088b9ba66475dee8d7f89e388bed
stack_t *get_dnodeint_at_index(stack_t *head, unsigned int index);
int sum_dlistint(stack_t *head);
stack_t *insert_dnodeint_at_index(stack_t **h, unsigned int idx, int n);
char **strtow(char *str);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);
void rm_nl(char **lineptr);
void free_global_struct(global_struct_t *ptr);
global_struct_t *create_global_struct(unsigned int linenumber, char *line);
int _strlen(char *s);
int wordcount(char *str);
void (*get_op_func(char *s))(stack_t **head, unsigned int linenumber);

#endif
