/*******************************************************************************
 *                               Stack.c
 *
 *
 *
 *
 ******************************************************************************/

/*******************************************************************************
 *                               Includes
 ******************************************************************************/
#include "stack.h"
#include "string.h"
#include "stdint.h"

/*******************************************************************************
 *                             Define Macros
 ******************************************************************************/
#define NULL_PTR    NULL

/*******************************************************************************
 *                          Function-Like Macros
 ******************************************************************************/

/*******************************************************************************
 *                           Type Declarations
 ******************************************************************************/

/*******************************************************************************
 *                          Object Declarations
 ******************************************************************************/

/*******************************************************************************
 *                         Functions Declarations
 ******************************************************************************/

/*******************************************************************************
 *                         Functions Definitions
 ******************************************************************************/

Stack_T Stack(void * elements, size_t size_element, size_t size_max)
{
    Stack_T stack;

    if (elements == NULL_PTR)
    {
        size_max = 0;
    }

    stack.elements      = elements;
    stack.size_element  = size_element;
    stack.size_max      = size_max;
    stack.len_stack     = 0;
    return stack;
}

bool Stack_Push(Stack_T * stack, void *element)
{
    if (stack == NULL_PTR || element == NULL_PTR)
    {
        return false;
    }
    else if (stack->len_stack >= stack->size_max)
    {
        return false;
    }
    else
    {
        size_t dest_byte_offset = stack->len_stack *  stack->size_element;
        uint8_t * target = (uint8_t *) stack->elements + dest_byte_offset;

        memcpy(target, (uint8_t *) element, stack->size_element);
        ++(stack->len_stack);

        return true;
    }
}


bool Stack_Pop(Stack_T * stack, void * element)
{
    if (stack == NULL_PTR || element == NULL_PTR)
    {
        return false;
    }
    else if (!stack->len_stack)
    {
        return false;
    }
    else
    {
        size_t source_byte_offset = (stack->len_stack - 1)* stack->size_element;
        uint8_t * source = (uint8_t *) stack->elements + source_byte_offset;

        memcpy(element, source, stack->size_element);
        --(stack->len_stack);
        return true;
    }
}


size_t Stack_Len(Stack_T * stack)
{
    if (stack == NULL_PTR)
    {
        return 0;
    }
    return stack->len_stack;
}

/*******************************************************************************
 *                             End Stack.c
 ******************************************************************************/


