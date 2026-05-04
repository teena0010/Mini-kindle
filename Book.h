#pragma once
#include <vector>
#include <string>
using namespace std;

enum class ReadingStatus {
    NotSet,
    WantToRead,
    CurrentlyReading,
    Read
};

class Book {
    string title;
    string author;
    string content;
    ReadingStatus status = ReadingStatus::NotSet;
public:
    vector<string> pages;
    bool loadFromFile(const string& filename, int linesPerPage);
    void setStatus(ReadingStatus newStatus);
    ReadingStatus getStatus() const;
    string getStatusString() const;
};
