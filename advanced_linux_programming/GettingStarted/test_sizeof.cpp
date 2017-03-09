#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <memory.h>

#define s8 char

static char* ok_response =
"HTTP/1.0 200 OK\n"
"Content-type: text/html\n"
"\n";

struct node
{
    int a;
    int b;
    char c;
};
struct node node1;

struct s1
{
    char a;
    double b;
    int c;
    char d;
};

struct s2
{
    char a;
    char b;
    int c;
    double d;
};

struct t1 
{
    char a[8];
};

struct t2
{
    double a;
};

struct t3 
{
    char a;
    struct t1 s;
};

struct t4
{
    char a;
    struct t2 s;
};

class A
{
public:
    void func_a()
    {
    }
};

A a;

static char str[100] = "hello";

int str2int(char * input)
{
    assert(input != NULL);
    if (strspn(input, "0123456789") != strlen(input))
        return -1;
    if (strlen(input) > 10)
        return -1;
    int res = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        res = res * 10 + input[i] - '0';
    }
    return res;
}

void func()
{
    s8 i;
    i = 0;
    int k = 0;
    for (i = 0; i < 127; i++)
    {
        k += i & 3;
    }
    printf("k=%d\n\n", k);
    printf("%d\n\n", (char)128);
}

int main( int argc, char* argv[] )
{
    func();
    printf("size of double: %d\n", sizeof(double));
    printf("size of float: %d\n", sizeof(float));
    printf("size of char: %d\n", sizeof(char));
    printf("size of short: %d\n", sizeof(short));
    printf("size of int: %d\n", sizeof(int));
    printf("size of unsigned int: %d\n", sizeof(unsigned int));
    printf("size of static char*: %d\n", sizeof(ok_response));
    printf("size of static char[]: %d\n", sizeof(str));
    printf("size of struct node{int a; int c; char c}: %d\n", sizeof(struct node));
    printf("size of struct node node1: %d\n", sizeof(node1));
    printf("size of struct s1{char a; double b; int c; char d}: %d\n", sizeof(struct s1));
    printf("size of struct s2{char a; char b; int c; double d}: %d\n", sizeof(struct s2));
    printf("size of struct t1{char a[8]}: %d\n", sizeof(struct t1));
    printf("size of struct t2{double a}: %d\n", sizeof(struct t2));
    printf("size of struct t3{char a; struct t1 s}: %d\n", sizeof(struct t3));
    printf("size of struct t4{char a; struct t2 s}: %d\n", sizeof(struct t4));
    printf("size of A: %d\n", sizeof(A));
    printf("size of a: %d\n", sizeof(a));
    printf("(unsigned short) (-1) = %d\n", (unsigned short)(-1));
    printf("(unsigned long) (unsigned short) (-1) = %ld\n", (unsigned long)(unsigned short)(-1));
    printf("12 & 012 = %d\n", 12 & 012);
    int a[4];
    memset(a, -1, sizeof(int)*4);
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", a[i]);
        printf("\n");
    }

    char str[10] = "a";
    const char* p = "hello";
    printf("const char* p = %s\n", p);
    p = str;
    printf("const char* p = %s\n", p);
    char* const pp = "world";
    printf("char* const pp = %s\n", pp);
    pp[0] = 'a';
    printf("char* const pp = %s\n", pp);
    char const *ppp = "flanders";
    printf("char const *ppp = %s\n", ppp);
    ppp = str;
    printf("char const *ppp = %s\n", ppp);


    char input[1024];
    scanf("%s", input);
    printf("%d\n", str2int(input));
    return 0;
}
