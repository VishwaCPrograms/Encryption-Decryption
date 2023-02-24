/* Author: Vishwa Venkateshwaran.
 * Date: Feb 3, 2022
 * Functions: main, encrypt and printArray */

#include <stdio.h>
#include "lab2header.h"
#include <string.h>

/* The function that reads in the character values and disperses all the tasks to the specific functions. */
int main() {
        int maxEntries;
        char charValue;
        char charValues[8];
        int i = 0;
        int count = 0;
        while (1) {
                charValue = getchar();
                if (charValue != EOF){
                        charValues[i] = charValue;
                        ++count;
                        if (count == INIT) {
                                maxEntries = count-1;
                                encrypt(charValues);
                                printArray(charValues, (count-1));
                                memset(charValues, 0, sizeof(charValues));
                                i = -1;
                                count = 0;
                        }
                } else {
                        if (count > 0 & count < INIT) {
                                maxEntries = count;
                                printArray(charValues, count);
                        }
                        break;

                }
                i++;
        }
        return 0;
}

/* Function that encrypts the characters using bit shifting and bit operations */
void encrypt(char charValues[]) {
        int i = 0;
        int index = 7;
        while (i < index) {
                int bit1 = (charValues[index] >> i) & 1U;
                int bit2 = (charValues[i] >> index) & 1U;
                if (bit1 != bit2) {
                        charValues[i] |= 1U << index;
                }
                i++;
        }
}        

/* Function to print out the values in the array */
void printArray(char charValues[], int maxEntries) {
        int i = 0;
        while (i < maxEntries) {
		putchar(charValues[i]);
               	i++;
	}
}

