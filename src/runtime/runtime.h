/**
 * Author: turrnut
 * Copyrighted © turrnut under the Apache 2.0 license
 *
 * We hoped that you will use this piece of open source
 * software fairly. read the LICENSE for more details about
 * how you can use it, you have freedom to distribute and
 * use this code in your project. However, you will have to
 * state changes you made and include the orginal author of
 * this code.
 *
 * compiler.h
 *
 */
#ifndef compiler_header
#define compiler_header

#include "../ir/ir.h"
#include "../error/error.h"

#define STACK_SIZE 1024 // 1 KiB of stack size by default

typedef struct
{
    IR *ir;
    uint8_t *bp; // byte pointer
    Data *stack;
    Data *stacktop;
    const char* filename;
} RuntimeEnvironment;

typedef enum
{
    EXECUTE_SUCCESS,
    COMPILE_ERROR,
    RUNTIME_ERROR
} Result;

void start_runtime_environment();
void end_runtime_environment();
void update_stacktop();
void stack_push(Data data);
int stack_is_empty();
int stack_alloc(int vol);
Data stack_pop();
uint8_t step();
Data readData();
Result reportRuntimeError(const char *err);
Data see(int i);
Result execute(const char* filename, const char* src);

#endif
