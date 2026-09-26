#include <iostream>
#include <fstream>
#include <string>

#include "Document.h"
#include "SearchEngine.h"

using namespace std;

string readFile(string filePath)
{
    ifstream file(filePath);

    if (!file.is_open())
    {
        cout << "Error opening file: "
             << filePath << endl;

        return "";
    }

    string content;
    string line;

    while (getline(file, line))
    {
        content += line + " ";
    }

    file.close();

    return content;
}

int main()
{
    SearchEngine engine;

    // Read documents
    string content1 =
        readFile("data/doc1.txt");

    string content2 =
        readFile("data/doc2.txt");

    string content3 =
        readFile("data/doc3.txt");

    // Create Document objects
    Document doc1(
        1,
        "doc1.txt",
        content1);

    Document doc2(
        2,
        "doc2.txt",
        content2);

    Document doc3(
        3,
        "doc3.txt",
        content3);

    // Add documents
    engine.addDocument(doc1);
    engine.addDocument(doc2);
    engine.addDocument(doc3);

    // Build inverted index
    engine.buildIndex();

    int choice;

    while (true)
    {
        cout << "\n";
        cout << "====================================\n";
        cout << "       MINI SEARCH ENGINE\n";
        cout << "====================================\n";

        cout << "1. Show Documents\n";
        cout << "2. Search\n";
        cout << "3. Show Inverted Index\n";
        cout << "4. Exit\n";

        cout << "\nEnter choice: ";
        cin >> choice;

        cin.ignore();

        if (choice == 1)
        {
            engine.showDocuments();
        }

        else if (choice == 2)
        {
            string query;

            cout << "\nEnter search query: ";

            getline(cin, query);

            engine.search(query);
        }

        else if (choice == 3)
        {
            engine.showIndex();
        }

        else if (choice == 4)
        {
            cout << "\nThank you for using Mini Search Engine!\n";
            break;
        }

        else
        {
            cout << "\nInvalid choice!\n";
        }
    }

    return 0;
}