#include <cctype>
#include <cstdio>

#include <iostream>


using namespace std;

enum Token {
    tok_eof = -1,

    // commands
    tok_def = -2,
    tok_extern = -3,

    // primary
    tok_identifier = -4,
    tok_number = -5
};

static std::string IdentifierStr; // Filled in if tok_identifier
static double NumVal;             // Filled in if tok_number

/// gettok - Return the next token from standard input.
static int gettok() {
    static int LastChar = ' ';

    while (isspace(LastChar))
        LastChar = getchar();                                  // space
    
    if (isalpha(LastChar)) {                                   // string [a-zA-Z][a-zA-Z0-9]*
        // identifier: [a-zA-Z][a-zA-Z0-9]*
        IdentifierStr = LastChar;
        while (isalnum((LastChar = getchar())))
            IdentifierStr += LastChar;
        
        if (IdentifierStr == "def") return tok_def;
        if (IdentifierStr == "extern") return tok_extern;
        return tok_identifier;
    }

    if (isdigit(LastChar) || LastChar == '.') {               // Number
        std::string NumStr;
        do {
            NumStr += LastChar;
            LastChar = getchar();
        } while (isdigit(LastChar) || LastChar == '.');
        NumVal = strtod(NumStr.c_str(), nullptr);
        return tok_number;
    }

    if (LastChar == '#') {                                    // #
        do
            LastChar = getchar();
        while (LastChar != EOF && LastChar != '\n' && LastChar != '\r');
        
    }

    if (LastChar == EOF)                                     // EOF
        return tok_eof;
    
    // 感觉也没必要这么复杂 直接判定这个string是不是关键字就可以了 没必要这么复杂
    // 见仁见智吧 反正这样也能token化
    int ThisChar = LastChar;                              
    LastChar = getchar();                                   // string ascii
    return ThisChar;

}

int main() {
    cout << "222" << endl;
    return 1;
}

static int get_next_token() { return }