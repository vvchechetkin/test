
// SineGraph.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CSineGraphApp:
// О реализации данного класса см. SineGraph.cpp
//

class CSineGraphApp : public CWinApp
{
public:
	CSineGraphApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CSineGraphApp theApp;