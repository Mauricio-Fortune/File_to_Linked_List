/*
*Mauricio Fortune *
*CPSC 2310 Fall 22 *
*UserName: mafortu *
*Instructor: Dr. Yvon Feaster *
*/

#include "functions.h"

// Add function: Adds node to the end of the list
void add(node_t **node, node_t **head){

    // If the head is NULL (No list created) then create the new head
    if(*head == NULL){
        *head = *node;
    }

    // Else, iterate to the end of the list and add it to the end
    else{
        node_t* temp;
        temp = *head;
        
        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = *node;
    }
    return;
}

// Read the node info from the input file, create a node and add it to the
// list
node_t* readNodeInfo(FILE* input){

    // The day, month and year will be read in as chars
    char day[5], month[5], year[7];

    // Variable that will contain the month
    int monthNum;

    // Allocate memory for a new node
    node_t* node = (node_t*)malloc(1*sizeof(node_t));

    // Read in the input which is all parsed by commas
    fscanf(input, 
    "%[^,]%*c %[^,]%*c %[^,]%*c %[^,]%*c %[^,]%*c %[^,]%*c %[^,]%*c %[^\n]%*c", 
    node->lName, node->fName, month, day, year,
     node->favSong, node->favPastime, node->whyCS);

    // Turn the month day and year into ints
    node->bday.month = atoi(month);
    node->bday.day = atoi(day);
    node->bday.year = atoi(year);
    node->next = NULL;

    return node;
}

// Calls functions to create the linked list
node_t* createList(FILE* input, node_t** head){
    
    // Keep reading till the file pointer is at the end of file
    while(!feof(input)){

        // Read the node info first, then add it to the list
        node_t* node = readNodeInfo(input);
        add(&node, head);
    }
    
    return *head;
}

// This prints out the linked list
void printList(FILE* output, node_t* head){

    // Double array containing the months of the year
    char monthArr[12][10]={"January", "February", "March", "April", "May",
    "June", "July", "August", "September", "October", "November", "December"};
    printBorder(output);
    fprintf(output, "\n");
    fprintf(output, "List Info: ");
    node_t* temp = head;

    // Keep printing till at the end of the linked list
    while(temp != NULL){
        fprintf(output, "\n");
        fprintf(output, "Name: %s %s\n", temp->fName, temp->lName);
        fprintf(output, "Date of Birth: %s %d, %d\n", 
        monthArr[temp->bday.month-1], temp->bday.day, temp->bday.year);
        fprintf(output, "Favorite Song: %s\n", temp->favSong);
        fprintf(output, "Favorite Pastime: %s\n", temp->favPastime);
        fprintf(output, "Why I Chose CS: %s\n", temp->whyCS);
        temp = temp-> next;
    }
    printBorder(output);
    return;
}

// Prints a border for the output
void printBorder(FILE* output){

    for(int i = 0; i < 80; i++){
        fprintf(output, "*");
    }
    return;
}

// Deallocate all the memory previously allocated
void deleteList(node_t** head){
    
    // two temp cariables
    node_t* temp;
    node_t* next;
    temp = *head;

    // Iterate through the Linked List and deallocate
    while(temp != NULL){
        
        next = temp->next;
        free(temp);
        temp = next;

    }

    return;
}
