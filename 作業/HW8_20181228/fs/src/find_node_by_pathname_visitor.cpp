#include "find_node_by_pathname_visitor.h"
#include "node_iterator.h"
#include "node_iterator.h"
#include "file.h"
#include "folder.h"
#include "link.h"
#include <iostream>
using namespace std;

FindNodeByPathnameVisitor::FindNodeByPathnameVisitor(vector<string>* pathnames):_pathnames(pathnames), _node(nullptr){
  _it = _pathnames->begin();
}

void FindNodeByPathnameVisitor::visitFile(File * file){
  if(_it != _pathnames->end()){
    if(file -> name().compare(*_it)==0){
      _node = file;
    }
  }
}

void FindNodeByPathnameVisitor::visitFolder(Folder * folder){
  if(_it != _pathnames->end()){
    if(folder->name().compare(*_it)==0){    //folder name = path name
      if(_it+1 != _pathnames->end()){       //path還有下一個的話
        _it++;
        NodeIterator * it = folder -> createIterator();
        for (it->first(); !it->isDone(); it->next()){
          it->currentItem()->accept(this);
        }
      } else{
        _node = folder;
      }
    }
  }
}

void FindNodeByPathnameVisitor::visitLink(Link * link){
  if(_it != _pathnames->end()){
    if(link -> name().compare(*_it)==0){
      _node = link;
    }
  }
}

Node * FindNodeByPathnameVisitor::getNode() const{
  return _node;
}
