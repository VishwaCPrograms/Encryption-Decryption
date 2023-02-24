/* Author: Vishwa Venkateshwaran. */

#include <stdio.h>
#include "lab2header.h"
#include <string.h>

int main() {
int maxEntries;
char charValue;
char charValues[8];
int i = 0;
int count = 0;
while (1) { /* Implicit comparison */
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
goto breakTheLoop; /* goto */
}
breakTheLoop:
	break; /* break */
}
i++;
}
return 0;
}

void encrypt(char charValues[]) {
int i = 0;
int index = 7;
while (i < index) {
int bit1 = (charValues[index] >> i) & 1U;
int bit2 = (charValues[i] >> index) & 1U;
if (bit1 == bit2) {
i++;
continue; /* continue */
}
if (bit1 != bit2) charValues[i] |= 1U << index; /* if construct without a block */
i++;
}
}        

void printArray(char charValues[], int maxEntries) {
int i = 0;
while (i < maxEntries) {
putchar(charValues[i]);
i++;
}
}

