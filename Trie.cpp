/*
Osee Pierre
CS3505
A4: Refactoring and Testing
*/

#include "Node.h"
#include "Trie.h"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

        //Constructor
        Trie::Trie()
        {
         root = Node();
        }

        //Add word to Trie
        void Trie::addAWord(std::string word)
        {

             Node* currentBranch = &root;

             for (size_t i = 0; i < word.length(); i++)
             {
                if(!currentBranch->isValidNode(word[i]))
                {
                    currentBranch->setNode(word[i]);
                }
                 auto iterator = currentBranch->getNodeIterator(word[i]);
                currentBranch = &iterator->second;
             }
            
            currentBranch->setIsWord(true);

        }

        //Determine is a word is valid word
        bool Trie::isAWord(std::string word)
        {
            if(word.length() == 0)
                return false;
            Node wordNode = searchTrie(word);

            if(wordNode.getIsWord())
                return true;
            else
                return false;

        }

        //Helper function that searches for a word
        Node Trie::searchTrie(std::string word)
        {
            Node currentBranch = root;
            

            for(size_t i = 0; i < word.length(); i++)
            {
                if(!currentBranch.isValidNode(word[i]))
                {
                    Node emptyBranch; 
                    return emptyBranch;
                }
                else
                {
                 currentBranch = currentBranch.getNode(word[i]);
                }
                
            }
            return currentBranch;

        }

        //Returns a list of words that start with a particular set of letters
        std::vector<std::string> Trie::allWordsStartingWithPrefix(std::string prefixLetters)
        {
            std::vector<std::string> wordList;

            Node prefixNode = searchTrie(prefixLetters);

             if((prefixNode.getBranchSize() < 1))
                return wordList;

            
            //Checks if the prefix characters is a word
             if (prefixNode.getIsWord())
             {
                wordList.push_back(prefixLetters);
             }
             //TraversTrie to collect words starting with the given prefix
             traverseTrie(prefixNode, prefixLetters, wordList);

            return wordList;
             
        }

        //Helper function to assist is in retrieving all words starting with a particular set of letter
        void Trie::traverseTrie(Node currentBranch, std::string word,  std::vector<std::string> &wordList)
        {
            Node nextBranch = currentBranch;
            std::string tempWord = word;
            
            //Checks if different letters represent a valid node, if so, traverse down
            //each valid node and collect complete words
             for (size_t i = 0; i < 26; i++)
             {
                 char letter = i + 97;
                 if(!currentBranch.isValidNode(letter))
                    continue;
                
                tempWord += letter;

                if(currentBranch.getNode(letter).getIsWord())
                    wordList.push_back(tempWord);
                
                // auto iterator = currentBranch.getNodeIterator(letter);
                // nextBranch = iterator->second;
                nextBranch = currentBranch.getNode(letter);

                traverseTrie(nextBranch, tempWord, wordList);
                tempWord = word;

             }

        }

