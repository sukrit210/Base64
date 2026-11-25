#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	
	//00000000 .010000.01 0100.0010 01.000011
	//010000 (01 0100)(0010 01)(0000 11)
    //
	//oo010000 oo010100 oo00.1001 oo000011  ---> 16 20 9 3
	
	char table[70] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	uint8_t buff[4];
	uint32_t byte[4];
	size_t n;
	FILE *target;
	if(argc != 2){
		printf("syntax error :: ./de file_name\n");
		exit(EXIT_FAILURE);
	}
	if((target = (fopen(argv[1],"rb"))) == NULL){
			printf("file not found\n");
			exit(EXIT_FAILURE);
	}
	while((n = fread(buff,1,sizeof(buff),target)) > 0){
        
		int i,j;
        for(i=0;i<4;i++){
            if(buff[i] == '='){
                byte[i] = 0;
            }
            for(j=0;j<64;j++){
                if(buff[i] == table[j]){
                    byte[i] = j;
                }
            }
            //printf("byte: %d\n",byte[i]);
            
        }
        uint32_t byte_set = ((byte[0] << 18) | (byte[1] << 12) | (byte[2] << 6) | (byte[3]));
        uint8_t b1,b2,b3;
        b1 = (byte_set >> 16);
        b2 = ((byte_set << 16) >> 24);
        b3 = ((byte_set << 24) >> 24);
        printf("%c%c%c",b1,b2,b3);
        

		memset(buff,0,sizeof(buff));
		}
		
		putchar('\n');
	    fclose(target);
	
}