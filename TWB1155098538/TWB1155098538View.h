
// TWB1155098538View.h : interface of the CTWB1155098538View class
//

#pragma once


class CTWB1155098538View : public CView
{
protected: // create from serialization only
	CTWB1155098538View();
	DECLARE_DYNCREATE(CTWB1155098538View)

// Attributes
public:
	CTWB1155098538Doc* GetDocument() const;
	HGLRC m_hRC;
	CDC* m_pDC;
	float xtrans, ytrans, ztrans;
	CPoint current_point;
	CPoint last_point;
	float xrot, yrot, zrot;
	float m_fScale;
	long POLY_MODE;
// Operations
public:
	bool InitializeOpenGL();
	bool SetupPixelFormat();
	bool SetupViewingFrustum(double aspect);
	bool SetupViewingTransform();
	bool RenderScene();
	bool Lighting();
	bool Material();
	vector<float> n1;
	vector<float> n2;
	vector<float> n3;
	vector<float> t1;
	vector<float> t2;
	vector<float> t3;
	float eyex, eyey, eyez, objx, objy, objz, dirx, diry, dirz;
	float fovy,fnear,ffar;
	float onsize;
// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CTWB1155098538View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTranslateXp();
	afx_msg void OnTranslateXn();
	afx_msg void OnTranslateYp();
	afx_msg void OnTranlateYn();
	afx_msg void OnTranslateZp();
	afx_msg void OnTranslateZn();
	afx_msg void OnRotateXp();
	afx_msg void OnRotateXn();
	afx_msg void OnRotateYp();
	afx_msg void OnRotateYn();
	afx_msg void OnRotateZp();
	afx_msg void OnRotateZn();
	afx_msg void OnZoomIn();
	afx_msg void OnZoomOut();
	afx_msg void OnShading();
	afx_msg void OnWireframe();
	afx_msg void OnReset();
	afx_msg void OnFileOpen();
	afx_msg void OnDestroy();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
};

#ifndef _DEBUG  // debug version in TWB1155098538View.cpp
inline CTWB1155098538Doc* CTWB1155098538View::GetDocument() const
   { return reinterpret_cast<CTWB1155098538Doc*>(m_pDocument); }
#endif

