#include "find_visitor.h"
#include "node_iterator.h"
#include "node.h"
#include "file.h"
#include "folder.h"
#include "link.h"
#include <iostream>
#include <algorithm>

FindVisitor::FindVisitor(string target):_rootPath(""), _target(target){
  _nodes.clear();
}

void FindVisitor::visitFile(File * file){
  if(_rootPath.length() == 0){
    _rootPath = file->getPath();
  }
  _nodes[file->getPath()] = file;
}

void FindVisitor::visitFolder(Folder * folder){
  if(_rootPath.length() == 0){
    _rootPath = folder->getPath();
  } else{
    _nodes[folder->getPath()] = folder;
  }
  NodeIterator * it = folder -> createIterator();
  for (it->first(); !it->isDone(); it->next()){
    it->currentItem()->accept(this);
  }
}

void FindVisitor::visitLink(Link * link){
  
}

string FindVisitor::findResult(){
  vector<string> result;
  result.clear();
  map<string, Node*>::iterator _its;
  for(_its = _nodes.begin(); _its != _nodes.end(); _its++){
    if(_target.compare((_its)->second->name()) == 0){
      int lengthOfRootPath = _rootPath.length();
      int lengthOfStrPath = (_its)->second->getPath().length();
      if(lengthOfRootPath != lengthOfStrPath){
        result.push_back("." + (_its)->second->getPath().substr(lengthOfRootPath, lengthOfStrPath-lengthOfRootPath));
      } else
        result.push_back(_target);
    }
  }
  sort(result.begin(), result.end(), [](string a, string b){
    int _a = 0, _b = 0;
    for(int i=0; i<a.length();i++){
      if(a[i]=='/'){
        _a++;
      }
    }
    for(int i=0; i<b.length();i++){
      if(b[i]=='/'){
        _b++;
      }
    }
    return _a < _b;
  });

  string finalResult("");
  for(int i=0; i<result.size(); i++){
    if(i>0)
      finalResult += "\n";
    finalResult += result[i];
  }
  _rootPath="";
  _nodes.clear();
  return finalResult;
}
