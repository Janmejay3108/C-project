#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

struct book {
    char title[50];
    char author[50];
    int id;
};

struct book library[MAX_BOOKS];
int num_books = 0;

void add_book() {
    if (num_books >= MAX_BOOKS) {
        printf("Library is full!\n");
        return;
    }

    struct book new_book;
    printf("Enter title of book: ");
    scanf("%s", new_book.title);

    printf("Enter author of book: ");
    scanf("%s", new_book.author);

    new_book.id = num_books + 1;
    library[num_books] = new_book;
    num_books++;

    printf("Book added successfully!\n");
}

void remove_book() {
    int id;
    printf("Enter ID of book to remove: ");
    scanf("%d", &id);

    if (id < 1 || id > num_books) {
        printf("Error: Invalid book ID!\n");
        return;
    }

    for (int i = id - 1; i < num_books - 1; i++) {
        library[i] = library[i + 1];
        library[i].id--;
    }

    num_books--;

    printf("Book removed successfully!\n");
}

void display_books() {
    if (num_books == 0) {
        printf("No books in library.\n");
        return;
    }

    printf("Current library inventory:\n");
    printf("ID\tTitle\t\tAuthor\n");

    for (int i = 0; i < num_books; i++) {
        printf("%d\t%s\t\t%s\n", library[i].id, library[i].title, library[i].author);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nLibrary Management System\n");
        printf("-------------------------\n");
        printf("1. Add book\n");
        printf("2. Remove book\n");
        printf("3. Display books\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                remove_book();
                break;
            case 3:
                display_books();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
