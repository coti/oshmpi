/* based on http://stackoverflow.com/questions/1765969/unable-to-locate-definition-of-etext-edata-end */

/* see http://stackoverflow.com/questions/10301542/getting-process-base-address-in-mac-osx to fix the remaining issues */

#include <stdio.h>
#include <stdlib.h>
//FIXME make this portable
#if defined(__APPLE__)
#include <mach-o/getsect.h>
#else
    extern char data_start;
    extern char etext;
    extern char edata;
    extern char end;
    static unsigned long get_sdata() { return (unsigned long)&data_start;   }
    static unsigned long get_end()   { return (unsigned long)&end;   }
#endif
int a;
static int b;
int c=1111;
static int d=2222;

int main(int argc, char *argv[])
{
    int e;
    int f=3333;
    static int g;
    static int h=4444;

#if defined(__APPLE__)
    printf("program text (etext)      %p\n", (void*)get_etext());
    printf("initialized data (edata)  %p\n", (void*)get_edata());
    printf("uninitialized data (end)  %p\n", (void*)get_end());
#else
    printf("initialized data (edata)  %p\n", (void*)get_sdata());
    printf("uninitialized data (end)  %p\n", (void*)get_end());
#endif
    printf("&a=%p\n", &a);
    printf("&b=%p\n", &b);
    printf("&c=%p\n", &c);
    printf("&d=%p\n", &d);
    printf("&e=%p\n", &e);
    printf("&f=%p\n", &f);
    printf("&g=%p\n", &g);
    printf("&h=%p\n", &h);

    return 0;
}
