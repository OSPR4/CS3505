
/*
Osee Pierre
CS3505
A3: A Trie and Rule-of-Three
*/
#include "Node.h"
#include <vector>
#include <string>


#ifndef TRIE_H
#define TRIE_H

class Trie
{
    private:
        Node root;

        void traverseTrie(Node current, std::string word,  std::vector<std::string> &wordList);

        Node searchTrie(std::string word);

    public:
        Trie();

        // Trie( const Trie& other);

        // Trie& operator=(Trie other);

        void addAWord(std::string word);

        bool isAWord(std::string word);
       
        std::vector<std::string> allWordsStartingWithPrefix(std::string word);

    
};
#endif