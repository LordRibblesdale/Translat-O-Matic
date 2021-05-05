#include "../include/multi_language_library.h"

#include <filesystem>
#include <iostream>
#include <fstream>

/**
 * Function: returns the string form of the Language enumerator
 *
 * @param lang represents the Language form of the locale parameter
 * @return the string form of Language
 */

LanguageResource::LanguageResource(const std::string& dir) :
        dir(dir), locale("en_UK") {
    loadLanguage();
}

LanguageResource::LanguageResource(const std::string& dir, const std::string &language, const std::string &territory) :
        dir(dir) {
    locale.append(language).append("_").append(territory);
    loadLanguage();
}

std::string LanguageResource::getLanguageResource(const std::string& keyword) const {
    return languagePhrases.at(keyword);
}

void LanguageResource::changeLanguage(const std::string &language, const std::string &territory) {
    locale = std::move(std::string(language).append("_").append(territory));
    loadLanguage();
}

void LanguageResource::loadLanguage() {
    // Prepare file path
    std::filesystem::path fileDir(std::filesystem::current_path());
    fileDir.append(dir);
    fileDir.append(locale + ".properties");

    std::ifstream inputFile(fileDir);

    if (inputFile) {
        std::stringstream langFile;
        std::string line, keyword, langText;
        size_t eqIndex, blankIndex;

        langFile << inputFile.rdbuf();

        while (!langFile.eof()) {
            // Clearing strings
            keyword.clear();
            langText.clear();
            // Getting line from stream
            std::getline(langFile, line);

            // Substring indices extraction
            eqIndex = line.find('=');
            blankIndex = line.find(' ');

            // Space-less keyword substring
            if (blankIndex != std::string::npos && blankIndex < eqIndex) {
                keyword = line.substr(0, blankIndex);
            } else {
                keyword = line.substr(0, eqIndex);
            }

            // Moving text first index to first non-space character
            while (line.at(++eqIndex) == ' ');

            // Assigning all remaining text to langText
            langText = line.substr(eqIndex);

            // Creating object into map
            languagePhrases.emplace(keyword, langText);
        }

        inputFile.close();
    } else {
        throw LangException();
    }
}

std::string LanguageResource::getLanguage() const {
    return locale.substr(0, 2);
}

std::string LanguageResource::getTerritory() const {
    return locale.substr(3);
}