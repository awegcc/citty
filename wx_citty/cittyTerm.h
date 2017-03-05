#ifndef CITTYTERM_H
#define CITTYTERM_H

#include <wx/textctrl.h>

class cittyTerm : public wxTextCtrl
{
    public:
        cittyTerm();
        cittyTerm(wxWindow *parent, wxWindowID id,
               const wxString& value = wxEmptyString,
               const wxPoint& pos = wxDefaultPosition,
               const wxSize& size = wxDefaultSize,
               long style = 0,
               const wxValidator& validator = wxDefaultValidator,
               const wxString& name = wxTextCtrlNameStr);
        virtual ~cittyTerm();

    protected:

    private:
};

#endif // CITTYTERM_H
