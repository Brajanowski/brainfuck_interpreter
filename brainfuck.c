// Interpreter for brainfuck language written in c
#include <stdio.h>

#define MAX_MEMORY 0x80

unsigned char memory[MAX_MEMORY] = { 0 };
unsigned char* ptr = memory; // memory pointer, starts at beginning of memory array

void bf_exec_code(const char* code) {
  unsigned int i = 0;
  
  while (code[i] != '\0') {
    if (code[i] == '>') {  
      if (ptr < memory + MAX_MEMORY)
        ++ptr;
    } else if (code[i] == '<') { 
      if (ptr >= memory)
        --ptr;
    } else if (code[i] == '+') {
      ++(*ptr);
    } else if (code[i] == '-') {
      --(*ptr);
    } else if (code[i] == '[') {
      ; // do nothing, loop code is implemented in ']' instructon
    } else if (code[i] == ']' && *ptr != 0) {
      unsigned int loops = 1;
      while (loops > 0) {
        char c = code[--i];

        if (c == ']')
          ++loops;
        else if (c == '[')
          --loops;
      }
    } else if (code[i] == '.') {
      putchar(*ptr);
    } else if (code[i] == ',') {
      *ptr = getchar();
    }
    // ignore rest characters

    ++i;
  }
}

int main() {
  // this should prints "Hello World!"
  bf_exec_code("++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>."); 
  return 0;
}

