#include "NumClass.h"


/* build a number from the digits of the original number but in opposite order
    for example: num=12321 -> reversedN=1 num = 1232 ->reversedN=12 num = 123 -...-> reversedN = 12321 
    and then check if reversedN = theN */
int Pow(int digit, int p);    
int isPalindrome(int num){
    int theN = num; //the original number
    int reversedN = 0;
    while (num > 0) {
        reversedN = (reversedN * 10) + (num % 10); 
        num = num/ 10;
    }

    if (theN == reversedN) {
        return TRUE;  // Palindrome
    } else {
        return FALSE;  // Not a palindrome
    }
}


int isArmstrong(int num){
    int digit=0;
    int sum=0;
    int n=num, theN = num, power=0;
    while(num>0){      //counts the number of digits in order to set the power
        power++;
        num=num/10;
    }
    while(n>0){
        digit=n%10; 
        sum=sum+Pow(digit,power);
        n=n/10;
        digit=0;
    }
    if(theN==sum){
        return TRUE;
    }
    else {
        return FALSE;
    }
}


// a regular function that computes a number in a given power.
int Pow(int digit, int p){
    int numberP  = 1;
    while (p > 0) {
        numberP = numberP * digit;
        p--;
    }
    return numberP;
}