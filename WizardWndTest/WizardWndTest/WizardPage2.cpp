// WizardPage2.cpp: 구현 파일
#include "pch.h"
#include "WizardWndTest.h"
#include "afxdialogex.h"
#include "WizardPage2.h"


// WizardPage2 대화 상자
IMPLEMENT_DYNAMIC(WizardPage2, CDialogEx)

WizardPage2::WizardPage2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PAGE2, pParent)
{

}

WizardPage2::~WizardPage2()
{
}

void WizardPage2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_OP_LIST, m_OpList);
}

BEGIN_MESSAGE_MAP(WizardPage2, CDialogEx)
	ON_BN_CLICKED(IDOK, &WizardPage2::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &WizardPage2::OnBnClickedCancel)
END_MESSAGE_MAP()

// WizardPage2 메시지 처리기
int WizardPage2::GetOpType()
{
	return m_OpList.GetCurSel();
}

void WizardPage2::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// CDialogEx::OnOK();
}

void WizardPage2::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// CDialogEx::OnCancel();
}

BOOL WizardPage2::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	SetBackgroundColor(RGB(232, 200, 228));
	m_OpList.InsertString(0, _T("+"));
	m_OpList.InsertString(1, _T("-"));
	m_OpList.InsertString(2, _T("*"));
	m_OpList.InsertString(3, _T("/"));
	m_OpList.SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
