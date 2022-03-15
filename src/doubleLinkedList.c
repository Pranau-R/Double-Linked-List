/*

Module: doubleLinkedList.c

Function:
    To create a Menu to add, delete, display and search names using double linked list.

Copyright notice:
    This file copyright (C) 2022 by

    MCCI Corporation
    3520 Krums Corners Road
    Ithaca, NY 14850

    An unpublished work. All rights reserved.

    This file is proprietary information, and may not be disclosed or
    copied without the prior permission of MCCI Corporation.

Author:
    Pranau R, MCCI Corporation   March 2022

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
    {
    struct node *prev;
    char name[20];
    struct node *next;
    };

struct node *head, *ptr;

/****************************************************************************\
|
|   Functions.
|
\****************************************************************************/

/*

Name: add()

Function:
    To add new names on the list.

Definition:
    void add (
        No arguments
        );

Description:
    It is a void function which returns no value. The character type argument is used here to store "strings" from user in a list.

Returns:
    Functions returning type void: Nothing.

*/

void add()
    {
    char insert_name[20];

    printf("You selected Insertion of Name... \n");

    printf("Enter a Name you wish to Add: ");
    scanf("%s", insert_name);

    struct node *temp;

    temp = (struct node *) malloc (sizeof (struct node));
    strcpy(temp -> name, insert_name);

    if (head == NULL)
        {
        printf("haha\n");
        head = temp;
        temp -> next = NULL;
        printf("hehe\n");
        }
    else
        {
        printf("lol\n");
        ptr = head;
        while (ptr -> next != NULL && strcmp(ptr -> name, insert_name) < 0)
            {
            printf("hi\n");
            ptr = ptr -> next;
            printf("hello\n");
            }
        printf("OUT\n");
        temp -> next = ptr -> next;
        temp -> prev = ptr;
        ptr -> next = temp;
        ptr -> next -> prev =temp;
        printf("Thats good\n");
        //ptr -> next = temp;
        //ptr -> next -> prev =temp;
            }
        }

/*

Name: display()

Function:
    To display all the entries in a List.

Definition:
void display (
        No Arguments
        );

Description:
    This function has no return value and no arguments. It is used to display the list whenever the function is called.

Returns:
    Functions returning type void: Nothing.

*/

void display()
    {
    ptr = head;
    printf("%s", ptr -> name);

    while ( ptr -> next != NULL)
        {
        ptr = ptr -> next;
        printf(" -> %s", ptr -> name);
        }

    printf("\n");
    printf("\n");
    }

/****************************************************************************\
|
|   Code.
|
\****************************************************************************/

void main()
    {
    void add();
    //void delete();
    void display();

    int ch;

    printf("\n");
    printf("-----------------------------------------------------\n");
    printf("This is doubleLinkedList.exe v1.0.0\n");
    printf("-----------------------------------------------------\n");
    printf("\n");
    printf("======== MENU ======== \n");
    printf("1. Add Entry: \n");
    printf("2. Delete Entry: \n");
    printf("3. Display Entries: \n");
    printf("4. exit \n");
    printf("\n");

    while(1)
        {
        printf("Enter the Choice: \n");
        scanf("%d", &ch);

        switch(ch)
            {
            case 1:
                {
                add();
                display();
                break;
                }

            case 2:
                exit(0);

            default:
                printf("Invalid Entry!!!\n");
            }
        }
    }