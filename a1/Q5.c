/* CS261- Assignment 1 - Q.5*/
/* Name: Shawn S Hillyer
 * Date: 01/03/2016
 * Solution description: Converts a single word entered by user to "stickycaps"
 * e.g. StickyCaps  returns sTICKYcAPS
 */

#include <stdio.h>
#include <stdlib.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

/* sticky() inverts the case of all characters of string 'word'
 * Precondition: none
 * Postcondition:  If word!=NULL, inverts case of all letters in word by reference.
 */
void sticky(char* word){
     /*Convert to sticky caps*/
     if (word != NULL) {
       char current_ch;

       int i = 0; // index of each letter
       /* Iterate through the word until we find a null character */
       do {
         current_ch = word[i];

         // If current character is lowercase
         if (current_ch >= 'a' && current_ch <= 'z') {
           word[i] = toUpperCase(word[i]);
         }
         // Else if current character is uppercase
         else if (current_ch >= 'A' && current_ch <= 'Z') {
           word[i] = toLowerCase(word[i]);
         }

         ++i; // Move forward one character

       } while (current_ch != '\0');
     }
}

int main(){
    printf("Enter a word and I will convert it using sTiCkYcApS:\n");

    /*Read word from the keyboard using scanf*/
    char word[256];
    scanf("%s", word);

    /*Call sticky*/
    sticky(word);

    /*Print the new word*/
    printf("%s\n", word);
    return 0;
}
