
// SineGraphDlg.cpp : ���� ����������
//

#include "stdafx.h"
#include "SineGraph.h"
#include "SineGraphDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���������� ���� CSineGraphDlg



CSineGraphDlg::CSineGraphDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSineGraphDlg::IDD, pParent)
	, m_freq(100)
	, m_freqdif(10)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSineGraphDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DRAWAREA, drawAreaObj);
	DDX_Text(pDX, IDC_FREQ, m_freq);
	DDX_Text(pDX, IDC_FREQDIF, m_freqdif);
	DDX_Control(pDX, IDC_FREQ, m_freqBox);
	DDX_Control(pDX, IDC_FREQDIF, m_freqdifBox);
	DDX_Control(pDX, IDC_DRAWGRAPH, m_plotBtn);
}

BEGIN_MESSAGE_MAP(CSineGraphDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_DRAWGRAPH, &CSineGraphDlg::OnBnClickedDrawgraph)
	ON_BN_CLICKED(IDC_ANIMATION, &CSineGraphDlg::OnBnClickedAnimation)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// ����������� ��������� CSineGraphDlg

BOOL CSineGraphDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ������ ������ ��� ����� ����������� ����.  ����� ������ ��� �������������,
	//  ���� ������� ���� ���������� �� �������� ����������
	SetIcon(m_hIcon, TRUE);			// ������� ������
	SetIcon(m_hIcon, FALSE);		// ������ ������

	// TODO: �������� �������������� �������������

	return TRUE;  // ������� �������� TRUE, ���� ����� �� ������� �������� ����������
}

// ��� ���������� ������ ����������� � ���������� ���� ����� ��������������� ����������� ���� �����,
//  ����� ���������� ������.  ��� ���������� MFC, ������������ ������ ���������� ��� �������������,
//  ��� ������������� ����������� ������� ��������.

void CSineGraphDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �������� ���������� ��� ���������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ������������ ������ �� ������ ����������� ��������������
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ��������� ������
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ������� �������� ��� ������� ��� ��������� ����������� ������� ��� �����������
//  ���������� ����.
HCURSOR CSineGraphDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSineGraphDlg::OnBnClickedDrawgraph()
{
	// TODO: �������� ���� ��� ����������� �����������

	UpdateData(TRUE);
	drawAreaObj.SetSineInfo(m_freq,m_freqdif);
	drawAreaObj.ResetPhase();
	drawAreaObj.Invalidate();



}


void CSineGraphDlg::OnBnClickedAnimation()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (!bAnim)
	{
		drawAreaObj.SetSineInfo(m_freq, m_freqdif);
		SetTimer(111, 50, NULL);
		bAnim = !bAnim;
		
		m_freqBox.SetReadOnly(TRUE);
		m_freqdifBox.SetReadOnly(TRUE);
		m_plotBtn.EnableWindow(FALSE);

	}
	else
	{
		KillTimer(111);
		bAnim = !bAnim;


		m_freqBox.SetReadOnly(FALSE);
		m_freqdifBox.SetReadOnly(FALSE);
		m_plotBtn.EnableWindow(TRUE);
	}

}


void CSineGraphDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default

	drawAreaObj.Invalidate();




	CDialogEx::OnTimer(nIDEvent);
}
