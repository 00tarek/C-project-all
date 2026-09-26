#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>

#endif // DOCUMENT_H

#include <string>
using namespace std;

class Document
{
private:
    int id;
    string fileName;
    string content;

public:
    Document(int id, const string &fileName, const string &content);

    int getId() const;
    string getFileName() const;
    string getContent() const;
};