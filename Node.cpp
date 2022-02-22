/*
Osee Pierre
CS3505
A3: A Trie and Rule-of-Three
*/
#include "Node.h"
#include <algorithm>

//Node constructor
Node::Node()
{
   
    isWord = false;
    // for(int i = 0; i < 26; i++)
    // {
    //     children[i] = nullptr;
    // }
}
    //Node Setter 
    void Node::setNode(char index)
        {
            Node n;
            branches[index] = n;
        }

    //Node Getter
    std::map<char, Node>::iterator Node::getNodeIterator(char index)
    {
        return branches.find(index);
    }

    Node Node::getNode(char index)
    {
        return branches[index];
    }

    //Setting for word validity
    void Node::setIsWord(bool val)
    {
        isWord = true;
    }

     //Getting for word validity
    bool Node::getIsWord()
    {
        return isWord;
    }


    // //Destructor
    // Node::~Node()
    // {
    //     for(int i = 0; i < 26; i++)
    //     {   
    //         if(children[i] != NULL)
    //         delete children[i];
    //     }
    // }

    // //Copy constructor
    // Node::Node( const Node&  other) 
    // {
    //     isWord = other.isWord;
    //     for(int i = 0; i < 26; i++)
    //     {
    //         children[i] = nullptr;
    //         if(other.children[i])
    //             children[i] = other.children[i];
    //     }
    //     // *children = *other.children;
    //     //children = new Node((other.children));
    // }

    // //Copy assignment operator 
    // Node& Node::operator=(Node other)
    // {
    //     std::swap(isWord, other.isWord);
    //     for(int i = 0; i < 26; i++)
    //     {
    //          std::swap(children[i], other.children[i]);
    //     }
       
    //     return *this;
    // }