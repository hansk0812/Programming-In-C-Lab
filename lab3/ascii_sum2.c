#include <stdio.h>

int main() {
char letter1 = 'B'; // ASCII value of 'B' is 66
char letter2 = 'C'; // ASCII value of 'C' is 67

// Performing arithmetic operation
int result = letter1 + letter2;

// Printing the result
printf("The result of adding '%c' and '%c' is: %d\n", letter1, letter2, result);

// 40 is just a heuristic to bring result back to the space of alphabets
printf("This corresponds to the character: %c\n", (char)(result-40));

return 0;

}
