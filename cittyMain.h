/***************************************************************
 * Name:      cittyMain.h
 * Purpose:   Defines Application Frame
 * Author:    dawter ()
 * Created:   2017-01-24
 * Copyright: dawter (github.com/dawter)
 * License:
 **************************************************************/

#ifndef CITTYMAIN_H
#define CITTYMAIN_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "cittyApp.h"

class cittyFrame: public wxFrame
{
    public:
        cittyFrame(wxFrame *frame, const wxString& title);
        ~cittyFrame();
    private:
        enum
        {
            idMenuQuit = 1000,
            idMenuAbout
        };
        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        DECLARE_EVENT_TABLE()
};


#endif // CITTYMAIN_H
