/*

NAME : Jami Charan Teja
DATE : 24-02-2025
DESCRIPTION : ARBITRARY PRECISION CALCULATOR
STUDENT ID : 24021_245

*/

#include "apc.h"



int main(int argc, char *argv[])
{
	/* Declare the pointers */
      
	Dlist *head1=NULL, *tail1=NULL;
	Dlist *head2=NULL, *tail2=NULL; 
	Dlist *headR=NULL,*tailR=NULL;

    if(validation_args(argc,argv) == FAILURE)
	{
		printf(RED "INFO : Validation Failure :-(\n" RESET);
		printf("\nHELP : Give CLA -> ./a.out <operand1> <operator> <operand2>\n");
		printf("\nDESCRIPTION : \n");
		printf("<operand1> & <operand2> should be positive integer values\n");
		printf("<operator> can be one of the following : '+', '-', 'x', '/'\n");
		return FAILURE;
	}
    int ret;
	char operator=argv[2][0];


		switch (operator)
		{
			case '+':

                add_mul_digit_to_list(&head1, &tail1, &head2, &tail2, argv);
				/* call the function to perform the addition operation */
                addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
				print_result(headR);
				break;
			case '-':	
				/* call the function to perform the subtraction operation */
				ret = sub_validation(&head1, &tail1, &head2, &tail2, argv);
				//subtraction(&head1,&tail1,&head2,&tail2,&headR,&tailR);
				if(!ret)
				{
					subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
					print_result(headR);
				}
				break;
			case 'x':	
				add_mul_digit_to_list(&head1, &tail1, &head2, &tail2, argv);
				/* call the function to perform the multiplication operation */
				multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR);
				print_result(headR);
				break;
			case '/':	
				ret = div_validation(&head1, &tail1, &head2, &tail2, argv);
				/* call the function to perform the division operation */
				if(!ret)
				{
					division(&head1, &tail1, &head2, &tail2, &headR, &tailR);
				}
				break;
			default:
				printf("Invalid Input:-( Try again...\n");
		}
	return 0;
}
