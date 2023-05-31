/**
 * Author: turrnut
 * Copyrighted © turrnut under the Apache 2.0 license
 *
 * We hoped that you will use this piece of open source
 * software fairly. read the LICENSE for details for
 * more details about how you can use it, you have freedom
 * to distribute and use this file in your project. However,
 * you will have to state changes you made and include the
 * orginal author of this file.
 *
 * data.h
 * This header file provide declarations for the Data type.
 * The Data type was created in order to store information
 * during runtime. For example the stack memory uses a
 * pointer of the type Data to store data in the program.
 */
#ifndef data_header
#define data_header

#include "../base/base.h"

/**
 * Types of data
*/
typedef enum {
    BOOLEAN_VALUE,
    NULL_VALUE,
    NUMBER_VALUE
} DataType;

/**
 * The Data struct represents a value stored in the program's
 * memory. It has two parts: the type and the actual value.
*/
typedef struct {
    DataType type;
    union {
        bool boolean;
        double number;
    } is;
} Data;

#define PACK_BOOLEAN(b) ((Data) {BOOLEAN_VALUE, {.boolean = b}}) // Pack a C bool value to boolean Data
#define PACK_NUMBER(n) ((Data) {NUMBER_VALUE, {.number = n}}) // Pack a C number value to number Data
#define PACK_NULL ((Data) {NULL_VALUE, {.number = 0}}) // Returns a null Data

#define UNPACK_BOOLEAN(b) ((b).is.boolean) // Unpack the Data into a C bool
#define UNPACK_NUMBER(n) ((n).is.number) // Unpack the Data into a C number

#define IS_BOOLEAN(b) ((b).type == BOOLEAN_VALUE)
#define IS_NULL(nu) ((nu).type == NULL_VALUE)
#define IS_NUMBER(n) ((n).type == NUMBER_VALUE)

bool isFalse (Data da);
bool isEqual(Data left, Data right);

/**
 * The DataCollection type definition
 * 
*/
typedef struct
{
    int volume;
    int count;
    Data *elements;
} DataCollection;

/**
 * This function takes in a DataCollection pointer as an
 * argument, then set all the properties empty.
 * 
*/
void emptyDataCollection(DataCollection *coll);

/**
 * Returns a string of the given DataType
*/
const char* get_str_from_type_name(DataType dat);

/**
 * This function takes in a DataCollection pointer as an
 * argument and then initialize an empty DataCollection
 * instance.
*/
void initDataCollection(DataCollection *coll);

/**
 * Add a new Data instance to the DataCollection
 * pointer. The first argument is the DataCollection
 * pointer and the second argument is the value you want
 * to add.
*/
void createDataCollection(DataCollection *coll, Data value);

/**
 * Free the DataCollection back to the memory. Takes in a
 * DataCollection pointer as the argument.
*/
void releaseDataCollection(DataCollection *coll);

/**
 * Print the data.
*/
void printData(Data d);

#endif
