 #include <iostream>
#include <limits>
#include <string>

#include "Huffman.h"
#include "FileManager.h"

using namespace std;

void printHeader()
{
    cout << "=============================================\n";
    cout << "   HUFFMAN FILE COMPRESSION SYSTEM\n";
    cout << "=============================================\n";
}

void printMenu()
{
    cout << "\n1. Compress File\n";
    cout << "2. Decompress File\n";
    cout << "3. Exit\n";
    cout << "\nEnter your choice: ";
}

int main()
{
    Huffman huffman;
    FileManager fileManager;

    int choice;

    while (true)
    {
        printHeader();
        printMenu();

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "\nInvalid input.\n\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice)
        {
            case 1:
            {
                string inputFile;
                string outputFile;

                cout << "\nEnter input text file: ";
                getline(cin, inputFile);

                cout << "Enter output compressed file (.huff): ";
                getline(cin, outputFile);

                if (huffman.compress(inputFile, outputFile))
                {
                    cout << "\n=====================================\n";
                    cout << "Compression Successful.\n";
                    cout << "Output File : " << outputFile << endl;
                    cout << "=====================================\n";
                }
                else
                {
                    cout << "\nCompression Failed.\n";
                }

                break;
            }

            case 2:
            {
                string inputFile;
                string outputFile;

                cout << "\nEnter compressed file (.huff): ";
                getline(cin, inputFile);

                cout << "Enter output text file: ";
                getline(cin, outputFile);

                if (huffman.decompress(inputFile, outputFile))
                {
                    cout << "\n=====================================\n";
                    cout << "Decompression Successful.\n";
                    cout << "Output File : " << outputFile << endl;
                    cout << "=====================================\n";
                }
                else
                {
                    cout << "\nDecompression Failed.\n";
                }

                break;
            }

            case 3:
            {
                cout << "\nThank you for using Huffman Compressor.\n";
                return 0;
            }

            default:
            {
                cout << "\nPlease enter a valid choice (1-3).\n";
            }
        }

        cout << "\nPress Enter to continue...";
        cin.get();

        cout << "\n\n";
    }

    return 0;
}
