#include "legato.h"
#include "interfaces.h"

#define HASHMAP_STRING_TABLE_SIZE	32

le_hashmap_Ref_t stringTable;

/*
struct dataVsId
{
    uint64_t probeId;
    float probeValue;
    string probeName;
};
*/



static void kvs_stringInit(void)
{
    stringTable = le_hashmap_Create(
                        "stringTable",
						HASHMAP_STRING_TABLE_SIZE,
                        le_hashmap_HashString,
                        le_hashmap_EqualsString
                      );



}

void kvs_stringPut(const char* keyStr, const char* valueStr)
{
	le_hashmap_Put(stringTable, keyStr, valueStr);
}

char * kvs_stringGet(const char* keyStr)
{
    return ((char * )le_hashmap_Get(stringTable,keyStr));
}

char values[16][32];
char keys[16][32];

COMPONENT_INIT
{   
    LE_INFO("started\n");
    sprintf(keys[0], "Key0");
    sprintf(values[0], "value0");

    sprintf(keys[1], "Key1");
    sprintf(values[1], "value1");

    sprintf(keys[2], "Key2");
    sprintf(values[2], "value2");

    sprintf(keys[3], "Key3");
    sprintf(values[3], "value3");

    sprintf(keys[4], "Key4");
    sprintf(values[4], "value4");

	kvs_stringInit();

    LE_INFO("1.0");
	kvs_stringPut(keys[0], values[0]);
    kvs_stringPut(keys[1], values[1]);
    kvs_stringPut(keys[2], values[2]);


	LE_INFO("%s", kvs_stringGet("Key0"));
    LE_INFO("%s", kvs_stringGet("Key1"));
    LE_INFO("%s", kvs_stringGet("Key2"));
    LE_INFO("%s", kvs_stringGet("Key3"));


    LE_INFO("1.1");
	LE_INFO("%s", kvs_stringGet(keys[0]));
	LE_INFO("%s", kvs_stringGet(keys[1]));
    LE_INFO("%s", kvs_stringGet(keys[2]));

    LE_INFO("1.2");

    kvs_stringPut("key1", values[0]);
    kvs_stringPut("Key3", values[1]);
    kvs_stringPut("key4", values[2]);

    LE_INFO("%s", kvs_stringGet("Key0"));
    LE_INFO("%s", kvs_stringGet("Key1"));
    LE_INFO("%s", kvs_stringGet("Key2"));
    LE_INFO("%s", kvs_stringGet("Key3"));
    LE_INFO("%s", kvs_stringGet("Key4"));



    LE_INFO("1.2");

    kvs_stringPut(keys[4], values[0]);
    kvs_stringPut(keys[3], values[1]);
    kvs_stringPut(keys[2], values[2]);
    kvs_stringPut(keys[1], values[3]);

    LE_INFO("%s", kvs_stringGet("Key0"));
    LE_INFO("%s", kvs_stringGet("Key1"));
    LE_INFO("%s", kvs_stringGet("Key2"));
    LE_INFO("%s", kvs_stringGet("Key3"));
    LE_INFO("%s", kvs_stringGet("Key4"));
}
