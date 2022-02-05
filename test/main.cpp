#include <iostream>
#include <string>

#include "LanguageResource.hpp"

int main() {
    LanguageResource lr("languages", "en", "UK");

    std::cout << "mymap contains:" << std::endl;
    std::function<void(const std::string&, const std::string&)> function = [] (const std::string& key,
            const std::string& value) {
        std::cout << key << ": \"" << value << "\""<< std::endl;
    };
    lr.forEachEntry(function);

    return 0;
}