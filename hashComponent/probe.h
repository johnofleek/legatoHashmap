/*
 * probe.h
 *
 *  Created on: 21 May 2018
 *      Author: john
 */

#ifndef PROBE_H_
#define PROBE_H_


void probeNameTest(void);

char * kvs_probeNameGet(uint64_t *keyUint32);

void kvs_probeNamePut(uint64_t * keyUint32, const char* valueStr);


#endif /* PROBE_H_ */
