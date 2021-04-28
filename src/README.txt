The ".properties" structure is like the one used for ResourceBundle from Java libraries.
The file structure is the following:
1: the first name is referred to the keyword used inside the source code
2: the equal is inserted in order to define the later used string for the code
3: the following characters will represent the final string used

TODO: name -> until space isn't found => substring(0, firstSpaceIndex) = keyword
      looking for equal character '='
      while the next characters after '=' are spaces, wait until they aren't
        then until '\n' character, substring(indexAfterLastSpace, indexOf('\n')) = languageString

̅̅̅̅̅̅̅̅̅̅̅̅̅̅̅̅̅̅̅̅̅̅̅̅̅̅̅̅̅̅̅̅̅̅˥
settings = Settings               |
seconds = seconds                 |
autoSaveText = Set autosave timer:|
selectLanguage = Select language: |
__________________________________˩