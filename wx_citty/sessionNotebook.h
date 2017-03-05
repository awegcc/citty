/**
 * @class sessionNotebook
 * @author chenc45
 * @date 16/02/2017
 * @file sessionNotebook.h
 * @brief
 */
#ifndef SESSIONNOTEBOOK_H
#define SESSIONNOTEBOOK_H

#include <wx/aui/aui.h>
#include <wx/notebook.h>
#include <wx/msgdlg.h>
#include <wx/menu.h>
#include "cittyTerm.h"

//#define CITTY_USE_STC
#ifdef CITTY_USE_STC
#include <wx/stc/stc.h>
#endif // CITTY_USE_STC

//#define CITTY_USE_HTML
#ifdef CITTY_USE_HTML
#include <wx/wxhtml.h>
#endif // CITTY_USE_HTML

class sessionNotebook: public wxAuiNotebook
{
private:
	enum
	{
		ID_MENU_NEW_SESSION = wxID_HIGHEST+1,
		ID_MENU_FIRST_SESSION,
		ID_MENU_LAST_SESSION,
		ID_MENU_ABOUT_SESSION
	};
	wxDECLARE_EVENT_TABLE();

public:
	sessionNotebook();
	~sessionNotebook();
    sessionNotebook(wxAuiNotebook* parent,
                    wxWindowID id = wxID_ANY,
                    const wxPoint& pos = wxDefaultPosition,
                    const wxSize& size = wxDefaultSize,
                    long style = wxAUI_NB_DEFAULT_STYLE);
    void CreateDialog(const wxString &title);
#ifdef CITTY_USE_STC
	wxStyledTextCtrl* CreateTextCtrl(const wxString& text = wxEmptyString);
	bool SetCppStyle(wxStyledTextCtrl *stc);
#else
    cittyTerm* CreateTextCtrl(const wxString& text = wxEmptyString);
#endif // CITTY_USE_STC

#ifdef CITTY_USE_HTML
	wxHtmlWindow* CreateHTMLCtrl(wxWindow* parent = NULL);
	bool SetHtmlStyle(wxStyledTextCtrl *stc);
#endif // CITTY_USE_HTML
	bool InsertSession( size_t position);
	bool AddSession();

private:
	wxString GetHtmlText();
	wxString GetCppText();

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
	void OnNewSession(wxCommandEvent& WXUNUSED(event));
	void OnFirstSession(wxCommandEvent& WXUNUSED(event));
	void OnLastSession(wxCommandEvent& WXUNUSED(event));

private:
	wxString m_title;
	wxAuiNotebook *m_parent;
	int m_switch;

};

#endif // SESSIONNOTEBOOK_H
