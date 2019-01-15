#ifndef NODE_ITERATOR
#define NODE_ITERATOR

class Node;

class NodeIterator{
public:
  virtual void first(){};
  virtual Node * currentItem(){};
  virtual void next(){};
  virtual bool isDone(){
    return true;
  };
  virtual ~NodeIterator(){}
};

#endif
