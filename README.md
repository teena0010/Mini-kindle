# Mini-kindle
# Mini Kindle: Personal Console-Based Book Reader

At a Glance: This C++ project provides a terminal-based interface for reading and managing a digital library. It features page-by-page navigation, reading status tracking, keyword searching, and persistent progress saving.

## Core Features

  * **Curated Library**: Pre-configured access to classic literature, including titles like *The Idiot*, *Pride & Prejudice*, *Oliver Twist*, and *Crime and Punishment*.
  * **Reading Management**:
      * **Status Tracking**: Assign categories such as "Want to Read," "Currently Reading," or "Read" to each book.
      * **Persistent Progress**: Automatically saves and loads your last-read page so you can resume sessions seamlessly.
  * **Interactive Reader**:
      * **Navigation**: Simple keyboard controls for moving between pages (Next/Prev).
      * **Search**: Locate specific keywords or phrases throughout the text.
      * **Bookmarks**: Mark important pages for quick reference.
  * **Dynamic Visuals**: Features custom ASCII art headers for different book titles and color-coded UI elements for an enhanced console experience.

## Project Structure

| File            | Description                                                                          |
| :-------------- | :----------------------------------------------------------------------------------- |
| `main.cpp`      | Entry point handling the library menu, book selection, and the main input loop.      |
| `Reader.h/.cpp` | Manages reading logic, including page navigation, searching, and progress I/O.       |
| `Book.h/.cpp`   | Defines the book structure, page pagination (20 lines per page), and reading status. |
| `utils.h/.cpp`  | Cross-platform utility functions for screen clearing and input handling.             |
| `progress.txt`  | Stores the file path and last page number of your current book.                      |

## Technical Implementation

  * **Pagination**: The system dynamically splits text files into pages based on a fixed line count (20 lines per page) to ensure readability in the terminal.
  * **Search Algorithm**: Iterates through the stored pages and uses string matching to find and display all occurrences of a keyword.
  * **Cross-Platform Support**: Includes conditional compilation for `clearScreen()` to work on both Windows (`cls`) and Linux/macOS (`clear`) systems.

## Getting Started

### Prerequisites

  * A C++ compiler (e.g., G++)
  * A directory named `books/` containing the `.txt` files listed in `main.cpp`.

### Compilation

To compile and run the project, use the following command:

``` bash
g++ main.cpp Reader.cpp Book.cpp utils.cpp -o mini_kindle && ./mini_kindle

```
<img width="753" height="702" alt="image" src="https://github.com/user-attachments/assets/6eb219b8-49c9-4aec-8dfa-405a773fe679" />

