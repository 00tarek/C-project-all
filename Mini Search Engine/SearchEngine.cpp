#include "SearchEngine.h"
#include "TextProcessor.h"

#include <iostream>
#include <sstream>

using namespace std;

void SearchEngine::addDocument(
    const Document &document)
{
    documents.push_back(document);
}

void SearchEngine::buildIndex()
{
    for (const Document &document : documents)
    {
        indexer.addDocument(document);
    }
}

void SearchEngine::search(const string &query)
{
    vector<string> queryWords =
        TextProcessor::process(query);

    if (queryWords.empty())
    {
        cout << "\nPlease enter a valid search query.\n";
        return;
    }

    vector<SearchResult> results =
        Ranker::rank(
            documents,
            queryWords,
            indexer);

    cout << "\n========== SEARCH RESULTS ==========\n";

    cout << "Query: " << query << endl;

    if (results.empty())
    {
        cout << "\nNo results found.\n";
        return;
    }

    int position = 1;

    for (const SearchResult &result : results)
    {
        cout << "\n"
             << position
             << ". "
             << result.document.getFileName()
             << endl;

        cout << "   Score: "
             << result.score
             << endl;

        cout << "   ID: "
             << result.document.getId()
             << endl;

        position++;
    }

    cout << "\n====================================\n";
}

void SearchEngine::showDocuments() const
{
    cout << "\n========== DOCUMENTS ==========\n";

    for (const Document &document : documents)
    {
        cout << "ID: "
             << document.getId()
             << " | File: "
             << document.getFileName()
             << endl;
    }

    cout << "===============================\n";
}

void SearchEngine::showIndex() const
{
    indexer.showIndex();
}