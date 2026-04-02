// adds the dump and restore functionality to the linked list version of
// inventory.c

/* Maintains a parts database (linked list version) */
#include "readline.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 25
#define MAX_FILE_NAME 100

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
    struct part *next;
};

struct part *inventory = NULL; // points to the first part
struct part *find_part(int number);

void dump(void);
void restore(void);
void getFilename(int max, char filename[]);

void insert(void);
void search(void);
void update(void);
void print(void);
void erase(void);

// main: Prompts the user to enter an operation code, then calls a function to
// perform the requested action. Repeats until the user enters the command 'q'.
// Prints an error message if the user enters an illegal code.
int main(void) {
    char code;
    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n')
            /* skips to end of line */
            ;
        switch (code) {
        case 'd':
            dump();
            break;
        case 'r':
            restore();
            break;
        case 'i':
            insert();
            break;
        case 's':
            search();
            break;
        case 'u':
            update();
            break;
        case 'p':
            print();
            break;
        case 'e':
            erase();
            break;
        case 'q':
            return 0;
        default:
            printf("Illegal code\n");
        }
        printf("\n");
    }
}

void dump(void) {
    printf("Enter name of save file: ");

    char filename[MAX_FILE_NAME + 1];
    getFilename(MAX_FILE_NAME, filename);

    FILE *fpOut;
    if ((fpOut = fopen(filename, "wb")) == NULL) {
        fprintf(stderr, "Unable to open file %s for writing\n", filename);
        exit(EXIT_FAILURE);
    }

    int numC, nameC, onHandC;
    for (struct part *curr = inventory; curr != NULL; curr = curr->next) {
        numC = fwrite(&curr->number, sizeof(int), 1, fpOut);
        nameC = fwrite(&curr->name, strlen(curr->name) + 1, 1, fpOut);
        onHandC = fwrite(&curr->on_hand, sizeof(int), 1, fpOut);

        if (!numC || !nameC || !onHandC) {
            fprintf(stderr, "Failed to write a part to file %s\n", filename);
            exit(EXIT_FAILURE);
        }
    }

    fclose(fpOut);
}

void restore(void) {
    printf("Enter name of save file to restore: ");

    char filename[MAX_FILE_NAME + 1];
    getFilename(MAX_FILE_NAME, filename);

    FILE *fpIn;
    if ((fpIn = fopen(filename, "rb")) == NULL) {
        fprintf(stderr, "Unable to open file %s for reading\n", filename);
        exit(EXIT_FAILURE);
    }

    // delete old list
    for (struct part *curr = inventory; curr != NULL;) {
        struct part *toDestroy = curr;
        curr = curr->next;
        free(toDestroy);
    }
    inventory = NULL;

    struct part *newNode, *currNode;
    int numC, onHandC, number;
    for (;;) {
        numC = fread(&number, sizeof(int), 1, fpIn);
        if (!numC)
            break;

        if ((newNode = malloc(sizeof(struct part))) == NULL) {
            fprintf(stderr,
                    "Couldn't allocate memory for new node in restore\n");
            exit(EXIT_FAILURE);
        }

        newNode->number = number;
        int c, i;
        for (i = 0; (c = getc(fpIn)) != EOF && c != 0; ++i)
            newNode->name[i] = c;

        if (c == EOF) {
            fprintf(stderr, "Error: partial part found\n");
            exit(EXIT_FAILURE);
        }
        newNode->name[i] = 0;

        onHandC = fread(&newNode->on_hand, sizeof(int), 1, fpIn);
        if (!onHandC) {
            fprintf(stderr, "Error: partial part found\n");
            exit(EXIT_FAILURE);
        }

        newNode->next = NULL;

        // add to list
        if (inventory == NULL) {
            inventory = newNode;
            currNode = newNode;
        } else {
            currNode->next = newNode;
            currNode = newNode;
        }
    }

    fclose(fpIn);
}

void getFilename(int max, char filename[]) {
    int c;
    while (isspace(c = getchar()))
        ;
    if (c == EOF) {
        fprintf(stderr, "Unable to get filename\n");
        exit(EXIT_FAILURE);
    }
    filename[0] = c;
    int i = 1;
    while (i < max && (c = getchar()) != EOF && !isspace(c))
        filename[i++] = c;
    filename[i] = 0;
}

// find_part: Looks up a part number in the inventory list. Returns a pointer to
// the node containing the part number; if the part number is not found, returns
// NULL.
struct part *find_part(int number) {
    struct part *p;
    for (p = inventory; p != NULL && number > p->number; p = p->next)
        ;
    if (p != NULL && number == p->number)
        return p;
    return NULL;
}

//  insert: Prompts the user for information about a new part and then inserts
//  the part into the inventory list; the list remains sorted by part number.
//  Prints an error message and returns prematurely if the part already exists
//  or space could not be allocated for the part.
void insert(void) {
    struct part *cur, *prev, *new_node;
    new_node = malloc(sizeof(struct part));
    if (new_node == NULL) {
        printf("Database is full; can't add more parts.\n");
        return;
    }
    printf("Enter part number: ");
    scanf("%d", &new_node->number);
    for (cur = inventory, prev = NULL;
         cur != NULL && new_node->number > cur->number;
         prev = cur, cur = cur->next)
        ;
    if (cur != NULL && new_node->number == cur->number) {
        printf("Part already exists.\n");
        free(new_node);
        return;
    }
    printf("Enter part name: ");
    read_line(new_node->name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &new_node->on_hand);
    new_node->next = cur;
    if (prev == NULL)
        inventory = new_node;
    else
        prev->next = new_node;
}

// search: Prompts the user to enter a part number, then * looks up the part in
// the database. If the part exists, prints the name and quantity on hand;
// if not, prints an error message.
void search(void) {
    int number;
    struct part *p;
    printf("Enter part number: ");
    scanf("%d", &number);
    p = find_part(number);
    if (p != NULL) {
        printf("Part name: %s\n", p->name);
        printf("Quantity on hand: %d\n", p->on_hand);
    } else
        printf("Part not found.\n");
}

// update: Prompts the user to enter a part number. Prints an error message if
// the part doesn't exist; otherwise, prompts the user to enter change in
// quantity on hand and updates the database.
void update(void) {
    int number, change;
    struct part *p;
    printf("Enter part number: ");
    scanf("%d", &number);
    p = find_part(number);
    if (p != NULL) {
        printf("Enter change in quantity on hand: ");
        scanf("%d", &change);
        p->on_hand += change;
    } else
        printf("Part not found.\n");
}

// print: Prints a listing of all parts in the database, showing the part
// number, part name, and quantity on hand. Part numbers will appear in
// ascending order.
void print(void) {
    printf("Part Number        Part Name                \
Quantity on Hand\n");
    for (struct part *p = inventory; p != NULL; p = p->next)
        printf("%11d        %-25s%-11d\n", p->number, p->name, p->on_hand);
}

void erase(void) {
    if (inventory == NULL) {
        printf("No parts to erase\n");
        return;
    }

    int number;
    printf("Enter part number to erase: ");
    scanf("%d", &number);

    struct part *toFree;
    if (inventory->number == number) {
        toFree = inventory;
        inventory = inventory->next;
        free(toFree);
        return;
    }

    for (struct part *curr = inventory->next, *prev = inventory;
         curr != NULL && curr->number <= number;
         prev = curr, curr = curr->next) {
        if (curr->number == number) {
            prev->next = curr->next;
            free(curr);
            return;
        }
    }

    printf("Part not found\n");
}
