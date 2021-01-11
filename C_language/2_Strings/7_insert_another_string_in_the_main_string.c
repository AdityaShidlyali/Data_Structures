// Author : Aditya Shidlyali

// Program to insert a new string to main string based on the position

#include <stdio.h>
#include <string.h>

int main() {

    // read the main string
    char mainString[10];
    printf("Enter the main string : ");
    scanf("%s", mainString);

    // now read the substring to insert
    char insertString[10];
    printf("Enter the new string to insert : ");
    scanf("%s", insertString);

    // now read the position to insert the insertString into the mainString
    printf("Enter the position of the main string to insert the substring : ");
    int pos;
    scanf("%d", &pos);

    // now check the entered position value to ensure the bounding of the length of the mainString
    if (pos <= strlen(mainString) + 1 || pos == -1) {
        // now copy the charachters from the mainString to newString upto the "pos"
        char newString[20];
        int i = 0;
        while (i < pos) {
            newString[i] = mainString[i];
            i++;
        }

        // store the index value of the main string from the "pos" to continue
        int temp = i;

        // now copy the character from the insertString to the newString
        int j = 0;
        while (insertString[j] != '\0') {
            newString[i] = insertString[j];
            i++;
            j++;
        }

        // now continue copying the characters from the mainString to newString from temp to null of the mainString
        while (mainString[temp] != '\0') {
            newString[i] = mainString[temp];
            i++;
            temp++;
        }

        // now print the final string that is newString
        printf("The final string is : %s", newString);
    } else {

        // else print the error message to enter the valid position to copy the characters
        printf("Enter the valid position and try again");
    }

    return 0;
}
