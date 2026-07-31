 #ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class FileManager
{
public:

    FileManager();
    ~FileManager();

    //=================================================
    // Text File Operations
    //=================================================

    // Read complete text file
    bool readTextFile(
        const string& filename,
        string& text
    );

    // Write decompressed text
    bool writeTextFile(
        const string& filename,
        const string& text
    );

    //=================================================
    // Binary Compression File
    //=================================================

    bool writeCompressedFile(
        const string& filename,
        const unordered_map<char, int>& frequencyTable,
        const vector<unsigned char>& compressedData,
        int validBits
    );

    bool readCompressedFile(
        const string& filename,
        unordered_map<char, int>& frequencyTable,
        vector<unsigned char>& compressedData,
        int& validBits
    );

    //=================================================
    // Bit Conversion
    //=================================================

    vector<unsigned char> packBits(
        const string& bitString
    );

    string unpackBits(
        const vector<unsigned char>& bytes,
        int validBits
    );
};

#endif
