/*
 * Filename:       binary.h
 * Date:           04/28/2020
 * Author:         Dylan Kapustka
 * Email:          dlk190000@utdallas.edu
 * Version:        1.0
 * Copyright:      2020, All Rights Reserved
 * 
 * 
 * Description:   binary class declarations
 * 
 */ 

#include <iostream>
#include "cdk.h"
#include <fstream>
#include <string>
#include <sstream>
#include <stdint.h>

#ifndef _BINARY_H_
#define _BINARY_H_

class BinaryFileHeader
{
public:
 uint32_t magicNumber; /* Should be 0xFEEDFACE */
 uint32_t versionNumber;
 uint64_t numRecords;
};

const int maxRecordStringLength = 25;
class BinaryFileRecord
{
public:
 uint8_t strLength;
 char stringBuffer[maxRecordStringLength];
};

void binAssign(CDKMATRIX*,BinaryFileHeader*,std::ifstream&);

#endif

