#include "NumClass.h"

int factorial(int num);     //declaration of an auxiliary function used later in this file

/*this function checks with a while loop if a given number is a prime number
(in our case 1 is a prime number) and the other will be checked with the loop and the condition below*/
int isPrime (int num){      
int i=2;
if(num==1){
    return TRUE;
}
while(i*i<=num ){
    if(num%i==0){
        return FALSE;
    }
    i=i+1;
}
return TRUE;
}

int isStrong(int num){
int theN = num, sum=0, digit=0;
while(num>0){
    digit=num%10; 
    sum=sum+(factorial(digit));
    num=num/10;
}
if(theN==sum){
    return TRUE;
}
else {
    return FALSE;
}
}

/*an auxiliary recursive function that helps to find the factorial of the number - 
this function used in the "isStrong" function above*/

int factorial(int num){
    int i;
    int mul=1;
    for(i=1;i<=num;i++){
        mul=mul*i;
    }
    return mul;
}