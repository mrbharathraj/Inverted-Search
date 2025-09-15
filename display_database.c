#include "inverted_Search.h"

void display_database( Wlist *head[])
{
    printf("[index]   [word]  file_count   File_name and word_count\n");

    for(int i = 0; i<27; i++)
    {
        if(head[i] != NULL)
        {
            print_word_count(head[i]);
        }
    }
}
int print_word_count(Wlist *head)
{
    //traverse through the Wlist
    while(head != NULL)
    {
        printf("[%d]  [%s]  %d", tolower(head->word[0]) % 97 , head->word , head->file_count);
        Ltable *Thead = head->Tlink;

        //traverse through the Ltable 
        while(Thead)
        {
            printf("File : %s   %d" , Thead->file_name , Thead->word_count);
            Thead = Thead->table_link;
        }
        printf("\n");
        head = head->link;
    }
}
