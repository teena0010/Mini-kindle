#pragma once
#include "Book.h"
#include <string>
#include <unordered_set>
using namespace std;

class Reader {
private:
    vector<Book> books;
    Book book;
    int currentPage;
    unordered_set<int> bookmarks;

public:
    Reader();
    bool load(const string& filename);
    void displayPage() const;
    void nextPage();
    void prevPage();
    void search(const string& keyword) const;
    void bookmark();
    bool saveProgress(const string& bookPath) const;
    bool loadProgress(const string& bookPath);
};