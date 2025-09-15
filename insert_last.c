#include "inverted_Search.h"

int insert_at_last(Wlist **head, char *data)
{
    Wlist *new = malloc(sizeof(Wlist));
    if (!new)
        return FAILURE;
    
    new->file_count = 1;
    strcpy(new->word, data);
    new->Tlink = NULL;
    new->link = NULL;

    update_link_table(new);

    if (*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }

    Wlist *temp = *head;
    while (temp->link)
    {
        temp = temp->link;
    }
    temp->link = new;
    return SUCCESS;
}

/* Function to update the link table */
int update_link_table(Wlist *head)
{
    Ltable *new = malloc(sizeof(Ltable));
    if (!new)
        return FAILURE;
    
    new->word_count = 1;
    strcpy(new->file_name, fname);  // Fix: fname is now properly defined in main.c
    new->table_link = head->Tlink;
    head->Tlink = new;
    
    return SUCCESS;
}