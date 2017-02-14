#ifndef CITTYAUINOTEBOOK_H
#define CITTYAUINOTEBOOK_H

#include <wx/aui/aui.h>
#include <wx/notebook.h>
#include <wx/wxhtml.h>
#include <wx/msgdlg.h>


class cittyAuiNotebook: public wxAuiNotebook
{
private:
	wxDECLARE_EVENT_TABLE();

public:
	cittyAuiNotebook();
	cittyAuiNotebook(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style);
	virtual ~cittyAuiNotebook();

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
	wxAuiNotebook *m_notebook;
	int id;
};

#endif // CITTYAUINOTEBOOK_H
