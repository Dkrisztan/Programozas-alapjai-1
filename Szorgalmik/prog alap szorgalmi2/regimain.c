#include <stdio.h>

int main() {
  // Ide kérjük be a programot
  char programkod[]="++++++++++[>+>+++>+++++++>++++++++++<<<<-]>>>++.---.+++++++..+++.";
  
  char szalag[32768] = {0};
  char *ptr = szalag;

  char current_char;
  int loop;

  for (int i = 0; programkod[i] != 0; i++) {
      current_char = programkod[i];
      if (current_char == '>') {
          ++ptr;
      } else if (current_char == '<') {
          --ptr;
      } else if (current_char == '+') {
          ++*ptr;
      } else if (current_char == '-') {
          --*ptr;
      } else if (current_char == '.' ) {
          putchar(*ptr);
      } else if (current_char == ',') {
          *ptr = getchar();
      } else if (current_char == '[') {
          continue;
      } else if (current_char == ']' && *ptr) {
          loop = 1;
          while (loop > 0) {
              current_char = programkod[--i];
              if (current_char == '[') {
                  loop--;
              } else if (current_char == ']') {
                  loop++;
              }
          }
      }
  }
  return 0;
}