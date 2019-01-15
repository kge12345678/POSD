#include "find_link_visitor.h"
#include "node_iterator.h"
#include "file.h"
#include "folder.h"
#include "link.h"

FindLinkVisitor::FindLinkVisitor(){
  _links.clear();
}

void FindLinkVisitor::visitFile(File * file){}

void FindLinkVisitor::visitFolder(Folder * folder){
  NodeIterator * it = folder -> createIterator();
  for (it->first(); !it->isDone(); it->next()){
    it->currentItem()->accept(this);
  }
}

void FindLinkVisitor::visitLink(Link * link) {
  _links.push_back(link);
}

vector<Node*> FindLinkVisitor::getLinks(){
  vector<Node*> temp = _links;
  _links.clear();
  return temp;
}
