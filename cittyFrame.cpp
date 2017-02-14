#include "cittyFrame.h"

wxBEGIN_EVENT_TABLE(cittyFrame, wxFrame)
	EVT_ERASE_BACKGROUND(cittyFrame::OnEraseBackground)
	EVT_SIZE(cittyFrame::OnSize)
	EVT_MENU(cittyFrame::ID_InsertNotebookPage, cittyFrame::OnInsertNotebookPage)
	EVT_MENU(cittyFrame::ID_CreatePerspective, cittyFrame::OnCreatePerspective)
	EVT_MENU(cittyFrame::ID_CopyPerspectiveCode, cittyFrame::OnCopyPerspectiveCode)
	EVT_MENU(ID_AllowFloating, cittyFrame::OnManagerFlag)
	EVT_MENU(ID_TransparentHint, cittyFrame::OnManagerFlag)
	EVT_MENU(ID_VenetianBlindsHint, cittyFrame::OnManagerFlag)
	EVT_MENU(ID_RectangleHint, cittyFrame::OnManagerFlag)
	EVT_MENU(ID_NoHint, cittyFrame::OnManagerFlag)
	EVT_MENU(ID_HintFade, cittyFrame::OnManagerFlag)
	EVT_MENU(ID_NoVenetianFade, cittyFrame::OnManagerFlag)
	EVT_MENU(ID_TransparentDrag, cittyFrame::OnManagerFlag)
	EVT_MENU(ID_LiveUpdate, cittyFrame::OnManagerFlag)
	EVT_MENU(ID_AllowActivePane, cittyFrame::OnManagerFlag)
	EVT_MENU(ID_NotebookTabFixedWidth, cittyFrame::OnNotebookFlag)
	EVT_MENU(ID_NotebookNoCloseButton, cittyFrame::OnNotebookFlag)
	EVT_MENU(ID_NotebookCloseButton, cittyFrame::OnNotebookFlag)
	EVT_MENU(ID_NotebookCloseButtonAll, cittyFrame::OnNotebookFlag)
	EVT_MENU(ID_NotebookCloseButtonActive, cittyFrame::OnNotebookFlag)
	EVT_MENU(ID_NotebookAllowTabMove, cittyFrame::OnNotebookFlag)
	EVT_MENU(ID_NotebookAllowTabExternalMove, cittyFrame::OnNotebookFlag)
	EVT_MENU(ID_NotebookAllowTabSplit, cittyFrame::OnNotebookFlag)
	EVT_MENU(ID_NotebookScrollButtons, cittyFrame::OnNotebookFlag)
	EVT_MENU(ID_NotebookWindowList, cittyFrame::OnNotebookFlag)
	EVT_MENU(ID_NotebookArtGloss, cittyFrame::OnNotebookFlag)
	EVT_MENU(ID_NotebookArtSimple, cittyFrame::OnNotebookFlag)
	EVT_MENU(ID_NotebookAlignTop, cittyFrame::OnTabAlignment)
	EVT_MENU(ID_NotebookAlignBottom,  cittyFrame::OnTabAlignment)
	EVT_MENU(ID_NoGradient, cittyFrame::OnGradient)
	EVT_MENU(ID_VerticalGradient, cittyFrame::OnGradient)
	EVT_MENU(ID_HorizontalGradient, cittyFrame::OnGradient)
	EVT_MENU(ID_Settings, cittyFrame::OnSettings)
	EVT_MENU(ID_TextContent, cittyFrame::OnChangeContentPane)
	EVT_MENU(ID_HTMLContent, cittyFrame::OnChangeContentPane)
	EVT_MENU(ID_NotebookContent, cittyFrame::OnChangeContentPane)
	EVT_MENU(wxID_EXIT, cittyFrame::OnExit)
	EVT_MENU(wxID_ABOUT, cittyFrame::OnAbout)
	EVT_UPDATE_UI(ID_NotebookTabFixedWidth, cittyFrame::OnUpdateUI)
	EVT_UPDATE_UI(ID_NotebookNoCloseButton, cittyFrame::OnUpdateUI)
	EVT_UPDATE_UI(ID_NotebookCloseButton, cittyFrame::OnUpdateUI)
	EVT_UPDATE_UI(ID_NotebookCloseButtonAll, cittyFrame::OnUpdateUI)
	EVT_UPDATE_UI(ID_NotebookCloseButtonActive, cittyFrame::OnUpdateUI)
	EVT_UPDATE_UI(ID_NotebookAllowTabMove, cittyFrame::OnUpdateUI)
	EVT_UPDATE_UI(ID_NotebookAllowTabExternalMove, cittyFrame::OnUpdateUI)
	EVT_UPDATE_UI(ID_NotebookAllowTabSplit, cittyFrame::OnUpdateUI)
	EVT_UPDATE_UI(ID_NotebookScrollButtons, cittyFrame::OnUpdateUI)
	EVT_UPDATE_UI(ID_NotebookWindowList, cittyFrame::OnUpdateUI)
	EVT_UPDATE_UI(ID_AllowFloating, cittyFrame::OnUpdateUI)
	EVT_UPDATE_UI(ID_TransparentHint, cittyFrame::OnUpdateUI)
	EVT_UPDATE_UI(ID_VenetianBlindsHint, cittyFrame::OnUpdateUI)
	EVT_UPDATE_UI(ID_RectangleHint, cittyFrame::OnUpdateUI)
	EVT_UPDATE_UI(ID_NoHint, cittyFrame::OnUpdateUI)
	EVT_UPDATE_UI(ID_HintFade, cittyFrame::OnUpdateUI)
	EVT_UPDATE_UI(ID_NoVenetianFade, cittyFrame::OnUpdateUI)
	EVT_UPDATE_UI(ID_TransparentDrag, cittyFrame::OnUpdateUI)
	EVT_UPDATE_UI(ID_LiveUpdate, cittyFrame::OnUpdateUI)
	EVT_UPDATE_UI(ID_NoGradient, cittyFrame::OnUpdateUI)
	EVT_UPDATE_UI(ID_VerticalGradient, cittyFrame::OnUpdateUI)
	EVT_UPDATE_UI(ID_HorizontalGradient, cittyFrame::OnUpdateUI)
	EVT_MENU_RANGE(cittyFrame::ID_FirstPerspective, cittyFrame::ID_FirstPerspective+1000, cittyFrame::OnRestorePerspective)
	EVT_AUI_PANE_CLOSE(cittyFrame::OnPaneClose)
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
	m_notebook_style = wxAUI_NB_DEFAULT_STYLE | wxAUI_NB_TAB_EXTERNAL_MOVE | wxNO_BORDER;
	m_notebook_theme = 0;

	// create menu
	wxMenu* file_menu = new wxMenu;
	file_menu->Append(ID_InsertNotebookPage, _("&Insert NotebookPage"), _("Insert a NotebookPage"));
	file_menu->Append(wxID_EXIT);

	wxMenu* view_menu = new wxMenu;
	view_menu->Append(ID_TextContent, _("Use a Text Control for the Content Pane"));
	view_menu->Append(ID_HTMLContent, _("Use an HTML Control for the Content Pane"));
	view_menu->Append(ID_NotebookContent, _("Use a wxAuiNotebook control for the Content Pane"));

	wxMenu* options_menu = new wxMenu;
	options_menu->AppendRadioItem(ID_TransparentHint, _("Transparent Hint"), _("Transparent Hint"));
	options_menu->AppendRadioItem(ID_VenetianBlindsHint, _("Venetian Blinds Hint"), _("Venetian Blinds Hint"));
	options_menu->AppendRadioItem(ID_RectangleHint, _("Rectangle Hint"), _("Rectangle Hint"));
	options_menu->AppendRadioItem(ID_NoHint, _("No Hint"), _("No Hint"));
	options_menu->AppendSeparator();
	options_menu->AppendCheckItem(ID_HintFade, _("Hint Fade-in"));
	options_menu->AppendCheckItem(ID_AllowFloating, _("Allow Floating"));
	options_menu->AppendCheckItem(ID_NoVenetianFade, _("Disable Venetian Blinds Hint Fade-in"));
	options_menu->AppendCheckItem(ID_TransparentDrag, _("Transparent Drag"));
	options_menu->AppendCheckItem(ID_AllowActivePane, _("Allow Active Pane"));
	options_menu->AppendCheckItem(ID_LiveUpdate, _("Live Resize Update"));
	options_menu->AppendSeparator();
	options_menu->AppendRadioItem(ID_NoGradient, _("No Caption Gradient"));
	options_menu->AppendRadioItem(ID_VerticalGradient, _("Vertical Caption Gradient"));
	options_menu->AppendRadioItem(ID_HorizontalGradient, _("Horizontal Caption Gradient"));
	options_menu->AppendSeparator();
	options_menu->AppendSeparator();
	options_menu->Append(ID_Settings, _("Settings Pane"));

	wxMenu* notebook_menu = new wxMenu;
	notebook_menu->AppendRadioItem(ID_NotebookArtGloss, _("Glossy Theme (Default)"));
	notebook_menu->AppendRadioItem(ID_NotebookArtSimple, _("Simple Theme"));
	notebook_menu->AppendSeparator();
	notebook_menu->AppendRadioItem(ID_NotebookNoCloseButton, _("No Close Button"));
	notebook_menu->AppendRadioItem(ID_NotebookCloseButton, _("Close Button at Right"));
	notebook_menu->AppendRadioItem(ID_NotebookCloseButtonAll, _("Close Button on All Tabs"));
	notebook_menu->AppendRadioItem(ID_NotebookCloseButtonActive, _("Close Button on Active Tab"));
	notebook_menu->AppendSeparator();
	notebook_menu->AppendRadioItem(ID_NotebookAlignTop, _("Tab Top Alignment"));
	notebook_menu->AppendRadioItem(ID_NotebookAlignBottom, _("Tab Bottom Alignment"));
	notebook_menu->AppendSeparator();
	notebook_menu->AppendCheckItem(ID_NotebookAllowTabMove, _("Allow Tab Move"));
	notebook_menu->AppendCheckItem(ID_NotebookAllowTabExternalMove, _("Allow External Tab Move"));
	notebook_menu->AppendCheckItem(ID_NotebookAllowTabSplit, _("Allow Notebook Split"));
	notebook_menu->AppendCheckItem(ID_NotebookScrollButtons, _("Scroll Buttons Visible"));
	notebook_menu->AppendCheckItem(ID_NotebookWindowList, _("Window List Button Visible"));
	notebook_menu->AppendCheckItem(ID_NotebookTabFixedWidth, _("Fixed-width Tabs"));

	m_perspectives_menu = new wxMenu();
	m_perspectives_menu->Append(ID_CreatePerspective, _("Create Perspective"));
	m_perspectives_menu->Append(ID_CopyPerspectiveCode, _("Copy Perspective Data To Clipboard"));
	m_perspectives_menu->AppendSeparator();
	m_perspectives_menu->Append(ID_FirstPerspective+0, _("Default Startup"));
	m_perspectives_menu->Append(ID_FirstPerspective+1, _("All Panes"));

	wxMenu* help_menu = new wxMenu;
	help_menu->Append(wxID_ABOUT);

	wxMenuBar *menubar = new wxMenuBar();
	menubar->Append(file_menu, _("&File"));
	menubar->Append(view_menu, _("&View"));
	menubar->Append(m_perspectives_menu, _("&Perspectives"));
	menubar->Append(options_menu, _("&Options"));
	menubar->Append(notebook_menu, _("&Notebook"));
	menubar->Append(help_menu, _("&Help"));

	SetMenuBar(menubar);

	CreateStatusBar();
	GetStatusBar()->SetStatusText(_("Ready"));

	// create the notebook off-window to avoid flicker
	wxSize client_size = GetClientSize();

	m_notebook = new cittyAuiNotebook(this, wxID_ANY,
			wxPoint(client_size.x, client_size.y),
			wxSize(430,200),
			m_notebook_style);
	m_notebook->Freeze();

	/*
	 * min size for the frame itself isn't completely done.
	 * see the end up wxAuiManager::Update() for the test
	 * code. For now, just hard code a frame minimum size
	 */
	SetMinSize(wxSize(500, 400));


	m_mgr.AddPane(new SettingsPanel(this,this), wxAuiPaneInfo().
			Name(wxT("settings")).Caption(wxT("Dock Manager Settings")).
			Dockable(false).Float().Hide());

	// create some center panes

	m_mgr.AddPane(CreateTextCtrl(), wxAuiPaneInfo().Name(wxT("text_content")).
			CenterPane().Hide());

	m_mgr.AddPane(CreateHTMLCtrl(), wxAuiPaneInfo().Name(wxT("html_content")).
			CenterPane().Hide());

	m_mgr.AddPane(CreateNotebook(), wxAuiPaneInfo().Name(wxT("notebook_content")).
			CenterPane().PaneBorder(false));

	// make some default perspectives
	wxString perspective_all = m_mgr.SavePerspective();

	m_mgr.GetPane(wxT("notebook_content")).Show();
	wxString perspective_default = m_mgr.SavePerspective();

	m_perspectives.Add(perspective_default);
	m_perspectives.Add(perspective_all);

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
	event.Skip();
}

