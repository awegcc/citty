#ifndef SETTINGSPANEL_H
#define SETTINGSPANEL_H

#include <wx/aui/aui.h>

#include "cittyFrame.h"

class cittyFrame;

class SettingsPanel: public wxPanel
{
private:
	enum
	{
		ID_PaneBorderSize = wxID_HIGHEST+1,
		ID_SashSize,
		ID_CaptionSize,
		ID_BackgroundColor,
		ID_SashColor,
		ID_InactiveCaptionColor,
		ID_InactiveCaptionGradientColor,
		ID_InactiveCaptionTextColor,
		ID_ActiveCaptionColor,
		ID_ActiveCaptionGradientColor,
		ID_ActiveCaptionTextColor,
		ID_BorderColor,
		ID_GripperColor
	};

public:
	SettingsPanel();
	SettingsPanel(wxWindow* parent, cittyFrame* frame);
	~SettingsPanel();

private:
	wxBitmap CreateColorBitmap(const wxColour& c);
	void UpdateColors();
	void OnPaneBorderSize(wxSpinEvent& event);
	void OnSashSize(wxSpinEvent& event);
	void OnCaptionSize(wxSpinEvent& event);
	void OnSetColor(wxCommandEvent& event);

private:
	cittyFrame* m_frame;
	wxSpinCtrl* m_border_size;
	wxSpinCtrl* m_sash_size;
	wxSpinCtrl* m_caption_size;
	wxBitmapButton* m_inactive_caption_text_color;
	wxBitmapButton* m_inactive_caption_gradient_color;
	wxBitmapButton* m_inactive_caption_color;
	wxBitmapButton* m_active_caption_text_color;
	wxBitmapButton* m_active_caption_gradient_color;
	wxBitmapButton* m_active_caption_color;
	wxBitmapButton* m_sash_color;
	wxBitmapButton* m_background_color;
	wxBitmapButton* m_border_color;
	wxBitmapButton* m_gripper_color;
	
private:
	wxDECLARE_EVENT_TABLE();
};


#endif // SETTINGSPANEL_H
