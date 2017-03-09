#include <pthread.h>
#include <stdio.h>

typedef struct
{
    char character;
    int count;
} char_print_params;

void* char_print(void * parameters)
{
    char_print_params *p = (char_print_params*)parameters;
    int i;
    for( i = 0; i < p->count; i++ )
        fputc(p->character, stderr);
    return NULL;
}

int main()
{
    pthread_t thread_id1, thread_id2;
    char_print_params thread_args1, thread_args2;

    thread_args1.character = 'x';
    thread_args1.count = 30000;

    thread_args2.character = 'o';
    thread_args2.count = 20000;

    pthread_create(&thread_id1, NULL, &char_print, &thread_args1);
    pthread_create(&thread_id2, NULL, &char_print, &thread_args2);

    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);
    return 0;
}

