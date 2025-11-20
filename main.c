#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show_usages(void);
FILE *read_file(char *,char *);
void encrypt(char *,char *);
void decrypt(char *,char *);

void show_usages(void){
	printf("\n\tascii-encryptor\tInvalid Usage\n\t\tUsage:\tascii-encrypt <fileToEncrypt> <OutputFile> <en/de>\n");
	exit(0);
}

FILE *read_file(char *file,char *mode)
{
	FILE *fp = fopen(file,mode);


	if (fp == NULL){
		printf("There has been some error while opening the file. Does that file exist?\n\n");
		exit(-1);
	}

	return fp;

}

void encrypt(char *master, char *slave)
{
	FILE *source = read_file(master,"r");
	FILE *destination = read_file(slave,"w");


	char buf;

	// read byte by byte (char by char) and write it to the new file 
	while (((buf = getc(source))!= EOF)){
		fprintf(destination,"%d ",buf);
	}
	
	// close the files 
	fclose(source);
	fclose(destination);

	printf("\nSucessfully Encrypted\n");
}

void decrypt(char *master, char *slave)
{
	FILE *source = read_file(master,"r");
	FILE *destination = read_file(slave,"w");

	int buf;

	while (fscanf(source,"%d", &buf) == 1){
		fprintf(destination,"%c",buf);
	}
	
	// close the files 
	fclose(source);
	fclose(destination);

	printf("\nSucessfully Decrypted\n");
}

int main(int argc, char *argv[]){

	// check if correct arguments are supplied
	if (argc < 4)
		show_usages();
	
	if ((strcmp(argv[3],"en")) == 0) 
		encrypt(argv[1],argv[2]);			
	
	else if((strcmp(argv[3],"de")) == 0){
		decrypt(argv[1],argv[2]);	
	}

	else{
		show_usages();
	}

	
	return 0;
}
