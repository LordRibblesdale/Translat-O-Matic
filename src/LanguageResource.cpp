#include "../include/LanguageResource.hpp"

#include <filesystem>
#include <iostream>
#include <fstream>

/**
 * Function: returns the string form of the Language enumerator
 *
 * @param lang represents the Language form of the locale parameter
 * @return the string form of Language
 */

LanguageResource::LanguageResource(const std::string& dir) : dir(dir) {
    loadLanguage();
}

LanguageResource::LanguageResource(const std::string& dir, const std::string &language, const std::string &territory) :
        dir(dir), locale(language + "_" + territory) {
    loadLanguage();
}

std::string LanguageResource::getLanguageResource(const std::string& keyword) const {
    return languagePhrases.at(keyword);
}

template <typename Predicate>
void LanguageResource::forEachEntry(Predicate&& function) const {
    for (auto& [first, second] : languagePhrases) {
        function(first, second);
    }
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

        std::string line;
        std::string keyword;
        std::string langText;

        size_t eqIndex;
        size_t blankIndex;

        langFile << inputFile.rdbuf();

        while (!langFile.eof()) {
            // Clearing strings
            keyword.clear();
            langText.clear();
            // Getting line from stream
            std::getline(langFile, line);

            // Substring indices extraction
            eqIndex = line.find('=');
            blankIndex = std::min(line.find(' '), line.find('\t'));

            // Space-less keyword substring
            if (blankIndex != std::string::npos && blankIndex < eqIndex) {
                keyword = line.substr(0, blankIndex);
            } else {
                keyword = line.substr(0, eqIndex);
            }

            // Moving text first index to first non-space character
            while (line.at(++eqIndex) == ' ' || line.at(eqIndex) == '\t');

            // Assigning all remaining text to langText
            langText = line.substr(eqIndex);

            // Creating object into map
            languagePhrases.try_emplace(keyword, langText);
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