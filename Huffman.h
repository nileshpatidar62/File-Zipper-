 #ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

//=========================================================
//                  Huffman Tree Node
//=========================================================

struct Node
{
    char data;
    int frequency;

    Node* left;
    Node* right;

    Node(char ch, int freq)
    {
        data = ch;
        frequency = freq;
        left = nullptr;
        right = nullptr;
    }

    bool isLeaf() const
    {
        return left == nullptr && right == nullptr;
    }
};

//=========================================================
//          Comparator for Min Priority Queue
//=========================================================

struct Compare
{
    bool operator()(Node* a, Node* b)
    {
        return a->frequency > b->frequency;
    }
};

//=========================================================
//                  Huffman Class
//=========================================================

class Huffman
{
private:

    Node* root;

    unordered_map<char, int> frequencyTable;

    unordered_map<char, string> huffmanCodes;

    // Build frequency table
    void buildFrequencyTable(const string& text);

    // Construct Huffman Tree
    void buildTree();

    // Generate binary codes
    void generateCodes(Node* node, string code);

    // Encode text into bit string
    string encode(const string& text);

    // Decode bit string
    string decode(const string& bits);

    // Free memory
    void deleteTree(Node* node);

    // Display compression information
    void displayStatistics(
        size_t originalBytes,
        size_t compressedBytes
    );

public:

    Huffman();

    ~Huffman();

    // Compress file
    bool compress(
        const string& inputFile,
        const string& outputFile
    );

    // Decompress file
    bool decompress(
        const string& inputFile,
        const string& outputFile
    );

    // Getters
    unordered_map<char,int>& getFrequencyTable();

    unordered_map<char,string>& getCodeTable();

    Node* getRoot();
};

#endif
