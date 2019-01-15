#ifndef LINK_H
#define LINK_H
#include "node.h"

class Link : public Node{
public:
  Link(const char * path, Node * node = nullptr) : Node(path){
    struct stat st;
    if (lstat(path, &st) == 0) {
      if (!S_ISLNK(st.st_mode))
        throw string("Not Link!");
    }
    this->addLink(node);
  }

  void accept(NodeVisitor * nv){
    // _source->accept(nv);
    nv->visitLink(this);
  }

  void addLink(Node * node){
    _source = node;
  }

  Node * getSource() {
    return _source;
  }

private:
  Node * _source;
};

#endif
