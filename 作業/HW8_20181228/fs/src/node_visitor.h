#ifndef NODE_VISITOR_H
#define NODE_VISITOR_H

#include "node_iterator.h"
#include <string>
#include <vector>

using namespace std;

class File;
class Folder;
class Link;

class NodeVisitor{
public:
  NodeVisitor(){}
  virtual void visitFile(File *) = 0;
  virtual void visitFolder(Folder *) = 0;
  virtual void visitLink(Link *) = 0;
  virtual vector<Node*> getLinks(){}
  virtual string findResult(){}
  virtual NodeIterator * createIterator(){}
};
#endif
