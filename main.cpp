#include "Reader.h"
#include "utils.h"
#include "Book.h"
#include <iostream>
#include <vector>
#include <conio.h>
using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

int main() {
    clearScreen();
    cout << BOLD << BLUE << R"(
 _      _  _      _    _  __ _  _      ____  _     _____
/ \__/|/ \/ \  /|/ \  / |/ // \/ \  /|/  _ \/ \   /  __/
| |\/||| || |\ ||| |  |   / | || |\ ||| | \|| |   |  \  
| |  ||| || | \||| |  |   \ | || | \||| |_/|| |_/\|  /_ 
\_/  \|\_/\_/  \|\_/  \_|\_\\_/\_/  \|\____/\____/\____\
                                                        
                                                        
                                                        
                                                        
                                                        
                                                        
                                                        )" << RESET << "\n";
    cout << "Your personal console-based book reader\n";
    vector<string> availableBooks = {
        "books/the-idiot.txt",
        "books/pride&prejudice.txt",
        "books/oliver-twist.txt",
        "books/the-blue-castle.txt",
        "books/crime-and-punishment.txt",
        "books/wuthering-heights.txt",
        "books/the-picture-of-dorian-gray.txt"
    };

    cout << "Available books:\n";
    cout << "🔍 [0] Find a Book by Title\n";
    for (size_t i = 0; i < availableBooks.size(); ++i) {
        cout<< "[" << i + 1 << "] " << availableBooks[i] << "\n";
    }
    int choice;
    cout << "Enter book number to read: ";
    cin >> choice;

        if(choice == 0) {
        cin.ignore(); // Clear newline
        string title;
        cout << "Enter book title to search: ";
        getline(cin, title);
        bool found = false;
        for (size_t i = 0; i < availableBooks.size(); ++i) {
            if (availableBooks[i].find(title) != string::npos) {
                cout << "[" << i + 1 << "] " << availableBooks[i] << "\n";
                found = true;
            }
        }
        if (!found) {
            cout << "No books found with that title.\n";
            return 1;
        }
        cout << "Enter book number to read: ";
        cin >> choice;
        if (choice < 1 || choice > availableBooks.size()) {
            cerr << "Invalid choice.\n";
            return 1;
        }
    }
    else if (choice < 1 || choice > availableBooks.size()) {
        cerr << "Invalid choice.\n";
        return 1;
    }
cout << "\n";

    Reader reader;
    if (!reader.load(availableBooks[choice - 1])) {
        cerr << "Failed to load book.\n";
        return 1;
    }
    clearScreen();

string selectedBook = availableBooks[choice - 1];

