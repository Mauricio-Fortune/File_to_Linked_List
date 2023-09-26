/*
*Mauricio Fortune *
*CPSC 2310 Fall 22 *
*UserName: mafortu *
*Instructor: Dr. Yvon Feaster *
*/

#include "functions.h"


int main(int argc, char * argv[])
{ 
    // Make sure the program was given 3 command line arguments
    // argv[0] = ./a.out argv[1] = inputFile argv[2] = outputFile
    assert(argc == 3);

    // Open input file for reading
    FILE* input = fopen(argv[1], "r");
    
    // Open output file to write
    FILE* output = fopen(argv[2], "w");

    // Make sure files got opened
    assert(input != NULL);
    assert(output != NULL);
    
    //Create a node to pass in to the files
    node_t *head = NULL;

    //Function Calls
    createList(input, &head);

    // Print out the list
    printList(output, head);

    // Delete the list
    deleteList(&head);

    // Close both files that were opened
    fclose(input);
    fclose(output);

    return 0;

}
