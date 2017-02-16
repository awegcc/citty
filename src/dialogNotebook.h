#ifndef CITTYNOTEBOOKDIALOG_H
#define CITTYNOTEBOOKDIALOG_H
/**
 * @class dialogNotebook
 * @author chenc45
 * @date 16/02/2017
 * @file dialogNotebook.h
 * @brief 
 */

#include <wx/aui/aui.h>
#include <wx/notebook.h>
#include <wx/wxhtml.h>
#include <wx/msgdlg.h>
#include <wx/menu.h>

class dialogNotebook: public wxAuiNotebook
{
private:
	enum
	{
		ID_MENU_NEW_DIALOG = wxID_HIGHEST+1,
		ID_MENU_FIRST_DIALOG,
		ID_MENU_LAST_DIALOG,
		ID_MENU_ABOUT_DIALOG
	};
	wxDECLARE_EVENT_TABLE();

public:
	dialogNotebook() { }
	virtual ~dialogNotebook() { }
	dialogNotebook(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style);
	void CreateDialog(const wxString &title);
	wxTextCtrl* CreateTextCtrl(const wxString& text = wxEmptyString);
	wxHtmlWindow* CreateHTMLCtrl(wxWindow* parent = NULL);
	bool InsertDialog( size_t position);
	bool AddDialog();
	
private:
	wxString GetHtmlText();

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
	void OnNewDialog(wxCommandEvent& WXUNUSED(event));
	void OnFirstDialog(wxCommandEvent& WXUNUSED(event));
	void OnLastDialog(wxCommandEvent& WXUNUSED(event));
	
private:
	wxString m_title;
	int m_id;

};

#endif // CITTYNOTEBOOKDIALOG_H
