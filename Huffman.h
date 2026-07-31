#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

// =======================
// Huffman Tree Node
// =======================
class Node
{
public:
    char data;
    int frequency;

    Node* left;
    Node* right;

    Node(char ch, int freq);

    bool isLeaf() const;
};

// =======================
// Comparator for Min Heap
// =======================
class Compare
{
public:
    bool operator()(Node* left, Node* right);
};

// =======================
// Huffman Class
// =======================
class Huffman
{
private:

    Node* root;

    unordered_map<char, int> frequencyTable;

    unordered_map<char, string> huffmanCodes;

    // Build frequency table
    void buildFrequencyTable(const string& text);

    // Build Huffman Tree
    void buildHuffmanTree();

    // Generate Binary Codes
    void generateCodes(Node* node, string code);

    // Encode text
    string encode(const string& text);

    // Decode binary string
    string decode(const string& bits);

    // Delete Tree
    void deleteTree(Node* node);

    // Save compressed file
    bool writeCompressedFile(
        const string& filename,
        const string& encodedData
    );

    // Read compressed file
    bool readCompressedFile(
        const string& filename,
        string& encodedData
    );

    // Save frequency table
    void writeFrequencyTable(ofstream& out);

    // Read frequency table
    void readFrequencyTable(ifstream& in);

    // Compression Statistics
    void displayStatistics(
        size_t originalSize,
        size_t compressedBits
    );

public:

    Huffman();

    ~Huffman();

    bool compress(
        const string& inputFile,
        const string& outputFile
    );

    bool decompress(
        const string& inputFile,
        const string& outputFile
    );
};

#endif
