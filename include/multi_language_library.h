#ifndef CMAKE_TRANSLAT_O_MATIC_MULTI_LANGUAGE_LIBRARY_H
#define CMAKE_TRANSLAT_O_MATIC_MULTI_LANGUAGE_LIBRARY_H

#include <string>
#include <unordered_map>
#include <exception>
#include <sstream>

class LangException : public std::exception {
    virtual const char* what() const throw() {
        return "LangException: language file not found OR not loaded";
    }
};

class LanguageResource {
private:
    std::string dir;
    std::string locale;


    /**
     * Private function: loads .properties file for language strings
     */
    void loadLanguage();

public:
    std::unordered_map<std::string, std::string> languagePhrases;

    /**
     * Constructor: initialises the LanguageResource class
     *
     * @param dir represents the directory in which all translation files are contained.
     *              The directory needs to be relative.
     *              The files needs to have the following name structure:
     *                  "language_TERRITORY.properties"
     */
    explicit LanguageResource(const std::string& dir);

    /**
     * Constructor: initialises the LanguageResource class
     *
     * @param dir represents the directory in which all translation files are contained.
     *              The directory needs to be relative.
     * @param language represents the language code for the locale parameters language_TERRITORY (ex: language=en in en_US)
     * @param territory represents the territory code for the locale parameters language_TERRITORY (ex: territory=US in en_US)
     */
    LanguageResource(const std::string& dir, const std::string& language, const std::string& territory);

    /**
     * Function: returns the locale-wise string used in source code, extracted from language resources files
     *
     * @param keyword representing the string used to represent a text in source code to be changed
     * @return the locale-wise string from the language resources
     */
    std::string getLanguageResource(const std::string& keyword);

    /**
     * Function: changes the language of the system
     * TODO: set a "setupUI" in order to be recalled if the language is changed
     *
     * @param language represents the language code for the locale parameters language_TERRITORY (ex: language=en in en_US)
     * @param territory represents the territory code for the locale parameters language_TERRITORY (ex: territory=US in en_US)
     */
    void changeLanguage(const std::string& language, const std::string& territory);
};


#endif //CMAKE_TRANSLAT_O_MATIC_MULTI_LANGUAGE_LIBRARY_H
