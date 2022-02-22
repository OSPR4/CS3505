/*
Osee Pierre
CS3505
A3: A Trie and Rule-of-Three
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
//     Node( const Node&  other);
//    ~Node();
//     Node& operator=(Node other);
    void setNode(char index); 
    Node getNode(char index);
    
    std::map<char, Node>::iterator getNodeIterator(char index);
   
    bool isValidNode(char index);
    int getBranchSize(); 
    void setIsWord(bool val);
    bool getIsWord();


};
#endif