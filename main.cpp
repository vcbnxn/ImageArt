/**
*
*
* There are a couple of things I want to play around with so I can understand exactly how the ppm file format works.
* I wonder if I could create a pool/map of colours so that each colour can only be used exactly once?
*/

#include <iostream>
#include <cmath>

//size parameters
#define DIM 1024
#define DM1 (DIM-1)

//useful functions
#define _sq(x) ((x)*(x))
#define _cb(x)  abs((x)*(x)*(x))
#define _cr(x) (unsigned short)(pow((x), 1/3))

//function declarations
unsigned short RD(int, int);
unsigned short GR(int, int);
unsigned short BL(int, int);
void pixel_write(int, int);

//globals
FILE *fp;

unsigned short RD(int i, int j){
 return 0;
}

unsigned short GR(int i, int j){
return _sq(j);
}

unsigned short BL(int i, int j){
return _sq(i);
}

/* Writes a simple, RGB ppm file */
int main(){
	fp  = fopen("output.ppm", "wb");
	fprintf(fp, "P6\n%d %d\n %d\n", DIM, DIM, DM1); //so how exactly should a ppm header be srtuctured?

	//write the actual pixels
	for (int j=0; j<DIM; j++){
		for (int i=0; i<DIM; i++){
			pixel_write(i,j);
		}
	}
	fclose(fp);

	return 0;
}


void pixel_write(int i, int j){
	static unsigned short color[3];
	color[0] = RD(i,j)&DM1; //why the &DM1? binary and operation.. what effect does this have? is it part of the ppm format
	color[1] = GR(i,j)&DM1;
	color[2] = BL(i,j)&DM1;
	fwrite(color, 2, 3, fp); //what are these parameters 2, 3?
}
