//
// Created by Liam Ross on 13/07/2022.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <map>
#include <set>

void part1();
void part2();
void displayWords(const std::map<std::string, int>& words);
void displayWords(const std::map<std::string, std::set<int>>& words);
std::string cleanStr(const std::string& str);

int main() {
    // /**=================**/
    // ===== Challenge 3 =====
    // /**=================**/

    // Using std::set & std::map

    // This challenge has 2 parts.
    // We will be reading words from a text file provided to you.
    // The text file is named words.txt and contains the first few
    // paragraphs from the book, "The Wonderful Wizard of Oz", by
    // L. Frank Baum.

    // Part 1:
    // For part 1 of this challenge, you are to display each unique word
    // in the file and immediately following each word display the number
    // of times it occurs in the text file.

    // The words should be displayed in ascending order.

    // Sample listing of the first few words:

    // Word         Count
    // ===================
    // Aunt         5
    // Dorothy      8
    // Dorothy's    1
    // Em           5
    // Even         1
    // From         1

    // Use std::map<std::string, int>

    // ===================================================================

    // Part 2:
    // For part 2 of the challenge, you are to display each unique wore
    // from the file and immediately following each word display the line
    // numbers in which that word appears.

    // The words should be displayed in ascending order and the line numbers
    // for each word should also e displayed in ascending order.
    // If a word appears more than once on a line then the number should only
    // appear once.

    // Sample listing of the first few words:

    // Word         Occurrences
    // ======================================
    // Aunt         [ 2 7 25 29 48 ]
    // Dorothy      [ 1 7 15 29 39 43 47 51 ]
    // Dorothy's    [ 31 ]
    // Em           [ 2 7 25 30 48 ]
    // Even         [ 19 ]
    // From         [ 50 ]

    // Use std::map<std::string, std::set<int>>

    part1();
    part2();
    return 0;
}

void part1() {
    std::map<std::string, int> words;
    std::string line;
    std::string word;
    std::ifstream inFile {"../Notes/Challenge3/words.txt"};

    if (inFile) {
        std::cout << "Found File!\n" << std::endl;

        // --- Code goes here ---
        while(getline(inFile, line)) {
            std::stringstream ss{line};

            while (ss >> word) {
                word = cleanStr(word);

//                auto iter = words.find(word);
//
//                if (iter == std::end(words))
//                    words.insert(std::make_pair(word, 1));
//                else
//                    words[word]++;

                words[word]++;
            }
        }
        inFile.close();
        displayWords(words);
    } else
        std::cerr << "\nError opening input file!" << std::endl;
}

void part2() {
    std::map<std::string, std::set<int>> words;
    std::string line;
    std::string word;
    std::ifstream inFile {"../Notes/Challenge3/words.txt"};

    if (inFile) {
        std::cout << "Found File!\n" << std::endl;
        int lineCount{1};

        // --- Code goes here ---
        while (getline(inFile, line)) {
            std::stringstream ss{line};

            while (ss >> word) {
                word = cleanStr(word);

//                auto iter = words.find(word);
//
//                if (iter == words.end())
//                    words.insert(std::pair<std::string, std::set<int>>(word, {lineCount}));
//                else
//                    words[word].insert(lineCount);

                words[word].insert(lineCount);
            }
            lineCount++;
        }

        inFile.close();
        displayWords(words);
    } else
        std::cerr << "\nError opening input file!" << std::endl;
}

void displayWords(const std::map<std::string, int>& words) {
    std::cout << std::setw(12) << std::left << "\nWord"
              << std::setw(7) << std::right << "Count" << std::endl;
    std::cout << "===========================" << std::endl;

    for (const auto& pair : words)
        std::cout << std::setw(12) << std::left << pair.first
                  << std::setw(7) << std::right << pair.second << "\n";

}
void displayWords(const std::map<std::string, std::set<int>>& words) {
    std::cout << std::setw(12) << std::left << "\nWord"
              << "Line Occurrences" << std::endl;
    std::cout << "======================================================" << std::endl;

    for (const auto& pair : words) {
        std::cout << std::setw(12) << std::left << pair.first
                  << std::left << "[ ";
        for (const auto& i : pair.second)
            std::cout << i << " ";
        std::cout << "]\n";
    }
}

std::string cleanStr(const std::string& str) {
    std::string result;
    for (const auto& c : str) {
        if (c == '.' || c == ',' || c == ';' || c == ':')
            continue;
        else result += c;
    }

    return result;
}
