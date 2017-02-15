#ifndef SETTINGSPANEL_H
#define SETTINGSPANEL_H

#include <wx/aui/aui.h>

#include "cittyFrame.h"

class cittyFrame;

class SettingsPanel: public wxPanel
{
public:
	SettingsPanel();
	~SettingsPanel();
	
private:
	cittyFrame* m_frame;
	wxSpinCtrl* m_border_size;
	wxSpinCtrl* m_sash_size;
	wxSpinCtrl* m_caption_size;
};


#endif // SETTINGSPANEL_H