if (selectedBook == "books/crime-and-punishment.txt") {
    cout << CYAN << R"(  ____  ____  _  _      _____   ____  _      ____    ____  _     _      _  ____  _     _      _____ _      _____ 
/   _\/  __\/ \/ \__/|/  __/  /  _ \/ \  /|/  _ \  /  __\/ \ /\/ \  /|/ \/ ___\/ \ /|/ \__/|/  __// \  /|/__ __\
|  /  |  \/|| || |\/|||  \    | / \|| |\ ||| | \|  |  \/|| | ||| |\ ||| ||    \| |_||| |\/|||  \  | |\ ||  / \  
|  \__|    /| || |  |||  /_   | |-||| | \||| |_/|  |  __/| \_/|| | \||| |\___ || | ||| |  |||  /_ | | \||  | |  
\____/\_/\_\\_/\_/  \|\____\  \_/ \|\_/  \|\____/  \_/   \____/\_/  \|\_/\____/\_/ \|\_/  \|\____\\_/  \|  \_/  
                                                                                                                
                                                                                                                
                                                                                                                
                                                                                                                
                                                                                                                
                                                                                                                
                                                                                                                )" << RESET << "\n";

}
else if (selectedBook == "books/oliver-twist.txt") {
    cout << YELLOW << R"(   ___   __    _                          _________              _          _    
 .'   `.[  |  (_)                        |  _   _  |            (_)        / |_  
/  .-.  \| |  __  _   __  .---.  _ .--.  |_/ | | \_|_   _   __  __   .--. `| |-' 
| |   | || | [  |[ \ [  ]/ /__\\[ `/'`\]     | |   [ \ [ \ [  ][  | ( (`\] | |   
\  `-'  /| |  | | \ \/ / | \__., | |        _| |_   \ \/\ \/ /  | |  `'.'. | |,  
 `.___.'[___][___] \__/   '.__.'[___]      |_____|   \__/\__/  [___][\__) )\__/  
                                                                                 
    )" << RESET << "\n";

}
else if (selectedBook == "books/pride&prejudice.txt") {
    cout << GREEN << R"(  _____       _                 __      _____              _           _             
 |  __ \     ( )    |  __      /  \    |  __ \       __   ( )|  |    |( )  __   __   
 | |__) ||__  |   __| /__\    | () |   | |__) ||__  /__\   | |  |  __| |  /  \ /__\  
 |  ___/ |  \ |  /  || ___|    \__/    |  ___/ |  \| ___|  | |  | /  | | |    | ___| 
 | |     |    | |   ||         /  \    | |     |   |    \  | \__/|   | |  \__/|      
 |_|         (_) \__/ \__/    / /\ \   |_|          \__/ \_/      \__/(_)      \__/  
                              \/  \/                                                                                                                             
                                                                                                                                                                   
    )" << RESET << "\n";

}
else if (selectedBook == "books/the-blue-castle.txt") {
    cout << BLUE << R"( .-') _    ('-. .-.   ('-.        .-. .-')                           ('-.                     ('-.      .-')    .-') _               ('-.   
(  OO) )  ( OO )  / _(  OO)       \  ( OO )                        _(  OO)                   ( OO ).-. ( OO ). (  OO) )            _(  OO)  
/     '._ ,--. ,--.(,------.       ;-----.\  ,--.     ,--. ,--.   (,------.         .-----.  / . --. /(_)---\_)/     '._ ,--.     (,------. 
|'--...__)|  | |  | |  .---'       | .-.  |  |  |.-') |  | |  |    |  .---'        '  .--./  | \-.  \ /    _ | |'--...__)|  |.-')  |  .---' 
'--.  .--'|   .|  | |  |           | '-' /_) |  | OO )|  | | .-')  |  |            |  |('-..-'-'  |  |\  :` `. '--.  .--'|  | OO ) |  |     
   |  |   |       |(|  '--.        | .-. `.  |  |`-' ||  |_|( OO )(|  '--.        /_) |OO  )\| |_.'  | '..`''.)   |  |   |  |`-' |(|  '--.  
   |  |   |  .-.  | |  .--'        | |  \  |(|  '---.'|  | | `-' / |  .--'        ||  |`-'|  |  .-.  |.-._)   \   |  |  (|  '---.' |  .--'  
   |  |   |  | |  | |  `---.       | '--'  / |      |('  '-'(_.-'  |  `---.      (_'  '--'\  |  | |  |\       /   |  |   |      |  |  `---. 
   `--'   `--' `--' `------'       `------'  `------'  `-----'     `------'         `-----'  `--' `--' `-----'    `--'   `------'  `------' 
    )" << RESET << "\n";

}
else if (selectedBook == "books/the-picture-of-dorian-gray.txt") {
    cout << RED<<R"( _____ _     _____   ____  _  ____ _____ _     ____  _____   ____  _____   ____  ____  ____  _  ____  _        _____ ____  ____ ___  _
/__ __Y \ /|/  __/  /  __\/ \/   _Y__ __Y \ /\/  __\/  __/  /  _ \/    /  /  _ \/  _ \/  __\/ \/  _ \/ \  /|  /  __//  __\/  _ \\  \//
  / \ | |_|||  \    |  \/|| ||  /   / \ | | |||  \/||  \    | / \||  __\  | | \|| / \||  \/|| || / \|| |\ ||  | |  _|  \/|| / \| \  / 
  | | | | |||  /_   |  __/| ||  \_  | | | \_/||    /|  /_   | \_/|| |     | |_/|| \_/||    /| || |-||| | \||  | |_//|    /| |-|| / /  
  \_/ \_/ \|\____\  \_/   \_/\____/ \_/ \____/\_/\_\\____\  \____/\_/     \____/\____/\_/\_\\_/\_/ \|\_/  \|  \____\\_/\_\\_/ \|/_/   
                                                                                                                                      
                                                                                                                                      
                                                                                                                                      
                                                                                                                                      
                                                                                                                                      
                                                                                                                                      
                                                                                                                                      )" << RESET << "\n";

}
else if (selectedBook == "books/the-idiot.txt") {
    cout << GREEN << R"(████████ ██   ██ ███████     ██ ██████  ██  ██████  ████████ 
   ██    ██   ██ ██          ██ ██   ██ ██ ██    ██    ██    
   ██    ███████ █████       ██ ██   ██ ██ ██    ██    ██    
   ██    ██   ██ ██          ██ ██   ██ ██ ██    ██    ██    
   ██    ██   ██ ███████     ██ ██████  ██  ██████     ██                                                                                                                                                                                                                                                                                                                
    )" << RESET << "\n";
}
else if (selectedBook == "books/wuthering-heights.txt") {
    cout << CYAN << R"(                           .                                                                          .   
.;.       .-.          ...;....;                .-.                 .;            .-.      .;     ...;... 
  `;     ;'   ,  :      .'    ;;-.  .-.   .;.::.`-' . ,';.  ,:.,'   ;;-.  .-.     `-',:.,' ;;-.    .'.    
   ;;    ;   ;   ;    .;     ;;  ;.;.-'   .;   ;'   ;;  ;; :   ;   ;;  ;.;.-'    ;' :   ; ;;  ;  .;.';    
  ;;  ;  ;;.'`..:;._.;      .;`  ` `:::'.;' _.;:._.';  ;;   `-:'  .;`  ` `:::'_.;:._.`-:'.;`  `.;.' .'    
  `;.' `.;'                                        ;    `.-._:'                    -._:'        '         
    )" << RESET << "\n";
}
 waitForEnter();  // Press Enter to continue
cout << BOLD << "📘 Opening: " << selectedBook << RESET << "\n\n";
    reader.loadProgress(availableBooks[choice - 1]);

    char key;
    do {
        reader.displayPage();
        cout << BOLD
          << GREEN << "[->] Next" << RESET << " | "
          << GREEN << "[<-] Prev" << RESET << " | "
          << YELLOW << "[s] Search" << RESET << " | "
          << CYAN << "[b] Bookmark" << RESET << " | "
          << RED << "[q] Quit" << RESET
          << "\n> ";
         key = _getch();

        switch (key) {
            case 77: reader.nextPage(); break;
            case 75: reader.prevPage(); break;
            case 's': {
                string word;
                cout << "Search: ";
                cin >> word;
                reader.search(word);
                break;
            }
            case 'b': reader.bookmark(); break;
        }
    } while (key != 'q');

    cout << "Goodbye!\n";
    reader.saveProgress(availableBooks[choice - 1]); 
    return 0;
}
//cd "C:\c++ programming\Mini Kindle" ; g++ main.cpp Reader.cpp Book.cpp utils.cpp -o main && .\main