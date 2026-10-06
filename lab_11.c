#include <stdio.h>
#include <pthread.h>

void *my_thread1_function(void *arg)
{
    printf("Hello from the new thread-1!\n");
    return NULL;
}

void *my_thread2_function(void *arg)
{
    printf("Hello from the new thread-2!\n");
    return NULL;
}
void *my_thread3_function(void *arg)
{
    printf("Hello from the new thread-3!\n");
    return NULL;
}

int main()
{
    pthread_t thread1, thread2,thread3;

    printf("Hello from the main thread!\n");

    // Create the first thread
    if (pthread_create(&thread1, NULL,
                       my_thread1_function, NULL) != 0)
    {
        printf("Failed to create thread 1.\n");
        return 1;
    }

    // Create the second thread
    if (pthread_create(&thread2, NULL,
                       my_thread2_function, NULL) != 0)
    {
        printf("Failed to create thread 2.\n");
        pthread_join(thread1, NULL);
        return 1;
    }
if (pthread_create(&thread3, NULL,
                       my_thread3_function, NULL) != 0)
    {
        printf("Failed to create thread 3.\n");
        pthread_join(thread1, NULL);
        return 1;
    }


    // Wait for both threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    printf("Both threads have finished. Exiting main.\n");

    return 0;
}
