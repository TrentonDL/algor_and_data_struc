/* Updated 2/25/2021 - Alexandra Stefan
 */

#include <stdlib.h>
#include <stdio.h>

#include "list.h"

/* compile:
gcc -g test_list.c list.c
run:
./a.out
run with Valgrind:
valgrind --leak-check=full --show-leak-kinds=all ./a.out
 */

int main()
{
   int arr[] = {9,1,7,260};
   int N = sizeof(arr)/sizeof(int);

   struct node * L = array_2_list(arr, N);

   print_list_pointer(L);

   L = delete_node(L, NULL);

   print_list_pointer(L);

   nodePT ptr = new_node(25);

   L = insert_node(L, NULL, ptr); // try to run just: insert_node(L, NULL, ptr); see Valrind error.

   print_list_pointer(L);

   int length = compute_length(L);
   printf("The length of the list is %d.\n", length);

   // https://en.wikipedia.org/wiki/Endianness
   printf("\nSee below the integers in the array are: \n");
   for(int i =0; i<N; i++){
	   printf("%p, ", &arr[i]);
   }
   printf("\nsize of int is: %ld\n", sizeof(int));

   destroy_list(L);

   return 0;
}