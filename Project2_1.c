#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <limits.h>
#include <stdbool.h>
#include <fcntl.h>

#include "Project2_1.h"


int main(int args, char* argv[]){
	char* filename = argv[1];
	char* source = NULL;
	read_file(char* source, char* filename);
	fprintf("Number of line is %d\n", count_line_file(char *source));

}



int count_line_file(char *source){
	int i;
	int count =0;
	char eof = '\0';
	char newLine = '\n';

	while(!strcmp(source[i],&eof)){ //check if the loop reach the EOF
		if(srrcmp(source[i],newLine)) count++; 
	}
	return count;
}

void read_file(char* source, char* filename){
	FILE *fp = fopen(filename, "r");
	if (fp != NULL) {
	    /* Go to the end of the file. */
	    if (fseek(fp, 0L, SEEK_END) == 0) {
	        /* Get the size of the file. */
	        long bufsize = ftell(fp);
	        if (bufsize == -1) { 
	        	/* Error */
	        	perror("Read file Error");
	        }

	        /* Allocate our buffer to that size. */
	        source = malloc(sizeof(char) * (bufsize + 1));

	        /* Go back to the start of the file. */
	        if (fseek(fp, 0L, SEEK_SET) != 0) {
	        	/* Error */ 
	        	perror("file pointer Error");
	        }

	        /* Read the entire file into memory. */
	        size_t newLen = fread(source, sizeof(char), bufsize, fp);
	        if ( ferror( fp ) != 0 ) {
	            fputs("Error reading file", stderr);
	        } else {
	            source[newLen++] = '\0'; /* Just to be safe. */
	        }
	    }
	    fclose(fp);
	}

	free(source); /* Don't forget to call free() later! */
}