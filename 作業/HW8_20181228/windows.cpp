#include <wx/wx.h>
#include <iostream>

#include "windows.h"
#include "tree_frame.h"
#include "node_builder.h"
#include "node_iterator.h"

IMPLEMENT_APP(Windows);

Windows::Windows(){}
// This is executed upon startup, like 'main()' in non-wxWidgets programs.
bool Windows::OnInit()
{
	if(argc < 2){
		cout << "You didn't assgin a folder." << endl;
	} else{
		TreeFrame *containerFrame = new TreeFrame(wxT("Windows"), 200, 300, 700, 400);
		containerFrame->Show(true);
		_tree = new wxTreeCtrl(containerFrame, wxID_ANY, wxPoint(0,0), wxSize(200,400), wxTR_DEFAULT_STYLE | wxTR_SINGLE | wxTR_EDIT_LABELS);
		containerFrame->setTree(_tree);
		_text = new wxTextCtrl(containerFrame, -1, _T("Welcome To POSD_EDITOR"), wxPoint(200,0), wxSize(500,300), wxTE_MULTILINE);
		_saveButton = new wxButton(containerFrame, wxID_ANY, wxT("Save"), wxPoint(200, 300), wxSize(500, 100), 0, wxDefaultValidator);
		this->SetTopWindow(containerFrame);
		string fileName = argv[1].ToStdString();
		NodeBuilder *nb = new NodeBuilder(_tree, nullptr, nullptr);
		nb->build(fileName.c_str());
		_tree->ExpandAllChildren(_tree->GetRootItem());
	}
	return true;
}

void Windows::setTreeCtrl(NodeBuilder *nb){

}
