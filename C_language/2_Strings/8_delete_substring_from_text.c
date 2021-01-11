// Author : Aditya Shidlyali

// Program to delete the sub string from the main string.

#include <stdio.h>
#include <string.h>

int main() {
    
    // read the main string
    printf("Enter the main String : ");
    char mainString[10];
    scanf("%s", mainString);

    // now read the substring to be deleted
    printf("Enter the substring to be deleted from the main String : ");
    char deleteString[10];
    scanf("%s", deleteString);

    // check whether the lenght string to be deleted is smaller than the mainString
    if (strlen(mainString) > strlen(deleteString)) {

        // now perform the deletion operation
        int i = 0;
        char newString[20];
        int afterDeleteIndex = 0, indexNewString = 0;
        while (mainString[i] != '\0') {

            // go upto the lenght of the deleteString and assign the characters from the mainString
            int k = i, j = 0;
            while (deleteString[j] == mainString[k]) {
                k++;
                j++;
            }

            // if scanning is done for all the characters of the deleteString then assign the afterDeleteIndex
            if (deleteString[j] == '\0') {
                afterDeleteIndex = k;
            }

            // now copy all the characters from mainString from the index afterDeleteIndex
            newString[indexNewString] = mainString[afterDeleteIndex];

            // increment all the index counters
            afterDeleteIndex++;
            indexNewString++;
            i++;
        }

        // now print the final string
        printf("The final String is : %s", newString);
    } else {
        
        // else give the error message to enter the deleteString which is smaller than the mainString
        printf("The lenght of the string to be deleted should be smaller than the main string");
    }

    return 0;
}
