#ifndef CMAKE_TRANSLAT_O_MATIC_MULTI_LANGUAGE_LIBRARY_H
#define CMAKE_TRANSLAT_O_MATIC_MULTI_LANGUAGE_LIBRARY_H

#include <string>
#include <unordered_map>
#include <exception>
#include <sstream>
#include <functional>

class LangException : public std::exception {
    virtual const char* what() const throw() {
        return "LangException: language file not found OR not loaded";
    }
};

class LanguageResource {
private:
    std::string dir;
    std::string locale;
    std::unordered_map<std::string, std::string> languagePhrases;

    /**
     * Private function: loads .properties file for language strings
     */
    void loadLanguage();

public:
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
     * @param language represents the language code for the locale parameters language_TERRITORY (ex: language=en in
     *          en_US)
     * @param territory represents the territory code for the locale parameters language_TERRITORY (ex: territory=US in
     *          en_US)
     */
    LanguageResource(const std::string& dir, const std::string& language, const std::string& territory);

    // TODO check if default is the optimal solution for standard variable definition
    /**
     * Copy constructor of LanguageResource
     *
     * @param languageResource: object input for copy
     */
    LanguageResource(const LanguageResource& languageResource) = default;

    /**
     * Move constructor of LanguageResource
     *
     * @param languageResource: object input for move
     */
    LanguageResource(LanguageResource&& languageResource) = default;

    /**
     * Destructor of LanguageResource
     */
    ~LanguageResource() = default;

    /**
     * Copy assignment of LanguageResource
     *
     * @param languageResource: object input for copy
     * @return copied value of LanguageResource
     */
    LanguageResource& operator=(const LanguageResource& languageResource) = default;

    /**
     * Move assignment of LanguageResource
     *
     * @param languageResource: object input for move
     * @return moved value of LanguageResource
     */
    LanguageResource& operator=(LanguageResource&& languageResource) = default;

    /**
     * Function: returns the locale-wise string used in source code, extracted from language resources files
     *
     * @param keyword representing the string used to represent a text in source code to be changed
     * @return the locale-wise string from the language resources
     */
    std::string getLanguageResource(const std::string& keyword) const;

    /**
     * Function: calls a function to be called for each element of the languagePhrases elements
     *
     * @param function lambda of the function to be called
     */
    void forEachEntry(std::function<void(const std::string&, const std::string&)>& function) const;

    /**
     * Function: changes the language of the system
     *
     * @param language represents the language code for the locale parameters language_TERRITORY (ex: language=en in
     *          en_US)
     * @param territory represents the territory code for the locale parameters language_TERRITORY (ex: territory=US in
     *          en_US)
     */
    void changeLanguage(const std::string& language, const std::string& territory);

    /**
     * Getter function of the chosen language, in locale variable
     *
     * @return the language (aa) from aa_BB locale format
     */
    std::string getLanguage() const;

    /**
    * Getter function of the chosen territory, in locale variable
    *
    * @return the territory (BB) from aa_BB locale format
    */
    std::string getTerritory() const;
};


#endif //CMAKE_TRANSLAT_O_MATIC_MULTI_LANGUAGE_LIBRARY_H
