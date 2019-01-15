#ifndef WINDOWS_H
#define WINDOWS_H

#include <wx/treectrl.h>
#include <wx/button.h>

#include "node.h"
#include "node_builder.h"

class Windows : public wxApp{
public:
	Windows();
	virtual bool OnInit();
  wxTreeCtrl * _tree;
	wxTextCtrl * _text;
	wxButton * _button;
};

DECLARE_APP(Windows)

#endif
