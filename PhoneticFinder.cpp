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

    bool compare_chars(char c1, char c2) {
        if (c1 == ' ' || c2 == ' ') {
            return (c1 == ' ' && c2 == ' ');
        }

        char c1_lower = tolower(c1);
        char c2_lower = tolower(c2);

        std::string c1_replacments = std::string(replacments[c1_lower - 'a']);
        int k = c1_replacments.length();
        for (int i = 0; i < k; i++) {
            if (c2_lower == c1_replacments[i]) {
                return true;
            }
        }

        return false;
    }


    std::string find(std::string text, std::string word) {
        for (int i = 0; i < text.length(); i++) {
            bool searchWordFound = true;

            for (int j = 0; j < word.length(); j++) {
                if (!(compare_chars(text[i + j], word[j]))) {
                    searchWordFound = false;
                    break;
                }
            }
                if(searchWordFound)
                {
                    std::string ans=text.substr(i, word.length());
                    if((text[i-1]==' ' && text[i+word.length()]==' ' ) || (text[i-1]==' ' && (i+word.length())==text.length())
                       || (compare_chars(text[0], word[0]) && (text[word.length()]==' ')) || ((text[0]==word[0]) && (text.length()==word.length())))
                    {
                        return text.substr(i, word.length());
                    }
                }
            }

            throw std::out_of_range{"The word: " + word +" didn't find at the text"};
        }

    }

