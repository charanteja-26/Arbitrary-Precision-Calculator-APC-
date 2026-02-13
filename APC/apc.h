#ifndef APC_H
#define APC_H

#include<stdio.h>
#include<string.h>
#include <ctype.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"

typedef struct node
{
	struct node *prev;
	int data;
	struct node *next;
}Dlist;

/* Include the prototypes here */


/* Function prototypes for list operations and arithmetic operations */

// Store the operands into the list
void add_mul_digit_to_list(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, char *argv[]);

// Store digits of operands into lists for subtraction and division
void sub_div_digit_to_list(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, char *str1, char *str2);

/* Arithmetic operations */

// Addition of two lists representing numbers
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

// Subtraction of two lists representing numbers
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

// Multiplication of two lists representing numbers
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

// Division of two lists representing numbers
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

/* Validation functions */

// Validate the command-line arguments
int validation_args(int argc, char *argv[]);

// Check whether the operand is a digit or not
int isstringdigit(char *argv);

/* List operations */

// Insert an element at the end of the list
int insert_at_last(Dlist **head, Dlist **tail, int data);

// Insert an element at the beginning of the list
int insert_at_first(Dlist **head, Dlist **tail, int data);

// Print the elements of the list
void print_list(Dlist *head);

// Delete the entire list
int dl_delete_list(Dlist **head, Dlist **tail);

// Print the result from the list
void print_result(Dlist *head);

/* Additional validation functions for specific operations */

// Validate operands for subtraction
int sub_validation(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, char *argv[]);

// Validate operands for division
int div_validation(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, char *argv[]);

/* Utility functions */

// Remove leading zeros from a string
void remove_leading_zeros(char *str);

// Calculate the length of a string
unsigned int calculate_length(const char *str);

// Calculate the length of the list
unsigned int list_length(Dlist *head);

int check_larger(Dlist *head1, Dlist *head2);


#endif
