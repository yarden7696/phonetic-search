#include "PhoneticFinder.hpp"
#include <stdexcept>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

namespace phonetic {
    const char *replacments['z' - 'a' + 1] =
            {
                    "a",
                    "bfp",
                    "ckq",
                    "dt",
                    "e",
                    "fbp",
                    "gj",
                    "h",
                    "iy",
                    "jg",
                    "kcq",
                    "l",
                    "m",
                    "n",
                    "ou",
                    "pbf",
                    "qck",
                    "r",
                    "sz",
                    "td",
                    "uo",
                    "vw",
                    "wv",
                    "x",
                    "yi",
                    "zs"
            };

    //this function checks if two chars are equals 
    bool compare_chars(char c1, char c2) {
        
        if (c1 == ' ' || c2 == ' ') { return (c1 == ' ' && c2 == ' '); }

        char c1_lower = tolower(c1);
        char c2_lower = tolower(c2);

        std::string c1_replacments = std::string(replacments[c1_lower - 'a']); //Look for the first word in the
                                                                              //array,c1_replacments is a string from the array
        int lenString = c1_replacments.length();
        for (int i = 0; i < lenString; i++) {
            if (c2_lower == c1_replacments[i]) { // running on the string caz we wont a single char from it  
                return true;
            }
        }
        return false;
    }


    std::string find(std::string text, std::string word) {
        
        for (int i = 0; i < text.length(); i++) { // running on the text
            bool searchWordFound = true;

            for (int j = 0; j < word.length(); j++) { //run on each char in the word we are looking for and check if it exists in the text
                if (!(compare_chars(text[i + j], word[j]))) { //"i" is the first char in the text that equals to the first char in the word
                    searchWordFound = false;
                    break;
                }
            }
                if(searchWordFound) // we found the all chars in the word
                {
                    std::string ans=text.substr(i, word.length());
                    if((text[i-1]==' ' && text[i+word.length()]==' ' ) || (text[i-1]==' ' && (i+word.length())==text.length())
                       || (compare_chars(text[0], word[0]) && (text[word.length()]==' ')) || ((text[0]==word[0]) && (text.length()==word.length())))
                    {
                        return text.substr(i, word.length()); // We found the word we were looking for - so we'll take it from the text
                                                             // substr(first position, how many chars to cut)
                    }
                }
            }

            throw std::out_of_range{"The word: " + word +" didn't find at the text"};
        }

    }

