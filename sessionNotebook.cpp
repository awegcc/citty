#include "sessionNotebook.h"

/*
   void OnTabClicked(wxAuiNotebookEvent& evt);
   void OnTabBeginDrag(wxAuiNotebookEvent& evt);
   void OnTabDragMotion(wxAuiNotebookEvent& evt);
   void OnTabEndDrag(wxAuiNotebookEvent& evt);
   void OnTabCancelDrag(wxAuiNotebookEvent& evt);
   void OnTabButton(wxAuiNotebookEvent& evt);
   void OnTabMiddleDown(wxAuiNotebookEvent& evt);
   void OnTabMiddleUp(wxAuiNotebookEvent& evt);
   void OnTabRightDown(wxAuiNotebookEvent& evt);
   void OnTabRightUp(wxAuiNotebookEvent& evt);
   void OnTabBgDClick(wxAuiNotebookEvent& evt);
   */

BEGIN_EVENT_TABLE(sessionNotebook, wxAuiNotebook)
	EVT_AUINOTEBOOK_PAGE_CLOSE(wxID_ANY, sessionNotebook::OnNotebookPageClose)
	EVT_AUINOTEBOOK_ALLOW_DND(wxID_ANY, sessionNotebook::OnAllowNotebookDnD)
	EVT_AUINOTEBOOK_PAGE_CLOSED(wxID_ANY, sessionNotebook::OnNotebookPageClosed)
	EVT_AUINOTEBOOK_TAB_RIGHT_DOWN(wxID_ANY, sessionNotebook::OnTabRightDown)
	EVT_MENU(ID_MENU_NEW_SESSION, sessionNotebook::OnNewSession)
	EVT_MENU(ID_MENU_ABOUT, sessionNotebook::OnAbout)
	
	/* EVT_AUINOTEBOOK_BUTTON
	 * Triggered by Close button click On Windows 7 x64
	 */
	//EVT_AUINOTEBOOK_BUTTON(wxID_ANY, cittyAuiNotebook::OnButton)
END_EVENT_TABLE()

sessionNotebook::sessionNotebook()
{
}


sessionNotebook::~sessionNotebook()
{
}

sessionNotebook::sessionNotebook(wxWindow* parent,
		wxWindowID id = wxID_ANY,
		const wxPoint& pos = wxDefaultPosition,
		const wxSize& size = wxDefaultSize,
		long style = wxAUI_NB_DEFAULT_STYLE)
: wxAuiNotebook(parent, id, pos, size, style)
{

	m_notebook_theme = 0;
	// set up sub notebook style
	m_notebook_style = wxNO_BORDER |
						wxAUI_NB_BOTTOM |
						wxAUI_NB_TAB_MOVE |
						wxAUI_NB_CLOSE_BUTTON |
						wxAUI_NB_WINDOWLIST_BUTTON |
						wxAUI_NB_MIDDLE_CLICK_CLOSE |
						wxAUI_NB_CLOSE_ON_ACTIVE_TAB;
	// create the notebook off-window to avoid flicker
	wxSize client_size = GetClientSize();
	
	m_notebook = new dialogNotebook(this, wxID_ANY,
			wxPoint(client_size.x, client_size.y),
			wxSize(430,200),
			m_notebook_style);
}


void sessionNotebook::OnNotebookPageClose(wxAuiNotebookEvent& evt)
{
	sessionNotebook* ctrl = (sessionNotebook*)evt.GetEventObject();
	if (ctrl->GetPage(evt.GetSelection())->IsKindOf(CLASSINFO(wxHtmlWindow)))
	{
		int res = wxMessageBox(wxT("Sure to close/hide this notebook page?"), wxT("wxAUI"), wxYES_NO, this);
		if (res != wxYES) {
			evt.Veto();
		}
	}
	else if(ctrl->GetPageCount() == (size_t)evt.GetSelection() + 1)
	{
		wxMessageBox(wxT("Can not close the last page!"), wxT("wxAUI"), wxOK, this);
		evt.Veto();
	}
}

void sessionNotebook::OnNotebookPageClosed(wxAuiNotebookEvent& evt)
{
	sessionNotebook* ctrl = (sessionNotebook*)evt.GetEventObject();

	// selection should always be a valid index
	wxASSERT_MSG( ctrl->GetSelection() < (int)ctrl->GetPageCount(),
			wxString::Format("Invalid selection %d, only %d pages left",
				ctrl->GetSelection(),
				(int)ctrl->GetPageCount()) );

	evt.Skip();
}

