
// SineGraphDlg.h : файл заголовка
//

#pragma once
#include <gdiplus.h>
#include "DrawArea.h"
#include "afxwin.h"

// диалоговое окно CSineGraphDlg
class CSineGraphDlg : public CDialogEx
{
// Создание
public:
	CSineGraphDlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
	enum { IDD = IDD_SINEGRAPH_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedDrawgraph();
	DrawArea drawAreaObj;


	afx_msg void OnBnClickedAnimation();
	double m_freq;
	double m_freqdif;
	bool bAnim = false;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CEdit m_freqBox;
	CEdit m_freqdifBox;
	CButton m_plotBtn;
};
