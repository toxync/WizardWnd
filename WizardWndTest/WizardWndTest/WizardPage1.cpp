// WizardPage1.cpp: 구현 파일
#include "pch.h"
#include "WizardWndTest.h"
#include "afxdialogex.h"
#include "WizardPage1.h"


// WizardPage1 대화 상자
IMPLEMENT_DYNAMIC(WizardPage1, CDialogEx)

WizardPage1::WizardPage1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PAGE1, pParent)
{

}

WizardPage1::~WizardPage1()
{
}

void WizardPage1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(WizardPage1, CDialogEx)
	ON_BN_CLICKED(IDOK, &WizardPage1::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &WizardPage1::OnBnClickedCancel)
END_MESSAGE_MAP()

// WizardPage1 메시지 처리기
void WizardPage1::GetNumData(int* ap_num1, int* ap_num2)
{
	*ap_num1 = GetDlgItemInt(IDC_NUM1_EDIT);
	*ap_num2 = GetDlgItemInt(IDC_NUM2_EDIT);
}

void WizardPage1::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// CDialogEx::OnOK();
}

void WizardPage1::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// CDialogEx::OnCancel();
}

BOOL WizardPage1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	SetBackgroundColor(RGB(228, 232, 200));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
