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
    void add ();
    
Parameter and Arguments:
    It has no data and no arguments

Description:
    It is a void function which returns no value.

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
        head = temp;
        }
    else if (strcmp (head -> name, temp -> name) >= 0)
        {
        temp -> next = head;
        temp -> next -> prev = temp;
        head = temp;
        }
    else
        {
        ptr = head;
        while (ptr -> next != NULL && strcmp(ptr -> next -> name, insert_name) < 0)
            {
            ptr = ptr -> next;
            }

        temp -> next = ptr -> next;
        temp -> prev = ptr;
        ptr -> next = temp;
        ptr -> next -> prev =temp;
        }
    }

/*

Name: delete()

Function:
    To delete a given name from the list.

Definition:
    void delete();

parameter and arguments:
    It has no data and no arguments.

Description:
    It is a void function which returns no value.

Returns:
    Functions returning type void: Nothing.

*/

void delete()
    {
    char delete_name[20];

    printf("You selected Deletion of Name... \n");

    printf("Enter a Name you wish to delete: ");
    scanf("%s", delete_name);

    struct node *pos;

    ptr = head;
    pos = ptr;

    while (strcmp (delete_name, ptr -> name) != 0)
        {
        if(ptr -> next == NULL)
            {
            printf("The name you entered is not present in the List!!\n");
            break;
            }
        else
            {
            pos = ptr;
            ptr = ptr -> next;
            }
        }

    if (ptr == head)
        {
        head = ptr -> next;
        }
    else if (ptr -> next == NULL)
        {
        ptr = pos -> next;
        pos -> next = NULL;
        }
    else
        {
        ptr = pos -> next;
        pos -> next = ptr -> next;
        ptr -> next -> prev = pos;
        }

    free (ptr);
    }

/*

Name: search()

Function:
    To search a name and to display the previous name and next name of searched name.

Definition:
    void search ();

Parameter and Arguments:
    It has no data and no arguments.

Description:
    This function has no return value and no arguments. .

Returns:
    Functions returning type void: Nothing.

*/
void search ()
    {
    char search_name[20];

    printf("You selected Search a Name... \n");

    printf("Enter a Name you wish to Search: ");
    scanf("%s", search_name);

    struct node *temp;

    temp = (struct node *) malloc (sizeof (struct node));

    strcpy(temp -> name, search_name);

    struct node *pos;

    ptr = head;
    pos = ptr;

    while (strcmp (search_name, ptr -> name) != 0)
        {
        if(ptr -> next == NULL)
            {
            printf("The name you entered is not present in the List!!\n");
            break;
            }
        else
            {
            pos = ptr;
            ptr = ptr -> next;
            }
        }

    if (ptr == head)
        {
        ptr = pos -> next;
        printf("There is no previous name in this List for your search!!! \n");

        printf("The next name is: %s \n", pos -> next -> name);
        }
    else if (ptr -> next == NULL)
        {
        ptr = pos -> next; 
        printf("The previous name is: %s \n", pos -> name);

        printf("There is no next name in this list for your search!!! \n");
        }
    else
        {
        ptr = pos -> next;
        printf("The previous name is: %s \n", pos -> name);

        printf("The next name is: %s \n", ptr -> next -> name);
        }
    }
    

/*

Name: display()

Function:
    To display all the entries in a List.

Definition:
    void display ();

parameter and arguments:
    It has no data and no arguments.

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
    void delete();
    void display();
    void search();

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
    printf("4. Search Entries: \n");
    printf("5. Exit: \n");
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
                {
                if (head == NULL)
                    {
                    printf("List is Empty, Deletion is not Possible!!\n");
                    break;
                    }
                else
                    {
                    delete();
                    display();
                    break;
                    }
                }
            case 3:
                {
                display();
                break;
                }
            case 4:
                {
                if (head == NULL)
                    {
                    printf("List is Empty, Search is not Possible!!\n");
                    break;
                    }
                else
                    {
                    search();
                    display();
                    break;
                    }
                }
            case 5:
                exit(0);

            default:
                printf("Invalid Entry!!!\n");
            }
        }
    }