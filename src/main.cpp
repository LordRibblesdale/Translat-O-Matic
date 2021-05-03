#include "../include/multi_language_library.h"

#include <iostream>

int main(void) {
    LanguageResource lr("languages", "en", "UK");

    std::cout << "mymap contains:" << std::endl;
    for (auto& x: lr.languagePhrases)
        std::cout << x.first << ": \"" << x.second << "\""<< std::endl;

    return 0;
}