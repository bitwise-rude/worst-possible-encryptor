#include <stdio.h>
#include <stdlib.h>


void main(){
	FILE *fp = fopen("test.txt","r"); // reading file
	FILE *fpw = fopen("test2.txt","w");  // writing file
	char buf;

	// if error
	if (fp == NULL || fpw == NULL){
		printf("There has been some error while opening the file. Does that file exist?\n\n");
		exit(-1);
	}
	
	// read byte by byte (char by char) and write it to the new file 
	while ((buf = getc(fp))!= EOF){
		fprintf(fpw,"%d ",buf);
	}
	
	// close the files
	fclose(fp);
	fclose(fpw);

}
