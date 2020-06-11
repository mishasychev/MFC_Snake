
// testMFCDlg.h : header file
//

#pragma once


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


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
	afx_msg
	void OnTimer(UINT uTime);
	void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
