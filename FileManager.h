#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class FileManager
{
public:

    // Constructor
    FileManager();

    // Destructor
    ~FileManager();

    //==============================
    // Text File Operations
    //==============================

    // Read entire text file
    bool readTextFile(
        const string& filename,
        string& text
    );

    // Write text to file
    bool writeTextFile(
        const string& filename,
        const string& text
    );

    //==============================
    // Binary File Operations
    //==============================

    // Save compressed data
    bool writeCompressedFile(
        const string& filename,
        const unordered_map<char, int>& frequencyTable,
        const string& encodedBits
    );

    // Load compressed data
    bool readCompressedFile(
        const string& filename,
        unordered_map<char, int>& frequencyTable,
        string& encodedBits
    );

private:

    //==============================
    // Helper Functions
    //==============================

    // Convert bit string (010101...)
    // into binary bytes
    vector<unsigned char> packBits(
        const string& bits
    );

    // Convert bytes back
    // into bit string
    string unpackBits(
        const vector<unsigned char>& bytes,
        int validBits
    );
};

#endif
