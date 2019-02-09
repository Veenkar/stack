/*******************************************************************************
 *                               Stack.h
 *
 *
 *
 *
 ******************************************************************************/
#pragma once

/*******************************************************************************
 *                               Includes
 ******************************************************************************/
#include <stddef.h>
#include <stdbool.h>

/*******************************************************************************
 *                             Define Macros
 ******************************************************************************/

/*******************************************************************************
 *                          Function-Like Macros
 ******************************************************************************/

/*******************************************************************************
 *                           Type Declarations
 ******************************************************************************/
typedef struct Stack_Tag
{
    void * elements;
    size_t size_element;
    size_t size_max;
    size_t len_stack;

} Stack_T;

/*******************************************************************************
 *                          Object Declarations
 ******************************************************************************/

/*******************************************************************************
 *                         Functions Declarations
 ******************************************************************************/
/**
 * @brief Stack create a new stack using memory passed as elements as a container
 * @param elements:     pointer to the memory that will contain stack elements
 * @param size_element: size of a single stack element
 * @param size_max:     the maximum amount of elements that can fit into elements pointer
 * @return stack instance
 */
Stack_T Stack(void * elements, size_t size_element, size_t size_max);

/**
 * @brief push push an element on the stack
 * @param stack:    stack instance
 * @param element:  element to push on the stack
 * @return false on overflow
 */
bool Stack_Push(Stack_T * stack, void * element);

/**
 * @brief Stack_Pop pop an alement from a stack
 * @param stack:    stack instance
 * @param element:  if ok, a popped element will go here
 * @return false on underflow
 */
bool Stack_Pop(Stack_T * stack, void * element);

/**
 * @brief Stack_Len return current stack length
 * @param stack:    stack instance
 * @return stack length
 */
size_t Stack_Len(Stack_T* stack);


/*******************************************************************************
 *                         Functions Definitions
 ******************************************************************************/

/*******************************************************************************
 *                             End Stack.h
 ******************************************************************************/
