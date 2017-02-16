#ifndef CITTYAUINOTEBOOK_H
#define CITTYAUINOTEBOOK_H
/**
 * @class sessionNotebook
 * @author chenc45
 * @date 16/02/2017
 * @file sessionNotebook.h
 * @brief 
 */

#include <wx/aui/aui.h>
#include <wx/notebook.h>
#include <wx/msgdlg.h>
#include <wx/menu.h>

#include "dialogNotebook.h"

class sessionNotebook: public wxAuiNotebook
{
private:
	enum
	{
		ID_MENU_NEW_SESSION = wxID_HIGHEST+1,
		ID_MENU_PREV_SESSION,
		ID_MENU_NEXT_SESSION,
		ID_MENU_ABOUT_SESSION
	};
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
	void OnAbout(wxCommandEvent& WXUNUSED(event));
	void OnNewSession(wxCommandEvent& WXUNUSED(event));
	void OnPrevSession(wxCommandEvent& WXUNUSED(event));
	void OnNextSession(wxCommandEvent& WXUNUSED(event));

private:
	dialogNotebook *m_notebook;
	wxString m_title;
	long m_notebook_style;
	long m_notebook_theme;
	int m_id;
};

#endif // CITTYAUINOTEBOOK_H
