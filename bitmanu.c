#include <stdio.h>
#include <string.h>
#include <stdint.h>

int main(){
	
	//01000001 01000010 01000011
	//010000 (01 0100)(0010 01)(0000 11)
	//010000 010100 001001 000011  ---> 16 20 9 3
	// 
	//unsigned char bit6_a = s[0] >> 2;
	//unsigned char tem_bit6_a = s[0] << 6;
	//unsigned char bit6_b = s[1] >> 2;
	//unsigned char tem_bit6_b = s[1] << 4;
	// add temp in 2nd main
	//bit6_b = tem_bit6_a ^ bit6_b;
	//bit6_b = bit6_b >> 2;
	//
	
	//unsigned char bit6_c = s[2] >> 4;
	//unsigned char tem_bit6_c = s[2] << 6;
	//bit6_c = bit6_c ^ tem_bit6_b;
	//bit6_c = bit6_c >> 2;
	
	//unsigned char bit6_d = s[2] << 2;
	//bit6_d = bit6_d >> 2;
	
	//printf("%c%c%c%c\n",table[bit6_a],table[bit6_b],table[bit6_c],table[bit6_d]); 
	
	char table[70] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	
	char s[20] = "it took me a day";
	
	int i=0;
	while(s[i] != '\0'){
		int bit;
		bit = i;
		unsigned char bit6_a = s[bit] >> 2;
		unsigned char tem_bit6_a = s[bit] << 6;
		unsigned char bit6_b = s[bit+1] >> 2;
		unsigned char tem_bit6_b = s[bit+1] << 4;
	
		bit6_b = tem_bit6_a ^ bit6_b;
		bit6_b = bit6_b >> 2;
	
	
		unsigned char bit6_c = s[bit+2] >> 4;
		unsigned char tem_bit6_c = s[bit+2] << 6;
		bit6_c = bit6_c ^ tem_bit6_b;
		bit6_c = bit6_c >> 2;
	
		unsigned char bit6_d = s[bit+2] << 2;
		bit6_d = bit6_d >> 2;
	
		printf("%c%c%c%c",table[bit6_a],table[bit6_b],table[bit6_c],table[bit6_d]); 
		i +=3;
	}              
	printf("\n");
}
