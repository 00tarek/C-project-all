#ifndef RANKER_H
#define RANKER_H

#include <vector>
#include <string>

#include "Document.h"
#include "Indexer.h"

using namespace std;

struct SearchResult
{
    Document document;
    int score;
};

class Ranker
{
public:
    static vector<SearchResult> rank(
        const vector<Document> &documents,
        const vector<string> &queryWords,
        const Indexer &indexer);
};

#endif