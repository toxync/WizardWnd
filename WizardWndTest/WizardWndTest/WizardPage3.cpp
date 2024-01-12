// WizardPage3.cpp: 구현 파일
#include "pch.h"
#include "WizardWndTest.h"
#include "afxdialogex.h"
#include "WizardPage3.h"


// WizardPage3 대화 상자
IMPLEMENT_DYNAMIC(WizardPage3, CDialogEx)

WizardPage3::WizardPage3(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PAGE3, pParent)
{

}

WizardPage3::~WizardPage3()
{
}

void WizardPage3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(WizardPage3, CDialogEx)
	ON_BN_CLICKED(IDOK, &WizardPage3::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &WizardPage3::OnBnClickedCancel)
END_MESSAGE_MAP()

// WizardPage3 메시지 처리기
void WizardPage3::SetResultValue(int a_result)
{
	SetDlgItemInt(IDC_RESULT_EDIT, a_result);
}

void WizardPage3::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// CDialogEx::OnOK();
}

void WizardPage3::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// CDialogEx::OnCancel();
}

BOOL WizardPage3::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	SetBackgroundColor(RGB(228, 160, 232));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
