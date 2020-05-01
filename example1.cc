/*
 * Filename:       example1.cc
 * Date:           04/28/2020
 * Author:         Dylan Kapustka
 * Email:          dlk190000@utdallas.edu
 * Version:        1.0
 * Copyright:      2020, All Rights Reserved
 * 
 * 
 * Description:   source file with matrix dimensions
 * 
 */ 

#include <iostream>
#include "cdk.h"
#include <fstream>
#include <string>
#include <sstream>
#include <stdint.h>
#include "binary.h"


#define MATRIX_WIDTH 5
#define MATRIX_HEIGHT 3
#define BOX_WIDTH 25
#define MATRIX_NAME_STRING "Binary File Contents"

using namespace std;

int main()
{

  WINDOW	*window;
  CDKSCREEN	*cdkscreen;
  CDKMATRIX     *myMatrix;           // CDK Screen Matrix

  BinaryFileHeader* fHeader = new BinaryFileHeader ();
  

  const char 	*rowTitles[MATRIX_HEIGHT+1] = {"R0", "a", "b", "c"};
  const char 	*columnTitles[MATRIX_WIDTH+1] = {"C0", "a", "b", "c","d","e"};
  int		boxWidths[MATRIX_WIDTH+1] = {BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH};
  int		boxTypes[MATRIX_WIDTH+1] = {vMIXED, vMIXED, vMIXED, vMIXED, vMIXED, vMIXED};

 
  window = initscr();
  cdkscreen = initCDKScreen(window);

  initCDKColor();

 
  myMatrix = newCDKMatrix(cdkscreen, CENTER, CENTER, MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_WIDTH, MATRIX_HEIGHT,
			  MATRIX_NAME_STRING, (char **) columnTitles, (char **) rowTitles, boxWidths,
				     boxTypes, 1, 1, ' ', ROW, true, true, false);

  if (myMatrix ==NULL)
    {
      printf("Error creating Matrix\n");
      _exit(1);
    }

  
  drawCDKMatrix(myMatrix, true);


 ifstream binFile("/scratch/perkins/cs3377.bin", ios::in | ios::binary);
 if (binFile.is_open())
{

 binFile.read ((char *) fHeader, sizeof (BinaryFileHeader));
   
  binAssign(myMatrix,fHeader,binFile);

  drawCDKMatrix (myMatrix, true);

  unsigned char x;
  cin >> x;
  binFile.close ();
  endCDK ();



}

}
