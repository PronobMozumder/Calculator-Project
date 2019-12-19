#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
void main()
{
    char input[256];
    char number_string[30];
    char op = 0;
    int index = 0;
    int to = 0;
    size_t input_length = 0;
    unsigned int number_length = 0;
    double result = 0.0;
    double number = 0.0;
    int n;


    printf("*************************************************************************************************************************************************************\n");
    printf("*\t \t \t **         **         **  **********  ***         **********      ******      ***       ***  **********                            *\n");
    printf("*\t \t \t  **       ****       **   ***         ***         **********    **      **    ** **   ** **  ***                                   * \n");
    printf("*\t \t \t   **     **  **     **    ********    ***         ***          **        **   **  ** **  **  ********                              * \n");
    printf("*\t \t \t    **   **    **   **     ********    ***         ***          **        **   **   ***   **  ********                              * \n");
    printf("*\t \t \t     ** **      ** **      ***         *********   **********    **      **    **    *    **  ***                                   * \n");
    printf("*\t \t  \t      ***        ***       **********  **********  **********      ******      **         **  **********                            *\n");
    printf("*************************************************************************************************************************************************************");
    printf("\n\t\t\t\t**********You can use this calculator,By enter any expression with" " or without spaces.**********");
    printf("\n*************************************************************************************************************************************************************\n");
    printf("\n\t\t#You may include this operators:\n");
    printf("\t\t\t\t\t    **********************************************************");
    printf("\n \t\t\t\t\t    *         +, -, *, /, %%, or ^(raise to a power).         *\n");
    printf("\t\t\t\t\t    **********************************************************\n");
    printf("\t\t\t NOTE:-\n");
    printf("\n\t\t\t     1.Use (A) at the beginning of a line to operate on the result of the previous calculation. Here A means Ans. ");
    printf("\n\t\t\t     2.Use (STOP) to stop the calculator.\n\n");





    while(strcmp(gets(input), "STOP") != 0)
    {
        input_length = strlen(input);


        for(to = 0, index = 0 ; index<=input_length ; index++)
            if(*(input+index) != ' ')
                *(input+to++) = *(input+index);

        input_length = strlen(input);
        index = 0;

        if(input[index]== 'A')
            index++;
        else
        {
            number_length = 0;
            if(input[index]=='+' || input[index]=='-')
                *(number_string+number_length++) = *(input+index++);


            for( ; isdigit(*(input+index)) ; index++)
                *(number_string+number_length++) = *(input+index);


            if(*(input+index)=='.')
            {

                *(number_string+number_length++) = *(input+index++);

                for( ; isdigit(*(input+index)) ; index++)
                    *(number_string+number_length++) = *(input+index);
            }
            *(number_string+number_length) = '\0';


            if(number_length>0)
                result = atof(number_string);
        }


        for(; index < input_length;)
        {
            op = *(input+index++);


            number_length = 0;


            if(input[index]=='+' || input[index]=='-')
                *(number_string+number_length++) = *(input+index++);


            for( ; isdigit(*(input+index)) ; index++)
                *(number_string+number_length++) = *(input+index);


            if(*(input+index)=='.')
            {

                *(number_string+number_length++) = *(input+index++);
                for( ; isdigit(*(input+index)) ; index++)
                    *(number_string+number_length++) = *(input+index);
            }
            *(number_string+number_length) = '\0';


            number = atof(number_string);


            switch(op)
            {
            case '+':
                result += number;
                break;
            case '-':
                result -= number;
                break;
            case '*':
                result *= number;
                break;
            case '/':
                if(number == 0)
                    printf("\n\n\aDivision by zero error!\n");
                else
                    result /= number;
                break;
            case '%':
                if((long)number == 0)
                    printf("\n\n\aDivision by zero error!\n");
                else
                    result = (double)((long)result % (long)number);
                break;
            case '^':
                result = pow(result, number);
                break;
            default:
                printf("\n\n\aIllegal operation!\n");
            }
        }
        printf("= %.2f\n", result);
    }
}
