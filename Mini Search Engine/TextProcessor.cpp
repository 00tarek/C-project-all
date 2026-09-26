#include "TextProcessor.h"

#include <sstream>
#include <cctype>
#include <algorithm>

string TextProcessor::toLowerCase(string text)
{
    for (char &ch : text)
    {
        ch = tolower(static_cast<unsigned char>(ch));
    }

    return text;
}

vector<string> TextProcessor::tokenize(string text)
{
    vector<string> words;

    string word;

    stringstream ss(text);

    while (ss >> word)
    {
        words.push_back(word);
    }

    return words;
}

bool TextProcessor::isStopWord(string word)
{
    static vector<string> stopWords =
        {
            "a",
            "an",
            "the",
            "is",
            "am",
            "are",
            "was",
            "were",
            "of",
            "to",
            "in",
            "on",
            "for",
            "and",
            "or",
            "but",
            "with",
            "this",
            "that",
            "it"};

    return find(
               stopWords.begin(),
               stopWords.end(),
               word) != stopWords.end();
}

vector<string> TextProcessor::process(string text)
{
    vector<string> result;

    text = toLowerCase(text);

    for (char &ch : text)
    {
        if (!isalnum(static_cast<unsigned char>(ch)))
        {
            ch = ' ';
        }
    }

    vector<string> words = tokenize(text);

    for (string word : words)
    {
        if (!isStopWord(word))
        {
            result.push_back(word);
        }
    }

    return result;
}