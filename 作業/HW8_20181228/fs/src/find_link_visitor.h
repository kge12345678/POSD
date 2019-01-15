#ifndef FIND_LINK_VISITOR_H
#define FIND_LINK_VISITOR_H
#include "node_visitor.h"
#include <string>
#include <vector>

using namespace std;

class FindLinkVisitor : public NodeVisitor{
public:
  FindLinkVisitor();
  void visitFolder(Folder *);
  void visitFile(File *);
  void visitLink(Link *);
  vector<Node*> getLinks();//return the Link objects.
private:
  vector<Node*> _links;
};
#endif
