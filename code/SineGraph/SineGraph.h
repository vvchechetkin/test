
// SineGraph.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CSineGraphApp:
// � ���������� ������� ������ ��. SineGraph.cpp
//

class CSineGraphApp : public CWinApp
{
public:
	CSineGraphApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CSineGraphApp theApp;