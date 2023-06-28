#include <stdio.h>
#include <string.h>
#include <ctype.h>
int max = 100;
char string[100];
int top = -1;

//Check whether the stack is full.
int isfull(){
    if(top == max-1){
        return 1;
    }
    else{
        return 0;
    }
}

//Check whether the stack is empty.
int isempty(){
    if(top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

//Push data to the stack.
char push(char data){
    if(isfull()){
        printf("The stack is full\n");
    }
    else{
        top = top + 1;
        string[top] = data;
    }
}

//Pop data from the stack.
char pop(){
    char data;
    if(isempty()){
        printf("The stack is full\n");
    }
    else{
        data = string[top];
        top = top - 1;
        return data; 
    }
}

//Main method declaration.
int main(){
    char array[20], a, b;
    int i,len;
    //Taking a character variable ‘m’, which is equal to 0.
    char m = '0';
    char n;

    //User input
    printf("Input the postfix expression : ");
    gets(array);

    //Length of the array which the postfix expression is stored.
    len = strlen(array);
  
    //Using the elements stored in the stack, one by one.
    for(i=0; i<len; i++){

        /*If the element in the array is not an operator, push it in
to the stack. */

        if(array[i] != '+' && array[i] != '-' && array[i] != '*' && array[i] != '/'){
            push(array[i]);
        }

        else{
            
            /*If the element in the array is ‘+’ pop the two topmost
elements from the stack. */
            if(array[i] == '+'){
                //Taking the first pop element as a.
                a = pop();
                //Taking the second pop element as b.
                b = pop();
                //If both a and b are digits,
                if(isdigit(a) && isdigit(b)){
                    //Printing the second element with ‘LD TEMP’.
                    printf("LD\tTEMP%c\n", a);
                    //Printing the first element with ‘AD TEMP’.
                    printf("AD\tTEMP%c\n", b);
                    //Taking the incremented ‘m’ as integer n.
                    n = ++m;
                    //Printing the value of n with ‘ST TEMP’.
                    printf("ST\tTEMP%c\n", n);
                    //Push the value of n to the stack.
                    push(n);
                }
                //If only a is a digit,
                else if(isdigit(a)){
                    //Printing b with ‘LD’.
                    printf("LD\t%c\n", b);
                    //Printing a with ‘AD TEMP’.
                    printf("AD\tTEMP%c\n", a);
                    //Taking the incremented ‘m’ as integer n.
                    n = ++m;
                    //Printing the value of n with ‘ST TEMP’.
                    printf("ST\tTEMP%c\n", n);
                    //Push the value of n to the stack.
                    push(n);
                }
                //If only b is a digit,
                else if(isdigit(b)){
                    //Printing b with ‘LD TEMP’.
                    printf("LD\tTEMP%c\n", b);
                    //Printing a with ‘AD’.
                    printf("AD\t%c\n", a);
                    //Taking the incremented ‘m’ as integer n.
                    n = ++m;
                    //Printing the value of n with ‘ST TEMP’.
                    printf("ST\tTEMP%c\n", n);
                    //Push the value of n to the stack.
                    push(n);
                }
                //If the both elements are not digits.
                else{
                    //Printing b with ‘LD’.
                    printf("LD\t%c\n", b);
                    //Printing a with ‘AD’.
                    printf("AD\t%c\n", a);
                    //Taking the incremented ‘m’ as integer n.
                    n = ++m;
                    //Printing the value of n with ‘ST TEMP’.
                    printf("ST\tTEMP%c\n", n);
                    //Push the value of n to the stack.
                    push(n);
                }
            }

            /*If the element in the array is ‘-’ pop the two topmost
elements from the stack. */
             if(array[i] == '-'){
                //Taking the first pop element as a.
                a = pop();
                //Taking the second pop element as b.
                b = pop();
                //If both a and b are digits,
                if(isdigit(a) && isdigit(b)){
                    //Printing the second element with ‘LD TEMP’.
                    printf("LD\tTEMP%c\n", b);
                    //Printing the first element with ‘SB TEMP’.
                    printf("SB\tTEMP%c\n", a);
                    //Taking the incremented ‘m’ as integer n.
                    n = ++m;
                    //Printing the value of n with ‘ST TEMP’.
                    printf("ST\tTEMP%c\n", n);
                    //Push the value of n to the stack.
                    push(n);
                }
                //If only a is a digit,
                else if(isdigit(a)){
                    //Printing b with ‘LD’.
                    printf("LD\t%c\n", b);
                    //Printing a with ‘AD TEMP’.
                    printf("SB\tTEMP%c\n", a);
                    //Taking the incremented ‘m’ as integer n.
                    n = ++m;
                    //Printing the value of n with ‘ST TEMP’.
                    printf("ST\tTEMP%c\n", n);
                    //Push the value of n to the stack.
                    push(n);
                }
                //If only b is a digit,
                else if(isdigit(b)){
                    //Printing b with ‘LD TEMP’.
                    printf("LD\tTEMP%c\n", b);
                    //Printing a with ‘SB’.
                    printf("SB\t%c\n", a);
                    //Taking the incremented ‘m’ as integer n.
                    n = ++m;
                    //Printing the value of n with ‘ST TEMP’.
                    printf("ST\tTEMP%c\n", n);
                    //Push the value of n to the stack.
                    push(n);
                }
                //If the both elements are not digits.
                else{
                    //Printing b with ‘LD’.
                    printf("LD\t%c\n", b);
                    //Printing a with ‘SB’.
                    printf("SB\t%c\n", a);
                    //Taking the incremented ‘m’ as integer n.
                    n = ++m;
                    //Printing the value of n with ‘ST TEMP’.
                    printf("ST\tTEMP%c\n", n);
                    //Push the value of n to the stack.
                    push(n);
                }
            }

            /*If the element in the array is ‘*’ pop the two topmost
elements from the stack. */
            if(array[i] == '*'){
                //Taking the first pop element as a.
                a = pop();
                //Taking the second pop element as b.
                b = pop();
                //If both a and b are digits,
                if(isdigit(a) && isdigit(b)){
                    //Printing the second element with ‘LD TEMP’.
                    printf("LD\tTEMP%c\n", b);
                    //Printing the first element with ‘ML TEMP’.
                    printf("ML\tTEMP%c\n", a);
                    //Taking the incremented ‘m’ as integer n.
                    n = ++m;
                    //Printing the value of n with ‘ST TEMP’.
                    printf("ST\tTEMP%c\n", n);
                    //Push the value of n to the stack.
                    push(n);
                }
                //If only a is a digit,
                else if(isdigit(a)){
                    //Printing b with ‘LD’.
                    printf("LD\t%c\n", b);
                    //Printing a with ‘ML TEMP’.
                    printf("ML\tTEMP%c\n", a);
                    //Taking the incremented ‘m’ as integer n.
                    n = ++m;
                    //Printing the value of n with ‘ST TEMP’.
                    printf("ST\tTEMP%c\n", n);
                    //Push the value of n to the stack.
                    push(n);
                }
                //If only b is a digit,
                else if(isdigit(b)){
                    //Printing b with ‘LD TEMP’.
                    printf("LD\tTEMP%c\n", b);
                    //Printing a with ‘ML’.
                    printf("ML\t%c\n", a);
                    //Taking the incremented ‘m’ as integer n.
                    n = ++m;
                    //Printing the value of n with ‘ST TEMP’.
                    printf("ST\tTEMP%c\n", n);
                    //Push the value of n to the stack.
                    push(n);
                }
                //If the both elements are not digits.
                else{
                    //Printing b with ‘LD’.
                    printf("LD\t%c\n", b);
                    //Printing a with ‘ML’.
                    printf("ML\t%c\n", a);
                    //Taking the incremented ‘m’ as integer n.
                    n = ++m;
                    //Printing the value of n with ‘ST TEMP’.
                    printf("ST\tTEMP%c\n", n);
                    //Push the value of n to the stack.
                    push(n);
                }
            }

            /*If the element in the array is ‘/’ pop the two
topmost elements from the stack. */
            if(array[i] == '/'){
                //Taking the first pop element as a.
                a = pop();
                //Taking the second pop element as b.
                b = pop();
                //If both a and b are digits,
                if(isdigit(a) && isdigit(b)){
                    //Printing the second element with ‘LD TEMP’.
                    printf("LD\tTEMP%c\n", b);
                    //Printing the first element with ‘DV TEMP’.
                    printf("DV\tTEMP%c\n", a);
                    //Taking the incremented ‘m’ as integer n.
                    n = ++m;
                    //Printing the value of n with ‘ST TEMP’.
                    printf("ST\tTEMP%c\n", n);
                    //Push the value of n to the stack.
                    push(n);
                }
                //If only a is a digit,
                else if(isdigit(a)){
                    printf("LD\t%c\n", b);
                    //Printing a with ‘DV TEMP’.
                    printf("DV\tTEMP%c\n", a);
                    //Taking the incremented ‘m’ as integer n.
                    n = ++m;
                    //Printing the value of n with ‘ST TEMP’.
                    printf("ST\tTEMP%c\n", n);
                    //Push the value of n to the stack.
                    push(n);
                }
                //If only b is a digit,
                else if(isdigit(b)){
                    //Printing b with ‘LD TEMP’.
                    printf("LD\tTEMP%c\n", b);
                    //Printing a with ‘DV’.
                    printf("DV\t%c\n", a);
                    //Taking the incremented ‘m’ as integer n.
                    n = ++m;
                    //Printing the value of n with ‘ST TEMP’.
                    printf("ST\tTEMP%c\n", n);
                    //Push the value of n to the stack.
                    push(n);
                }
                //If the both elements are not digits.
                else{
                    //Printing b with ‘LD’.
                    printf("LD\t%c\n", b);
                    //Printing a with ‘DV’
                    printf("DV\t%c\n", a);
                    //Taking the incremented ‘m’ as integer n.
                    n = ++m;
                    //Printing the value of n with ‘ST TEMP’.
                    printf("ST\tTEMP%c\n", n);
                    //Push the value of n to the stack.
                    push(n);
                }
            }
        }
    }
   return 0;
}


