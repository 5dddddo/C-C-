
// bouncingBallView.cpp : CbouncingBallView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "bouncingBall.h"
#endif

#include "bouncingBallDoc.h"
#include "bouncingBallView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CbouncingBallView

IMPLEMENT_DYNCREATE(CbouncingBallView, CView)

BEGIN_MESSAGE_MAP(CbouncingBallView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
//	ON_WM_TIMER()
ON_WM_DESTROY()
ON_WM_TIMER()
END_MESSAGE_MAP()

// CbouncingBallView ����/�Ҹ�

CbouncingBallView::CbouncingBallView()
	: R(30)
	, STEP(10)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CbouncingBallView::~CbouncingBallView()
{
}

BOOL CbouncingBallView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CbouncingBallView �׸���

void CbouncingBallView::OnDraw(CDC* /*pDC*/)
{
	CbouncingBallDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CbouncingBallView �μ�

BOOL CbouncingBallView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CbouncingBallView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CbouncingBallView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CbouncingBallView ����

#ifdef _DEBUG
void CbouncingBallView::AssertValid() const
{
	CView::AssertValid();
}

void CbouncingBallView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CbouncingBallDoc* CbouncingBallView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CbouncingBallDoc)));
	return (CbouncingBallDoc*)m_pDocument;
}
#endif //_DEBUG


// CbouncingBallView �޽��� ó����


void CbouncingBallView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	SetTimer(0, 50, NULL);
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
}


void CbouncingBallView::OnDestroy()
{
	CView::OnDestroy();
	KillTimer(0);
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
}


void CbouncingBallView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CClientDC dc(this);
	static int nX = R, nY = R;
	static int nCX = STEP, nCY = STEP;

	CRect rect;
	GetClientRect(&rect);
	// ������ �����
	dc.SelectStockObject(WHITE_BRUSH);
	dc.Ellipse(nX - R, nY - R, nX + R, nY + R);

	// X ��ǥ ����
	// Y ��ǥ ����
	if (nX<R) nCX = STEP;
	else if (nX >rect.Width() - R) nCX = -STEP;
	nX += nCX;

	if (nY<R) nCY = STEP;
	else if (nY > rect.Height() - R) nCY = -STEP;
	nY += nCY;

	// Red pen
	CBrush brush, *pOldBrush;
	brush.CreateSolidBrush(RGB(255, 0, 0));

	pOldBrush = (CBrush *)dc.SelectObject(&brush);
	dc.Ellipse(nX - R, nY - R, nX + R, nY + R);
	dc.SelectObject(pOldBrush);

	CView::OnTimer(nIDEvent);
}
