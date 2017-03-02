#include "cittyFrame.h"

#include <wx/aboutdlg.h>

//helper functions
enum wxbuildinfoformat {
    short_f,
    long_f
};

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}


wxBEGIN_EVENT_TABLE(cittyFrame, wxFrame)
EVT_CLOSE(cittyFrame::OnClose)
EVT_ERASE_BACKGROUND(cittyFrame::OnEraseBackground)
EVT_SIZE(cittyFrame::OnSize)
EVT_MENU(cittyFrame::ID_InsertNotebookPage, cittyFrame::OnInsertNotebookPage)
EVT_MENU(wxID_EXIT, cittyFrame::OnExit)
EVT_MENU(wxID_ABOUT, cittyFrame::OnAbout)
wxEND_EVENT_TABLE()


cittyFrame::cittyFrame(wxWindow* parent,
                       wxWindowID id,
                       const wxString& title,
                       const wxPoint& pos,
                       const wxSize& size,
                       long style)
: wxFrame(parent, id, title, pos, size, style)
{
    // tell wxAuiManager to manage this frame
    m_mgr.SetManagedWindow(this);

    // set frame icon
    SetIcon(wxIcon(sample_xpm));

    // set up default notebook style
    m_session_style = wxNO_BORDER |
                        wxAUI_NB_TOP |
                        wxAUI_NB_TAB_MOVE |
                        wxAUI_NB_CLOSE_BUTTON |
                        wxAUI_NB_SCROLL_BUTTONS |
                        wxAUI_NB_WINDOWLIST_BUTTON |
                        wxAUI_NB_MIDDLE_CLICK_CLOSE |
                        wxAUI_NB_CLOSE_ON_ACTIVE_TAB;
    m_notebook_theme = 0;

#ifdef wxUSE_MENUS
    wxMenu* file_menu = new wxMenu;
    file_menu->Append(ID_InsertNotebookPage, _("&New connection"), _("New a connection"));
    file_menu->Append(wxID_EXIT);

    wxMenu* help_menu = new wxMenu;
    help_menu->Append(wxID_ABOUT);

    wxMenuBar *menubar = new wxMenuBar();
    menubar->Append(file_menu, _("&File"));
    menubar->Append(help_menu, _("&Help"));
    SetMenuBar(menubar);
#endif // wxUSE_MENUS

#if wxUSE_STATUSBAR
    CreateStatusBar();
    GetStatusBar()->SetStatusText(wxbuildinfo(short_f));
#endif //wxUSE_STATUSBAR

    // create the notebook off-window to avoid flicker
    wxSize client_size = GetClientSize();

    m_notebook = new connectionNotebook(this, wxID_ANY,
                                        wxPoint(client_size.x, client_size.y),
                                        wxSize(430,200),
                                        m_session_style);
    //m_notebook->AddConnection();

    /*
     * min size for the frame itself isn't completely done.
     * see the end up wxAuiManager::Update() for the test
     * code. For now, just hard code a frame minimum size
     */
    SetMinSize(wxSize(500, 400));

    // make some default perspectives
    //wxString perspective_all = m_mgr.SavePerspective();
    //m_mgr.GetPane(wxT("notebook_content")).Show();

    this->Centre();

    // "commit" all changes made to wxAuiManager
    m_mgr.Update();
}

cittyFrame::~cittyFrame()
{
    m_mgr.UnInit();
}

wxAuiDockArt* cittyFrame::GetDockArt()
{
    return m_mgr.GetArtProvider();
}

void cittyFrame::DoUpdate()
{
    m_mgr.Update();
}

void cittyFrame::OnEraseBackground(wxEraseEvent& event)
{
    this->SetTitle(wxT("OnEraseBackground"));
    event.Skip();
}

void cittyFrame::OnSize(wxSizeEvent& event)
{
    this->SetTitle(wxT("OnSize"));
    event.Skip();
}

void cittyFrame::OnPaneClose(wxAuiManagerEvent& evt)
{
    this->SetTitle(wxT("OnPaneClose"));
    if (evt.pane->name == wxT("test10")) {
        int res = wxMessageBox(wxT("Are you sure you want to close/hide this pane?"),
                               wxT("wxAUI"),
                               wxYES_NO,
                               this);
        if (res != wxYES)
            evt.Veto();
    }
}


wxPoint cittyFrame::GetStartPosition()
{
    static int x = 0;
    x += 30;
    wxPoint pt = ClientToScreen(wxPoint(0,0));
    return wxPoint(pt.x + x, pt.y + x);
}


void cittyFrame::OnInsertNotebookPage(wxCommandEvent& WXUNUSED(event))
{
    this->SetTitle(wxT("OnInsertNotebookPage"));
    wxLogMessage("Enter OnInsertNotebookPage");
    size_t position = m_notebook->GetPageCount();
    m_notebook->InsertConnection(position);
}


void cittyFrame::OnExit(wxCommandEvent& WXUNUSED(event))
{
    Close(true);
}

void cittyFrame::OnClose(wxCloseEvent& event)
{
    Destroy();
}

void cittyFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
    this->SetTitle(wxT("OnAbout"));

    wxString msg = wxbuildinfo(long_f);
    // need library adv(wxAdvanced)
    wxAboutDialogInfo info;
    info.SetName(_("citty"));
    info.SetVersion(msg);
    info.SetCopyright(_("citty"));
    info.AddDeveloper(_("dawter"));
    info.AddDeveloper(_("Need more developers"));
    info.SetWebSite(_("https://github.com/dawter/citty"));
    info.SetLicence(_("wxWidgets v3"));
    info.SetDescription(_("A light ssh client"));
    ::wxAboutBox(info);

    //wxMessageBox(msg, wxT("About"), wxOK, this);
}

