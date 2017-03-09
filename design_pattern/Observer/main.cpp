#include "subject.h"
#include "observer.h"
#include <iostream>
#include <pthread.h>
using namespace std;

struct param
{
    Subject* subject;
};
void* run(void* parameter)
{
    struct param* p = (struct param*) parameter;
    string array[10] = {"5", "3", "1", "6", "7"};
    for (int i = 0; i < 5; i++)
    {
        p->subject->set_subject_state(array[i]);
        cout << "Subject " << p->subject->get_subject_state() << endl;
        p->subject->notify();
    }
}

int main()
{
    Subject* subject = new Subject();
    IObserver* observer1 = new Observer(subject, "Center", "\t\t");
    IObserver* observer2 = new Observer(subject, "Right", "\t\t\t\t");

    pthread_t thread_id;
    struct param thread_args;
    thread_args.subject = subject;
    pthread_create(&thread_id, NULL, &run, &thread_args);
    pthread_join(thread_id, NULL);

    delete observer1;
    delete observer2;
    delete subject;
    return 0;
}
