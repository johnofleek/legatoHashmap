/*
 * probe.c
 *
 *  Created on: 21 May 2018
 *      Author: john
 *
 *      Note            le_hashmap_HashUInt64,
                        le_hashmap_EqualsUInt64
        Are not available in 16.10.4
 */


#include "legato.h"
#include "interfaces.h"

#include "probe.h"

#define HASHMAP_STRING_TABLE_SIZE   32

static le_hashmap_Ref_t probeNameTable;



static void kvs_Uint64Init(void)
{
    /*
    probeNameTable = le_hashmap_Create(
                        "probeNameTable",
                        HASHMAP_STRING_TABLE_SIZE,
                        le_hashmap_HashUInt64,
                        le_hashmap_EqualsUInt64
                      );
                      */
    probeNameTable = le_hashmap_Create(
                        "probeNameTable",
                        HASHMAP_STRING_TABLE_SIZE,
                        le_hashmap_HashVoidPointer,
                        le_hashmap_EqualsVoidPointer
                      );
}




void kvs_probeNamePut(uint64_t * keyUint64, const char* valueStr)
{
    le_hashmap_Put(probeNameTable, keyUint64, valueStr);
}

char * kvs_probeNameGet(uint64_t *keyUint64)
{
    return ((char * )le_hashmap_Get(probeNameTable, keyUint64));
}

/*
 * Events send
 *  double value;
    uint64_t probeId;
 */
#define MAX_PROBE_ENTRIES   16
#define MAX_PROBE_NAME_LEN  32

uint64_t probeId_key[MAX_PROBE_ENTRIES] = {10,11,12,13,14};
char probeName_value[MAX_PROBE_ENTRIES][MAX_PROBE_NAME_LEN];

void probeNameTest(void)
{
    LE_INFO("started\n");
    kvs_Uint64Init();

    probeId_key[0] =  0x100002;
    sprintf(probeName_value[4], "input_temperature");

    probeId_key[1] = 0x200003;
    sprintf(probeName_value[3], " ");

    probeId_key[2] = 0x300004;
    sprintf(probeName_value[2], "supplyCurrent");

    probeId_key[3] = 0x400005;
    sprintf(probeName_value[1], "output_temperature");

    probeId_key[4] = 0x500006;
    sprintf(probeName_value[0], "fan_temperature");


    LE_INFO("1.0");
    kvs_probeNamePut(&probeId_key[0], probeName_value[0]);
    kvs_probeNamePut(&probeId_key[1], probeName_value[1]);
    kvs_probeNamePut(&probeId_key[2], probeName_value[2]);
    kvs_probeNamePut(&probeId_key[3], probeName_value[3]);
    kvs_probeNamePut(&probeId_key[4], probeName_value[4]);



    LE_INFO("get using pointers to keys");
    uint8_t ctr;

    for(ctr = 0 ; ctr < 5 ; ctr++)
    {
        LE_INFO("%" PRIx64  " %s",probeId_key[ctr],  kvs_probeNameGet( &probeId_key[ctr]) );

    }


}
