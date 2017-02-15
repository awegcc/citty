#ifndef CITTYAUINOTEBOOK_H
#define CITTYAUINOTEBOOK_H

#include <wx/aui/aui.h>
#include <wx/notebook.h>
#include <wx/msgdlg.h>

#include "dialogNotebook.h"

class sessionNotebook: public wxAuiNotebook
{
private:
	wxDECLARE_EVENT_TABLE();

public:
	sessionNotebook();
	sessionNotebook(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style);
	virtual ~sessionNotebook();
	void CreateSession(const wxString &title);
	bool InsertSession( size_t position);
	bool AddSession();
	
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
	void OnAllowNotebookDnD(wxAuiNotebookEvent& evt);
	void OnButton(wxAuiNotebookEvent& evt);

private:
	dialogNotebook *m_notebook;
	wxString m_title;
	long m_notebook_style;
	long m_notebook_theme;
	int m_id;
};

#endif // CITTYAUINOTEBOOK_H
