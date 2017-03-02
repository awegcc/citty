/**
 * @class cittyFrame
 * @author chenc45
 * @date 16/02/2017
 * @file cittyFrame.h
 * @brief
 */
#ifndef CITTYFRAME_H
#define CITTYFRAME_H

#include <wx/aui/aui.h>
#include <wx/textctrl.h>
#include <wx/menu.h>
#include <wx/artprov.h>
#include <wx/spinctrl.h>
#include <wx/colordlg.h>
#include <wx/msgdlg.h>
#include <wx/textdlg.h>
#include <wx/clipbrd.h>
#include <wx/log.h>

#include "settingsPanel.h"
#include "connectionNotebook.h"
#include "sample.xpm"

class cittyFrame : public wxFrame
{
private:
	enum
	{
		ID_InsertNotebookPage = wxID_HIGHEST+1
	};

public:
	cittyFrame(wxWindow* parent,
			wxWindowID id,
			const wxString& title,
			const wxPoint& pos = wxDefaultPosition,
			const wxSize& size = wxDefaultSize,
			long style = wxDEFAULT_FRAME_STYLE | wxSUNKEN_BORDER);

	~cittyFrame();

	wxAuiDockArt* GetDockArt();
	void DoUpdate();

private:
	wxPoint GetStartPosition();
	connectionNotebook* CreateNotebook();

private:
	void OnSize(wxSizeEvent& evt);
	void OnEraseBackground(wxEraseEvent& evt);
	void OnInsertNotebookPage(wxCommandEvent& evt);
	void OnCreatePerspective(wxCommandEvent& evt);
	void OnCopyPerspectiveCode(wxCommandEvent& evt);
	void OnRestorePerspective(wxCommandEvent& evt);
	void OnAllowNotebookDnD(wxAuiNotebookEvent& evt);
	void OnNotebookPageClose(wxAuiNotebookEvent& evt);
	void OnNotebookPageClosed(wxAuiNotebookEvent& evt);
	void OnExit(wxCommandEvent& evt);
	void OnClose(wxCloseEvent& evt);
	void OnAbout(wxCommandEvent& evt);
	void OnTabAlignment(wxCommandEvent &evt);
	void OnGradient(wxCommandEvent& evt);
	void OnManagerFlag(wxCommandEvent& evt);
	void OnNotebookFlag(wxCommandEvent& evt);
	void OnUpdateUI(wxUpdateUIEvent& evt);
	void OnPaneClose(wxAuiManagerEvent& evt);

private:
	wxAuiManager m_mgr;
	connectionNotebook* m_notebook;
	long m_session_style; // session notebook style
	long m_dialog_style;  // dialog notebook style
	long m_notebook_theme;

private:
	wxDECLARE_EVENT_TABLE();
};

#endif //CITTYFRAME_H
