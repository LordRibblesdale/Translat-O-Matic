# Translat-O-Matic language resource library
Translat-O-Matic is a language handler library, inspired by ResourceBundle from Java language.<br>
It is possible to create a "*.properties" file in which create a key-value structure for each language entry.<br>

## Structure
> key = value

For each line in a properties file, a key is defined, identifying a unique call for an internal map; this will allow 
searching in any language a specific language resource.<br>
Then, after inserting equal symbol, it is possible to define the actual translated line for that entry.