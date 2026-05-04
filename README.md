# Get_Next_Line

## 📖 Description

**Get_Next_Line** is a project from the 42 curriculum.  
The goal is to implement a function that reads a file descriptor **line by line**, returning each line every time the function is called.

A "line" is defined as a sequence of characters ending with `\n` or the end of file (EOF).

This project teaches important concepts such as:
- File descriptor handling
- Static variables
- Dynamic memory allocation
- Buffer management

---

## ⚙️ Function Prototype

int get_next_line(int fd, char **line);

---

## 📌 Behavior

- Reads from a file descriptor one line at a time
- Each call returns:
  - `1` → A line has been read
  - `0` → End of file reached
  - `-1` → Error occurred
- The returned line:
  - Does NOT include `\n`
  - Must be dynamically allocated (must be freed)

---

## 🧠 Key Idea

The function keeps track of leftover data between calls using **static storage**, allowing it to continue reading from where it stopped.

---

## 🚀 Usage Example

int fd = open("file.txt", O_RDONLY);
char *line;

while (get_next_line(fd, &line) > 0)
{
printf("%s\n", line);
free(line);
}
close(fd);


---

## 📚 Notes

- Works with any valid file descriptor (file, input, etc.)
- Designed to handle different buffer sizes efficiently
- Memory leaks are not allowed

---

## 🏁 Author

simossd
