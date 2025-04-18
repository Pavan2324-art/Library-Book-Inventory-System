#include <stdio.h>
#include <string.h>
#define MAX_BOOKS 100
typedef struct {
    char name[100];
    char author[100];
    int availability; 
} Book;
Book library[MAX_BOOKS];
int bookCount = 0;
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Library is full!\n");
        return;
    }
    printf("Enter book name: ");
    getchar();
    fgets(library[bookCount].name, sizeof(library[bookCount].name), stdin);
    library[bookCount].name[strcspn(library[bookCount].name, "\n")] = 0; 
    printf("Enter author name: ");
    fgets(library[bookCount].author, sizeof(library[bookCount].author), stdin);
    library[bookCount].author[strcspn(library[bookCount].author, "\n")] = 0; 
    printf("Enter availability (1 for available, 0 for borrowed): ");
    scanf("%d", &library[bookCount].availability);
    bookCount++;
    printf("Book added successfully!\n");
}
void searchBook() {
    char searchTerm[100];
    printf("Enter book name or author to search: ");
    getchar(); 
    fgets(searchTerm, sizeof(searchTerm), stdin);
    searchTerm[strcspn(searchTerm, "\n")] = 0;
    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (strstr(library[i].name, searchTerm) != NULL || strstr(library[i].author, searchTerm) != NULL) {
            printf("Book found: %s by %s - Availability: %s\n", library[i].name, library[i].author, 
                   library[i].availability ? "Available" : "Borrowed");
            found = 1;
        }
    }
    if (!found) {
        printf("No books found matching your search.\n");
    }
}
void updateBook() {
    char bookName[100];
    printf("Enter the book name to update: ");
    getchar();  
    fgets(bookName, sizeof(bookName), stdin);
    bookName[strcspn(bookName, "\n")] = 0;
    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].name, bookName) == 0) {
            printf("Book found: %s by %s - Availability: %s\n", library[i].name, library[i].author, 
                   library[i].availability ? "Available" : "Borrowed");

            printf("Enter new availability (1 for available, 0 for borrowed): ");
            scanf("%d", &library[i].availability);
            found = 1;
            printf("Book details updated successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Book not found in the library.\n");
    }
}
void deleteBook() {
    char bookName[100];
    printf("Enter the book name to delete: ");
    getchar();  
    fgets(bookName, sizeof(bookName), stdin);
    bookName[strcspn(bookName, "\n")] = 0;  
    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].name, bookName) == 0) {
            for (int j = i; j < bookCount - 1; j++) {
                library[j] = library[j + 1]; 
            }
            bookCount--;
            found = 1;
            printf("Book deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Book not found in the library.\n");
    }
}
void displayMenu() {
    printf("\nLibrary Book Inventory System\n");
    printf("1. Add Book\n");
    printf("2. Search Book\n");
    printf("3. Update Book\n");
    printf("4. Delete Book\n");
    printf("5. Exit\n");
}
int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                searchBook();
                break;
            case 3:
                updateBook();
                break;
            case 4:
                deleteBook();
                break;
            case 5:
                printf("Exiting the system...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
