#include "Book.h"
#include <fstream>
#include <sstream>
using namespace std;

bool Book::loadFromFile(const string& filename, int linesPerPage) {
    ifstream file(filename);
    if (!file.is_open()) return false;

    string line, page;
    int lineCount = 0;

    while (getline(file, line)) {
        page += line + "\n";
        lineCount++;
        if (lineCount >= linesPerPage) {
            pages.push_back(page);
            page.clear();
            lineCount = 0;
        }
    }
    if (!page.empty()) pages.push_back(page);
    return true;
}
void Book::setStatus(ReadingStatus newStatus) {
    status = newStatus;
}

ReadingStatus Book::getStatus() const {
    return status;
}

std::string Book::getStatusString() const {
    switch (status) {
        case ReadingStatus::WantToRead: return "📚 Want to Read";
        case ReadingStatus::CurrentlyReading: return "📖 Currently Reading";
        case ReadingStatus::Read: return "✅ Read";
        default: return "— No Status —";
    }
}

