#include "NumClass.h"

/*in the same way as the loop version but recursive:
1. the main function (מעטפת)
2. a function that reverses the number */
int countDigits(int num) ;
int reverse(int num, int reversedN);
int doPow(int digit, int p);
int isArmstrongHelper(int num, int power);

int isPalindrome(int num) {
    int reversedN = 0;
    reversedN=reverse(num, reversedN);

    // Check if the reversed number is equal to the original number
    if (num == reversedN) {
        return TRUE;  // Palindrome
    } else {
        return FALSE;  // Not a palindrome
    }
}

int reverse(int num, int reversedN) {
    if (num == 0) {       //finished reversing the number
        return reversedN;
    }
    else{
        reversedN = (reversedN * 10) +( num % 10);
        num = num/10; 
    return reverse(num, reversedN);
    }
}

int isArmstrong(int num){
    int theN = num;
    int power = 1;
    int result=0;
    power = countDigits(num);

    // Call the recursive function
    result= isArmstrongHelper(theN,power);
    if(theN == result){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

int countDigits(int num) { //also recursive
    if (num == 0) {
        return 0;
    } else {
        return 1 + countDigits(num / 10);
    }
}

int doPow(int digit, int p) {
    if (p == 0) {
        return 1;
    }
    return digit * doPow(digit, p - 1);
}

// Recursive function to check if a number is an Armstrong number (helper)
int isArmstrongHelper(int num, int power) {
    if (num == 0) {
        return 0;
    }
    int digit = num % 10;
    int nNum = num/10;
    return doPow(digit, power) + isArmstrongHelper(nNum, power); //does the sum
}
