#include "inverted_Search.h"

char *fname; // Fix: Define fname globally

int main(int argc, char *argv[])
{
    system("clear");

    Wlist *head[27] = {NULL};

    if (argc <= 1)
    {
        printf("Enter the valid number of arguments\n");
        printf("./Slist.exe file1.txt file2.txt ....\n");
        return 0;
    }

    Flist *f_head = NULL;
    file_validation_n_file_list(&f_head, argv);

    if (f_head == NULL)
    {
        printf("No files added to file linked list\n");
        printf("Hence the process got terminated \n");
        return 1;
    }

    int user_choice;
    char word[WORD_SIZE];

    while (1)
    {
        printf("\nSelect your choice:\n");
        printf("1. Create DATABASE\n");
        printf("2. Display Database\n");
        printf("3. Update DATABASE\n");
        printf("4. Search\n");
        printf("5. Save Database\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &user_choice);

        switch (user_choice)
        {
            case 1:
                create_database(f_head, head);
                break;
            case 2:
                display_database(head);
                break;
            case 3:
                update_database(head, &f_head);
                break;
            case 4:
                printf("Enter the word: ");
                scanf("%s", word);
                int index = tolower(word[0]) - 'a';
                search(head[index], word);
                break;
            case 5:
                save_database(head);
                break;
            case 6:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}