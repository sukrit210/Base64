#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	
	//00000000 .010000.01 0100.0010 01.000011.
	//010000 (01 0100)(0010 01)(0000 11)
	//010000 010100 001001 000011  ---> 16 20 9 3
	
	char table[70] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	uint8_t buff[3];
	
	size_t n;
	FILE *target;
	if(argc != 2){
		printf("syntax error\n");
		exit(EXIT_FAILURE);
	}
	if((target = (fopen(argv[1],"rb"))) == NULL){
			printf("file not found\n");
			exit(EXIT_FAILURE);
	}
	while((n = fread(buff,1,sizeof(buff),target)) > 0){
		if(n == 3){
			uint32_t block = ((buff[0] << 16) | (buff[1] << 8) | (buff[2]));
			uint8_t b1 = (block >> 18);
	        uint8_t b2 = ((block << 14) >> 26);
	        uint8_t b3 = ((block << 20) >> 26);
	        uint8_t b4 = ((block << 26) >> 26);
	        printf("%c%c%c%c",table[b1],table[b2],table[b3],table[b4]);
			}
			
		else if(n == 2){
			uint32_t block = ((buff[0] << 16) | (buff[1] << 8) | (buff[2]));
			uint8_t b1 = (block >> 18);
	        uint8_t b2 = ((block << 14) >> 26);
	        uint8_t b3 = ((block << 20) >> 26);
	        char b4 = '=';
	        printf("%c%c%c%c",table[b1],table[b2],table[b3],b4);
		    }
		    
		else if((n == 1) && (buff[0] != '\n') && (buff[0] != '\r')){
		    uint32_t block = ((buff[0] << 16) | (buff[1] << 8) | (buff[2]));
			uint8_t b1 = (block >> 18);
	        uint8_t b2 = ((block << 14) >> 26);
	        char b3 = '=';
	        char b4 = '=';
	        printf("%c%c%c%c",table[b1],table[b2],b3,b4);
		}
		memset(buff,0,sizeof(buff));
		}
		if(n==0){
		putchar('\n');
	    fclose(target);
	}
	
	
	
	
	
	
	
	
	
	
}

	
	
	
	
	
	
	
	
	
	
	
	

