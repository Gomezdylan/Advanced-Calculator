#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<limits.h>

int main(){

    // Initializations
    char input[100];
    signed int number1;
    char temp[100];
    char temp2[100];
    char temp3[100];
    char temp4[100];
    char temp5[100];
    char temp6[100];
    char operand[100];
    char answer[1025];
    int temp_index = 0;
    int ch;
    signed int number2;
    int choice;
    signed int result;
    char operator;
    int MAX_LENGTH = 1024;
    int operand_length;
    int total_length;
    int check = 1;


    // Instructions
    while(check){
    printf("(1) You can enter two integers (2) You can enter an integer and a string\n"); 


    scanf("%d", &choice);
    getchar(); // Clears extra stuff from scanf
    if(choice == 1){
        printf("Enter a problem ");
        printf("(e.g 24+5)\n");
        while((ch = getchar()) != '\n' && ch != EOF){
            if(isdigit(ch) || ch == '-' && temp_index == 0){
                temp[temp_index++] = (unsigned char)ch;
            } else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%'){
                    temp[temp_index] = '\0';
                    number1 = atoll(temp);
                    operator = ch;
                    break;
            } else{
                printf("Invalid input: There was a space in the code or a non-integer");
                while ((ch = getchar()) != '\n' && ch != EOF); // Clear buffer
                temp_index = 0;
                memset(temp, 0, sizeof(temp));  // Clear temp
                break;
            }
            
        }
        if(number1 > INT_MAX || number1 < 0){
            printf("Invalid number: It exceeds the bounds\n");
                continue;
        }
        temp_index = 0;
        while((ch = getchar()) != '\n' && ch != EOF){
            if(isdigit(ch) || ch == '-' && temp_index == 0){
                temp2[temp_index++] = (unsigned char)ch;
                } 
             else{
                printf("Invalid input: There was a space in the code or a non-integer\n");
                printf("Add something else to the first part of your number. Only two inputs are allowed: ");
                while ((ch = getchar()) != '\n' && ch != EOF); // Clear buffer
                temp_index = 0;
                memset(temp2, 0, sizeof(temp2));  // Clear temp
                continue;
            }
        }
        temp2[temp_index] = '\0';
        number2 = atoll(temp2);

        if(number2 > INT_MAX || number2 < 0){
            printf("Invalid number: It exceeds the bounds\n");
            continue;
        }
        temp_index = 0;

        // now perform the case

        switch(operator){
            case '+':
            if ((number1 > 0 && number2 > 0 && (INT_MAX - number1 < number2)) ||
                (number1 < 0 && number2 < 0 && (INT_MIN - number1 > number2))) {
                printf("Error: Addition overflow detected.\n");
                printf("Enter smaller values for this calculator \n");
                continue;
            } else {
                result = number1 + number2; // check for integer overflow and underflow in all of these
                break;
            }
            case '-':
                result = number1 - number2;
                break;
            case '*':
                if (number1 != 0 && number2 != 0) {
                // Check for multiplication overflow
                if ((number1 > 0 && number2 > 0 && number1 > INT_MAX / number2) ||
                    (number1 > 0 && number2 < 0 && number2 < INT_MIN / number1) ||
                    (number1 < 0 && number2 > 0 && number1 < INT_MIN / number2) ||
                    (number1 < 0 && number2 < 0 && number1 < INT_MAX / number2)) {
                    printf("Error: Multiplication overflow detected.\n");
                    printf("Enter smaller values for this calculator.\n");
                    continue;
                    }
                }
                result = number1 * number2;
                break;
            case '/':
                if(number2 != 0){
                result = number1 / number2;
                break;
                } else{
                    printf("This operation will result in a divide by zero error");
                    continue;
                }
            case '%':
                if(number2 == 0){
                    printf("Not allowed: Enter something other than 0\n");
                    continue;
                }
                result = number1 % number2;
                break;
            default:
                printf("Invalid operator");
                continue;


        };
        printf("Result: %d\n", result);
        printf("(0) If you would like to exit the code (1) Keep running the calculator: ");
        scanf("%d", &check);
        getchar();
        if(check == 0){
            printf("You are now exiting the calculator");
            return 0;
        }

        // this is where the while loop would end
        
        // Now we are dealing with the one string and one integer
//--------------------------------choice 2--------------------------------------------------------
        
    } else{
            printf("Enter a problem: ");
            temp_index = 0;
            memset(temp3, 0, sizeof(temp3));
            memset(temp4, 0, sizeof(temp4));
            memset(operand, 0, sizeof(operand));
            memset(answer, 0, sizeof(answer)); // <-- Clear answer here

// If an integer is entered first

            if((ch = getchar()) != '\n' && ch != EOF){ // Grabbing the first character here and it decides where the code starts
                if(isdigit(ch) || ch == '-' && temp_index == 0){
                    temp3[temp_index++] = (unsigned char)ch; // Grabbed the first character and its a integer
                    while((ch = getchar()) != '\n' && ch != EOF){
                        if(isdigit(ch)){
                            temp3[temp_index++] = (unsigned char)ch;
                    } else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%'){
                        temp3[temp_index] = '\0';
                        number1 = atoll(temp3);
                        operator = ch;
                        break;
                    } else{
                        printf("Invalid input: There was a space in the code or a non-integer\n");
                        printf("Enter a string to break out: ");
                        while ((ch = getchar()) != '\n' && ch != EOF); // Clear buffer
                        temp_index = 0;
                        memset(temp3, 0, sizeof(temp3));  // Clear temp
                        break;
                    }
                } 
                if(number1 > INT_MAX || number1 < 0){
                    printf("Invalid number: It exceeds the bounds");
                    continue;
            }
        temp_index = 0;
        while((ch = getchar()) != '\n' && ch != EOF ){
                    if(temp_index >= 100){
                        printf("The string exceeds 100 characters and is too long");
                        printf("(1) You can enter two integers (2) You can enter an integer and a string\n"); 
                         while ((ch = getchar()) != '\n' && ch != EOF); // Clear buffer
                         temp_index = 0;  // Reset index for new input
                         memset(operand, 0, sizeof(operand)); // Clear operand
                        break;
                    }
                    if(isalpha(ch)){
                        temp4[temp_index++] = (unsigned char)ch;
                    } else{
                        printf("Invalid input: There was a space in the code or a non-character\n");
                        while ((ch = getchar()) != '\n' && ch != EOF); // Clear buffer
                        temp_index = 0;
                        memset(temp4, 0, sizeof(temp4));  // Clear temp
                        break;
                    }
                }
                strcpy(operand, temp4);
                temp_index = 0;
            } 
            
            
            // If a string is entered first
            
            
            else if(isalpha(ch)){
                temp5[temp_index++] = (unsigned char)ch; // the first character grabbed was not an integer
                while((ch = getchar()) != '\n' && ch != EOF ){
                    if(temp_index >= 100){
                        printf("The string exceeds 100 characters and is too long\n");
                        printf("(1) You can enter two integers (2) You can enter an integer and a string\n"); 
                         while ((ch = getchar()) != '\n' && ch != EOF); // Clear buffer
                         temp_index = 0;  // Reset index for new input
                         memset(operand, 0, sizeof(operand)); // Clear operand
                        break;
                    }
                    if(isalpha(ch)){
                        temp5[temp_index++] = (unsigned char)ch;
                    } else if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%'){
                        temp5[temp_index] = '\0';
                        strcpy(operand, temp5);
                        operator = ch;
                        if(strlen(operand) > 100){
                            printf("The string exceeds 100 characters and is too long.\n");
                            while ((ch = getchar()) != '\n' && ch != EOF); // Clear buffer
                            temp_index = 0;  // Reset index for new input
                            memset(operand, 0, sizeof(operand)); // Clear operand
                            break;
                        }
                        break;
                    } else{
                        printf("Invalid input: There was a space in the code or a non-character\n");
                        printf("(1) You can enter two integers (2) You can enter an integer and a string\n");
                        while ((ch = getchar()) != '\n' && ch != EOF); // Clear buffer
                        temp_index = 0;
                        memset(temp5, 0, sizeof(temp5));  // Clear temp
                        break;
                    }
                } 
                temp_index = 0;
                while((ch = getchar()) != '\n' && ch != EOF){
                    if(isdigit(ch) || ch == '-' && temp_index == 0){
                        temp6[temp_index++] = (unsigned char)ch;
            } else{
                printf("Invalid input: There was a space in the code or a non-integer");
                printf("(1) You can enter two integers (2) You can enter an integer and a string\n");
                while ((ch = getchar()) != '\n' && ch != EOF); // Clear buffer
                temp_index = 0;
                memset(temp6, 0, sizeof(temp6));  // Clear temp
                break;
            }
        }
        temp6[temp_index] = '\0';
        number1 = atoll(temp6);
        temp_index = 0;




        if(strlen(operand) > 100){
            printf("The string is longer than 100 characters");
            while ((ch = getchar()) != '\n' && ch != EOF); // Clear buffer
            temp_index = 0;  // Reset index for new input
            memset(operand, 0, sizeof(operand)); // Clear operand
            break;
        }

        if(number1 > INT_MAX || number1 < 0){
                    printf("Invalid number: It exceeds the bounds");
                    continue;
        }
            // if the first character grabbed wasn't either of the cases then we hit here
            } else{
                printf("Invalid input");
                continue;
            }
            }
            // we should now have two operands and can begin working on the cases of different operations


            switch(operator){
                case '+':
                    for(int i = 0; operand[i] != '\0'; i++){
                        if(isalpha(operand[i])){
                            if(isupper(operand[i])){
                                operand[i] = (operand[i] - 'A' + number1) % 26 + 'A';
                            } else if(islower(operand[i])){
                                operand[i] = (operand[i] - 'a' + number1) % 26 + 'a';
                            }
                        }
                    }
                    printf("This is the result\n: %s", operand);
                    printf("(0) If you would like to exit the code (1) Keep running the calculator: ");
                    scanf("%d", &check);
                    getchar();
                    if(check == 0){
                        printf("You are now exiting the calculator");
                        return 0;
                    }
                    break;
                case '-':
                    for(int i = 0; operand[i] != '\0'; i++){
                        if(isalpha(operand[i])){
                            if(isupper(operand[i])){
                                operand[i] = ((operand[i] - 'A' - number1 + 26) % 26) + 'A';
                            } else if(islower(operand[i])){
                                operand[i] = ((operand[i] - 'a' - number1 + 26) % 26) + 'a';
                            }
                        }
                    }
                    printf("This is the result: %s\n", operand);
                    printf("(0) If you would like to exit the code (1) Keep running the calculator: ");
                    scanf("%d", &check);
                    getchar();
                    if(check == 0){
                        printf("You are now exiting the calculator");
                        return 0;
                }
                    break;
                case '*':
                    operand_length = strlen(operand);
                    total_length = operand_length * number1;

                    if(total_length > MAX_LENGTH){
                        printf("Result string is too long. It will be shrunk down to fit 1024 characters.\n");
                        int repetitions = MAX_LENGTH / operand_length;
                        for(int i = 0; i < repetitions; i++){
                            strncat(answer, operand, MAX_LENGTH - strlen(answer));
                    }
                    } else{
                        for(int i = 0; i < number1; i++){
                            strncat(answer, operand, MAX_LENGTH - strlen(answer));
                        }
                    }
                    answer[MAX_LENGTH] = '\0';
                    printf("This is the result\n: %s\n", answer);
                    printf("(0) If you would like to exit the code (1) Keep running the calculator: ");
                    scanf("%d", &check);
                    getchar();
                    if(check == 0){
                        printf("You are now exiting the calculator");
                        return 0;
                    }
                    break;
                case '/': 
                    operand_length = strlen(operand);
                    if(number1 >= operand_length){
                        operand[0] = '\0';
                    } else{
                        operand[operand_length - number1] = '\0';
                    }
                    printf("This is the result: %s\n", operand);
                    printf("(0) If you would like to exit the code (1) Keep running the calculator: ");
                    scanf("%d", &check);
                    getchar();
                    if(check == 0){
                        printf("You are now exiting the calculator");
                        return 0;
                    }
                    break;
                case '%':
                    printf("Rejected: the modulo is not allowed\n");
                    return 0;
                default:
                    printf("Invalid statement: You can use -,+,/,*\n");
                    continue;
            };
    }
}
}

