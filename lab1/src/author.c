#include "author.h"

#define AUTHOR_GROUP GROUP
#define AUTHOR_NAME NAME

int print_author(FILE* out) 
{
    if (!out) {
        goto invalid_out;
    }
    fprintf(out, "%s %s\n", AUTHOR_GROUP, AUTHOR_NAME);
    fflush(out);

invalid_out:
    return -1;
}