void cittyFrame::OnSize(wxSizeEvent& event)
{
	event.Skip();
}

void cittyFrame::OnSettings(wxCommandEvent& WXUNUSED(evt))
{
	// show the settings pane, and float it
	wxAuiPaneInfo& floating_pane = m_mgr.GetPane(wxT("settings")).Float().Show();

	if (floating_pane.floating_pos == wxDefaultPosition)
		floating_pane.FloatingPosition(GetStartPosition());

	m_mgr.Update();
}

void cittyFrame::OnGradient(wxCommandEvent& event)
{
	int gradient = 0;

	switch (event.GetId())
	{
		case ID_NoGradient:         gradient = wxAUI_GRADIENT_NONE; break;
		case ID_VerticalGradient:   gradient = wxAUI_GRADIENT_VERTICAL; break;
		case ID_HorizontalGradient: gradient = wxAUI_GRADIENT_HORIZONTAL; break;
	}

	m_mgr.GetArtProvider()->SetMetric(wxAUI_DOCKART_GRADIENT_TYPE, gradient);
	m_mgr.Update();
}

void cittyFrame::OnManagerFlag(wxCommandEvent& event)
{
	unsigned int flag = 0;

#if !defined(__WXMSW__) && !defined(__WXMAC__) && !defined(__WXGTK__)
	if (event.GetId() == ID_TransparentDrag ||
			event.GetId() == ID_TransparentHint ||
			event.GetId() == ID_HintFade)
	{
		wxMessageBox(wxT("This option is presently only available on wxGTK, wxMSW and wxMac"));
		return;
	}
#endif

	int id = event.GetId();

	if (id == ID_TransparentHint ||
			id == ID_VenetianBlindsHint ||
			id == ID_RectangleHint ||
			id == ID_NoHint)
	{
		unsigned int flags = m_mgr.GetFlags();
		flags &= ~wxAUI_MGR_TRANSPARENT_HINT;
		flags &= ~wxAUI_MGR_VENETIAN_BLINDS_HINT;
		flags &= ~wxAUI_MGR_RECTANGLE_HINT;
		m_mgr.SetFlags(flags);
	}

	switch (id) {
		case ID_AllowFloating: flag = wxAUI_MGR_ALLOW_FLOATING; break;
		case ID_TransparentDrag: flag = wxAUI_MGR_TRANSPARENT_DRAG; break;
		case ID_HintFade: flag = wxAUI_MGR_HINT_FADE; break;
		case ID_NoVenetianFade: flag = wxAUI_MGR_NO_VENETIAN_BLINDS_FADE; break;
		case ID_AllowActivePane: flag = wxAUI_MGR_ALLOW_ACTIVE_PANE; break;
		case ID_TransparentHint: flag = wxAUI_MGR_TRANSPARENT_HINT; break;
		case ID_VenetianBlindsHint: flag = wxAUI_MGR_VENETIAN_BLINDS_HINT; break;
		case ID_RectangleHint: flag = wxAUI_MGR_RECTANGLE_HINT; break;
		case ID_LiveUpdate: flag = wxAUI_MGR_LIVE_RESIZE; break;
	}

	if (flag) {
		m_mgr.SetFlags(m_mgr.GetFlags() ^ flag);
	}

	m_mgr.Update();
}


