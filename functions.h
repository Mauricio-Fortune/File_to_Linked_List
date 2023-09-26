/*
*Mauricio Fortune *
*CPSC 2310 Fall 22 *
*UserName: mafortu *
*Instructor: Dr. Yvon Feaster *
*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stddef.h>
#include <string.h>

//implement BDay struct here
struct birthday{
    int month;
    int day;
    int year;
};

//implement node_t struct here
//use typedef on this struct!
typedef struct node{

    char fName[20];
    char lName[20];
    char favSong[100];
    char favPastime[100];
    char whyCS[500];
    struct birthday bday;
    struct node* next;

}node_t;

/*
* Parameters: node_t**node is the node that need to be added
*             node_t**head is the head of the linkedlist
*
* Return: None
* This function is used to add nodes to the linkedlist
*/
void add(node_t **node, node_t **head);

/*
* Paramters: input is the input file pointer
*
* Return: a node that is full of data
* This function will be used to read the data from the input file.
*/
node_t* readNodeInfo(FILE* input);

/*
* Parameters: FILE* is the input file pointer
*            node_t** is the head of the list
*
* Return: a pointer to the head of the list
* Loops to read each record in the file then adds the record
* to the list
*/
node_t* createList(FILE*, node_t**);

/*
* Parameters: FILE* is the output file pointer
*             node_t* is the head of the LL 
*
* Return: None
* Prints output to the output file
*/
void printList(FILE*, node_t*);

/*
* Parameters: output file pointer
*
* Return: None
* Prints a border of 80 * to the output file
*/
void printBorder(FILE*);

/*
* Parameters: node_t** head of the LL
*
* Return: None
* Frees the memory back to the system
*/
void deleteList(node_t**);
#endif
