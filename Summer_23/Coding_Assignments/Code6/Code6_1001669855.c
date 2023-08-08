// Coding Assignment 6 - Trenton Laule - 1001669855

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
 
#define HASHTABLESIZE 30

typedef struct Coaster
{
    char *name;
    float G_Force;
    int max_height;
    int max_speed;
    char *manufacturer;
    char owner;
    char *park_location;
    int year_opened;
    int height_requirement;
    struct Coaster *next_ptr;
}
COASTER;

int CalculateHashIndex(char *HashValue)
{
    int string_len = strlen(HashValue);

    if(HashValue[string_len-1] == '\n');
        HashValue[string_len-1] = '\0';
    
    int i, sum = 0;

    for(i = 0; i<string_len; i++)
    {
        sum += HashValue[i];
    }
    //printf("%d\n", sum);
    return sum % HASHTABLESIZE;
}

void AddNode(COASTER *NewNode, COASTER *Credits[])
{
    int HashIndex = CalculateHashIndex(NewNode->name);

    if(Credits[HashIndex] == NULL)
    {
        #if PRINTINSERT
        printf("\nInserting %s at index %d\n", NewNode->name, HashIndex);
        #endif
        Credits[HashIndex] = NewNode;
    }
    else
    {
        COASTER *tempPtr = Credits[HashIndex];

        while(tempPtr->next_ptr != NULL)
        {
            tempPtr = tempPtr->next_ptr;
        } 
        tempPtr->next_ptr = NewNode;
        #if PRINTINSERT
        printf("\nInserting %s at index %d\n", NewNode->name, HashIndex);
        #endif
    }
}

void FreeDynamicMemory(COASTER *Credits[])
{
    COASTER *TempPtr = NULL, *NextPtr = NULL;

    for(int i = 0; i < HASHTABLESIZE; i++)
    {
        TempPtr = Credits[i];

        if(TempPtr != NULL)
        {
            while(TempPtr != NULL)
            {
                free(TempPtr->name);
                free(TempPtr->manufacturer);
                free(TempPtr->park_location);
                NextPtr = TempPtr->next_ptr;
                free(TempPtr);
                TempPtr = NextPtr;
            }
        }
    }
}

int DeleteNode(COASTER *Credits[])
{
    char LookupName[100] = {};
    int result = 0;

    printf("Enter a name of a Coaster to delete from your Credits ");
    fgets(LookupName, 100-1, stdin);
    fgets(LookupName, sizeof(LookupName)-1, stdin);

    int HashIndex = CalculateHashIndex(LookupName);

    COASTER *TempPtr = Credits[HashIndex], *PrevPtr = NULL;

    if (TempPtr == NULL)
    {
        printf("\n\nCoaster %s is not in your credits\n\n", LookupName);
        result = 0;
    }
    else
    {
        while(TempPtr != NULL)
        {
            if(strcmp(TempPtr->name, LookupName) == 0)
            {
                if(TempPtr == Credits[HashIndex])
                {
                    Credits[HashIndex] = TempPtr->next_ptr;
                    printf("\nCoaster %s has been deleted from your Credits\n\n", TempPtr->name);
                    free(TempPtr);
                    TempPtr = NULL;
                }
                else
                {
                    PrevPtr->next_ptr = TempPtr->next_ptr;
                    printf("\nCoaster %s has been deleted from your Credits\n\n", TempPtr->name);
					free(TempPtr);
					TempPtr = NULL;
                }
                result = 1;
            }
            else
            {
                PrevPtr = TempPtr;
                TempPtr = TempPtr->next_ptr;
            }
        }
        if(result == 0)
        {
            printf("\n\nCoaster %s is not in your credits\n\n", LookupName);
        }
    }
    return result;
}

void DisplayHashTable(COASTER *Credits[])
{
	int i;
	COASTER *TempPtr = NULL;
	
	for (i = 0; i < HASHTABLESIZE; i++) 
	{
		TempPtr = Credits[i];

		printf("\nCredits[%d]-", i);
		
		if (TempPtr != NULL) 
        {
			while (TempPtr != NULL)
			{
				printf("%s|", TempPtr->name);
				TempPtr = TempPtr->next_ptr;
			}
		}
	}
}

