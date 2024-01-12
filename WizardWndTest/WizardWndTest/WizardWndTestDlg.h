// WizardWndTestDlg.h: 헤더 파일
#pragma once
#include "WizardPage1.h"
#include "WizardPage2.h"
#include "WizardPage3.h"

#define MAX_PAGE_COUNT 3

// CWizardWndTestDlg 대화 상자
class CWizardWndTestDlg : public CDialogEx
{
private:
	CDialogEx* mp_Page[MAX_PAGE_COUNT];
	CRect m_WizardRect;
	int m_PageIndex = 0, m_Num1 = 0, m_Num2 = 0;
// 생성입니다.
public:
	CWizardWndTestDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	void AddPage(CDialogEx* ap_page, int a_index, int a_dlg_id);
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WIZARDWNDTEST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedPrevBtn();
	afx_msg void OnBnClickedNextBtn();
};
