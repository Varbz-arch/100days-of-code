// Problem: Read a string and check if it is a palindrome using two-pointer comparison.
// Input:
// - Single line: string s
// Output:
// - Print YES if palindrome, otherwise NO
// Example:
// Input:
// level
// Output:
// YES
// Explanation: String reads same forwards and backwards

#include<stdio.h>
int main(){
    char str[100];
    scanf("%s", str);
    int i=0;
    while(str[i]!=0){
        i++;
    }
    int start=0, end= i-1;
    int isPalindrome =1; //Assuming that it is palindrome
    while (start<end){
        if(str[start]!= str[end]){
            isPalindrome=0;
            break;
        }
        start++;
        end--;
    }
    if(isPalindrome){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
}