void cittyFrame::OnNotebookFlag(wxCommandEvent& event)
{
	int id = event.GetId();

	if (id == ID_NotebookNoCloseButton ||
			id == ID_NotebookCloseButton ||
			id == ID_NotebookCloseButtonAll ||
			id == ID_NotebookCloseButtonActive)
	{
		m_notebook_style &= ~(wxAUI_NB_CLOSE_BUTTON |
				wxAUI_NB_CLOSE_ON_ACTIVE_TAB |
				wxAUI_NB_CLOSE_ON_ALL_TABS);

		switch (id)
		{
			case ID_NotebookNoCloseButton: break;
			case ID_NotebookCloseButton: m_notebook_style |= wxAUI_NB_CLOSE_BUTTON; break;
			case ID_NotebookCloseButtonAll: m_notebook_style |= wxAUI_NB_CLOSE_ON_ALL_TABS; break;
			case ID_NotebookCloseButtonActive: m_notebook_style |= wxAUI_NB_CLOSE_ON_ACTIVE_TAB; break;
		}
	}

	if (id == ID_NotebookAllowTabMove) {
		m_notebook_style ^= wxAUI_NB_TAB_MOVE;
	}
	if (id == ID_NotebookAllowTabExternalMove) {
		m_notebook_style ^= wxAUI_NB_TAB_EXTERNAL_MOVE;
	}
	else if (id == ID_NotebookAllowTabSplit) {
		m_notebook_style ^= wxAUI_NB_TAB_SPLIT;
	}
	else if (id == ID_NotebookWindowList) {
		m_notebook_style ^= wxAUI_NB_WINDOWLIST_BUTTON;
	}
	else if (id == ID_NotebookScrollButtons) {
		m_notebook_style ^= wxAUI_NB_SCROLL_BUTTONS;
	}
	else if (id == ID_NotebookTabFixedWidth) {
		m_notebook_style ^= wxAUI_NB_TAB_FIXED_WIDTH;
	}

	size_t i, count;
	wxAuiPaneInfoArray& all_panes = m_mgr.GetAllPanes();
	for (i = 0, count = all_panes.GetCount(); i < count; ++i)
	{
		wxAuiPaneInfo& pane = all_panes.Item(i);
		if (pane.window->IsKindOf(CLASSINFO(wxAuiNotebook)))
		{
			wxAuiNotebook* nb = (wxAuiNotebook*)pane.window;

			if (id == ID_NotebookArtGloss)
			{
				nb->SetArtProvider(new wxAuiDefaultTabArt);
				m_notebook_theme = 0;
			}
			else if (id == ID_NotebookArtSimple)
			{
				nb->SetArtProvider(new wxAuiSimpleTabArt);
				m_notebook_theme = 1;
			}


			nb->SetWindowStyleFlag(m_notebook_style);
			nb->Refresh();
		}
	}
}


