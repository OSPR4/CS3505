/*
Osee Pierre
CS3505
A4: Refactoring and Testing
*/
#include "Trie.h"
#include "gtest/gtest.h"

TEST(TrieTest, TestAddWord) {
    Trie tr;
    std::string n("dog");
    tr.addAWord(n);
    bool expectedResult = tr.isAWord(n);
    ASSERT_TRUE(expectedResult);
}

TEST(TrieTest, TestLongWord) {
    Trie tr;
    std::string n("donaudampfschiffahrtselektrizitatenhauptbetriebswerkbauunterbeamtengesellschaft");
    tr.addAWord(n);
    bool expectedResult = tr.isAWord(n);
    ASSERT_TRUE(expectedResult);
}

TEST(TrieTest, TesSingleLetter) {
    Trie tr;
    std::string n("z");
    tr.addAWord(n);
    bool expectedResult = tr.isAWord(n);
    ASSERT_TRUE(expectedResult);
}

TEST(TrieTest, TestAddEmptyWord) {
    Trie tr;
    std::string n("");
    tr.addAWord(n);
    bool expectedResult = tr.isAWord(n);
    ASSERT_FALSE(expectedResult);
}

TEST(TrieTest, PrefixTestForWordsInTrie) {
    Trie tr;
    int count = 0;
    std::vector<std::string> wordList = {"cat","cast","dog","their","school","sit","language","house"};
    std::vector<std::string> wordsReturned;
    for (size_t i = 0; i < wordList.size(); i++)
    {
     tr.addAWord(wordList.at(i));
    }

    std::vector<std::string> prefixWordList = {"c","do","t","s","lang","ho"};

    for (size_t i = 0; i < prefixWordList.size(); i++)
    {
       wordsReturned = tr.allWordsStartingWithPrefix(prefixWordList.at(i));
       count = count + wordsReturned.size();
    }

    ASSERT_EQ(wordList.size(), count);
}

TEST(TrieTest, PrefixTestForWordsNotInTrie) {
    Trie tr;
    int count = 0;
    std::vector<std::string> wordList = {"cat","cast","dog"};
    std::vector<std::string> wordsReturned;
    for (size_t i = 0; i < wordList.size(); i++)
    {
     tr.addAWord(wordList.at(i));
    }

    std::vector<std::string> prefixWordList = {"s","lang","ho"};

    for (size_t i = 0; i < prefixWordList.size(); i++)
    {
       wordsReturned = tr.allWordsStartingWithPrefix(prefixWordList.at(i));
       count = count + wordsReturned.size();
    }
    
    ASSERT_EQ(0, count);
}

TEST(TrieTest, TestForDuplicateEntries) {
    Trie tr;
    int count = 0;
    std::vector<std::string> wordList = {"cast","cast","dog","dog"};
    std::vector<std::string> wordsReturned;
    for (size_t i = 0; i < wordList.size(); i++)
    {
     tr.addAWord(wordList.at(i));
    }
    std::vector<std::string> prefixWordList = {"c","d"};

    for (size_t i = 0; i < prefixWordList.size(); i++)
    {
       wordsReturned = tr.allWordsStartingWithPrefix(prefixWordList.at(i));
       count = count + wordsReturned.size();
    }
    
    ASSERT_EQ(2, count);
}

TEST(TrieTest, TestTrieAssignment) {
    Trie myTrie;
    myTrie.addAWord("apple");
    Trie otherTrie = myTrie;
    bool expectedResult = otherTrie.isAWord("apple");

    ASSERT_TRUE(expectedResult);

}

TEST(TrieTest, TestTrieAssignment1) {
    Trie myTrie;
    myTrie.addAWord("apple");
    Trie otherTrie = myTrie;

    otherTrie.addAWord("pear");

    bool expectedResult = myTrie.isAWord("pear");
    ASSERT_FALSE(expectedResult);
}

TEST(TrieTest, TestTrieAssignment2) {
    Trie myTrie;
    myTrie.addAWord("apple");
    Trie otherTrie = myTrie;

     Trie myTrie2;
     myTrie2.addAWord("kiwi");

    otherTrie = myTrie2;

    bool expectedResult = otherTrie.isAWord("apple");
    ASSERT_FALSE(expectedResult);

    expectedResult = otherTrie.isAWord("kiwi");
    ASSERT_TRUE(expectedResult);
}