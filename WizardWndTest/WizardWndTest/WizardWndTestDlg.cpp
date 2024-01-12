// WizardWndTestDlg.cpp: 구현 파일
#include "pch.h"
#include "framework.h"
#include "WizardWndTest.h"
#include "WizardWndTestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWizardWndTestDlg 대화 상자



CWizardWndTestDlg::CWizardWndTestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_WIZARDWNDTEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWizardWndTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CWizardWndTestDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_PREV_BTN, &CWizardWndTestDlg::OnBnClickedPrevBtn)
	ON_BN_CLICKED(IDC_NEXT_BTN, &CWizardWndTestDlg::OnBnClickedNextBtn)
END_MESSAGE_MAP()


// CWizardWndTestDlg 메시지 처리기
void CWizardWndTestDlg::AddPage(CDialogEx* ap_page, int a_index, int a_dlg_id)
{
	mp_Page[a_index] = ap_page;
	mp_Page[a_index]->Create(a_dlg_id, this);
	mp_Page[a_index]->SetWindowPos(NULL, m_WizardRect.left, m_WizardRect.top,
		m_WizardRect.Width(), m_WizardRect.Height(), 0);
}

BOOL CWizardWndTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	GetDlgItem(IDC_WIZARD_RECT)->GetWindowRect(&m_WizardRect);
	ScreenToClient(&m_WizardRect);
	AddPage(new WizardPage1, 0, IDD_PAGE1);
	AddPage(new WizardPage2, 1, IDD_PAGE2);
	AddPage(new WizardPage3, 2, IDD_PAGE3);
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CWizardWndTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CWizardWndTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CWizardWndTestDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	for (int i = 0; i < MAX_PAGE_COUNT; ++i)
	{
		mp_Page[i]->DestroyWindow();
		delete mp_Page[i];
	}
}

void CWizardWndTestDlg::OnBnClickedPrevBtn()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_PageIndex > 0)
	{
		--m_PageIndex;
		// 이동하기 전 자식 다이얼로그를 감추고 이동한 자식 다이얼로그를 표시
		mp_Page[m_PageIndex]->ShowWindow(SW_SHOWNA); // 이동한 자식 다이얼로그를 비활성화된 상태로 표시
		mp_Page[m_PageIndex + 1]->ShowWindow(SW_HIDE);
		// 이동한 자식 다이얼로그가 첫 번째 자식 다이얼로그라면 "이전 페이지로" 버튼 비활성화
		if (m_PageIndex == 0)
		{
			GetDlgItem(IDC_PREV_BTN)->EnableWindow(FALSE);
		}
		// 이동한 자식 다이얼로그가 마지막 이전 자식 다이얼로그라면 "다음 페이지로" 버튼 활성화
		else if (m_PageIndex == MAX_PAGE_COUNT - 2)
		{
			GetDlgItem(IDC_NEXT_BTN)->EnableWindow(TRUE);
		}
	}
}

void CWizardWndTestDlg::OnBnClickedNextBtn()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_PageIndex < MAX_PAGE_COUNT - 1)
	{
		++m_PageIndex;
		// 이동하기 전 자식 다이얼로그를 감추고 이동한 자식 다이얼로그를 표시
		mp_Page[m_PageIndex]->ShowWindow(SW_SHOWNA); // 이동한 자식 다이얼로그를 비활성화된 상태로 표시
		mp_Page[m_PageIndex - 1]->ShowWindow(SW_HIDE);
		// 이동한 자식 다이얼로그가 마지막 자식 다이얼로그라면
		if (m_PageIndex == MAX_PAGE_COUNT - 1)
		{
			// "다음 페이지로" 버튼 비활성화
			GetDlgItem(IDC_NEXT_BTN)->EnableWindow(FALSE);
			int result = 0;
			// 두 번째 자식 다이얼로그의 선택된 리스트 박스 항목을 가져와서 연산 결과를
			// 마지막 자식 다이얼로그의 에디트 컨트롤에 표시함
			switch (((WizardPage2*)mp_Page[m_PageIndex - 1])->GetOpType())
			{
			case 0:
				result = m_Num1 + m_Num2;
				break;
			case 1:
				result = m_Num1 - m_Num2;
				break;
			case 2:
				result = m_Num1 * m_Num2;
				break;
			case 3:
				if (m_Num2) // 나누는 수가 0이 아닌 경우에만 나누기 수행
				{
					result = m_Num1 / m_Num2;
				}
				break;
			}
			((WizardPage3*)mp_Page[m_PageIndex])->SetResultValue(result);
		}
		// 이동한 자식 다이얼로그가 두 번째 자식 다이얼로그라면
		else if (m_PageIndex == 1)
		{
			// "이전 페이지로" 버튼 활성화
			GetDlgItem(IDC_PREV_BTN)->EnableWindow(TRUE);
			// 첫 번째 자식 다이얼로그의 에디트 컨트롤들로부터 입력된 값 얻어옴
			((WizardPage1*)mp_Page[m_PageIndex - 1])->GetNumData(&m_Num1, &m_Num2);
		}
	}
}