void cittyFrame::OnUpdateUI(wxUpdateUIEvent& event)
{
	unsigned int flags = m_mgr.GetFlags();

	switch (event.GetId())
	{
		case ID_NoGradient:
			event.Check(m_mgr.GetArtProvider()->GetMetric(wxAUI_DOCKART_GRADIENT_TYPE) == wxAUI_GRADIENT_NONE);
			break;
		case ID_VerticalGradient:
			event.Check(m_mgr.GetArtProvider()->GetMetric(wxAUI_DOCKART_GRADIENT_TYPE) == wxAUI_GRADIENT_VERTICAL);
			break;
		case ID_HorizontalGradient:
			event.Check(m_mgr.GetArtProvider()->GetMetric(wxAUI_DOCKART_GRADIENT_TYPE) == wxAUI_GRADIENT_HORIZONTAL);
			break;
		case ID_AllowFloating:
			event.Check((flags & wxAUI_MGR_ALLOW_FLOATING) != 0);
			break;
		case ID_TransparentDrag:
			event.Check((flags & wxAUI_MGR_TRANSPARENT_DRAG) != 0);
			break;
		case ID_TransparentHint:
			event.Check((flags & wxAUI_MGR_TRANSPARENT_HINT) != 0);
			break;
		case ID_LiveUpdate:
			event.Check((flags & wxAUI_MGR_LIVE_RESIZE) != 0);
			break;
		case ID_VenetianBlindsHint:
			event.Check((flags & wxAUI_MGR_VENETIAN_BLINDS_HINT) != 0);
			break;
		case ID_RectangleHint:
			event.Check((flags & wxAUI_MGR_RECTANGLE_HINT) != 0);
			break;
		case ID_NoHint:
			event.Check(((wxAUI_MGR_TRANSPARENT_HINT |
							wxAUI_MGR_VENETIAN_BLINDS_HINT |
							wxAUI_MGR_RECTANGLE_HINT) & flags) == 0);
			break;
		case ID_HintFade:
			event.Check((flags & wxAUI_MGR_HINT_FADE) != 0);
			break;
		case ID_NoVenetianFade:
			event.Check((flags & wxAUI_MGR_NO_VENETIAN_BLINDS_FADE) != 0);
			break;

		case ID_NotebookNoCloseButton:
			event.Check((m_notebook_style & (wxAUI_NB_CLOSE_BUTTON|wxAUI_NB_CLOSE_ON_ALL_TABS|wxAUI_NB_CLOSE_ON_ACTIVE_TAB)) != 0);
			break;
		case ID_NotebookCloseButton:
			event.Check((m_notebook_style & wxAUI_NB_CLOSE_BUTTON) != 0);
			break;
		case ID_NotebookCloseButtonAll:
			event.Check((m_notebook_style & wxAUI_NB_CLOSE_ON_ALL_TABS) != 0);
			break;
		case ID_NotebookCloseButtonActive:
			event.Check((m_notebook_style & wxAUI_NB_CLOSE_ON_ACTIVE_TAB) != 0);
			break;
		case ID_NotebookAllowTabSplit:
			event.Check((m_notebook_style & wxAUI_NB_TAB_SPLIT) != 0);
			break;
		case ID_NotebookAllowTabMove:
			event.Check((m_notebook_style & wxAUI_NB_TAB_MOVE) != 0);
			break;
		case ID_NotebookAllowTabExternalMove:
			event.Check((m_notebook_style & wxAUI_NB_TAB_EXTERNAL_MOVE) != 0);
			break;
		case ID_NotebookScrollButtons:
			event.Check((m_notebook_style & wxAUI_NB_SCROLL_BUTTONS) != 0);
			break;
		case ID_NotebookWindowList:
			event.Check((m_notebook_style & wxAUI_NB_WINDOWLIST_BUTTON) != 0);
			break;
		case ID_NotebookTabFixedWidth:
			event.Check((m_notebook_style & wxAUI_NB_TAB_FIXED_WIDTH) != 0);
			break;
		case ID_NotebookArtGloss:
			event.Check(m_notebook_style == 0);
			break;
		case ID_NotebookArtSimple:
			event.Check(m_notebook_style == 1);
			break;

	}
}

