#include <iostream>
#include <string>
#include "Huffman.h"

using namespace std;

void printMenu()
{
    cout << "\n=============================================\n";
    cout << "   HUFFMAN FILE COMPRESSION SYSTEM\n";
    cout << "=============================================\n";
    cout << "1. Compress File\n";
    cout << "2. Decompress File\n";
    cout << "3. Exit\n";
    cout << "=============================================\n";
    cout << "Enter your choice: ";
}

int main()
{
    Huffman huffman;
    int choice;

    while (true)
    {
        printMenu();

        cin >> choice;
        cin.ignore();

        if (choice == 1)
        {
            string inputFile;
            string outputFile;

            cout << "\nEnter input text file: ";
            getline(cin, inputFile);

            cout << "Enter compressed file name (.huff): ";
            getline(cin, outputFile);

            if (huffman.compress(inputFile, outputFile))
            {
                cout << "\nCompression Successful!\n";
            }
            else
            {
                cout << "\nCompression Failed!\n";
            }
        }
        else if (choice == 2)
        {
            string inputFile;
            string outputFile;

            cout << "\nEnter compressed file (.huff): ";
            getline(cin, inputFile);

            cout << "Enter output text file: ";
            getline(cin, outputFile);

            if (huffman.decompress(inputFile, outputFile))
            {
                cout << "\nDecompression Successful!\n";
            }
            else
            {
                cout << "\nDecompression Failed!\n";
            }
        }
        else if (choice == 3)
        {
            cout << "\nThank you for using Huffman Compressor.\n";
            break;
        }
        else
        {
            cout << "\nInvalid Choice!\n";
        }
    }

    return 0;
}
