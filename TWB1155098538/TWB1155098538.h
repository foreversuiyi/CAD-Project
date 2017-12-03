
// TWB1155098538.h : main header file for the TWB1155098538 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CTWB1155098538App:
// See TWB1155098538.cpp for the implementation of this class
//

class CTWB1155098538App : public CWinApp
{
public:
	CTWB1155098538App();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTWB1155098538App theApp;
