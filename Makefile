CC = g++
CFLAGS = -std=c++11 -Wall -fsanitize=address -fsanitize=undefined -g
GOOGLETEST = ./googletest
OUTPUTNAME = TrieTests

$(OUTPUTNAME): Node.o Trie.o TrieTests.o
	$(CC) $(CFLAGS) Node.o Trie.o TrieTests.o -o TrieTests -L$(GOOGLETEST)/lib -lgtest -lgtest_main -lpthread

TrieTests.o: TrieTests.cpp Trie.o Node.o
	$(CC) $(CFLAGS) -c TrieTests.cpp -I$(GOOGLETEST)/googletest/include

Trie.o: Trie.cpp Trie.h
	$(CC) $(CFLAGS) -c Trie.cpp

Node.o: Node.cpp Node.h
	$(CC) $(CFLAGS) -c Node.cpp 

test: $(OUTPUTNAME)
	./$(OUTPUTNAME)

clean:
	rm -f TrieTest *.o
rebuild:
	make clean 
	make $(OUTPUTNAME) 
	make test


