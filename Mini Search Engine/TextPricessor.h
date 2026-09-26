#ifndef TEXTPROCESSOR_H
#define TEXTPROCESSOR_H

#include <string>
#include <vector>

using namespace std;

class TextProcessor
{
public:
    static string toLowerCase(string text);

    static vector<string> tokenize(string text);

    static bool isStopWord(string word);

    static vector<string> process(string text);
};

#endif