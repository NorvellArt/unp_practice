#include "unp.h"
#include "unpthread.h"

/* include Pthread_mutex_lock */
void Pthread_mutex_lock(pthread_mutex_t *mptr)
{
    int n;

    if ((n = pthread_mutex_lock(mptr)) == 0)
        return;
    errno = n;
    err_sys("pthread_mutex_lock error");
}
/* end Pthread_mutex_lock */