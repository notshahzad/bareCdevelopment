#include <stddef.h>
#include <stdint.h>
uint16_t* terminalbuffer = (uint16_t *) 0x0b8000;
void termwrite(char str[12]){
  for (int i = 0; i < 12; i++){
    terminalbuffer[i] = (uint16_t) str[i] | 0x7100;
  }
}
void kernel_main(void){
  char string[12] = "hello,world!";
  termwrite(string);
}
