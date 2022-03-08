/*
    convert.cpp

    Convert the string

    Note: The "@CONCERN" is for pedagogical purposes only
*/

#include <iostream>
#include <string>
#include <cctype>

typedef void (*Conversion)(char& c);

// @CONCERN string, traversal, apply()
void myforeach(std::string::const_iterator begin, std::string::const_iterator end,
    void (*apply)(char c)) {

    for (auto pc = begin; pc != end; ++pc)
        apply(*pc);
    std::cout << '\n';
}

// @CONCERN string, traversal, apply()
void myforeach(std::string::iterator begin, std::string::iterator end,
    Conversion apply) {

    for (auto pc = begin; pc != end; ++pc)
        apply(*pc);
    std::cout << '\n';
}

// output
// @CONCERN output format
void output(char c) {
    std::cout << c;
}

// upper
// @CONCERN ctype
void upper(char& c) {
    c = std::toupper(c);
}

// lower
// @CONCERN ctype
void lower(char& c) {
    c = std::tolower(c);
}

int main(int argc, char* argv[]) {

    // requires conversion option and string
    // @CONCERN argc, argv, error handling
    if (argc != 3) {
        std::cerr << "usage: " << argv[0] << " <option> <string>\n";
        return 1;
    }

    // conversion option
    // @CONCERN argv, argv[1] is option, option
    std::string option(argv[1]);

    // input string
    // @CONCERN argv, argv[2] is string, string
    std::string s = argv[2];

    // convert the string according to the option
    // @CONCERN "--upper", "--lower", invalid option, error handling
    Conversion conversion = nullptr;
    if (option == "--upper") {

        conversion = upper;

    } else if (option == "--lower") {

        conversion = lower;

    } else {

        std::cerr << "Invalid conversion option: " << option << '\n';
        return 1;
    }

    // apply the conversion
    // @CONCERN string, myforeach(), upper(), lower()
    myforeach(s.begin(), s.end(), conversion);

    // output converted string
    // @CONCERN string, output(), myforeach()
    myforeach(s.cbegin(), s.cend(), output);

    return 0;
}
