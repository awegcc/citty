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

wxStyledTextCtrl* sessionNotebook::CreateTextCtrl(const wxString& ctrl_text)
{
	enum
	{
		MARGIN_LINE_NUMBERS,
		MARGIN_FOLD
	};
	wxStyledTextCtrl *text;
	text = new wxStyledTextCtrl(this, wxID_ANY );
	
	text->StyleClearAll();
	text->SetLexer(wxSTC_LEX_CPP);
 
	text->SetMarginWidth (MARGIN_LINE_NUMBERS, 50);
	text->StyleSetForeground (wxSTC_STYLE_LINENUMBER, wxColour (75, 75, 75) );
	text->StyleSetBackground (wxSTC_STYLE_LINENUMBER, wxColour (220, 220, 220));
	text->SetMarginType (MARGIN_LINE_NUMBERS, wxSTC_MARGIN_NUMBER);
 
 
	// ---- Enable code folding
	text->SetMarginType (MARGIN_FOLD, wxSTC_MARGIN_SYMBOL);
	text->SetMarginWidth(MARGIN_FOLD, 15);
	text->SetMarginMask (MARGIN_FOLD, wxSTC_MASK_FOLDERS);
	text->StyleSetBackground(MARGIN_FOLD, wxColor(200, 200, 200) );
	text->SetMarginSensitive(MARGIN_FOLD, true);
 
	// Properties found from http://www.scintilla.org/SciTEDoc.html
	text->SetProperty (wxT("fold"),         wxT("1") );
	text->SetProperty (wxT("fold.comment"), wxT("1") );
	text->SetProperty (wxT("fold.compact"), wxT("1") );
 
	wxColor grey( 100, 100, 100 );
	text->MarkerDefine (wxSTC_MARKNUM_FOLDER, wxSTC_MARK_ARROW );
	text->MarkerSetForeground (wxSTC_MARKNUM_FOLDER, grey);
	text->MarkerSetBackground (wxSTC_MARKNUM_FOLDER, grey);
 
	text->MarkerDefine (wxSTC_MARKNUM_FOLDEROPEN,    wxSTC_MARK_ARROWDOWN);
	text->MarkerSetForeground (wxSTC_MARKNUM_FOLDEROPEN, grey);
	text->MarkerSetBackground (wxSTC_MARKNUM_FOLDEROPEN, grey);
 
	text->MarkerDefine (wxSTC_MARKNUM_FOLDERSUB,     wxSTC_MARK_EMPTY);
	text->MarkerSetForeground (wxSTC_MARKNUM_FOLDERSUB, grey);
	text->MarkerSetBackground (wxSTC_MARKNUM_FOLDERSUB, grey);
 
	text->MarkerDefine (wxSTC_MARKNUM_FOLDEREND,     wxSTC_MARK_ARROW);
	text->MarkerSetForeground (wxSTC_MARKNUM_FOLDEREND, grey);
	text->MarkerSetBackground (wxSTC_MARKNUM_FOLDEREND, _T("WHITE"));
 
	text->MarkerDefine (wxSTC_MARKNUM_FOLDEROPENMID, wxSTC_MARK_ARROWDOWN);
	text->MarkerSetForeground (wxSTC_MARKNUM_FOLDEROPENMID, grey);
	text->MarkerSetBackground (wxSTC_MARKNUM_FOLDEROPENMID, _T("WHITE"));
 
	text->MarkerDefine (wxSTC_MARKNUM_FOLDERMIDTAIL, wxSTC_MARK_EMPTY);
	text->MarkerSetForeground (wxSTC_MARKNUM_FOLDERMIDTAIL, grey);
	text->MarkerSetBackground (wxSTC_MARKNUM_FOLDERMIDTAIL, grey);
 
	text->MarkerDefine (wxSTC_MARKNUM_FOLDERTAIL,    wxSTC_MARK_EMPTY);
	text->MarkerSetForeground (wxSTC_MARKNUM_FOLDERTAIL, grey);
	text->MarkerSetBackground (wxSTC_MARKNUM_FOLDERTAIL, grey);
	// ---- End of code folding part
 
	text->SetWrapMode (wxSTC_WRAP_WORD); // other choice is wxSCI_WRAP_NONE
 
	text->SetText(GetCppText());
 
	text->StyleSetForeground (wxSTC_C_STRING,            wxColour(150,0,0));
	text->StyleSetForeground (wxSTC_C_PREPROCESSOR,      wxColour(165,105,0));
	text->StyleSetForeground (wxSTC_C_IDENTIFIER,        wxColour(40,0,60));
	text->StyleSetForeground (wxSTC_C_NUMBER,            wxColour(0,150,0));
	text->StyleSetForeground (wxSTC_C_CHARACTER,         wxColour(150,0,0));
	text->StyleSetForeground (wxSTC_C_WORD,              wxColour(0,0,150));
	text->StyleSetForeground (wxSTC_C_WORD2,             wxColour(0,150,0));
	text->StyleSetForeground (wxSTC_C_COMMENT,           wxColour(150,150,150));
	text->StyleSetForeground (wxSTC_C_COMMENTLINE,       wxColour(150,150,150));
	text->StyleSetForeground (wxSTC_C_COMMENTDOC,        wxColour(150,150,150));
	text->StyleSetForeground (wxSTC_C_COMMENTDOCKEYWORD, wxColour(0,0,200));
	text->StyleSetForeground (wxSTC_C_COMMENTDOCKEYWORDERROR, wxColour(0,0,200));
	text->StyleSetBold(wxSTC_C_WORD, true);
	text->StyleSetBold(wxSTC_C_WORD2, true);
	text->StyleSetBold(wxSTC_C_COMMENTDOCKEYWORD, true);
 
	// a sample list of keywords, I haven't included them all to keep it short...
	text->SetKeyWords(0, wxT("return for while break continue"));
	text->SetKeyWords(1, wxT("const int float void char double"));
	
	return text;
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

wxString sessionNotebook::GetCppText()
{
	const char* text = "// Some example\n"
						"#define MAX 0\n\n"
						"/** @brief The entry point */\n"
						"int main(int argc, char *argv[])\n"
						"{\n"
						"	for (int n=0; n<MAX; n++)\n"
						"	{\n"
						"		printf(\"Hello World %i\\n\", n);\n"
						"	}\n"
						"	return 0;\n"
						"}\n";
	return wxString::FromAscii(text);
}
