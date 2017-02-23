#include <wx/wxprec.h>

#include <wx/app.h>
#include <wx/image.h>
#include <wx/imaglist.h>
#include <wx/dataobj.h>
#include <wx/dcclient.h>
#include <wx/statusbr.h>

#include "cittyFrame.h"

// -- application --
class cittyApp : public wxApp
{
public:
    bool OnInit();
};

DECLARE_APP(cittyApp);
#ifdef _DEBUG
wxIMPLEMENT_APP_CONSOLE(cittyApp);
#else
wxIMPLEMENT_APP(cittyApp);
#endif

bool cittyApp::OnInit()
{
    if ( !wxApp::OnInit() ) {
        return false;
    }
    
    wxFrame* frame = new cittyFrame(NULL,
                                    wxID_ANY,
                                    wxT("wxAUI Sample Application"),
                                    wxDefaultPosition,
                                    wxSize(800, 600));
    frame->Show();
    
    return true;
}
