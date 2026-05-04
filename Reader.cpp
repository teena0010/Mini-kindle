#include "Reader.h"
#include "utils.h"
#include "Book.h"
#include <iostream>
using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

Reader::Reader() : currentPage(0) {}

bool Reader::load(const string& filename) {
    bool success = book.loadFromFile(filename, 20); // 20 lines per page
    if (success) {
        // Prompt user to set reading status
        cout << "\nSet reading status:\n";
        cout << "1. 📚 Want to Read\n";
        cout << "2. 📖 Currently Reading\n";
        cout << "3. ✅ Read\n";
        cout << "Choice [1-3]: ";

        int choice;
        cin >> choice;
        cin.ignore();  // Clear newline

        switch (choice) {
            case 1: book.setStatus(ReadingStatus::WantToRead); break;
            case 2: book.setStatus(ReadingStatus::CurrentlyReading); break;
            case 3: book.setStatus(ReadingStatus::Read); break;
            default: cout << "No status set.\n"; break;
        }
    }
    return success;
}

void Reader::displayPage() const {
    clearScreen();
    cout << BOLD << CYAN << "+----------------------------------+\n";
    cout << "| Page " << currentPage + 1 << " of " << book.pages.size() << " |\n";
    cout << "+----------------------------------+" << RESET << "\n";
    cout << GREEN << "[Status: " << book.getStatusString() << "]" << RESET << "\n";
    cout << book.pages[currentPage];
    if (bookmarks.count(currentPage)) {
        cout << YELLOW << "\n[Bookmarked]" << RESET;
    }
}

void Reader::nextPage() {
    if (currentPage < book.pages.size() - 1) currentPage++;
}

void Reader::prevPage() {
    if (currentPage > 0) currentPage--;
}

void Reader::search(const string& keyword) const {
    clearScreen();
    bool found = false;
    for (size_t i = 0; i < book.pages.size(); ++i) {
        if (book.pages[i].find(keyword) != string::npos) {
            cout << "Found on page " << i + 1 << ":\n";
            cout << book.pages[i] << "\n---\n";
            found = true;
        }
    }
    if (!found) cout << "Keyword not found.\n";
    waitForEnter();
}

void Reader::bookmark() {
    bookmarks.insert(currentPage);
    cout << "Page " << currentPage + 1 << " bookmarked.\n";
    waitForEnter();
}
#include <fstream>

bool Reader::saveProgress(const string& bookPath) const {
    ofstream out("progress.txt");
    if (!out) return false;
    out << bookPath << "\n" << currentPage;
    return true;
}

bool Reader::loadProgress(const string& bookPath) {
    ifstream in("progress.txt");
    if (!in) return false;

    string savedPath;
    int savedPage;
    getline(in, savedPath);
    in >> savedPage;

    if (savedPath == bookPath && savedPage >= 0 && savedPage < book.pages.size()) {
        currentPage = savedPage;
        return true;
    }
    return false;
}

