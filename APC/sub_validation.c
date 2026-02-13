#include "apc.h"


unsigned int calculate_length(const char *str)
{
    
    unsigned int i = 0;

    while (str[i] != '\0')
    {
        i++;
    }

    return i;
}

int sign_flag = 0;

int sub_validation(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, char *argv[])
{
    remove_leading_zeros(argv[1]);
    remove_leading_zeros(argv[3]);

    unsigned int len1 = calculate_length(argv[1]);
    //printf("length1 = %d\n", len1);
    
    unsigned int len2 = calculate_length(argv[3]);
    //printf("length2 = %d\n", len2);


    char *str1, *str2;
    if (len1 < len2)
    {
        str1 = argv[3];
        str2 = argv[1];
        sign_flag = 1;

    }
    else if (len1 > len2)
    {
        str1 = argv[1];
        str2 = argv[3];
    }
    else
    {

        if (strcmp(argv[1],argv[3]) < 0)
        {
            str1 = argv[3];
            str2 = argv[1];
            sign_flag = 1;
        }
        else if (strcmp(argv[1],argv[3]) > 0)
        {
            str1 = argv[1];
            str2 = argv[3];
        }
        else
        {
            str1 = argv[1];
            str2 = argv[3];
            sub_div_digit_to_list(head1, tail1, head2, tail2, str1, str2);
            printf(CYAN);
            printf("Result : 0\n");
            printf(RESET);
            return 1;

        }

    
    }
    sub_div_digit_to_list(head1, tail1, head2, tail2, str1, str2);

    // subtraction(head1, tail1, head2, tail2, headR, tailR);
    return SUCCESS;
}