/*
Osee Pierre
CS3505
A3: A Trie and Rule-of-Three
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

        // //Copy constructor
        // Trie::Trie( const Trie& other) 
        // {
           
        //     root = new Node(*(other.root));
        // }

        // //Copy assignment operator 
        // Trie& Trie::operator=(Trie other)
        // {
        //     std::swap(root, other.root);
        //     return *this;
        // }

        //Add word to Trie
        void Trie::addAWord(std::string word)
        {

             Node* current = &root;

            for(int i = 0; i < word.length(); i++)
            {
                    
                if(!current->isValidNode(word[i]))
                {
                    current->setNode(word[i]);
                }
                 auto iterator = current->getNodeIterator(word[i]);
                current = &iterator->second;
             
            }
            
            current->setIsWord(true);

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
            Node current = root;
            

            for(int i = 0; i < word.length(); i++)
            {
                if(!current.isValidNode(word[i]))
                {
                    Node empty; 
                    return empty;
                }
                else
                {
                 current = current.getNode(word[i]);
                }
                
            }
            return current;

        }

        //Returns a list of word that start with a particular set of letter
        std::vector<std::string> Trie::allWordsStartingWithPrefix(std::string word)
        {
            std::vector<std::string> words;

            Node prefixNode = searchTrie(word);

             if((prefixNode.getBranchSize() < 1))
                return words;

               
             if (prefixNode.getIsWord())
             {
                words.push_back(word);
             }
             traverseTrie(prefixNode, word, words);

            return words;
             
        }

        //Helper function to assist is in retrieving all words starting with a particular set of letter
        void Trie::traverseTrie(Node current, std::string word,  std::vector<std::string> &wordList)
        {
            Node next = current;
            std::string tempWord = word;

            //  std::cout << "made it here: " << current->getBranchSize() << std::endl;
           // std::cout << "made it here: " << word << std::endl;
            
             for (size_t i = 0; i < 26; i++)
             {
                 char c = i + 97;
                 if(!current.isValidNode(c))
                    continue;
                
                tempWord += c;

                // auto iterator = current->getNodeIterator(c);
                // current = &iterator->second;

                if(current.getNode(c).getIsWord())
                    wordList.push_back(tempWord);
                
                auto iterator = current.getNodeIterator(c);
                next = iterator->second;
               // std::cout << "made it here: " << next.getIsWord() << std::endl;
                traverseTrie(next, tempWord, wordList);
                tempWord = word;

             }

        }

