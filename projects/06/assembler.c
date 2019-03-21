#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//function to check for type of command 
int istype(char line[]){
	for (int i = 0; i < 256; i++){
		if (!isspace(line[i]) && line[i] != '\0'){
			if (line[i] == '/'){
				return 1;
			}
			else if (line[i] == '@'){
				return 2;
			}
			else if (line[i] == '('){
				return 3;
			}
			else{
				return 0;
			}
		}
	}
	return 1;
}

int main(int argc, char *argv[])
{
	//check if there are 2 commandline arguments
	if (argc != 3){
		printf("Incorrect number of arguments.\nCorrect format: \"./assembler input_name.asm output_name.hack\"\n");
		exit(1);
	}

	FILE *inputfile;
	FILE *outputfile;
	char line[256];
	//reset buffer
	memset(line, 0, sizeof line);

	//open input file and check if it exists
	if ((inputfile = fopen(argv[1], "r")) == NULL){
		printf("Error opening file!\n");
		exit(1);
	}

	//open output file for writing
	outputfile = fopen(argv[2], "w");

	//read lines from input file
	while (fgets(line, sizeof line, inputfile) != NULL)
    {
    	int type = istype(line);
    	//skip comments and new lines
    	if (type == 1){
    		memset(line, 0, sizeof line);
    		continue;
    	}
    	//check if is A command and write to output file
    	else if (type == 2){
    		//printf("A_COMMAND\n");
    		fprintf(outputfile, "A_COMMAND\n");
    	}
    	//check if is L command and write to output file
    	else if (type == 3){
    		//printf("L_COMMAND\n");
    		fprintf(outputfile, "L_COMMAND\n");
    	}
    	//check if is C command and write to output file
    	else {
    		//printf("C_COMMAND\n");
    		fprintf(outputfile, "C_COMMAND\n");
    	}
    	//reset buffer
    	memset(line, 0, sizeof line);
    }

    memset(line, 0, sizeof line);
    rewind(inputfile);

    	//read lines from input file
	while (fgets(line, sizeof line, inputfile) != NULL)
    {
    	int type = istype(line);
    	//skip comments and new lines
    	if (type == 1){
    		memset(line, 0, sizeof line);
    		continue;
    	}
    	//check if is A command and write to output file
    	else if (type == 2){
    		//printf("A_COMMAND\n");
    		fprintf(outputfile, "A_COMMAND\n");
    	}
    	//check if is L command and write to output file
    	else if (type == 3){
    		//printf("L_COMMAND\n");
    		fprintf(outputfile, "L_COMMAND\n");
    	}
    	//check if is C command and write to output file
    	else {
    		//printf("C_COMMAND\n");
    		fprintf(outputfile, "C_COMMAND\n");
    	}
    	//reset buffer
    	memset(line, 0, sizeof line);
    }
    //close input and output files
    fclose(outputfile);
    fclose(inputfile);
}