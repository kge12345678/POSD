#ifndef NODE_BUILDER_H
#define NODE_BUILDER_H
#include <wx/treectrl.h>
#include <dirent.h>
#include "node.h"
#include "file.h"
#include "folder.h"
#include "link.h"
#include <string>
#include <sys/stat.h>
#include <dirent.h>

using namespace std;

class NodeBuilder {
public:
  NodeBuilder(wxTreeCtrl * tree, wxTreeItemId treeRoot, wxTreeItemId folder):_tree(tree), _treeroot(treeRoot), _folder(folder) {}

  void build(const char * path){
    struct stat st;
    if(lstat(path, &st) == 0){
      if(S_ISREG(st.st_mode)){
        _root = new File(path);
        if(_treeroot == nullptr){
          _treeroot = _tree -> AddRoot(wxString(_root -> getInfo()));
        } else{
          _tree -> AppendItem(_folder, wxString(_root -> getInfo()));
        }
      } else if (S_ISLNK(st.st_mode)){
        _root = new Link(path);
        if(_treeroot == nullptr){
          _treeroot = _tree -> AddRoot(wxString(_root -> getInfo()));
        } else{
          _tree -> AppendItem(_folder, wxString(_root -> getInfo()));
        }
      } else if(S_ISDIR(st.st_mode)){
        _root = new Folder(path);
        if(_treeroot == nullptr){
          _treeroot = _tree -> AddRoot(wxString(_root -> getInfo()));
          _folder = _treeroot;
        } else{
          _folder = _tree -> AppendItem(_folder, wxString(_root -> getInfo()));
        }
        DIR * dir = opendir(path);
        if (dir == nullptr){
          throw string("open folder error");
        }
        struct dirent * entry = nullptr;
        while((entry = readdir(dir)) != nullptr) {
          if (string(entry -> d_name) != "." && string(entry -> d_name) != "..") {
            NodeBuilder * nb = new NodeBuilder(_tree, _treeroot, _folder);
            string pathName = string(path) + "/" + entry -> d_name;
            nb -> build(pathName.c_str());
            _root -> add(nb -> getRoot());
          }
        }
      }
    }
  }

  Node * getRoot() {
    return _root;
  }

private:
  Node * _root;
  wxTreeCtrl * _tree;
  wxTreeItemId _treeroot;
  wxTreeItemId _folder;
};

#endif
