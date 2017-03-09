#include <pthread.h>
#include <iostream>
using namespace std;
class ThreadExitException
{
public:
    //Create an exception-signaling thread exit with RETURN_VALUE.
    ThreadExitException (void* return_value)
        : thread_return_value_ (return_value)
    {}

    /* Actually exit the thread, using the return value provided in the
     * constructor. */
    void* DoThreadExit ()
    {
        cout << "do thread exit...\n" << endl;
        pthread_exit (thread_return_value_);
    }
private:
    //The return value that will be used when exiting the thread.
    void* thread_return_value_;
};

bool should_exit_thread_immediately()
{
    return true;
}

void do_some_work ()
{
    cout << "do some work..." << endl;
    while (1) 
    {
        /* Do some useful things here...
        */
        if (should_exit_thread_immediately ())
            throw ThreadExitException (/* thread’s return value = */ NULL);
    }
}
void* thread_function (void*)
{
    try 
    {
        do_some_work ();
    }
    catch (ThreadExitException ex) 
    {
        //Some function indicated that we should exit the thread.
        cout << "ThreadExitException catched..." << endl;
        ex.DoThreadExit ();
    }
    return NULL;
}

int main()
{
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, &thread_function, NULL);
    pthread_join(thread_id, NULL);
    return 0;
}
