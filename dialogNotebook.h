#ifndef DIALOGNOTEBOOK_H
#define DIALOGNOTEBOOK_H

#include <wx/aui/aui.h>
#include <wx/notebook.h>
#include <wx/wxhtml.h>
#include <wx/msgdlg.h>
#include <wx/bmpbuttn.h>

class dialogNotebook: public wxAuiNotebook
{
private:
	wxDECLARE_EVENT_TABLE();

public:
	dialogNotebook();
	dialogNotebook(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style);
	virtual ~dialogNotebook();
	void CreateDialog(const wxString &title);
	wxTextCtrl* CreateTextCtrl(const wxString& text = wxEmptyString);
	wxHtmlWindow* CreateHTMLCtrl(wxWindow* parent = NULL);
	
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
private:
	wxString m_title;
	int m_id;

};

#endif // DIALOGNOTEBOOK_H

