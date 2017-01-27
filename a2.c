#include <stdint.h>
#include <string.h> // included for strcat()

#define u32 uint32_t

// printu() code
typedef unsigned int u32;
int BASE = 10;
char *table = "0123456789ABCDEF";

int rpu(u32 x)
{
  char c;
  if (x) {
    c = table[x % BASE];
    rpu(x / BASE);
    putchar(c);
  }
}

int printu(u32 x)
{
  if (x==0)
    putchar('0');
  else
    rpu(x);
  putchar(' ');
}
// end printu() code

int printc(char c)
{
  putchar(c);
}

int prints(char *s)
{
  while (*s)
    putchar(*s++);
}

int printd(int x) // might have to convert int to u32 here
{
  if (x==0)
    putchar('0');
  else if (x<0)
    {
      x = -1 * x;
      putchar('-');
      printu((uint32_t)x);
    }
  else
    printu((uint32_t)x);
}

int printo(u32 x)
{
  BASE = 8;
  putchar('0');
  printu(x);
}

int printx(u32 x)
{
  BASE = 16;
  putchar('0x');
  printu(x);
}

int myprintf(char *fmt, ...) // *** TODO: handle the case where there are more %_'s
{                            // than *ip's given
  char *cp = fmt;
  int *ip = &fmt + 1;
  while (*cp)
    {
	putchar('l');
      if (*cp == '%')
	{
	  *cp++;
	  if (*cp=='c')
	    putchar(*ip);
	  else if (*cp=='s')
	    prints(*ip);
	  else if (*cp=='u')
	    printu(*ip);
	  else if (*cp=='d')
	    printd(*ip);
	  else if (*cp=='o')
	    printo(*ip);
	  else
	    printx(*ip);
	  *ip++;
	}
      else if (*cp == '\n')
	putchar(strcat(*cp, '\r'));
      else
	putchar(*cp);
      *cp++;
    }
}

// main() function
int main(int argc, char *argv[ ], char *env[ ])
{
  myprintf("this is a string\n");
  myprintf("this is %c hi %d test %x\n", 'A', 1234, 100);
  
  return 0;
}
