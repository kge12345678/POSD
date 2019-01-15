#ifndef NODE_H
#define NODE_H
#include <sys/stat.h>
#include <string>
#include "node_iterator.h"

class NodeVisitor;
class NodeIterator;

using namespace std;

class Node{
public:
  Node(const char * path): _path(path){
    if(lstat(_path, &_st) != 0){
      throw string("error");
    }
    // lstat(_path, &_st);
    _nodeName = (string(_path).substr(this->getPath().rfind('/')+1));
  }

  int size() const{
    return _st.st_size;
  }

  virtual void accept(NodeVisitor *) = 0;

  virtual void add(Node * node){
    throw string("unable to add");
  }

  virtual int numberOfChildren() const{
    // throw string("number of children: not applicable");
    return 0;
  }

  virtual NodeIterator* createIterator(){
    return nullptr;
  }

  string getPath(){
    return string(_path);
  }

  string name(){
    return _nodeName;
  }

  Node * getParent() const{
    return _p;
  }

  void setParent (Node * p){
    _p = p;
  }

  string getInfo(){
    return name() + ", " + to_string(size());
  }

  virtual ~ Node(){}

private:
  struct stat _st;
  const char * _path;
  string _nodeName;
  Node * _p;
};

#endif
