#ifndef NODE_H
#define NODE_H
#include <sys/stat.h>
#include <string>
class InfoContentVisitor;

class Node {
public:
  Node(const char * path): _path(path)
  {
    lstat(_path, &_st);
  }

  int size() const
  {
    return _st.st_size;
  }

  virtual void accept(InfoContentVisitor * icv) = 0;

  virtual void add(Node *node)
  {
    throw std::string("unable to add");
  }

  virtual int numberOfChildren() const
  {
    throw std::string("number of children: not applicable");
  }

private:
  const char * _path;
  struct stat _st;
};

#endif
