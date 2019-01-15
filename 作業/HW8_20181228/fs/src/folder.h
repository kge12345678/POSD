#ifndef FOLDER_H
#define FOLDER_H

#include <vector>
#include <string>
#include "node.h"
#include "info_content_visitor.h"
#include "node_iterator.h"
#include <map>
#include <iostream>
using namespace std;

class Folder:public Node{
public:
  class FolderIterator : public NodeIterator{
  public:
    FolderIterator(Folder * f): _folder(f){}
    void first(){
      _it = _folder->_children.begin();
    }
    Node * currentItem(){
      if (isDone()){
        throw std::string("no current item");
      }
      return _it->second;
    }
    void next(){
      if (isDone()){
        throw std::string("moving past the end");
      }
      _it++;
    }
    bool isDone(){
      return _it == _folder->_children.end();
    }
  private:
    Folder * _folder;
    map<string, Node*>::iterator _it;
  };

  Folder(const char* path):Node(path){
    struct stat st;
    if (lstat(path, &st) == 0) {
      if (!S_ISDIR(st.st_mode))
        throw string("Not Folder!");
    }
  }

  void add(Node * node){
    // _children.insert(pair<string, Node *>(node->name(), node));
    node->setParent(this);
    _children[node->getPath()] = node;
  }

  int numberOfChildren() const{
    return _children.size();
  }

  void accept(NodeVisitor * nv){
    nv->visitFolder(this);
  }

  NodeIterator * createIterator(){
    return new FolderIterator(this);
  }

private:
  map<string, Node*> _children;
};
#endif
