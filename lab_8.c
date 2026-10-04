//printing memory segment addresses
#include <stdio.h>
#include <stdlib.h>

int g_init = 1;        // 1. Global Initialized (.data)
int g_uninit;          // 2. Global Uninitialized (.bss)
static int s_init = 2; // 3. Static Initialized (.data)
static int s_uninit;   // 4. Static Uninitialized (.bss)

void dummy_func()
{
} // 5. Extra Function Address (Text)

int main(int argc, char *argv[]) { // argc = 6. Stack Argument
    int stack_local = 0;           // 7. Stack Local
    int *heap_var = malloc(4);     // 8. Heap Variable

    printf("--- TEXT (CODE) ---\nMain:  %p\nFunc:  %p\n", (void*)main, (void*)dummy_func);
    printf("--- DATA (INIT) ---\nGlobal:%p\nStatic:%p\n", (void*)&g_init, (void*)&s_init);
    printf("--- BSS (UNINIT) ---\nGlobal:%p\nStatic:%p\n", (void*)&g_uninit, (void*)&s_uninit);
    printf("--- HEAP ---\nHeap:  %p\n", (void*)heap_var);
    printf("--- STACK ---\nArg:   %p\nLocal: %p\n", (void*)&argc, (void*)&stack_local);

    free(heap_var);
    return 0;
}
