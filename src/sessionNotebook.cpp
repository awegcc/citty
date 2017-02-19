#include "sessionNotebook.h"

/*
 * Event table
 */
BEGIN_EVENT_TABLE(sessionNotebook, wxAuiNotebook)
	EVT_AUINOTEBOOK_PAGE_CLOSE(wxID_ANY, sessionNotebook::OnNotebookPageClose)
	EVT_AUINOTEBOOK_ALLOW_DND(wxID_ANY, sessionNotebook::OnAllowNotebookDnD)
	EVT_AUINOTEBOOK_PAGE_CLOSED(wxID_ANY, sessionNotebook::OnNotebookPageClosed)
	EVT_AUINOTEBOOK_TAB_RIGHT_DOWN(wxID_ANY, sessionNotebook::OnTabRightDown)
	EVT_MENU(ID_MENU_NEW_SESSION, sessionNotebook::OnNewSession)
	EVT_MENU(ID_MENU_FIRST_SESSION, sessionNotebook::OnFirstSession)
	EVT_MENU(ID_MENU_LAST_SESSION, sessionNotebook::OnLastSession)
	EVT_MENU(ID_MENU_ABOUT_SESSION, sessionNotebook::OnAbout)
END_EVENT_TABLE()

sessionNotebook::sessionNotebook(wxWindow* parent,
		wxWindowID id = wxID_ANY,
		const wxPoint& pos = wxDefaultPosition,
		const wxSize& size = wxDefaultSize,
		long style = wxAUI_NB_DEFAULT_STYLE)
: wxAuiNotebook(parent, id, pos, size, style)
{
	this->AddPage(CreateHTMLCtrl(this), wxT("Welcome to wxAUI") , true, wxNullBitmap);
	this->SetPageToolTip(this->GetPageCount()-1, "HTML (PageTooltip)");
}

void sessionNotebook::CreateDialog(const wxString& title)
{
}

wxTextCtrl* sessionNotebook::CreateTextCtrl(const wxString& ctrl_text)
{
	static int n = 0;

	wxString text;
	if ( !ctrl_text.empty() ) {
		text = ctrl_text;
	}
	else {
		text.Printf(wxT("This is text box %d"), ++n);
	}

	return new wxTextCtrl(this, wxID_ANY, text,
			wxPoint(0,0), wxSize(150,90),
			wxNO_BORDER | wxTE_MULTILINE);
}

wxHtmlWindow* sessionNotebook::CreateHTMLCtrl(wxWindow* parent)
{
	if (!parent) {
		parent = this;
	}

	wxHtmlWindow* ctrl = new wxHtmlWindow(parent, wxID_ANY, wxDefaultPosition, wxSize(400,300));
	ctrl->SetPage(GetHtmlText());
	return ctrl;
}

wxString sessionNotebook::GetHtmlText()
{
	const char* text =
		"<html>"
		"<body>"
		"<h3>Welcome to wxAUI</h3>"
		"<br/><b>Overview</b><br/>"
		"<p>wxAUI is an Advanced User Interface library for the wxWidgets toolkit "
		"that allows developers to create high-quality, cross-platform user "
		"interfaces quickly and easily.</p>"
		"<p><b>Features</b></p>"
		"<p>With wxAUI, developers can create application frameworks with:</p>"
		"<ul>"
		"<li>Native, dockable floating frames</li>"
		"<li>Perspective saving and loading</li>"
		"<li>Native toolbars incorporating real-time, &quot;spring-loaded&quot; dragging</li>"
		"<li>Customizable floating/docking behaviour</li>"
		"<li>Completely customizable look-and-feel</li>"
		"<li>Optional transparent window effects (while dragging or docking)</li>"
		"<li>Splittable notebook control</li>"
		"</ul>"
		"<p><b>What's new in 0.9.4?</b></p>"
		"<p>wxAUI 0.9.4, which is bundled with wxWidgets, adds the following features:"
		"<ul>"
		"<li>New wxAuiToolBar class, a toolbar control which integrates more "
		"cleanly with wxAuiFrameManager.</li>"
		"<li>Lots of bug fixes</li>"
		"</ul>"
		"<p>See README.txt for more information.</p>"
		"</body>"
		"</html>";

	return wxString::FromAscii(text);
}

void sessionNotebook::OnTabClicked(wxAuiNotebookEvent& evt)
{
}

void sessionNotebook::OnTabDragMotion(wxAuiNotebookEvent& evt)
{
}

void sessionNotebook::OnTabEndDrag(wxAuiNotebookEvent& evt)
{
}

void sessionNotebook::OnTabCancelDrag(wxAuiNotebookEvent& evt)
{
}

void sessionNotebook::OnTabButton(wxAuiNotebookEvent& evt)
{
}

void sessionNotebook::OnTabMiddleDown(wxAuiNotebookEvent& evt)
{
}

void sessionNotebook::OnTabMiddleUp(wxAuiNotebookEvent& evt)
{
}

void sessionNotebook::OnTabRightDown(wxAuiNotebookEvent& evt)
{
	wxMenu menu;
	menu.Append(ID_MENU_NEW_SESSION, wxT("&New Session"), wxT("New a Session behind me") );
	menu.Append(ID_MENU_FIRST_SESSION, wxT("&First Session"), wxT("Switch to the First Session") );
	menu.Append(ID_MENU_LAST_SESSION, wxT("&Last Session"), wxT("Switch to the Last Session") );
	menu.AppendSeparator();
	menu.Append(ID_MENU_ABOUT_SESSION, wxT("&About Session"), wxT("About this Session"), true);
	PopupMenu(&menu);
}

void sessionNotebook::OnTabRightUp(wxAuiNotebookEvent& evt)
{
}

void sessionNotebook::OnTabBgDClick(wxAuiNotebookEvent& evt)
{
}

void sessionNotebook::OnNotebookPageClose(wxAuiNotebookEvent& evt)
{
}

void sessionNotebook::OnNotebookPageClosed(wxAuiNotebookEvent& evt)
{
}

void sessionNotebook::OnAllowNotebookDnD(wxAuiNotebookEvent& evt)
{
}

void sessionNotebook::OnButton(wxAuiNotebookEvent& evt)
{
}

void sessionNotebook::OnAbout(wxCommandEvent& event)
{
	wxString content = wxT("Session: XXXXX\n"
							"Host   : XXXXX\n"
							"Port   : XXXXX");
	wxMessageBox(content, _("Session"), wxOK, this);
}

void sessionNotebook::OnNewSession(wxCommandEvent& event)
{
	size_t position = this->GetSelection();
	InsertSession(position + 1);
}

void sessionNotebook::OnFirstSession(wxCommandEvent& event)
{
	// switch to the first page
	this->SetSelection(0);
}

void sessionNotebook::OnLastSession(wxCommandEvent& event)
{
	size_t position = this->GetPageCount();
	if ( position > 0 ) {
		// switch to the last page
		this->SetSelection(position - 1);
	}
}

bool sessionNotebook::InsertSession(size_t position)
{
	bool retval = false;
	wxString title;
	// create the notebook off-window to avoid flicker
	wxSize client_size = GetClientSize();

	title.Printf(wxT("Session %lu"), position);
	this->Freeze();
	retval = this->InsertPage(position, CreateTextCtrl(), title, true);
	this->SetPageToolTip(position, title);
	this->Thaw();
	
	return retval;
}

bool sessionNotebook::AddSession()
{
	return InsertSession(this->GetPageCount());
}