void cittyFrame::OnPaneClose(wxAuiManagerEvent& evt)
{
	if (evt.pane->name == wxT("test10")) {
		int res = wxMessageBox(wxT("Are you sure you want to close/hide this pane?"),
				wxT("wxAUI"),
				wxYES_NO,
				this);
		if (res != wxYES)
			evt.Veto();
	}
}

void cittyFrame::OnCreatePerspective(wxCommandEvent& WXUNUSED(event))
{
	wxTextEntryDialog dlg(this, wxT("Enter a name for the new perspective:"),
			wxT("wxAUI Test"));

	dlg.SetValue(wxString::Format(wxT("Perspective %u"), unsigned(m_perspectives.GetCount() + 1)));
	if (dlg.ShowModal() != wxID_OK)
		return;

	if (m_perspectives.GetCount() == 0)
	{
		m_perspectives_menu->AppendSeparator();
	}

	m_perspectives_menu->Append(ID_FirstPerspective + m_perspectives.GetCount(), dlg.GetValue());
	m_perspectives.Add(m_mgr.SavePerspective());
}

void cittyFrame::OnCopyPerspectiveCode(wxCommandEvent& WXUNUSED(evt))
{
	wxString s = m_mgr.SavePerspective();

#if wxUSE_CLIPBOARD
	if (wxTheClipboard->Open())
	{
		wxTheClipboard->SetData(new wxTextDataObject(s));
		wxTheClipboard->Close();
	}
#endif
}

