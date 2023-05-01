
// SineGraphDlg.cpp : файл реализации
//

#include "stdafx.h"
#include "SineGraph.h"
#include "SineGraphDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// диалоговое окно CSineGraphDlg



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


// обработчики сообщений CSineGraphDlg

BOOL CSineGraphDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CSineGraphDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CSineGraphDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSineGraphDlg::OnBnClickedDrawgraph()
{
	// TODO: добавьте свой код обработчика уведомлений

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
