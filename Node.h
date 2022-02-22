/*
Osee Pierre
CS3505
A3: A Trie and Rule-of-Three
*/
#ifndef NODE_H
#define NODE_H

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
    void setNode(int index);
    Node* getNode(int index);
    void setIsWord(bool val);
    bool getIsWord();

};
#endif