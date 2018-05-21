#include "legato.h"
#include "interfaces.h"

#define HASHMAP_STRING_TABLE_SIZE	32

le_hashmap_Ref_t stringTable;

static void kvs_stringInit(void)
{
    stringTable = le_hashmap_Create(
                        "stringTable",
						HASHMAP_STRING_TABLE_SIZE,
                        le_hashmap_HashString,
                        le_hashmap_EqualsString
                      );



}

void kvs_stringPut(keyStr,valueStr)
{
	le_hashmap_Put(stringTable, keyStr, valueStr);
}


COMPONENT_INIT
{   
    LE_INFO("started\n");

	kvs_stringInit();

	kvs_stringPut();
}
