#include "Document.h"

Document::Document(int id, const string &fileName, const string &content)
{
    this->id = id;
    this->fileName = fileName;
    this->content = content;
}

int Document::getId() const
{
    return id;
}

string Document::getFileName() const
{
    return fileName;
}

string Document::getContent() const
{
    return content;
}