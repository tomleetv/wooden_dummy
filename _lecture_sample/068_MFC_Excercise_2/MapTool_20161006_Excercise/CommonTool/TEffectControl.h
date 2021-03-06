#pragma once

#include "TEffectForm.h"
// TEffectControl

class TEffectControl : public CDockablePane
{
	DECLARE_DYNAMIC(TEffectControl)

public:
	TEffectControl();
	virtual ~TEffectControl();

	TEffectForm* m_wndForm;

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg int OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message);
};


