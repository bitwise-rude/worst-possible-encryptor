#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define True 1
#define False 0

void show_usages(void);


void show_usages(void){
	printf("\n\tascii-encryptor\tInvalid Usage\n\t\tUsage:\tascii-encrypt <fileToEncrypt> <OutputFile> <en/de>\n");
}

void main(int argc, char *argv[]){

	// check if correct arguments are supplied
	if (argc < 4){
		show_usages();
		exit(0); // quit program
	}
	
	if (strcmp(argv[3],"en")) == 0 {
			
	}

	else if(strcmp(argv[3],"de")) == 0{
	
	}

	else{
		show_usages();
		exit(0);
	}

	FILE *fp = fopen(argv[1],"r"); // reading file
	FILE *fpw = fopen(argv[2],"w");  // writing file
	char buf;

	// if error
	if (fp == NULL || fpw == NULL){
		printf("There has been some error while opening the file. Does that file exist?\n\n");
		exit(-1);
	}
	
	// find out if it's encrypting or decrypting
	switch (strcmp(argv[3],"enc"))
	{

	// read byte by byte (char by char) and write it to the new file 
	while ((buf = getc(fp))!= EOF){
		fprintf(fpw,"%d ",buf);
	}
	
	// close the files
	fclose(fp);
	fclose(fpw);

}
