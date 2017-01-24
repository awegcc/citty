/***************************************************************
 * Name:      cittyApp.cpp
 * Purpose:   Code for Application Class
 * Author:    dawter ()
 * Created:   2017-01-24
 * Copyright: dawter (github.com/dawter)
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "cittyApp.h"
#include "cittyMain.h"

IMPLEMENT_APP(cittyApp);

bool cittyApp::OnInit()
{
    cittyFrame* frame = new cittyFrame(0L, _("wxWidgets Application Template"));
    frame->SetIcon(wxICON(aaaa)); // To Set App Icon
    frame->Show();
    
    return true;
}
