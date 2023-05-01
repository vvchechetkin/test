
// SineGraphDlg.h : ���� ���������
//

#pragma once
#include <gdiplus.h>
#include "DrawArea.h"
#include "afxwin.h"

// ���������� ���� CSineGraphDlg
class CSineGraphDlg : public CDialogEx
{
// ��������
public:
	CSineGraphDlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
	enum { IDD = IDD_SINEGRAPH_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// ��������� DDX/DDV


// ����������
protected:
	HICON m_hIcon;

	// ��������� ������� ����� ���������
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
