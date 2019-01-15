#include <wx/wx.h>
#include "tree_test.h"
#include "tree_frame.h"

IMPLEMENT_APP(TreeTestApp)

bool TreeTestApp::OnInit()
{
  wxFrame *frame = new TreeFrame(wxT("***Tree Test***"), 200,100,600,400);
  frame->Show(true);
  this->SetTopWindow(frame);
  return true;
}
