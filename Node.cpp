/*
Osee Pierre
CS3505
A4: Refactoring and Testing
*/
#include "Node.h"
#include <algorithm>

//Node constructor
Node::Node()
{
   
    isWord = false;
}
    //Node Setter 
    void Node::setNode(char index)
        {
            Node newNode;
            branches[index] = newNode;
        }

    //Node Getter with iterator
    std::map<char, Node>::iterator Node::getNodeIterator(char index)
    {
        return branches.find(index);
    }

    //Node Getter 
    Node Node::getNode(char index)
    {
        return branches[index];
    }

    //Determine if a letter is within the branches map
    bool Node::isValidNode(char index)
    {
         
        auto search = branches.find(index);
        if (search != branches.end()) {
            return true;
        } else {
            return false;
        }
    }

    int Node::getBranchSize()
    {
        return branches.size();
    }
    //Setter for word validity
    void Node::setIsWord(bool val)
    {
        isWord = true;
    }

     //Getter for word validity
    bool Node::getIsWord()
    {
        return isWord;
    }
