# Line-editor
# Line Editor in C

A simple **command-line based Line Editor** developed in C. The program allows users to create and manage a text document line by line, with features such as inserting, deleting, searching, replacing, saving, and loading text files.

## Features

* Insert a new line at a specific line number
* Delete an existing line
* Display the complete document
* Save the document to a file
* Load a document from a file
* Search for a word or phrase
* Find and replace text
* Dynamic memory allocation for storing lines
* File handling using C standard library functions

## Technologies Used

* **Language:** C
* **Compiler:** GCC / MinGW / Any standard C compiler
* **Libraries:**

  * `stdio.h`
  * `stdlib.h`
  * `string.h`

## Project Structure

```text
Line-Editor/
│
├── line_editor.c
├── README.md
└── HELP.md
```

## How It Works

The editor stores each line of the document dynamically using an array of character pointers.

```c
char *lines[MAX_LINES];
```

Each pointer points to a dynamically allocated string containing one line of the document.

The maximum number of lines is:

```c
#define MAX_LINES 100
```

The maximum length of each line is:

```c
#define MAX_LENGTH 500
```

## Menu Options

When the program starts, the following menu is displayed:

```text
========== LINE EDITOR ==========
1. Insert Line
2. Delete Line
3. Display Document
4. Save File
5. Load File
6. Search
7. Find & Replace
8. Exit
=================================
```

### 1. Insert Line

Allows the user to insert text at a particular line number.

Example:

```text
Enter line number: 1
Enter text: Hello World
Line inserted successfully.
```

If a line is inserted between existing lines, the existing lines are shifted automatically.

### 2. Delete Line

Deletes a line from the document.

Example:

```text
Enter line number to delete: 2
Line deleted successfully.
```

The memory allocated for the deleted line is released using `free()`.

### 3. Display Document

Displays all currently stored lines with their line numbers.

Example:

```text
----------- DOCUMENT -----------
1 | Hello World
2 | This is a line editor.
3 | Written in C.
--------------------------------
```

### 4. Save File

Saves the current document into a text file.

Example:

```text
Enter filename: document.txt
File saved successfully.
```

### 5. Load File

Loads an existing text file into the editor.

The currently loaded document is cleared before the new file is read.

Example:

```text
Enter filename: document.txt
File loaded successfully.
```

### 6. Search

Searches for a word or phrase in every line of the document.

Example:

```text
Enter word or phrase to search: C
Found on line 3: Written in C.
```

The program uses the `strstr()` function to locate the search text.

### 7. Find & Replace

Finds text and replaces the first occurrence of that text in each matching line.

Example:

```text
Enter text to find: Hello
Enter replacement text: Hi

Find & replace completed.
```

### 8. Exit

Terminates the program and releases dynamically allocated memory before exiting.

## Concepts Demonstrated

This project demonstrates several important concepts in C programming.

### Arrays of Pointers

```c
char *lines[MAX_LINES];
```

An array of character pointers is used to store multiple lines.

### Dynamic Memory Allocation

Memory is allocated according to the length of each line.

```c
lines[lineNumber - 1] = malloc(strlen(text) + 1);
```

Memory is released using:

```c
free(lines[i]);
```

### String Handling

The project uses functions such as:

```c
strlen()
strcpy()
strcat()
strncpy()
strstr()
strcspn()
```

### File Handling

Files are opened using:

```c
fopen()
```

Data is written using:

```c
fprintf()
```

Data is read using:

```c
fgets()
```

Files are closed using:

```c
fclose()
```

### Functions

The program is divided into separate functions:

```text
insertLine()
deleteLine()
displayLines()
saveFile()
loadFile()
searchLines()
replaceText()
```

This makes the program modular and easier to understand.

## Compilation

Using GCC:

```bash
gcc line_editor.c -o line_editor
```

## Running the Program

### Windows

```bash
line_editor.exe
```

### Linux / macOS

```bash
./line_editor
```

## Example Workflow

```text
1. Insert Line
2. Insert Line
3. Insert Line
3. Display Document
6. Search
7. Find & Replace
4. Save File
8. Exit
```

The user can create a document, modify it, search through it, replace text, save it, and load it again later.

## Limitations

* Maximum of 100 lines
* Maximum of 500 characters per line
* Text is handled as a simple line-based document
* Find & Replace replaces only the first occurrence of the searched text in each line
* No undo/redo functionality
* No cursor-based editing

## Future Improvements

The project can be extended with:

* Undo and redo
* Multiple file support
* Line editing instead of only insertion/deletion
* Replace all occurrences in a line
* Case-insensitive search
* Word count and character count
* Copy, cut, and paste
* Command-based editing similar to Unix `ed`
* Better error handling
* Dynamic expansion beyond 100 lines
* User-friendly terminal interface

## Learning Outcomes

Through this project, the following concepts can be understood and practiced:

* C programming
* Functions
* Arrays and pointers
* Dynamic memory allocation
* Strings
* File handling
* Searching algorithms
* Basic text processing
* Memory management
* Modular programming

## Author

**Developed as a C programming project demonstrating a basic command-line text editor.**