void cittyFrame::OnRestorePerspective(wxCommandEvent& evt)
{
	m_mgr.LoadPerspective(m_perspectives.Item(evt.GetId() - ID_FirstPerspective));
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
	wxString title;
	title.Printf(wxT("Insert %lu page"), m_notebook->GetPageCount()-1);
	wxTextCtrl *textctrl = new wxTextCtrl( m_notebook,
						wxID_ANY, title,
						wxDefaultPosition,
						wxDefaultSize,
						wxTE_MULTILINE|wxNO_BORDER );
	m_notebook->Freeze();
	m_notebook->InsertPage(m_notebook->GetPageCount()-1, textctrl, title, true);
	m_notebook->SetPageToolTip(m_notebook->GetPageCount()-2, title);
	m_notebook->Thaw();
}

void cittyFrame::OnChangeContentPane(wxCommandEvent& evt)
{
	m_mgr.GetPane(wxT("text_content")).Show(evt.GetId() == ID_TextContent);
	m_mgr.GetPane(wxT("html_content")).Show(evt.GetId() == ID_HTMLContent);
	m_mgr.GetPane(wxT("notebook_content")).Show(evt.GetId() == ID_NotebookContent);
	m_mgr.Update();
}


void cittyFrame::OnTabAlignment(wxCommandEvent &evt)
{
	size_t i, count;
	wxAuiPaneInfoArray& all_panes = m_mgr.GetAllPanes();
	for (i = 0, count = all_panes.GetCount(); i < count; ++i)
	{
		wxAuiPaneInfo& pane = all_panes.Item(i);
		if (pane.window->IsKindOf(CLASSINFO(wxAuiNotebook)))
		{
			wxAuiNotebook* nb = (wxAuiNotebook*)pane.window;

			long style = nb->GetWindowStyleFlag();
			style &= ~(wxAUI_NB_TOP | wxAUI_NB_BOTTOM);
			if (evt.GetId() == ID_NotebookAlignTop)
				style |= wxAUI_NB_TOP;
			else if (evt.GetId() == ID_NotebookAlignBottom)
				style |= wxAUI_NB_BOTTOM;
			nb->SetWindowStyleFlag(style);

			nb->Refresh();
		}
	}
}

