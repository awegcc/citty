/**
 * @class connectionNotebook
 * @author chenc45
 * @date 16/02/2017
 * @file connectionNotebook.h
 * @brief
 */
#ifndef CONNECTIONNOTEBOOK_H
#define CONNECTIONNOTEBOOK_H

#include <wx/aui/aui.h>
#include <wx/notebook.h>
#include <wx/msgdlg.h>
#include <wx/menu.h>

#include "sessionNotebook.h"

class connectionNotebook: public wxAuiNotebook
{
private:
	enum
	{
		ID_MENU_NEW_CONNECTION = wxID_HIGHEST+1,
		ID_MENU_FIRST_CONNECTION,
		ID_MENU_LAST_CONNECTION,
		ID_MENU_ABOUT_CONNECTION
	};
private:
	wxDECLARE_EVENT_TABLE();

public:
	connectionNotebook() { }
	connectionNotebook(wxFrame* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style);
	virtual ~connectionNotebook() { }
	void CreateConnection(const wxString &title);
	bool InsertConnection( size_t position);
	bool AddConnection();

protected:
	void OnTabClicked(wxAuiNotebookEvent& evt);
	void OnTabDragMotion(wxAuiNotebookEvent& evt);
	void OnTabEndDrag(wxAuiNotebookEvent& evt);
	void OnTabCancelDrag(wxAuiNotebookEvent& evt);
	void OnTabButton(wxAuiNotebookEvent& evt);
	void OnTabMiddleDown(wxAuiNotebookEvent& evt);
	void OnTabMiddleUp(wxAuiNotebookEvent& evt);
	void OnTabRightDown(wxAuiNotebookEvent& evt);
	void OnTabRightUp(wxAuiNotebookEvent& evt);
	void OnTabBgDClick(wxAuiNotebookEvent& evt);

protected:
	void OnNotebookPageClose(wxAuiNotebookEvent& evt);
	void OnNotebookPageClosed(wxAuiNotebookEvent& evt);
    void OnNotebookPageChanged(wxAuiNotebookEvent& evt);
	void OnAllowNotebookDnD(wxAuiNotebookEvent& evt);
	void OnButton(wxAuiNotebookEvent& evt);
	void OnAbout(wxCommandEvent& WXUNUSED(event));
	void OnNewConnection(wxCommandEvent& WXUNUSED(event));
	void OnFirstConnection(wxCommandEvent& WXUNUSED(event));
	void OnLastConnection(wxCommandEvent& WXUNUSED(event));

private:
	sessionNotebook *m_notebook;
	wxFrame *m_parent;
	wxString m_title;
	long m_notebook_style;
	long m_notebook_theme;
	int m_id;
};

#endif // CONNECTIONNOTEBOOK_H
