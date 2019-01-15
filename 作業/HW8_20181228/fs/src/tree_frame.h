#ifndef TREE_FRAME_H
#define TREE_FRAME_H

#include <wx/wx.h>
#include <wx/kbdstate.h>
#include <wx/treectrl.h>
#include <wx/event.h>

#include "node.h"
#include "node_builder.h"
#include "texts.h"

using namespace std;

class TreeFrame : public wxFrame{
public:
  TreeFrame(const wxChar * title, int xpos, int ypos, int width, int height):wxFrame((wxFrame *) nullptr, -1, title, wxPoint(xpos, ypos), wxSize(width, height)){}

  void Save(wxCommandEvent & event){
    wxMessageBox("You want save?", "Confirm", wxCANCEL | wxYES_NO | wxYES_DEFAULT | wxICON_QUESTION);
  }

  void setTree(wxTreeCtrl * tree){
    _tree = tree;
  }

  void OnEndEdit(wxTreeEvent & event){
    Texts * t = new Texts(wxT("Confirm"));
    t->editname(event);
  }

  void OnEdit(wxTreeEvent & event){
    _tree -> EditLabel(event.GetItem());
    cout << "edited" << endl;
  }

  void OnClick(wxTreeEvent & event){
    cout << event.GetLabel().ToStdString() << endl;
  }

  wxTreeCtrl * _tree;
private:
  DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(TreeFrame, wxFrame)
EVT_TREE_END_LABEL_EDIT (wxID_ANY, TreeFrame::OnEndEdit)
EVT_TREE_SEL_CHANGED (wxID_ANY, TreeFrame::OnClick)
EVT_TREE_ITEM_ACTIVATED(wxID_ANY, TreeFrame::OnEdit)
END_EVENT_TABLE()
#endif
