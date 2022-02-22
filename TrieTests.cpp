#include "Trie.h"
#include "gtest/gtest.h"

TEST(TrieTest, AddWord) {
    Trie tr;
    std::string n("dog");
    tr.addAWord(n);
    bool expectedResult = tr.isAWord(n);
    ASSERT_TRUE(expectedResult);
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