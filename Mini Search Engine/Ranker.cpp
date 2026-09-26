#include "Ranker.h"
#include "TextProcessor.h"

#include <algorithm>

vector<SearchResult> Ranker::rank(
    const vector<Document> &documents,
    const vector<string> &queryWords,
    const Indexer &indexer)
{
    vector<SearchResult> results;

    for (const Document &document : documents)
    {
        int score = 0;

        for (const string &word : queryWords)
        {
            score += indexer.getFrequency(
                word,
                document.getId());
        }

        if (score > 0)
        {
            results.push_back(
                {document,
                 score});
        }
    }

    sort(
        results.begin(),
        results.end(),
        [](const SearchResult &a,
           const SearchResult &b)
        {
            return a.score > b.score;
        });

    return results;
}