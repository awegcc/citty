#include "cittyTerm.h"

cittyTerm::cittyTerm():wxTextCtrl(nullptr, wxID_ANY)
{

}

cittyTerm::cittyTerm(wxWindow *parent, wxWindowID id,
               const wxString& value,
               const wxPoint& pos,
               const wxSize& size,
               long style,
               const wxValidator& validator,
               const wxString& name)
    :wxTextCtrl(parent, id, value, pos, size, style, validator, name)
{
    //ctor
}

cittyTerm::~cittyTerm()
{
    //dtor
}
