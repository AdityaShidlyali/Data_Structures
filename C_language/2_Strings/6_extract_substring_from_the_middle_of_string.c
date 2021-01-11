// Author : Aditya Shidlyali

// Program to extaract the substring from the main string

#include <stdio.h>
#include <string.h>

int main() {

    // define and read the main string
    char mainString[10];
    printf("Enter main string : ");
    scanf("%s", mainString);

    // read the position of main string to extract the main string
    printf("Enter the position of the string to extract the substring : ");
    int pos;
    scanf("%d", &pos);

    // now read the lenght of the string
    printf("Enter the length of the substring to extract : ");
    int len;
    scanf("%d", &len);

    // check whether the entered length exceeds the length of the main string
    if (len+pos <= strlen(mainString)) {
        // now define the new empty string and perform the extraction
        char newString[10];
        int i = pos, j = 0;
        while (len--) {
            newString[j] = mainString[i];
            i++;
            j++;
        }
    
        // print the newString which the substring of the mainString
        printf("The final string is : %s", newString);
    } else {

        // else print the message to enter the valid lenght and positions
        printf("Enter the valid length and position and try again");
    }
    
    return 0;
}
