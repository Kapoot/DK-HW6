/*
 * Filename:       example2.cc
 * Date:           04/28/2020
 * Author:         Dylan Kapustka
 * Email:          dlk190000@utdallas.edu
 * Version:        1.0
 * Copyright:      2020, All Rights Reserved
 * 
 * 
 * Description:   source2 with I/O for binary
 * 
 */ 


#include "binary.h"


using namespace std;



void binAssign(CDKMATRIX* myMatrix,BinaryFileHeader* fHeader,ifstream& binFile)
{

  stringstream ss1;
  string s1;
  ss1 << hex << fHeader->magicNumber;
  s1 += ss1.str ();

  stringstream ss2;
  string s2;
  ss2 << fHeader->versionNumber;
  s2 += ss2.str();

  stringstream ss3;
  string s3;
  ss3 << fHeader->numRecords;
  s3 += ss3.str();

  setCDKMatrixCell (myMatrix, 1, 1, ("Magic: 0x" + s1).c_str ());
  setCDKMatrixCell (myMatrix, 1, 2, ("Version: " +s2).c_str ());
  setCDKMatrixCell (myMatrix, 1, 3, ("NumRecords: " + s3).c_str ());
  drawCDKMatrix (myMatrix, true);

}

