#include "inverted_Search.h"

/* Function to create the database */
int create_database(Flist *f_head, Wlist *head[])
{
    while (f_head)
    {
        read_datafile(f_head, head, f_head->file_name);
        f_head = f_head->link;
    }
    return SUCCESS;
}

/* Function to read words from a file and update Wlist */
Wlist *read_datafile(Flist *file, Wlist *head[], char *filename)
{
    FILE *fptr = fopen(filename, "r");
    if (!fptr)
    {
        printf("Error: Could not open file %s\n", filename);
        return NULL;
    }

    char word[WORD_SIZE];
    while (fscanf(fptr, "%s", word) != EOF)
    {
        int index = tolower(word[0]) - 'a';
        if (index < 0 || index > 25)
            index = 26;

        Wlist *temp = head[index];
        int flag = 1;

        while (temp)
        {
            if (strcmp(temp->word, word) == 0)
            {
                update_word_count(&temp, filename);
                flag = 0;
                break;
            }
            temp = temp->link;
        }

        if (flag == 1)
        {
            insert_at_last(&head[index], word);
        }
    }
    fclose(fptr);
    return *head;
}

/* Function to update word count in Wlist */
int update_word_count(Wlist **head, char *file_name)
{
    Ltable *temp = (*head)->Tlink;

    while (temp)
    {
        if (strcmp(temp->file_name, file_name) == 0)
        {
            temp->word_count++;
            return SUCCESS;
        }
        temp = temp->table_link;
    }

    Ltable *new_node = (Ltable *)malloc(sizeof(Ltable));
    if (!new_node)
    {
        printf("Memory allocation failed\n");
        return FAILURE;
    }
    strcpy(new_node->file_name, file_name);
    new_node->word_count = 1;
    new_node->table_link = (*head)->Tlink;
    (*head)->Tlink = new_node;
    (*head)->file_count++;
    return SUCCESS;
}