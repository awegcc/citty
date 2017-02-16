#include "dialogNotebook.h"


BEGIN_EVENT_TABLE(dialogNotebook, wxAuiNotebook)
	EVT_AUINOTEBOOK_PAGE_CLOSE(wxID_ANY, dialogNotebook::OnNotebookPageClose)
	EVT_AUINOTEBOOK_ALLOW_DND(wxID_ANY, dialogNotebook::OnAllowNotebookDnD)
	EVT_AUINOTEBOOK_PAGE_CLOSED(wxID_ANY, dialogNotebook::OnNotebookPageClosed)
	EVT_AUINOTEBOOK_TAB_RIGHT_DOWN(wxID_ANY, dialogNotebook::OnTabRightDown)
END_EVENT_TABLE()

dialogNotebook::dialogNotebook()
{
}

dialogNotebook::~dialogNotebook()
{
	
}

dialogNotebook::dialogNotebook(wxWindow* parent,
		wxWindowID id = wxID_ANY,
		const wxPoint& pos = wxDefaultPosition,
		const wxSize& size = wxDefaultSize,
		long style = wxAUI_NB_DEFAULT_STYLE)
: wxAuiNotebook(parent, id, pos, size, style)
{
	this->AddPage(CreateHTMLCtrl(this), wxT("Welcome to wxAUI") , true, wxNullBitmap);
	this->SetPageToolTip(this->GetPageCount()-1, "HTML (PageTooltip)");
}

void dialogNotebook::CreateDialog(const wxString& title)
{
}

wxTextCtrl* dialogNotebook::CreateTextCtrl(const wxString& ctrl_text)
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

wxHtmlWindow* dialogNotebook::CreateHTMLCtrl(wxWindow* parent)
{
	if (!parent) {
		parent = this;
	}

	wxHtmlWindow* ctrl = new wxHtmlWindow(parent, wxID_ANY, wxDefaultPosition, wxSize(400,300));
	ctrl->SetPage(GetHtmlText());
	return ctrl;
}

wxString dialogNotebook::GetHtmlText()
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

void dialogNotebook::OnTabClicked(wxAuiNotebookEvent& evt)
{
}

void dialogNotebook::OnTabDragMotion(wxAuiNotebookEvent& evt)
{
}

void dialogNotebook::OnTabEndDrag(wxAuiNotebookEvent& evt)
{
}

void dialogNotebook::OnTabCancelDrag(wxAuiNotebookEvent& evt)
{
}

void dialogNotebook::OnTabButton(wxAuiNotebookEvent& evt)
{
}

void dialogNotebook::OnTabMiddleDown(wxAuiNotebookEvent& evt)
{
}

void dialogNotebook::OnTabMiddleUp(wxAuiNotebookEvent& evt)
{
}

void dialogNotebook::OnTabRightDown(wxAuiNotebookEvent& evt)
{
}

void dialogNotebook::OnTabRightUp(wxAuiNotebookEvent& evt)
{
}

void dialogNotebook::OnTabBgDClick(wxAuiNotebookEvent& evt)
{
}

void dialogNotebook::OnNotebookPageClose(wxAuiNotebookEvent& evt)
{
}

void dialogNotebook::OnNotebookPageClosed(wxAuiNotebookEvent& evt)
{
}

void dialogNotebook::OnAllowNotebookDnD(wxAuiNotebookEvent& evt)
{
}

void dialogNotebook::OnButton(wxAuiNotebookEvent& evt)
{
}
