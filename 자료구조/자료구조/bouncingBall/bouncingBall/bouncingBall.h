
// bouncingBall.h : bouncingBall ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CbouncingBallApp:
// �� Ŭ������ ������ ���ؼ��� bouncingBall.cpp�� �����Ͻʽÿ�.
//

class CbouncingBallApp : public CWinAppEx
{
public:
	CbouncingBallApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CbouncingBallApp theApp;
