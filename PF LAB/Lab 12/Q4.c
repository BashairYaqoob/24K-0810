/* Create a nested structure for a library management system. Use a structure Book (fields:
title, author, publicationYear) inside a structure Library. Input details of 5
books and display the titles of all books published after the year 2000. The structure
variable must be created using DMA.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct l
{
    struct b
    {
        char title[100];
        char author[50];
        int pubyear;
    } *books;
} library;
FILE *fptr;
void create()
{
    library *l = (library *)malloc(sizeof(library));
    int n, i;
    printf("Enter number of books to add details for:");
    scanf("%d", &n);
    l->books = (struct b *)calloc(n, sizeof(struct b));
    fptr = fopen("file1.txt", "w");
    fprintf(fptr,  "%-20s %-20s %-15s\n", "Book Name", "Book Author", "Publishing Year");
    getchar();
    for (i = 0; i < n; i++)
    {
        printf("Book name:");
        fgets(l->books[i].title, sizeof(l->books[i].title), stdin);
        l->books[i].title[strcspn(l->books[i].title, "\n")] = 0;
        printf("Book Author:");
        fgets(l->books[i].author, sizeof(l->books[i].author), stdin);
        l->books[i].author[strcspn(l->books[i].author, "\n")] = 0;
        printf("Book publishing year:");
        scanf("%d", &l->books[i].pubyear);
        getchar();

        fprintf(fptr, "%-20s %-20s %-15d\n", l->books[i].title, l->books[i].author, l->books[i].pubyear);
    }
    fclose(fptr);
    free(l->books);
    free(l);
}
void update()
{
    library *l = (library *)malloc(sizeof(library));
    int n, i;
    printf("Enter number of books to append:");
    scanf("%d", &n);
    l->books = (struct b *)calloc(n, sizeof(struct b));
    fptr = fopen("file1.txt", "a");
    getchar();
    for (i = 0; i < n; i++)
    {
        printf("Book name:");
        fgets(l->books[i].title, sizeof(l->books[i].title), stdin);
        l->books[i].title[strcspn(l->books[i].title, "\n")] = 0;
        printf("Book Author:");
        fgets(l->books[i].author, sizeof(l->books[i].author), stdin);
        l->books[i].author[strcspn(l->books[i].author, "\n")] = 0;
        printf("Book publishing year:");
        scanf("%d", &l->books[i].pubyear);
        getchar();

        fprintf(fptr, "%-20s %-20s %-15d\n", l->books[i].title, l->books[i].author, l->books[i].pubyear);
    }
    fclose(fptr);
    free(l->books);
    free(l);
}
void display()
{
    fptr = fopen("file1.txt", "r");
    char ch;
    while ((ch = fgetc(fptr)) != EOF)
    {
        putchar(ch);
    }
    fclose(fptr);
}
void delete()
{
    char deltitle[100];
    int found = 0;
    printf("Enter book title you want to delete:");
    fgets(deltitle, sizeof(deltitle), stdin);
    deltitle[strcspn(deltitle, "\n")] = 0;
    fptr = fopen("file1.txt", "r");
    FILE *fptr2 = fopen("temp.txt", "w");
    char line[200];
    while (fgets(line, sizeof(line), fptr))
    {
        char title[100], author[50];
        int pubyear;
        if (sscanf(line, "%99s %49s %d", title, author, &pubyear) == 3) {
            if (strcmp(title, deltitle) == 0) {
                found = 1;
            } else {
                fprintf(fptr2, "%s", line);
            }
        } else {
            fprintf(fptr2, "%s", line);
        }
    
    }
    fclose(fptr);
    fclose(fptr2);
    if (found)
    {
        remove("file1.txt");
        rename("temp.txt", "file1.txt");
        printf("Data for book with title %s deleted successfully!", deltitle);
    }
    else
    {
        remove("temp.txt");
        printf("No data found with such title!");
    }
}
int main()
{
    int ch;
    while (1)
    {
        printf("--MENU--\n 1-Enter details of a book\n 2-Update details\n 3-Display books\n 4-Delete a detail\n0-Exit \nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            update();
            break;
        case 3:
            display();
            break;
        case 4:
            delete ();
            break;
        case 0:
            printf("Exiting...");
            return 0;

        default:
            printf("Enter valid choice!");
            break;
        }
    }
    return 0;
}
