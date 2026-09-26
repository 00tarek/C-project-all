#include "Indexer.h"
#include "Text Processor.h"

#include <iostream>

using namespace std;

void Indexer::addDocument(const Document &document)
{
    vector<string> words =
        TextProcessor::process(
            document.getContent());

    for (const string &word : words)
    {
        // Add document ID
        invertedIndex[word].insert(
            document.getId());

        // Increase frequency
        frequencyIndex[word][document.getId()]++;
    }
}

set<int> Indexer::searchWord(const string &word) const
{
    string processedWord =
        TextProcessor::toLowerCase(word);

    auto it = invertedIndex.find(processedWord);

    if (it != invertedIndex.end())
    {
        return it->second;
    }

    return {};
}

int Indexer::getFrequency(
    const string &word,
    int documentId) const
{
    string processedWord =
        TextProcessor::toLowerCase(word);

    auto wordIt =
        frequencyIndex.find(processedWord);

    if (wordIt == frequencyIndex.end())
    {
        return 0;
    }

    auto docIt =
        wordIt->second.find(documentId);

    if (docIt == wordIt->second.end())
    {
        return 0;
    }

    return docIt->second;
}

void Indexer::showIndex() const
{
    cout << "\n========== INVERTED INDEX ==========\n";

    for (const auto &entry : invertedIndex)
    {
        cout << entry.first << " -> ";

        for (int docId : entry.second)
        {
            cout << "Doc" << docId << " ";
        }

        cout << endl;
    }

    cout << "====================================\n";
}