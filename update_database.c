#include "inverted_Search.h"

/* Fix: Ensure isFileEmpty is properly linked */
int update_database(Wlist *head[], Flist **f_head)
{
    char file_name[FNAME_SIZE];
    printf("Enter the new file name: ");
    scanf("%s", file_name);

    int empty = isFileEmpty(file_name);
    if (empty == FILE_NOTAVAILABLE)
    {
        printf("File: %s is not available\n", file_name);
        return FAILURE;
    }
    if (empty == FILE_EMPTY)
    {
        printf("File: %s is empty\n", file_name);
        return FAILURE;
    }

    int ret_val = to_create_list_of_files(f_head, file_name);
    if (ret_val == SUCCESS)
    {
        printf("Successfully inserted file: %s\n", file_name);
    }
    else if (ret_val == REPEATATION)
    {
        printf("File %s is duplicated\n", file_name);
    }
    else
    {
        printf("Failure in inserting file\n");
    }

    create_database(*f_head, head);
    return SUCCESS;
}