void ShowByLetter(COASTER *Credits[])
{
	int i;
	COASTER *TempPtr = NULL;
	char LookupLetter = 'A';

	printf("\n\nEnter a letter of the alphabet ");
	scanf(" %c", &LookupLetter);
	LookupLetter = toupper(LookupLetter);

	for (i = 0; i < HASHTABLESIZE; i++) 
	{
		TempPtr = Credits[i];

		if (TempPtr != NULL) 
		{
			while (TempPtr != NULL)
			{
				if (toupper(TempPtr->name[0]) == LookupLetter)
				{
					printf("%s\n", TempPtr->name);
				}
				TempPtr = TempPtr->next_ptr;
			}
		}
	}
}

void ShowByName(COASTER *Credits[])
{
    COASTER *TempPtr = NULL;
    char LookupName[100] = {};
    char gforce[10]= {};
    int FoundIt = 0;

    printf("\n\nEnter Coaster's name ");
    fgets(LookupName, 100-1, stdin);
    fgets(LookupName, sizeof(LookupName)-1, stdin);
    #if TIMING
	clock_t start, end;
	start = clock();
	#endif
    for(int i = 0; i < HASHTABLESIZE; i++)
    {
        TempPtr = Credits[i];

        if(TempPtr != NULL)
        {
            while(TempPtr != NULL)
            {
                if(strcmp(TempPtr->name, LookupName) == 0)
                {
                    #if TIMING
                    end = clock();
                    printf("\n\nSearch took %ld tics\n\n", end-start); 
                    #endif
                    
                    FoundIt = 1;
                    printf("\n\n%s\n", TempPtr->name);

                    printf("G-Force\t\t%.2f G's\n", TempPtr->G_Force);
                    printf("Max Height\t\t%d",TempPtr->max_height);
                    printf("Max Speed\t\t%d", TempPtr->max_speed);
                    printf("Manufacturer\t\t%s", TempPtr->manufacturer);
                    printf("Owning Company\t\t");
                    switch (TempPtr->owner)
                    {
                    case 'S':
                        printf("Six Flags Entertainment Corporation");
                        break;
                    case 'W':
                        printf("SeaWorld Parks & Entertainment");
                        break;
                    case 'C':
                        printf("Cedar Fair Entertainment Company");
                        break;
                    case 'H':
                        printf("Herschend Family Entertainment");
                        break;
                    case 'D':
                        printf("The Walt Disney Company");
                        break;
                    case 'U':
                        printf("Universal Destinations & Experiences");
                        break;
                    case 'Y':
                        printf("Hershey Entertainment and Resorts Company");
                        break;
                    default:
                        printf("Company Unknown");
                        break;
                    }
                    printf("\n");
                    printf("Park Location\t\t%s\n", TempPtr->park_location);
                    printf("Year Opened\t\t%d\n", TempPtr->year_opened);
                    printf("Height Requirement\t\t%d\n", TempPtr->height_requirement);
                }
                TempPtr = TempPtr->next_ptr;
            }
        }
    }

    if(FoundIt == 0)
        printf("\n\nCoaster %s not found in Credits\n\n", LookupName);
}

void AddNewCoaster(COASTER *Credits[])
{
    int HashIndex = 0;
    COASTER *NewNode;
    char TempBuffer[100] = {};

    NewNode = malloc(sizeof(COASTER));
    NewNode->next_ptr = NULL;

    printf("\n\nEnter new Coaster's name ");
    fgets(TempBuffer, 100-1, stdin);
    TempBuffer[strlen(TempBuffer)-1] = '\0';
    NewNode->name = malloc(strlen(TempBuffer)*sizeof(char)+1);
    strcpy(NewNode->name, TempBuffer);

    printf("\n\nEnter %s's G-force (ex. 4.1) ", NewNode->name);
    scanf("%f", &(NewNode->G_Force));

    printf("\n\nEnter %s's Max Height as an integer ", NewNode->name);
    scanf("%d", &(NewNode->max_height));

    printf("\n\nEnter %s's Max Speed as an integer ", NewNode->name);
    scanf("%d", &(NewNode->max_speed));

    fgets(TempBuffer, sizeof(TempBuffer)-1, stdin);

    printf("\n\nEnter %s's Manufacturer ", NewNode->name);
    fgets(TempBuffer, 100-1, stdin);
    TempBuffer[strlen(TempBuffer)-1] = '\0';
    NewNode->manufacturer = malloc(strlen(TempBuffer)*sizeof(char)+1);
    strcpy(NewNode->manufacturer,TempBuffer);

    printf("\n\nEnter %s's Owning Company as a char (S/C/U/H/Y/D) ", NewNode->name);
    scanf(" %c", &(NewNode->owner));
    NewNode->owner = toupper(NewNode->owner);

    fgets(TempBuffer, sizeof(TempBuffer)-1, stdin);

    printf("");

    
}