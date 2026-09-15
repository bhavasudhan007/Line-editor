#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LENGTH 500

void insertLine(char *lines[], int *count);
void deleteLine(char *lines[], int *count);
void displayLines(char *lines[], int count);
void saveFile(char *lines[], int count);
void loadFile(char *lines[], int *count);
void searchLines(char *lines[], int count);
void replaceText(char *lines[], int count);

int main()
{
    char *lines[MAX_LINES];
    int count = 0;
    int choice;

    for (int i = 0; i < MAX_LINES; i++)
        lines[i] = NULL;

    while (1)
    {
        printf("\n========== LINE EDITOR ==========\n");
        printf("1. Insert Line\n");
        printf("2. Delete Line\n");
        printf("3. Display Document\n");
        printf("4. Save File\n");
        printf("5. Load File\n");
        printf("6. Search\n");
        printf("7. Find & Replace\n");
        printf("8. Exit\n");
        printf("=================================\n");

        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
            case 1:
                insertLine(lines, &count);
                break;

            case 2:
                deleteLine(lines, &count);
                break;

            case 3:
                displayLines(lines, count);
                break;

            case 4:
                saveFile(lines, count);
                break;

            case 5:
                loadFile(lines, &count);
                break;

            case 6:
                searchLines(lines, count);
                break;

            case 7:
                replaceText(lines, count);
                break;

            case 8:
                for (int i = 0; i < count; i++)
                    free(lines[i]);

                printf("Exiting editor...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}


/* INSERT LINE */

void insertLine(char *lines[], int *count)
{
    int lineNumber;
    char text[MAX_LENGTH];

    if (*count >= MAX_LINES)
    {
        printf("Document is full!\n");
        return;
    }

    printf("Enter line number: ");
    scanf("%d", &lineNumber);
    getchar();

    if (lineNumber < 1 || lineNumber > *count + 1)
    {
        printf("Invalid line number!\n");
        return;
    }

    printf("Enter text: ");
    fgets(text, MAX_LENGTH, stdin);

    text[strcspn(text, "\n")] = '\0';

    for (int i = *count; i >= lineNumber; i--)
    {
        lines[i] = lines[i - 1];
    }

    lines[lineNumber - 1] = malloc(strlen(text) + 1);

    if (lines[lineNumber - 1] == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    strcpy(lines[lineNumber - 1], text);

    (*count)++;

    printf("Line inserted successfully.\n");
}


/* DELETE LINE */

void deleteLine(char *lines[], int *count)
{
    int lineNumber;

    if (*count == 0)
    {
        printf("Document is empty!\n");
        return;
    }

    printf("Enter line number to delete: ");
    scanf("%d", &lineNumber);
    getchar();

    if (lineNumber < 1 || lineNumber > *count)
    {
        printf("Invalid line number!\n");
        return;
    }

    free(lines[lineNumber - 1]);

    for (int i = lineNumber - 1; i < *count - 1; i++)
    {
        lines[i] = lines[i + 1];
    }

    lines[*count - 1] = NULL;

    (*count)--;

    printf("Line deleted successfully.\n");
}


/* DISPLAY */

void displayLines(char *lines[], int count)
{
    if (count == 0)
    {
        printf("Document is empty!\n");
        return;
    }

    printf("\n----------- DOCUMENT -----------\n");

    for (int i = 0; i < count; i++)
    {
        printf("%d | %s\n", i + 1, lines[i]);
    }

    printf("--------------------------------\n");
}


/* SAVE */

void saveFile(char *lines[], int count)
{
    char filename[100];
    FILE *file;

    printf("Enter filename: ");
    fgets(filename, sizeof(filename), stdin);

    filename[strcspn(filename, "\n")] = '\0';

    file = fopen(filename, "w");

    if (file == NULL)
    {
        printf("Could not open file!\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(file, "%s\n", lines[i]);
    }

    fclose(file);

    printf("File saved successfully.\n");
}


/* LOAD */

void loadFile(char *lines[], int *count)
{
    char filename[100];
    char buffer[MAX_LENGTH];

    FILE *file;

    printf("Enter filename: ");
    fgets(filename, sizeof(filename), stdin);

    filename[strcspn(filename, "\n")] = '\0';

    file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Could not open file!\n");
        return;
    }

    /* Clear old document */

    for (int i = 0; i < *count; i++)
    {
        free(lines[i]);
        lines[i] = NULL;
    }

    *count = 0;

    /* Read new document */

    while (fgets(buffer, MAX_LENGTH, file) != NULL &&
           *count < MAX_LINES)
    {
        buffer[strcspn(buffer, "\n")] = '\0';

        lines[*count] = malloc(strlen(buffer) + 1);

        if (lines[*count] == NULL)
        {
            printf("Memory allocation failed!\n");
            fclose(file);
            return;
        }

        strcpy(lines[*count], buffer);

        (*count)++;
    }

    fclose(file);

    printf("File loaded successfully.\n");
}


/* SEARCH */

void searchLines(char *lines[], int count)
{
    char search[MAX_LENGTH];
    int found = 0;

    printf("Enter word or phrase to search: ");
    fgets(search, MAX_LENGTH, stdin);

    search[strcspn(search, "\n")] = '\0';

    if (strlen(search) == 0)
    {
        printf("Search text cannot be empty!\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        if (strstr(lines[i], search) != NULL)
        {
            printf("Found on line %d: %s\n",
                   i + 1,
                   lines[i]);

            found = 1;
        }
    }

    if (!found)
    {
        printf("Text not found.\n");
    }
}


/* FIND & REPLACE */

void replaceText(char *lines[], int count)
{
    char oldText[MAX_LENGTH];
    char newText[MAX_LENGTH];

    printf("Enter text to find: ");
    fgets(oldText, MAX_LENGTH, stdin);
    oldText[strcspn(oldText, "\n")] = '\0';

    printf("Enter replacement text: ");
    fgets(newText, MAX_LENGTH, stdin);
    newText[strcspn(newText, "\n")] = '\0';

    if (strlen(oldText) == 0)
    {
        printf("Search text cannot be empty!\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        char *position = strstr(lines[i], oldText);

        if (position != NULL)
        {
            int oldLength = strlen(oldText);
            int newLength = strlen(newText);

            char buffer[MAX_LENGTH];

            int prefixLength = position - lines[i];

            strncpy(buffer, lines[i], prefixLength);

            buffer[prefixLength] = '\0';

            strcat(buffer, newText);

            strcat(buffer, position + oldLength);

            free(lines[i]);

            lines[i] = malloc(strlen(buffer) + 1);

            if (lines[i] != NULL)
            {
                strcpy(lines[i], buffer);
            }
        }
    }

    printf("Find & replace completed.\n");
}