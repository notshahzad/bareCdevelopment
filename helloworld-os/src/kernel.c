#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>
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
    if (chr == '\n'){
      currentcolumn = 0;
      currentrow += 1;
      return;
    }
  termbuffer[(currentrow * termcolumn) + currentcolumn] = (uint16_t) chr | 0x0F00;
  currentcolumn ++;

}
void writeString(const char* string);
void k_print(const char* format, ...){
  int len = strlen(format);
  va_list args;
  va_start(args, format);
  for (int i = 0; i < len; i++){
    if (format[i] == '%'){
      int var;
      switch (format[i+1]) {
        case 'd':
          var = va_arg(args,int);
          if (var < 0) putchar('-');
          void dec(int vr){
            int temp = vr % 10;
            vr = (int) vr / 10;
            if (vr > 0)
              dec(vr);
            putchar(temp + 48);
          }
          dec(var);
          i+=1;
          break;
        case 's':
          writeString((const char*)va_arg(args, char *));
          i+=1;
          break;
        case 'c':
          putchar((char)va_arg(args, int));
          i+=1;
          break;
        default:
          break;
      }
    }else{
      putchar(format[i]);
    }
  }
}

void writeString(const char *string){
  int len = strlen(string);
  for (int i = 0; i < len; i++)
    putchar(string[i]);
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
  k_print("%d %c %s",123435,'c',"asdjaks");
}
