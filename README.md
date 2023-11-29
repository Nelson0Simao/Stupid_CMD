Certainly! Here's a simple documentation template with a nice header for the "Stuped_CMD" library:

---

# Stuped_CMD Documentation

## User: SrRoot
## Date: 29/11/2023

## Overview

Stuped_CMD is a simple C library that provides basic command-line functionalities, including a command history, custom commands, and the ability to execute external commands. This documentation outlines the basic usage, allowed commands, and potential limitations.

## Usage

1. **Including the Library:**

    ```c
    #include "stuped_cmd.h"
    ```

2. **Initializing the Command History:**

    ```c
    Node* history = NULL; // Declare a history pointer
    ```

3. **Adding Commands to History:**

    ```c
    history = add_history(history, "your_command_here");
    ```

4. **Showing Command History:**

    ```c
    show_history(history);
    ```

5. **Executing Commands:**

    - **Built-in Commands:**
        - `exit`: Exit the command-line interface.
        - `history`: Display command history.
        - `ls`: List files in the current directory.
        - `cd <directory>`: Change the current directory.
        - `pwd`: Print the current working directory.
        - `clear`: Clear the console screen.
        - `mkdir <directory>`: Create a new directory.
        - `touch <file>`: Create a new empty file.

    - **External Commands:**
        ```c
        execute_external_command("your_external_command_here");
        ```

6. **Freeing Command History:**

    ```c
    free_history(history);
    ```

## Limitations

- The library is designed for basic command-line interactions and may not handle complex scenarios.
- External command execution relies on the underlying system's capabilities and may have limitations.

## Notes

- Customize the main loop in the example to fit your application's needs.
- Refer to the library functions for more details on each command.

Feel free to integrate Stuped_CMD into your project and adapt it as needed!

---
