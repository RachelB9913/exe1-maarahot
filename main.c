#include "NumClass.h"
#include <stdio.h>

/* the main recieves two numbers from the user, and 
returns all the Armstrong, Palindrome, Prime and Storng (in this order) numbers in between the to numbers including them.*/
int main() { 
    int i, x, y, min=0, max=0;
    scanf(" %d" , &x);
    scanf(" %d" , &y);
    if(x>y){
        min=y;
        max=x;
    }
    else{
        min=x;
        max=y;
    }
    printf("The Armstrong numbers are:");
    for(i=min;i<=max;i++){
        if(isArmstrong(i)==TRUE){
            printf(" %d" , i);
        }
    }

    
    printf("\nThe Palindromes are:");
    for(i=min;i<=max;i++){
        if(isPalindrome(i)==TRUE){
            printf(" %d" , i);
        }
    }

    printf("\nThe Prime numbers are:");
    for(i=min;i<=max;i++){
        if(isPrime(i)==TRUE){
            printf(" %d" , i);
        }
    }
    
    printf("\nThe Strong numbers are:");
    for(i=min;i<=max;i++){
        if(isStrong(i)==TRUE){
            printf(" %d" , i);
        }
    }
    printf("\n");
    return 0;
}

