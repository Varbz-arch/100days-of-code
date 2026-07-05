// Write a function that reverses a string. The input string is given as an array of characters s.
// You must do this by modifying the input array in-place with O(1) extra memory.
// Example 1:
// Input: s = ["h","e","l","l","o"]
// Output: ["o","l","l","e","h"]

#include<stdio.h>
int main(){
    char s[50];
    // scanf("%s", &s);     
    int start = 0;
    int i=0;
    // Read a full line including spaces
    fgets(s, sizeof(s), stdin);

    // while(s[i]!=0){
    //     i++;
    // }

    // Find length and remove '\n' if present
    while (s[i] != '\0') {
        if (s[i] == '\n') {
            s[i] = '\0';
            break;
        }
        i++;
    }
    int end=i-1;
    while(start<end){
        int temp= s[start];
        s[start]=s[end];
        s[end]=temp;
        start++;
        end--;
    }
    printf("YOUR REVERSED INPUT STRING IS: %s", s);
    return 0;
}