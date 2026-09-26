#ifndef INDEXER_H
#define INDEXER_H

#include <string>
#include <vector>
#include <unordered_map>
#include <set>

#include "Document.h"

using namespace std;

class Indexer
{
private:
    // word -> document IDs
    unordered_map<string, set<int>> invertedIndex;

    // word -> document ID -> frequency
    unordered_map<string, unordered_map<int, int>> frequencyIndex;

public:
    void addDocument(const Document &document);

    set<int> searchWord(const string &word) const;

    int getFrequency(
        const string &word,
        int documentId) const;

    void showIndex() const;
};

#endif