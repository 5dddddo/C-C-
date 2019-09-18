
// bouncingBallView.cpp : CbouncingBallView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
//	ON_WM_TIMER()
ON_WM_DESTROY()
ON_WM_TIMER()
END_MESSAGE_MAP()

// CbouncingBallView 생성/소멸

CbouncingBallView::CbouncingBallView()
	: R(30)
	, STEP(10)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CbouncingBallView::~CbouncingBallView()
{
}

BOOL CbouncingBallView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CbouncingBallView 그리기

void CbouncingBallView::OnDraw(CDC* /*pDC*/)
{
	CbouncingBallDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CbouncingBallView 인쇄

BOOL CbouncingBallView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CbouncingBallView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CbouncingBallView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CbouncingBallView 진단

#ifdef _DEBUG
void CbouncingBallView::AssertValid() const
{
	CView::AssertValid();
}

void CbouncingBallView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CbouncingBallDoc* CbouncingBallView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CbouncingBallDoc)));
	return (CbouncingBallDoc*)m_pDocument;
}
#endif //_DEBUG


// CbouncingBallView 메시지 처리기


void CbouncingBallView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	SetTimer(0, 50, NULL);
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
}


void CbouncingBallView::OnDestroy()
{
	CView::OnDestroy();
	KillTimer(0);
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}


void CbouncingBallView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);
	static int nX = R, nY = R;
	static int nCX = STEP, nCY = STEP;

	CRect rect;
	GetClientRect(&rect);
	// 이전공 지우기
	dc.SelectStockObject(WHITE_BRUSH);
	dc.Ellipse(nX - R, nY - R, nX + R, nY + R);

	// X 좌표 변경
	// Y 좌표 변경
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
