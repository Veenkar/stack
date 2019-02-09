#include <stdio.h>
#include <stdint.h>
#include "stack.h"

#define ELM_SIZE(arr)   ( sizeof(arr[0]) )
#define N_ELEMS(arr)    ( sizeof(arr) / ELM_SIZE(arr) )

int main()
{
    typedef uint32_t Element_T;

    Element_T buf[64];
    Stack_T stack = Stack(buf, ELM_SIZE(buf), N_ELEMS(buf));

    uint32_t push_vals[] = {10, 15, 19};
    for (size_t i =0; i < N_ELEMS(push_vals); ++i)
    {
        Stack_Push(&stack, &push_vals[i]);
    }

    uint32_t el;
    while (Stack_Pop(&stack, &el))
    {
        printf("%u\n",el);
    }

    printf("Done!\n");
    return 0;
}
