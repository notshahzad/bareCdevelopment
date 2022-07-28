#include <stddef.h>
#include <stdint.h>
uint16_t* termbuffer = (uint16_t*) 0x0B8000;
int termrow = 25;
int termcolumn = 80;
int currentrow = 0;
int currentcolumn = 0;
//returns length of string in int
int strlen(const char* str){
  int len = 0;
  while (str[len])
    len++;
  return len;
}
void putchar(const char chr){
  termbuffer[(currentrow * termcolumn) + currentcolumn] = (uint16_t) chr | 0x0F00;

}
void term_print(const char *string){
  int len = strlen(string);
  for (int i = 0; i < len; i++){
    if (string[i] == '\n'){
      currentcolumn = 0;
      currentrow += 1;
      continue;
    }
    putchar(string[i]);
    currentcolumn += 1;
  }
}
void term_init(){
  for (int i = 0; i < termrow; i++){
    for (int j = 0; j < termcolumn; j++){
      termbuffer[i + (j * termcolumn)] = (uint16_t) 0x0000;

    }
  }
}
void kernel_main(void){
  term_init();
 term_print("hello,world!\n"); 
 term_print("okeh");
}
