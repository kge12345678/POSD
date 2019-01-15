#include <wx/wx.h>
#include <iostream>

#include "windows.h"
#include "tree_frame.h"
#include "node_builder.h"
#include "node_iterator.h"

IMPLEMENT_APP(Windows);

Windows::Windows(){}

bool Windows::OnInit(){
	TreeFrame * treeFrame = new TreeFrame(wxT("Windows"), 0, 0, 500, 400);
	_tree = new wxTreeCtrl(treeFrame, wxID_ANY, wxPoint(0,0), wxSize(200,400), wxTR_DEFAULT_STYLE | wxTR_SINGLE | wxTR_EDIT_LABELS);
	_button = new wxButton(treeFrame, wxID_ANY, wxT("Save"), wxPoint(200, 300), wxSize(300, 100), 0, wxDefaultValidator);
	_text = new wxTextCtrl(treeFrame, wxID_ANY, _T("Welcome To POSD_EDITOR"), wxPoint(200,0), wxSize(300,300), wxTE_MULTILINE);
	treeFrame -> Show(true);
	treeFrame -> setTree(_tree);
	string folderName = argv[1].ToStdString();
	NodeBuilder * nb = new NodeBuilder(_tree, nullptr, nullptr);
	nb -> build(folderName.c_str());
	_tree -> ExpandAllChildren(_tree -> GetRootItem());
	return true;
}