void cittyFrame::OnExit(wxCommandEvent& WXUNUSED(event))
{
	Close(true);
}

void cittyFrame::OnAbout(wxCommandEvent& WXUNUSED(event))
{
	wxString content = wxT("wxWidgets AUI\n(c) Copyright 2010-2016, Nobody");
	wxMessageBox(content, _("About citty"), wxOK, this);
}

wxTextCtrl* cittyFrame::CreateTextCtrl(const wxString& ctrl_text)
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

wxHtmlWindow* cittyFrame::CreateHTMLCtrl(wxWindow* parent)
{
	if (!parent) {
		parent = this;
	}

	wxHtmlWindow* ctrl = new wxHtmlWindow(parent, wxID_ANY, wxDefaultPosition, wxSize(400,300));
	ctrl->SetPage(GetHtmlText());
	return ctrl;
}

cittyAuiNotebook* cittyFrame::CreateNotebook()
{

	//wxBitmap page_bmp = wxArtProvider::GetBitmap(wxART_NORMAL_FILE, wxART_OTHER, wxSize(16,16));
	wxBitmap page_bmp = wxNullBitmap;

	m_notebook->AddPage(CreateHTMLCtrl(m_notebook), wxT("Welcome to wxAUI") , false, page_bmp);
	m_notebook->SetPageToolTip(m_notebook->GetPageCount()-1, "HTML (PageTooltip)");

	wxNotebookPage *nbp = new wxNotebookPage(m_notebook, wxID_ANY );
	delete nbp;
	wxButton *btn = new wxButton(m_notebook, wxID_ANY);
	m_notebook->AddPage( btn, wxT("New"), true);
	m_notebook->SetPageToolTip(m_notebook->GetPageCount()-1, "wxNotebookPage (PageTooltip)");

	m_notebook->Thaw();
	return m_notebook;
}


wxString cittyFrame::GetHtmlText()
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

