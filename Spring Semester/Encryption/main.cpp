#include <iostream>
#include <vector>
#include <iomanip>

std::string encrypt(std::string code, int shift) {
    // lowercase input
    for(int i = 0; i < code.size(); i++) {
        code[i] = char(tolower(code[i]));
    }
    // keep spaces
    for(int i = 0; i < code.size(); i++) {
        if(code[i] == ' ') {
            continue;
        }
        // wrap around if string is shifted beyond "z"
        code[i] = char((((code[i] + shift) - 97) % 26) + 97);
    }
    return code;
}

int main() {
    // get user input
    char str[100];
    std::cout << " Enter a key: ";
    int key;
    std::cin >> key;
    std::cin.ignore();
    std::cout << " Enter a string: ";
    std::cin.getline(str, 100);

    // split up input based on spaces
    char *ptr;
    ptr = strtok(str, " ");

    // vectorize the split up input string
    std::vector<std::string> input;
    while (ptr != NULL) {
        input.push_back(ptr);
        ptr = strtok (NULL, " , ");
    }

    // create another vector and encrypt the values of the orignal vector
    std::vector<std::string> encrypted;
    for(int i = 0; i < input.size(); i++) {
        encrypted.push_back(encrypt(input.at(i), key));
    }

    // print out string and encrypted string in table format
    for(int i = 0; i < input.size(); i++) {
        std::cout << std::setw(21) << std::left << input.at(i) << encrypted.at(i) << std::endl;
    }

    return 0;
}
