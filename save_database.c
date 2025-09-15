#include "inverted_Search.h"

int save_database( Wlist *head[])
{
    char file_name[FNAME_SIZE];

    printf("Enter the filename\n");
    scanf("%s" , file_name);

    //open file
    FILE *fptr = fopen(file_name , "w");
    for(int i = 0; i < 27; i++)
    {
        if(head[i] != NULL)
        {
            write_databasefile(head[i] , fptr);
        }
    }
}

void write_databasefile(Wlist *head, FILE *databasefile)
{
    fprintf(databasefile, "[%c] word: %s, file count: %d\n", head->word[0], head->word, head->file_count);
    Ltable *temp = head->Tlink;
    while (temp)
    {
        fprintf(databasefile, "File: %s, Word Count: %d\n", temp->file_name, temp->word_count);
        temp = temp->table_link;
    }
}
