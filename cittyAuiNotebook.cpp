#include "cittyAuiNotebook.h"

/*
   void OnTabClicked(wxAuiNotebookEvent& evt);
   void OnTabBeginDrag(wxAuiNotebookEvent& evt);
   void OnTabDragMotion(wxAuiNotebookEvent& evt);
   void OnTabEndDrag(wxAuiNotebookEvent& evt);
   void OnTabCancelDrag(wxAuiNotebookEvent& evt);
   void OnTabButton(wxAuiNotebookEvent& evt);
   void OnTabMiddleDown(wxAuiNotebookEvent& evt);
   void OnTabMiddleUp(wxAuiNotebookEvent& evt);
   void OnTabRightDown(wxAuiNotebookEvent& evt);
   void OnTabRightUp(wxAuiNotebookEvent& evt);
   void OnTabBgDClick(wxAuiNotebookEvent& evt);
   */

BEGIN_EVENT_TABLE(cittyAuiNotebook, wxAuiNotebook)
	EVT_AUINOTEBOOK_PAGE_CLOSE(wxID_ANY, cittyAuiNotebook::OnNotebookPageClose)
	EVT_AUINOTEBOOK_ALLOW_DND(wxID_ANY, cittyAuiNotebook::OnAllowNotebookDnD)
	EVT_AUINOTEBOOK_PAGE_CLOSED(wxID_ANY, cittyAuiNotebook::OnNotebookPageClosed)
	EVT_AUINOTEBOOK_TAB_RIGHT_DOWN(wxID_ANY, cittyAuiNotebook::OnTabRightDown)
	EVT_AUINOTEBOOK_BUTTON(wxID_ANY, cittyAuiNotebook::OnButton)
END_EVENT_TABLE()

cittyAuiNotebook::cittyAuiNotebook()
{
}


cittyAuiNotebook::~cittyAuiNotebook()
{
}

cittyAuiNotebook::cittyAuiNotebook(wxWindow* parent,
		wxWindowID id = wxID_ANY,
		const wxPoint& pos = wxDefaultPosition,
		const wxSize& size = wxDefaultSize,
		long style = wxAUI_NB_DEFAULT_STYLE)
: wxAuiNotebook(parent, id, pos, size, style)
{
}


void cittyAuiNotebook::OnNotebookPageClose(wxAuiNotebookEvent& evt)
{
	cittyAuiNotebook* ctrl = (cittyAuiNotebook*)evt.GetEventObject();
	if (ctrl->GetPage(evt.GetSelection())->IsKindOf(CLASSINFO(wxHtmlWindow)))
	{
		int res = wxMessageBox(wxT("Sure to close/hide this notebook page?"), wxT("wxAUI"), wxYES_NO, this);
		if (res != wxYES) {
			evt.Veto();
		}
	}
	else if(ctrl->GetPageCount() == (size_t)evt.GetSelection() + 1)
	{
		wxMessageBox(wxT("Can not close this page!"), wxT("wxAUI"), wxOK, this);
		evt.Veto();
	}
}

void cittyAuiNotebook::OnNotebookPageClosed(wxAuiNotebookEvent& evt)
{
	cittyAuiNotebook* ctrl = (cittyAuiNotebook*)evt.GetEventObject();

	// selection should always be a valid index
	wxASSERT_MSG( ctrl->GetSelection() < (int)ctrl->GetPageCount(),
			wxString::Format("Invalid selection %d, only %d pages left",
				ctrl->GetSelection(),
				(int)ctrl->GetPageCount()) );

	evt.Skip();
}

void cittyAuiNotebook::OnAllowNotebookDnD(wxAuiNotebookEvent& evt)
{
	// for the purpose of this test application, explicitly
	// allow all noteboko drag and drop events
	evt.Allow();
}


void cittyAuiNotebook::OnTabClicked(wxAuiNotebookEvent& evt)
{
	wxMessageBox(wxT("OnTabClicked"), _("OnTabClicked"), wxOK, this);
}

void cittyAuiNotebook::OnTabDragMotion(wxAuiNotebookEvent& evt)
{
	wxMessageBox(wxT("OnTabDragMotion"), _("OnTabDragMotion"), wxOK, this);
}

void cittyAuiNotebook::OnTabEndDrag(wxAuiNotebookEvent& evt)
{
	wxMessageBox(wxT("OnTabEndDrag"), _("OnTabEndDrag"), wxOK, this);
}

void cittyAuiNotebook::OnTabCancelDrag(wxAuiNotebookEvent& evt)
{
	wxMessageBox(wxT("OnTabCancelDrag"), _("OnTabCancelDrag"), wxOK, this);
}

void cittyAuiNotebook::OnTabButton(wxAuiNotebookEvent& evt)
{
	wxMessageBox(wxT("OnTabButton"), _("OnTabButton"), wxOK, this);
}

void cittyAuiNotebook::OnButton(wxAuiNotebookEvent& evt)
{
	wxMessageBox(wxT("OnButton"), _("OnButton"), wxOK, this);
}

void cittyAuiNotebook::OnTabMiddleDown(wxAuiNotebookEvent& evt)
{
	wxMessageBox(wxT("OnTabMiddleDown"), _("OnTabMiddleDown"), wxOK, this);
}

void cittyAuiNotebook::OnTabMiddleUp(wxAuiNotebookEvent& evt)
{
	wxMessageBox(wxT("OnTabMiddleUp"), _("OnTabMiddleUp"), wxOK, this);
}

void cittyAuiNotebook::OnTabRightDown(wxAuiNotebookEvent& evt)
{
	wxMessageBox(wxT("OnTabRightDown"), _("OnTabRightDown"), wxOK, this);
}

void cittyAuiNotebook::OnTabRightUp(wxAuiNotebookEvent& evt)
{
	wxMessageBox(wxT("OnTabRightUp"), _("OnTabRightUp"), wxOK, this);
}

void cittyAuiNotebook::OnTabBgDClick(wxAuiNotebookEvent& evt)
{
	wxMessageBox(wxT("OnTabRightUp"), _("OnTabRightUp"), wxOK, this);
}

