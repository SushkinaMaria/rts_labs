#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

#include "../src/author.h"

#define TEST_PASSED "Test passed"
#define TEST_FAILED(test_num, exp, act) \
"Test #%d failed:\n\
expected: %s\n\
actual: %s\n",\
test_num, exp, act \

char buffer[100];
int fd[2];
FILE *out;

int test_correct_output(int test_num)
{
    char expected[] = "I993 Sushkina Mariya\n";

    print_author(out);
    close(fd[1]);
    int readed = read(fd[0], buffer, sizeof(buffer));

    if (memcmp(buffer, expected, readed) != 0) {
        printf(TEST_FAILED(test_num, expected, buffer));
        return 0;
    }

    return 1;
}

int main(int argc, char const *argv[])
{
    int ret;
    int passed = 0;
    int test_num = 0;

    ret = pipe(fd);
    if (ret) {
        printf("Pipe error");
        exit(1);
    }
    out = fdopen(fd[1], "w");
    if (!out) {
        printf("Out error");
        exit(1);
    }
  
    passed += test_correct_output(test_num++);

    printf("%d tests passed\n", passed);
    
    return 0;
}
