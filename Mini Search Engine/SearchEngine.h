#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H

#include <vector>
#include <string>

#include "Document.h"
#include "Indexer.h"
#include "Ranker.h"

using namespace std;

class SearchEngine
{
private:
    vector<Document> documents;

    Indexer indexer;

public:
    void addDocument(const Document &document);

    void buildIndex();

    void search(const string &query);

    void showDocuments() const;

    void showIndex() const;
};

#endif