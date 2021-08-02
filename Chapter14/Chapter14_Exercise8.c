#include <stdio.h>

#define LINE_FILE printf("Line %d of file %s",__LINE__,__FILE__);

int main()
{
    LINE_FILE;
}