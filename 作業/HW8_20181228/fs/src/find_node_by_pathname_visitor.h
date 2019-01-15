#ifndef FIND_NODE_BY_PATHNAME_H
#define FIND_NODE_BY_PATHNAME_H

#include <vector>
#include <string>
#include <iostream>
#include "node_visitor.h"

using namespace std;

class FindNodeByPathnameVisitor : public NodeVisitor{
public:
  FindNodeByPathnameVisitor(vector<string>* pathnames);
  void visitFile(File *);
  void visitFolder(Folder *);
  void visitLink(Link *);
  Node * getNode() const; // return the Node object if the path indicate the node in the file system, and if not, return nullptr.
private:
  vector<string>* _pathnames;
  vector<string>::iterator _it;
  Node * _node;
};

#endif
