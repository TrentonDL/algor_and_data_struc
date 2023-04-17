#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "spell.h"

/*  Suggestions
- When you work with 2D arrays, be careful. Either manage the memory yourself, or
work with local 2D arrays. Note C99 allows parameters as array sizes as long as 
they are declared before the array in the parameter list. See: 
https://www.geeksforgeeks.org/pass-2d-array-parameter-c/

Worst case time complexity to compute the edit distance from T test words
 to D dictionary words where all words have length MAX_LEN:
Student answer:  Theta(............)


Worst case to do an unsuccessful binary search in a dictionary with D words, when 
all dictionary words and the searched word have length MAX_LEN 
Student answer:  Theta(............)
*/


int min(int x, int y, int z){
	if(x < y && x < z)
		return x;
	else if(y < x && y < z)
		return y;
	else 
		return z;
}

int Dist(char * f, char * s, int i, int j){
	if(j == 0)
		return i;

	if(i == 0)
		return j;

	if (f[i-1] == s[j - 1])
		return Dist(f, s, i-1, j-1);

	return 1 + min(Dist(f, s, i, j-1), Dist(f, s, i-1, j), Dist(f, s, i-1, j-1));
}

void p_table(char * v_string, char * h_string, int * arr[], int v, int h){
	printf("\n  |");
	for(int i=0;i<=h; i++){
		if(i == 0)
			printf("   |");
		else
			printf("  %c|", h_string[i-1]);
	}
	printf("\n---");
	for(int i=0;i<=h; i++){
		printf("----");
	}
	printf("\n  |");

	for(int j=0; j<=h; j++){
		printf("  %d|", j);
	}
	printf("\n---");
	for(int i=0;i<=h; i++){
		printf("----");
	}
	printf("\n");
	for(int k=0; k<v; k++){
		printf(" %c|", v_string[k]);
		printf("  %d|", k);
		for(int c=0;c<h; c++){
			printf("  %d|", arr[k][c]);
		}
		printf("\n---");
		for(int c=0;c<=h; c++){
			printf("----");
		}
		printf("\n");
	}
	printf("\n");
}

void fill_dictonary(char** dictonary, char str[]){
	int length = strlen(str);
	if(length != 0){
		*dictonary = calloc(length, sizeof(char));
		*dictonary = str;
	}
}

/*
Parameters:
  - first_string - pointer to the first string (displayed vertical in the table)
  - second_string - pointer to the second string (displayed horizontal in the table)
  - print_table - If 1, the table with the calculations for the edit distance will be printed.
                  If 0 (or any value other than 1)it will not print the table
Return:  the value of the edit distance
*/
int edit_distance(char * first_string, char * second_string, int print_table){
	int f_length = strlen(first_string);
	int s_length = strlen(second_string);
	int* edit_arr[f_length];
	//int (*edit_arr)[f_length] = calloc(s_length, f_length * sizeof(int));
	for(int i=0; i < f_length; i++){
		edit_arr[i] =(int *)malloc(s_length * sizeof(int));
	}


	for(int i = f_length - 1; i >= 0; i--){
		for(int j = s_length - 1; j >= 0; j--){
			int equals = 0;

			if(first_string[i] != second_string[j])
				equals = 2;

			edit_arr[i][j] = Dist(first_string, second_string, i, j);
			//min(Dist(first_string, second_string, i-1, j) +1,
			//					Dist(first_string, second_string, i, j-1) +1,
			//					Dist(first_string, second_string, i-1, j-1) + equals);
		}
	}

	if(print_table == 1){
		p_table(first_string, second_string, edit_arr, f_length, s_length);
	}

	//Dist(first_string, second_string, f_length, s_length);

	return edit_arr[f_length-1][s_length-1];  // replace this line with your code
}

/*
Parameters:
  - testname - string containing the name of the file with the paragraph to spell check, includes file extenssion e.g. "text1.txt" 
  - dictname - name of file with dictionary words. Includes file extenssion, e.g. "dsmall.txt"
Behavior: If any of the files cannot be open displays a message and returns. (Does not exit the program.)
*/
void spell_check(char * testname, char * dictname){
	FILE * fp_testname = NULL;
	FILE * fp_dictname = NULL;

	fp_dictname = fopen(dictname, "r");
	if (fp_dictname == NULL)
	{
		printf("Could not open %s. Exit\n", *dictname);
		return;
	}

	fp_testname = fopen(testname, "r");
	if(fp_testname == NULL){
		printf("Could not open %s. Exit\n", *testname);
		return;
	}

	char *dictionary[1] = {};
	int dict_size = 1;
	fscanf(fp_dictname, "%d ", dict_size);
	for(int j=0; j<dict_size; j++){
		dictionary[j] = malloc(sizeof(char*));
	}
	printf("dictionary allocated\n");

	for(int i = 0; i < dict_size; i++){
		char str[20] = {};
		fscanf(fp_dictname, "%s ", str);
		if(*str != EOF || str != NULL){
			fill_dictonary(&dictionary[i], str);
			printf("%s\n", *dictionary[i]);
		}
	}
}
