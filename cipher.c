/*
Program t o implement a text cipher

Author Aly Mohamed 	Sodtware Eng	March 13th 2021		Initial try 
Author Aly Mohamed      Sodtware Eng    March 14th 2021 	found the function to encrypt
Author Aly Mohamed      Sodtware Eng    March 15th 2021 	wrote error messages
Author Aly Mohamed      Sodtware Eng    March 17th 2021 	wrote bash file	
*/

#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[]) {


	//argv2 is the word
	//argv0 is supposed to be -e
	//argv1 is the key

	if(argc!=4) {
	printf("Usage : ./cipher [-e|-d] <key> <MESSAGE> \n");
	return 1;
	}

	if(argv[1][0] != '-'){	
	printf("Error %s is not a valid option \n", argv[2]);
	return 1;
	}

	if(argv[1][1] != 'd' && argv[1][1] != 'e'){
	printf("Error %s is not a valid option \n", argv[1]);
	return 1;
	}
	
	if(argv[2][0] -'0' != 1 && argv[2][1] != '\0'){
	printf("Error %s is not a valid key \n", argv[2]);
        return 1;
	}


	if(argv[2][0] -'0' == 1 && (argv[2][1] - '0' != 0)){
	printf("Error %s is not a valid key \n", argv[2]);
	return 1;
	}
	
	if(argv[2][0]-'0' > 9 || argv[2][0]-'0' <0){
	printf("Error %s is not a valid key \n", argv[2]);
	return 1;
	}	

	int size = 0;
	
	//count size of input word
	while(1){
		if(argv[3][size]!= '\0') size++;
		else break;
	}
	int key = argv[2][0]-'0';
	if(size<=key){

	printf("%s\n",argv[3]);	
	return 1;
	}

//	printf("size %d, key %d", size, key);
	if(size==0){
	return 0;
	}
	
	//if all inputs are correct and we want to encrypt
	if(argv[1][0]=='-' && argv[1][1]=='e'){

//		int key = argv[2][0]-'0';
		int gap = (key-2)*2+1;
		int i = 0;
		int row = 0;
		int up = 1;

	if(argv[2][1] - '0' == 0 && argv[2][0]-'0'==1) key = 10;

		while(1){

			//base case
			if((i>=size) && (row==key-1)){
				printf("\n");
				break;
			}

			//we are at the end of the row
			if((i>=size) && row!=key-1){
				row++;
				i=row;
			}
			
			//we are on an even round ,so we are going down
			if((int) i/(key-1)%2==0) up=0;
			else up=1;
			
			//gap if going up
			if(up==1){
				gap= (row-1)*2+1;
				i+=gap+1;
				putchar(argv[3][i-gap-1]);

			}

			//gap if going down
			else{
				gap=(key-row-2)*2+1;
				i+=gap+1;
				putchar(argv[3][i-gap-1]);
			}


		}

	}
	if(argv[1][0]=='-' && argv[1][1]=='d'){

	int gap = (key-2)*2+1;
	int row=0;
	int size=0;	
	while(1){
                if(argv[3][size]!= '\0') size++;
                else break;
        }
	char decrypt[key][size];

	int i=0;
		int j=0;
		
		int iteration = 0;
		for(int c = 0; c<size;c++) {
			
			decrypt[i][j]=argv[3][c];
//			System.out.println(decrypt[i][j] + " row= " + i + ", col= " + j);
			
			
			if(iteration%2==0 ) {
				
				gap = (key-row-2)*2+1;
				
				}
			else {
				if(row!=0) gap = (row-1)*2+1;
			}
			
			if(j+gap+1>=size) {
				//switch rows

				
				row++;
				i=row;
				j=row;
				iteration=0;

			}
			else {
				if(iteration%2==0 ) {
					gap = (key-row-2)*2+1;
					if(row==key-1) gap = (key-2)*2+1;
					
					j+=gap+1;
					iteration++;
				}
				else {
					if(row!=0) gap = (row-1)*2+1;
					j+=gap+1;
					iteration++;
				}

			}
		}
		int x=0;
		int y=0;
		int up=1;
		
		while(x<size) {
			printf("%c",decrypt[y][x]);
			if(y==key-1 || y==0) {
				if(up==0) up = 1;
				else up=0;
			}
			if(up!=1) {
				x++;
				y++;
			}
			else {
				x++;
				y--;
			}
		if(x>=size) printf("\n");
		}
	

	
	}
	return 0;
}

