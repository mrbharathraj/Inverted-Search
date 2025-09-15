#include "inverted_Search.h"

void file_validation_n_file_list(Flist **f_head, char *argv[])
{
    int i = 1, empty;
    while (argv[i] != NULL)
    {
        empty = isFileEmpty(argv[i]);
        if (empty == FILE_NOTAVAILABLE)
        {
            printf("File: %s is not available\n", argv[i]);
            i++;
            continue;
        }
        else if (empty == FILE_EMPTY)
        {
            printf("File: %s is empty\n", argv[i]);
            i++;
            continue;
        }
        else
        {
            int ret_val = to_create_list_of_files(f_head, argv[i]);
            if (ret_val == SUCCESS)
                printf("Successfully added file: %s\n", argv[i]);
            else if (ret_val == REPEATATION)
                printf("File %s is duplicated\n", argv[i]);
            else
                printf("File insertion failed\n");
            i++;
        }
    }
}

/* Fix: Implement isFileEmpty */
int isFileEmpty(char *filename)
{
    FILE *fptr = fopen(filename, "r");
    if (!fptr)
    {
        if (errno == ENOENT)
        {
            return FILE_NOTAVAILABLE;
        }
        return FAILURE;
    }

    fseek(fptr, 0, SEEK_END);
    if (ftell(fptr) == 0)
    {
        fclose(fptr);
        return FILE_EMPTY;
    }

    fclose(fptr);
    return SUCCESS;
}

/* Fix: Implement to_create_list_of_files */
int to_create_list_of_files(Flist **f_head, char *name)
{
    Flist *temp = *f_head;
    while (temp)
    {
        if (strcmp(temp->file_name, name) == 0)
        {
            return REPEATATION;
        }
        temp = temp->link;
    }

    Flist *new_node = malloc(sizeof(Flist));
    if (!new_node)
    {
        printf("Memory allocation failed\n");
        return FAILURE;
    }
    strcpy(new_node->file_name, name);
    new_node->link = *f_head;
    *f_head = new_node;

    return SUCCESS;
}