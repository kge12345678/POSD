#include <vector>
#include "node.h"
#include "info_content_visitor.h"

class Folder:public Node{
public:
  friend class InfoContentVisitor;

  Folder(const char* path):Node(path)
  {

  }

  void add(Node *node)
  {
    _children.push_back(node);
  }

  int numberOfChildren() const
  {
    return _children.size();
  }

  void accept(InfoContentVisitor * icv)
  {
    icv->visitFolder(this);
  }

private:
  std::vector<Node *> _children;
};
