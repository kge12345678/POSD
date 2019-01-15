#include "texts.h"

Texts::Texts(const wxString& title): wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(200, 100)){}

void Texts::editname(wxCommandEvent& event){
  wxMessageDialog * dial = new wxMessageDialog(NULL, wxT("Are you sure to edit Name ?"), wxT("Confirm"),wxYES_NO | wxCANCEL | wxICON_QUESTION | wxSTAY_ON_TOP, wxDefaultPosition);
  dial->ShowModal();
}
