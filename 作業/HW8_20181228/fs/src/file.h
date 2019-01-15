#ifndef FILE_H
#define FILE_H

#include "node.h"
#include "node_visitor.h"
#include "node_iterator.h"
#include "info_content_visitor.h"

class File: public Node{
public:
  class NullIterator:public NodeIterator{
  public:
    NullIterator(){}
    Node * currentItem(){
      return nullptr;
    };
  };

  File(const char * path): Node(path){
    struct stat st;
    if (lstat(path, &st) == 0) {
      if (!S_ISREG(st.st_mode))
        throw string("Not File!");
    }
  }

  void accept(NodeVisitor * nv){
    nv->visitFile(this);
  }

  NodeIterator * createIterator(){
    return new NullIterator();
  }

};

#endif
