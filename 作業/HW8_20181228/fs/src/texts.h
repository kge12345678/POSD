#ifndef TEXTS_H
#define TEXTS_H
#include <wx/wx.h>

class Texts : public wxFrame
{
public:
  Texts(const wxString &);

  void editname(wxCommandEvent &);

};

const int ID_INFO = 1;
const int ID_ERROR = 2;
const int ID_QUESTION = 3;
const int ID_ALERT = 4;
#endif
