#include<stdio.h>
#include<string.h>
#include<time.h>
char shift_table[200];	//shift table array to check for shift spaces
void shift_table_creation(char test[])	//initialize all values in shift table
{
	int i;
	int len = strlen(test);
	for(i=0;i<128;i++)	//make all 128 ascii characters value as length of the string
		shift_table[i] = len;
	for(i=0;i<len-1;i++)	//input shift data in the array
		shift_table[test[i]] = len-1-i;	//pattern[i] will give ascii value of the character
	
}
int string_match(char pattern[],char test[])	// returns arrray index of the matched string
{
	//shift_table_creation(test);	// create shift table as per the sub string you want to search
	int len_pattern = strlen(pattern);
	int len_test = strlen(test);
	//printf("\nLength of pattern from which have to search =%d",len_pattern);
	//printf("\n Length of test pattern to search =%d",len_test);
	int i = len_test-1;	//to get index value
	while(i<len_pattern)
	{
		int k = 0;
		while((k<=len_test - 1)&&(pattern[i-k]==test[len_test-1-k]))
			k++;
		if(k == len_test)
			return i-len_test+1;	//return position of matched string
		else
			i = i + shift_table[pattern[i]];
	}
	return -1;	//element not found
} 
void main()
{
	char pattern[100],test[99];
	printf("Enter the data\n");
	gets(pattern);
	printf("Enter substring to search\n");
	gets(test);
	shift_table_creation(test);	
	int index = string_match(pattern,test);	//searching......
	printf("\nthe sub-string found at index \t : %d",index);
	int i;
	for(i=0;i<128;i++)
		printf(" %d ",shift_table[i]);
}
