#include "connectionNotebook.h"

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

BEGIN_EVENT_TABLE(connectionNotebook, wxAuiNotebook)
	EVT_AUINOTEBOOK_PAGE_CLOSE(wxID_ANY, connectionNotebook::OnNotebookPageClose)
	EVT_AUINOTEBOOK_ALLOW_DND(wxID_ANY, connectionNotebook::OnAllowNotebookDnD)
	EVT_AUINOTEBOOK_PAGE_CLOSED(wxID_ANY, connectionNotebook::OnNotebookPageClosed)
	EVT_AUINOTEBOOK_TAB_RIGHT_DOWN(wxID_ANY, connectionNotebook::OnTabRightDown)
	EVT_MENU(ID_MENU_NEW_CONNECTION, connectionNotebook::OnNewConnection)
	EVT_MENU(ID_MENU_FIRST_CONNECTION, connectionNotebook::OnFirstConnection)
	EVT_MENU(ID_MENU_LAST_CONNECTION, connectionNotebook::OnLastConnection)
	EVT_MENU(ID_MENU_ABOUT_CONNECTION, connectionNotebook::OnAbout)
	
	/* EVT_AUINOTEBOOK_BUTTON
	 * Triggered by Close button click On Windows 7 x64
	 */
	//EVT_AUINOTEBOOK_BUTTON(wxID_ANY, cittyAuiNotebook::OnButton)
END_EVENT_TABLE()

connectionNotebook::connectionNotebook(wxWindow* parent,
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
						wxAUI_NB_SCROLL_BUTTONS |
						wxAUI_NB_WINDOWLIST_BUTTON |
						wxAUI_NB_MIDDLE_CLICK_CLOSE |
						wxAUI_NB_CLOSE_ON_ACTIVE_TAB;
	// create the notebook off-window to avoid flicker
	wxSize client_size = GetClientSize();
	
	m_notebook = new sessionNotebook(this, wxID_ANY,
			wxPoint(client_size.x, client_size.y),
			wxSize(430,200),
			m_notebook_style);
}


void connectionNotebook::OnNotebookPageClose(wxAuiNotebookEvent& evt)
{
	connectionNotebook* ctrl = (connectionNotebook*)evt.GetEventObject();
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

void connectionNotebook::OnNotebookPageClosed(wxAuiNotebookEvent& evt)
{
	connectionNotebook* ctrl = (connectionNotebook*)evt.GetEventObject();

	// selection should always be a valid index
	wxASSERT_MSG( ctrl->GetSelection() < (int)ctrl->GetPageCount(),
			wxString::Format("Invalid selection %d, only %d pages left",
				ctrl->GetSelection(),
				(int)ctrl->GetPageCount()) );

	evt.Skip();
}

void connectionNotebook::OnAllowNotebookDnD(wxAuiNotebookEvent& evt)
{
	// for the purpose of this test application, explicitly
	// allow all noteboko drag and drop events
	evt.Allow();
}


void connectionNotebook::OnTabClicked(wxAuiNotebookEvent& evt)
{
	wxMessageBox(wxT("OnTabClicked"), _("OnTabClicked"), wxOK, this);
}

void connectionNotebook::OnTabDragMotion(wxAuiNotebookEvent& evt)
{
	wxMessageBox(wxT("OnTabDragMotion"), _("OnTabDragMotion"), wxOK, this);
}

void connectionNotebook::OnTabEndDrag(wxAuiNotebookEvent& evt)
{
	wxMessageBox(wxT("OnTabEndDrag"), _("OnTabEndDrag"), wxOK, this);
}

void connectionNotebook::OnTabCancelDrag(wxAuiNotebookEvent& evt)
{
	wxMessageBox(wxT("OnTabCancelDrag"), _("OnTabCancelDrag"), wxOK, this);
}

void connectionNotebook::OnTabButton(wxAuiNotebookEvent& evt)
{
	wxMessageBox(wxT("OnTabButton"), _("OnTabButton"), wxOK, this);
	evt.Allow();
}

void connectionNotebook::OnButton(wxAuiNotebookEvent& evt)
{
	wxMessageBox(wxT("OnButton"), _("OnButton"), wxOK, this);
}

void connectionNotebook::OnTabMiddleDown(wxAuiNotebookEvent& evt)
{
	wxMessageBox(wxT("OnTabMiddleDown"), _("OnTabMiddleDown"), wxOK, this);
}

void connectionNotebook::OnTabMiddleUp(wxAuiNotebookEvent& evt)
{
	wxMessageBox(wxT("OnTabMiddleUp"), _("OnTabMiddleUp"), wxOK, this);
}

void connectionNotebook::OnTabRightDown(wxAuiNotebookEvent& evt)
{
	//m_notebook->ShowWindowMenu();
	wxMenu menu;
	menu.Append(ID_MENU_NEW_CONNECTION, wxT("&New Connection"), wxT("New a Connection behind me") );
	menu.Append(ID_MENU_FIRST_CONNECTION, wxT("&First Connection"), wxT("Switch to the First Connection") );
	menu.Append(ID_MENU_LAST_CONNECTION, wxT("&Last Connection"), wxT("Switch to the Last Connection") );
	menu.AppendSeparator();
	menu.Append(ID_MENU_ABOUT_CONNECTION, wxT("&About Connection"), wxT("About this Connection"), true);
	PopupMenu(&menu);
}

void connectionNotebook::OnTabRightUp(wxAuiNotebookEvent& evt)
{
	wxMessageBox(wxT("OnTabRightUp"), _("OnTabRightUp"), wxOK, this);
}

void connectionNotebook::OnTabBgDClick(wxAuiNotebookEvent& evt)
{
	wxMessageBox(wxT("OnTabRightUp"), _("OnTabRightUp"), wxOK, this);
}

bool connectionNotebook::InsertConnection(size_t position)
{
	bool retval = false;
	wxString title;
	// create the notebook off-window to avoid flicker
	wxSize client_size = GetClientSize();

	title.Printf(wxT("Connection %lu"), position);
	sessionNotebook *session = new sessionNotebook(this, wxID_ANY,
			wxPoint(client_size.x, client_size.y),
			wxSize(430,200),
			m_notebook_style);
	this->Freeze();
	retval = this->InsertPage(position, session, title, true);
	this->SetPageToolTip(position, title);
	this->Thaw();
	
	return retval;
}

bool connectionNotebook::AddConnection()
{
	return InsertConnection(this->GetPageCount());
}

void connectionNotebook::OnNewConnection(wxCommandEvent& event)
{
	size_t position = this->GetSelection();
	InsertConnection(position + 1);
}

void connectionNotebook::OnAbout(wxCommandEvent& WXUNUSED(event))
{
	wxString content = wxT("Host      : XXXXX\nPort      : XXXXX");
	wxMessageBox(content, _("Connection"), wxOK, this);
}

void connectionNotebook::CreateConnection(const wxString& title)
{
}

void connectionNotebook::OnFirstConnection(wxCommandEvent& event)
{
	//  switch to the first page
	this->SetSelection(0);
}

void connectionNotebook::OnLastConnection(wxCommandEvent& event)
{
	size_t position = this->GetPageCount();
	if ( position > 0 ) {
		// switch to the last page
		this->SetSelection(position - 1);
	}
}

