#pragma once

#include <memory>
#include "ModeDispatcher.h"
#include "constants.h"

// CtestMFCDlg dialog
class CtestMFCDlg : public CDialogEx
{
// Construction
public:
	CtestMFCDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TESTMFC_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
	afx_msg void OnTimer(UINT_PTR uTime);
	afx_msg __forceinline constexpr BOOL OnEraseBkgnd(CDC* pDC) { return TRUE; }
	afx_msg void OnPaint();
	afx_msg __forceinline constexpr HCURSOR OnQueryDragIcon() { return m_hIcon; }
	DECLARE_MESSAGE_MAP()

private:
	std::unique_ptr<ModeDispatcher> dispatcher_;
};