# Line Editor - Help Guide

## 1. Introduction

The Line Editor is a simple command-line text editor written in C.

It allows you to create and manage a document using numbered lines.

You can:

* Insert lines
* Delete lines
* Display the document
* Save the document
* Load an existing file
* Search for text
* Find and replace text

---

# 2. Starting the Program

After compiling and running the program, you will see:

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
Enter choice:
```

Enter the number corresponding to the operation you want to perform.

---

# 3. Insert Line

Select:

```text
1
```

The program asks for a line number.

Example:

```text
Enter line number: 1
Enter text: Welcome to C programming.
```

The line is inserted into the document.

### Valid line numbers

If there are currently 3 lines, you can insert at:

```text
1
2
3
4
```

Line 4 means adding the new line at the end.

---

# 4. Delete Line

Select:

```text
2
```

Enter the line number that you want to remove.

Example:

```text
Enter line number to delete: 2
```

The selected line is deleted and the lines below it move up.

---

# 5. Display Document

Select:

```text
3
```

The program displays all lines.

Example:

```text
----------- DOCUMENT -----------
1 | Hello
2 | Welcome to my project.
3 | This is written in C.
--------------------------------
```

---

# 6. Save File

Select:

```text
4
```

Enter a filename.

Example:

```text
Enter filename: notes.txt
```

The document will be stored in the specified text file.

If the file does not already exist, it will be created.

---

# 7. Load File

Select:

```text
5
```

Enter the name of an existing text file.

Example:

```text
Enter filename: notes.txt
```

The program reads the file line by line and loads it into the editor.

### Important

Loading a file clears the document currently stored in memory.

So save your current document before loading another file if you want to keep it.

---

# 8. Search

Select:

```text
6
```

Enter the word or phrase you want to find.

Example:

```text
Enter word or phrase to search: programming
```

If the text exists, the program displays the matching line.

Example:

```text
Found on line 2: Welcome to C programming.
```

If there is no match:

```text
Text not found.
```

---

# 9. Find & Replace

Select:

```text
7
```

The program asks for two pieces of information.

First:

```text
Enter text to find:
```

Then:

```text
Enter replacement text:
```

Example:

```text
Enter text to find: C
Enter replacement text: C Programming
```

The matching text is replaced in the document.

---

# 10. Exit

Select:

```text
8
```

The program releases the memory used by the document and exits.

Example:

```text
Exiting editor...
```

---

# 11. Example Session

A complete example:

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

Enter choice: 1
Enter line number: 1
Enter text: Hello World
Line inserted successfully.

Enter choice: 1
Enter line number: 2
Enter text: This is my C project.
Line inserted successfully.

Enter choice: 3

----------- DOCUMENT -----------
1 | Hello World
2 | This is my C project.
--------------------------------

Enter choice: 6
Enter word or phrase to search: C
Found on line 2: This is my C project.

Enter choice: 7
Enter text to find: Hello
Enter replacement text: Hi
Find & replace completed.

Enter choice: 3

----------- DOCUMENT -----------
1 | Hi World
2 | This is my C project.
--------------------------------

Enter choice: 4
Enter filename: document.txt
File saved successfully.

Enter choice: 8
Exiting editor...
```

---

# 12. Error Messages

### Document is full

```text
Document is full!
```

This occurs when the editor already contains 100 lines.

### Document is empty

```text
Document is empty!
```

This occurs when you try to delete or display lines without having any lines.

### Invalid line number

```text
Invalid line number!
```

This occurs when the entered line number is outside the allowed range.

### File cannot be opened

```text
Could not open file!
```

This occurs when the specified file cannot be opened.

### Memory allocation failure

```text
Memory allocation failed!
```

This occurs when the program cannot allocate the required memory.

### Empty search text

```text
Search text cannot be empty!
```

This occurs when no search text is entered.

---

# 13. Important Notes

* Maximum number of lines: **100**
* Maximum characters per line: **499 characters plus the null character**
* Files are saved as normal text files.
* Loading a file replaces the current document.
* The program uses dynamic memory allocation for every line.
* Memory is released when lines are deleted or when the program exits.

---

# 14. Basic Command Summary

| Option | Operation      | Purpose                   |
| ------ | -------------- | ------------------------- |
| 1      | Insert Line    | Add a new line            |
| 2      | Delete Line    | Remove a line             |
| 3      | Display        | Show the document         |
| 4      | Save           | Save document to a file   |
| 5      | Load           | Load document from a file |
| 6      | Search         | Find a word or phrase     |
| 7      | Find & Replace | Replace text              |
| 8      | Exit           | Close the editor          |

---

# 15. Troubleshooting

### Program does not compile

Make sure you have a C compiler such as GCC installed.

Try:

```bash
gcc line_editor.c -o line_editor
```

### File is not loading

Check that:

* The filename is correct.
* The file exists.
* The file is accessible from the program's current directory.

### Program says "Document is full"

The program currently supports a maximum of 100 lines.

---

# 16. Project Purpose

This project is designed to demonstrate practical use of:

* Arrays
* Pointers
* Dynamic memory allocation
* Strings
* Functions
* File handling
* Searching
* Text manipulation

It is suitable as a beginner/intermediate C programming project for understanding how a basic text editor can be implemented using fundamental C concepts.
