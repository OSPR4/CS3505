/*
Osee Pierre
CS3505
A4: Refactoring and Testing
*/
#ifndef NODE_H
#define NODE_H
#include <map>

class Node
{
   private:
        bool isWord;
        std::map<char, Node> branches;

    public:  
    Node();

    void setNode(char index); 
    Node getNode(char index);
    
    std::map<char, Node>::iterator getNodeIterator(char index);
   
    bool isValidNode(char index);
    int getBranchSize(); 
    void setIsWord(bool val);
    bool getIsWord();


};
#endif