#include <stdio.h>
#include <stdlib.h>

void show_usages(void);


void show_usages(void){
	printf("\n\tascii-encryptor\tInvalid Usage\n\t\tUsage:\tascii-encrypt <fileToEncrypt> <OutputFile>\n");
}

void main(int argc, char *argv[]){

	// check if correct arguments are supplied
	if (argc < 3){
		show_usages();
		exit(0); // quit program
	}

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
