# GNL (get_next_line)

A C function that reads a line from a file descriptor.

## Description

`get_next_line` is a function that reads a file descriptor line by line. Each call returns the next line from the file descriptor until EOF is reached.

## Files

- `get_next_line.c` - Main function implementation
- `get_next_line_utils.c` - Helper utility functions
- `get_next_line.h` - Header file with function prototypes

## Function Prototype

```c
char *get_next_line(int fd);
```

## Compilation

Compile with your preferred `BUFFER_SIZE`:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c your_main.c
```

## Usage Example

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## Return Value

- Returns the line read from the file descriptor (including the newline character if present)
- Returns `NULL` when EOF is reached or an error occurs