void sessionNotebook::OnAllowNotebookDnD(wxAuiNotebookEvent& evt)
{
	// for the purpose of this test application, explicitly
	// allow all noteboko drag and drop events
	evt.Allow();
}


void sessionNotebook::OnTabClicked(wxAuiNotebookEvent& evt)
{
	wxMessageBox(wxT("OnTabClicked"), _("OnTabClicked"), wxOK, this);
}

void sessionNotebook::OnTabDragMotion(wxAuiNotebookEvent& evt)
{
	wxMessageBox(wxT("OnTabDragMotion"), _("OnTabDragMotion"), wxOK, this);
}

void sessionNotebook::OnTabEndDrag(wxAuiNotebookEvent& evt)
{
	wxMessageBox(wxT("OnTabEndDrag"), _("OnTabEndDrag"), wxOK, this);
}

void sessionNotebook::OnTabCancelDrag(wxAuiNotebookEvent& evt)
{
	wxMessageBox(wxT("OnTabCancelDrag"), _("OnTabCancelDrag"), wxOK, this);
}

void sessionNotebook::OnTabButton(wxAuiNotebookEvent& evt)
{
	wxMessageBox(wxT("OnTabButton"), _("OnTabButton"), wxOK, this);
	evt.Allow();
}

void sessionNotebook::OnButton(wxAuiNotebookEvent& evt)
{
	wxMessageBox(wxT("OnButton"), _("OnButton"), wxOK, this);
}

void sessionNotebook::OnTabMiddleDown(wxAuiNotebookEvent& evt)
{
	wxMessageBox(wxT("OnTabMiddleDown"), _("OnTabMiddleDown"), wxOK, this);
}

void sessionNotebook::OnTabMiddleUp(wxAuiNotebookEvent& evt)
{
	wxMessageBox(wxT("OnTabMiddleUp"), _("OnTabMiddleUp"), wxOK, this);
}

void sessionNotebook::OnTabRightDown(wxAuiNotebookEvent& evt)
{
	//m_notebook->ShowWindowMenu();
	//wxMessageBox(wxT("OnTabRightDown"), _("OnTabRightDown"), wxOK, this);
	wxMenu menu;
	menu.Append(ID_MENU_ABOUT, wxT("&About"), wxT("About this session"));
	menu.Append(wxID_ANY, wxT("&Second"), wxT("Second item"));
	menu.Append(wxID_ANY, wxT("&Third"), wxT("Third item"));
	menu.AppendSeparator();
	menu.Append(ID_MENU_NEW_SESSION, wxT("&New"), wxT("New a session behand me."));
	PopupMenu(&menu);
}

void sessionNotebook::OnTabRightUp(wxAuiNotebookEvent& evt)
{
	//wxMessageBox(wxT("OnTabRightUp"), _("OnTabRightUp"), wxOK, this);
}

void sessionNotebook::OnTabBgDClick(wxAuiNotebookEvent& evt)
{
	wxMessageBox(wxT("OnTabRightUp"), _("OnTabRightUp"), wxOK, this);
}

bool sessionNotebook::InsertSession(size_t position)
{
	bool retval = false;
	wxString title;
	// create the notebook off-window to avoid flicker
	wxSize client_size = GetClientSize();

	title.Printf(wxT("the page %lu"), position);
	dialogNotebook *dialog = new dialogNotebook(this, wxID_ANY,
			wxPoint(client_size.x, client_size.y),
			wxSize(430,200),
			m_notebook_style);
	this->Freeze();
	retval = this->InsertPage(position, dialog, title, true);
	this->SetPageToolTip(position, title);
	this->Thaw();
	
	return retval;
}

bool sessionNotebook::AddSession()
{
	return InsertSession(this->GetPageCount());
}

void sessionNotebook::OnNewSession(wxCommandEvent& event)
{
	size_t position = this->GetSelection();
	InsertSession(position);
}

void sessionNotebook::OnAbout(wxCommandEvent& WXUNUSED(event))
{
	wxString content = wxT("Session: XXXXX\n"
							"Host  : XXXXX\n"
							"Port  : XXXXX");
	wxMessageBox(content, _("Session"), wxOK, this);
}

