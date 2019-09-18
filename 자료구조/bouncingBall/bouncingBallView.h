
// bouncingBallView.h : CbouncingBallView Ŭ������ �������̽�
//

#pragma once


class CbouncingBallView : public CView
{
protected: // serialization������ ��������ϴ�.
	CbouncingBallView();
	DECLARE_DYNCREATE(CbouncingBallView)

// Ư���Դϴ�.
public:
	CbouncingBallDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CbouncingBallView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual void OnInitialUpdate();
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
private:
	int R;
	int STEP;
};

#ifndef _DEBUG  // bouncingBallView.cpp�� ����� ����
inline CbouncingBallDoc* CbouncingBallView::GetDocument() const
   { return reinterpret_cast<CbouncingBallDoc*>(m_pDocument); }
#endif

