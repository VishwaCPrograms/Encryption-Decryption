/* Author: Vishwa Venkateshwaran.
 * Date: Feb 3, 2022
 * Functions: main, decrypt and printArray */

#include <stdio.h>
#include "lab2header.h"
#include <string.h>

/* The function that reads in the character values and disperses all the tasks to the specific functions. */
int main() {
        int maxEntries;
        char charValue;
        char charValues[INIT];
        int i = 0;
        int count = 0;
        while (1) {
                charValue = getchar();
                if (charValue != EOF){
                        charValues[i] = charValue;
                        ++count;
                        if (count == SEVEN) {
                                decrypt(charValues);
                               	printArray(charValues, INIT);
				memset(charValues, 0, sizeof(charValues));
                                i = -1;
                                count = 0;
                        }
                } else {
                        if (count > 0 & count < SEVEN) {
                                maxEntries = count;
                                printArray(charValues, maxEntries);
                        }
                        break;

                }
                i++;
        }
        return 0;
}

/* Function that decrypts the characters using bit shifting and bit operations */
void decrypt(char charValues[]) {
        int i = 0;
        int index = 7;
	int mask;
        while (i < index) {
                int bit1 = (charValues[i] >> index) & 1U;
                int bit2 = (charValues[index] >> i) & 1U;
                mask = 1U << i;
		if (bit1 != bit2) {
			if (bit2 == 1 && bit1 == 0) {
				charValues[index] &= ~(mask);
			} else if (bit2 == 0 && bit1 == 1) {
                        	charValues[index] |= mask;
			}
                }
                charValues[i] &= ~(1U << index);
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

