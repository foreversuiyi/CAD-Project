
// TWB1155098538View.cpp : implementation of the CTWB1155098538View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TWB1155098538.h"
#endif

#include "TWB1155098538Doc.h"
#include "TWB1155098538View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTWB1155098538View

IMPLEMENT_DYNCREATE(CTWB1155098538View, CView)

BEGIN_MESSAGE_MAP(CTWB1155098538View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_Translate_XP, &CTWB1155098538View::OnTranslateXp)
	ON_COMMAND(ID_Translate_XN, &CTWB1155098538View::OnTranslateXn)
	ON_COMMAND(ID_Translate_YP, &CTWB1155098538View::OnTranslateYp)
	ON_COMMAND(ID_Tranlate_YN, &CTWB1155098538View::OnTranlateYn)
	ON_COMMAND(ID_Translate_ZP, &CTWB1155098538View::OnTranslateZp)
	ON_COMMAND(ID_Translate_ZN, &CTWB1155098538View::OnTranslateZn)
	ON_COMMAND(ID_Rotate_XP, &CTWB1155098538View::OnRotateXp)
	ON_COMMAND(ID_Rotate_XN, &CTWB1155098538View::OnRotateXn)
	ON_COMMAND(ID_Rotate_YP, &CTWB1155098538View::OnRotateYp)
	ON_COMMAND(ID_Rotate_YN, &CTWB1155098538View::OnRotateYn)
	ON_COMMAND(ID_Rotate_ZP, &CTWB1155098538View::OnRotateZp)
	ON_COMMAND(ID_Rotate_ZN, &CTWB1155098538View::OnRotateZn)
	ON_COMMAND(ID_Zoom_In, &CTWB1155098538View::OnZoomIn)
	ON_COMMAND(ID_Zoom_Out, &CTWB1155098538View::OnZoomOut)
	ON_COMMAND(ID_Shading, &CTWB1155098538View::OnShading)
	ON_COMMAND(ID_Wireframe, &CTWB1155098538View::OnWireframe)
	ON_COMMAND(ID_Reset, &CTWB1155098538View::OnReset)
	ON_COMMAND(ID_FILE_OPEN, &CTWB1155098538View::OnFileOpen)
	ON_WM_DESTROY()
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_KEYDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSEWHEEL()
END_MESSAGE_MAP()

// CTWB1155098538View construction/destruction

CTWB1155098538View::CTWB1155098538View()
{
	// TODO: add construction code here
	m_hRC = 0;
	m_pDC = 0;
	xtrans = 0.0;
	ytrans = 0.0;
	ztrans = 0.0;
	xrot = 0.0;
	yrot = 0.0;
	zrot = 0.0;
	m_fScale = 1.0;
	POLY_MODE = GL_FILL;
	eyex = 0.0;
	eyey = 0.0;
	eyez = 10.0;
	objx = 0.0;
	objy = 0.0;
	objz = 0.0;
	dirx = 0.0;
	diry = 1.0;
	dirz = 0.0;
	fovy = 60.0;
	fnear = 0.01;
	ffar = 1000;
}

CTWB1155098538View::~CTWB1155098538View()
{
}

BOOL CTWB1155098538View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CTWB1155098538View drawing

void CTWB1155098538View::OnDraw(CDC* /*pDC*/)
{
	CTWB1155098538Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	SetupViewingFrustum(onsize);
	SetupViewingTransform();
	glScalef(m_fScale, m_fScale, m_fScale);
	glTranslatef(xtrans, ytrans, ztrans);
	glRotatef(xrot, 1, 0, 0);
	glRotatef(yrot, 0, 1, 0);
	glRotatef(zrot, 0, 0, 1);
	RenderScene();
	::SwapBuffers(m_pDC->GetSafeHdc());
	// TODO: add draw code for native data here
}


// CTWB1155098538View printing

BOOL CTWB1155098538View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTWB1155098538View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTWB1155098538View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CTWB1155098538View diagnostics

#ifdef _DEBUG
void CTWB1155098538View::AssertValid() const
{
	CView::AssertValid();
}

void CTWB1155098538View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTWB1155098538Doc* CTWB1155098538View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTWB1155098538Doc)));
	return (CTWB1155098538Doc*)m_pDocument;
}
#endif //_DEBUG


// CTWB1155098538View message handlers


void CTWB1155098538View::OnTranslateXp()
{
	xtrans += 1.0;
	InvalidateRect(0, FALSE);
	//AfxMessageBox("You have pressed the ¡°Translation X+¡± selection in the menu.");
	// TODO: Add your command handler code here
}


void CTWB1155098538View::OnTranslateXn()
{
	xtrans -= 1.0;
	InvalidateRect(0, FALSE);
	//AfxMessageBox("You have pressed the ¡°Translation X-¡± selection in the menu.");
	// TODO: Add your command handler code here
}


void CTWB1155098538View::OnTranslateYp()
{
	ytrans += 1.0;
	InvalidateRect(0, FALSE);
	//AfxMessageBox("You have pressed the ¡°Translation Y+¡± selection in the menu.");
	// TODO: Add your command handler code here
}


void CTWB1155098538View::OnTranlateYn()
{
	ytrans -= 1.0;
	InvalidateRect(0, FALSE);
	//AfxMessageBox("You have pressed the ¡°Translation Y-¡± selection in the menu.");
	// TODO: Add your command handler code here
}


void CTWB1155098538View::OnTranslateZp()
{
	ztrans += 1.0;
	InvalidateRect(0, FALSE);
	//AfxMessageBox("You have pressed the ¡°Translation Z+¡± selection in the menu.");
	// TODO: Add your command handler code here
}


void CTWB1155098538View::OnTranslateZn()
{
	ztrans -= 1.0;
	InvalidateRect(0, FALSE);
	//AfxMessageBox("You have pressed the ¡°Translation Z-¡± selection in the menu.");
	// TODO: Add your command handler code here
}


void CTWB1155098538View::OnRotateXp()
{
	xrot += 5;
	InvalidateRect(0, FALSE);
	//AfxMessageBox("You have pressed the ¡°Rotation X+¡± selection in the menu.");
	// TODO: Add your command handler code here
}


void CTWB1155098538View::OnRotateXn()
{
	xrot -= 5;
	InvalidateRect(0, FALSE);
	//AfxMessageBox("You have pressed the ¡°Rotation X-¡± selection in the menu.");
	// TODO: Add your command handler code here
}


void CTWB1155098538View::OnRotateYp()
{
	yrot += 5;
	InvalidateRect(0, FALSE);
	//AfxMessageBox("You have pressed the ¡°Rotation Y+¡± selection in the menu.");
	// TODO: Add your command handler code here
}


void CTWB1155098538View::OnRotateYn()
{
	yrot -= 5;
	InvalidateRect(0, FALSE);
	//AfxMessageBox("You have pressed the ¡°Rotation Y-¡± selection in the menu.");
	// TODO: Add your command handler code here
}


void CTWB1155098538View::OnRotateZp()
{
	zrot += 5;
	InvalidateRect(0, FALSE);
	//AfxMessageBox("You have pressed the ¡°Rotation Z+¡± selection in the menu.");
	// TODO: Add your command handler code here
}


void CTWB1155098538View::OnRotateZn()
{
	zrot -= 5;
	InvalidateRect(0, FALSE);
	//AfxMessageBox("You have pressed the ¡°Rotation Z-¡± selection in the menu.");
	// TODO: Add your command handler code here
}


void CTWB1155098538View::OnZoomIn()
{
	m_fScale += 0.1;
	InvalidateRect(0, FALSE);
	//AfxMessageBox("You have pressed the ¡°Zoom In¡± selection in the menu.");
	// TODO: Add your command handler code here
}


void CTWB1155098538View::OnZoomOut()
{
	m_fScale -= 0.1;
	InvalidateRect(0, FALSE);
	//AfxMessageBox("You have pressed the ¡°Zoom Out¡± selection in the menu.");
	// TODO: Add your command handler code here
}


void CTWB1155098538View::OnShading()
{
	POLY_MODE = GL_FILL;
	InvalidateRect(0, FALSE);
	//AfxMessageBox("You have pressed the ¡°Shading Display¡± selection in the menu.");
	// TODO: Add your command handler code here
}


void CTWB1155098538View::OnWireframe()
{
	POLY_MODE = GL_LINE;
	InvalidateRect(0, FALSE);
	//AfxMessageBox("You have pressed the ¡°Wireframe Display¡± selection in the menu.");
	// TODO: Add your command handler code here
}


void CTWB1155098538View::OnReset()
{
	xtrans = 0.0;
	ytrans = 0.0;
	ztrans = 0.0;
	xrot = 0.0;
	yrot = 0.0;
	zrot = 0.0;
	m_fScale = 1.0;
	POLY_MODE = GL_FILL;
	InvalidateRect(0, FALSE);
	//AfxMessageBox("You have pressed the ¡°Reset Display¡± selection in the menu.");
	// TODO: Add your command handler code here
}


void CTWB1155098538View::OnFileOpen()
{
	ifstream in;
	CString szFilter;
	szFilter = "stl|*.stl|*.*|*.*||";
	CFileDialog FD(TRUE, _T("stl"), _T("*.stl"), OFN_HIDEREADONLY, szFilter);
	if (FD.DoModal() == IDOK)
	{
		in.open(FD.GetPathName());
		string tmp;
		in >> tmp;
		vector <float>().swap(t1);
		vector <float>().swap(t2);
		vector <float>().swap(t3);
		vector <float>().swap(n1);
		vector <float>().swap(n2);
		vector <float>().swap(n3);
		float a, b, c;
		while (!in.eof())
		{
			if (!tmp.compare("normal"))
			{
				in >> a >> b >> c;
				n1.push_back(a);
				n2.push_back(b);
				n3.push_back(c);
			}
			if (!tmp.compare("vertex"))
			{
				in >> a >> b >> c;
				t1.push_back(a);
				t2.push_back(b);
				t3.push_back(c);
			}
			in >> tmp;
		}
		in.close();
	}
	objx = accumulate(t1.begin(), t1.end(), 0.0) / t1.size();
	objy = accumulate(t2.begin(), t2.end(), 0.0) / t2.size();
	objz = accumulate(t3.begin(), t3.end(), 0.0) / t3.size();
	eyex = objx;
	eyey = objy;
	vector<float>::iterator max = max_element(t3.begin(), t3.end());
	vector<float>::iterator min = min_element(t3.begin(), t3.end());
	eyez = *max + *max - *min;
	ffar = eyez-*min+2*(*max-*min);
	InvalidateRect(0, FALSE);
	// TODO: Add your command handler code here
}

bool CTWB1155098538View::InitializeOpenGL()
{
	m_pDC = new CClientDC(this);
	if (m_pDC == NULL)
		return false;
	if (!SetupPixelFormat())
		return false;
	m_hRC = ::wglCreateContext(m_pDC->GetSafeHdc());
	if ((m_hRC) == 0)
		return false;
	if (!(::wglMakeCurrent(m_pDC->GetSafeHdc(), m_hRC)))
		return false;
	return true;
}

bool CTWB1155098538View::SetupPixelFormat()
{
	static PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof(PIXELFORMATDESCRIPTOR),
		1,
		PFD_DRAW_TO_WINDOW |
		PFD_SUPPORT_OPENGL |
		PFD_DOUBLEBUFFER |
		PFD_TYPE_RGBA,
		24,
		0,0,0,0,0,0,
		0,
		0,
		0,
		0,0,0,0,
		16,
		0,
		0,
		PFD_MAIN_PLANE,
		0,
		0,0,0
	};
	int pixelformat;
	if ((pixelformat = ::ChoosePixelFormat(m_pDC->GetSafeHdc(), &pfd)) == 0)
		return false;
	if (!(::SetPixelFormat(m_pDC->GetSafeHdc(), pixelformat, &pfd)))
		return false;
	return true;
}

void CTWB1155098538View::OnDestroy()
{
	CView::OnDestroy();
	::wglMakeCurrent(NULL, NULL);
	::wglDeleteContext(m_hRC);
	if (m_pDC)
		delete m_pDC;
	// TODO: Add your message handler code here
}


int CTWB1155098538View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	if (!InitializeOpenGL())
		return -1;
	if (!Lighting())
		return -1;
	if (!Material())
		return -1;
	return 0;
}


void CTWB1155098538View::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	glViewport(0, 0, cx, cy);
	onsize = (double)cx / (double)cy;
	SetupViewingFrustum(onsize);
	// TODO: Add your message handler code here
}

bool CTWB1155098538View::SetupViewingFrustum(double aspect)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fovy, aspect, fnear, ffar);
	return TRUE;
}

bool CTWB1155098538View::SetupViewingTransform()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyex, eyey, eyez,
		objx, objy, objz,
		dirx, diry, dirz);
	return TRUE;
}

bool CTWB1155098538View::RenderScene()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK, POLY_MODE);
	glShadeModel(GL_SMOOTH);
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < n1.size(); i++)
	{
		glNormal3f(n1[i], n2[i], n3[i]);
		glVertex3f(t1[i * 3], t2[i * 3], t3[i * 3]);
		glVertex3f(t1[i * 3 + 1], t2[i * 3 + 1], t3[i * 3 + 1]);
		glVertex3f(t1[i * 3 + 2], t2[i * 3 + 2], t3[i * 3 + 2]);
	}
	glEnd();
	return true;
}

bool CTWB1155098538View::Lighting()
{
	glEnable(GL_LIGHTING);
	glEnable(GL_NORMALIZE);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHT0);
	GLfloat light_position[] = { 0.0f,30.0f,50.0f,0.0f };
	GLfloat light_ambient[] = { 0.0f,0.0f,0.0f,1.0f };
	GLfloat light_diffuse[] = {1.0f,1.0f,1.0f,1.0f};
	GLfloat light_specular[] = { 1.0f,1.0f,1.0f,1.0f };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	return true;
}

bool CTWB1155098538View::Material()
{
	//glEnable(GL_COLOR_MATERIAL); ///Set the object's color with glColor3f();
	//glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE); /// With using glColor3f(),
	GLfloat mat_diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };
	GLfloat mat_specular[] = { 0.2f,0.2f,0.2f,1.0f };
	GLfloat mat_shininess[] = { 50.0f };
	GLfloat mat_emission[] = { 0.2f, 0.2f, 0.2, 1.0f };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
	return TRUE;
}

void CTWB1155098538View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
	switch (nChar)
	{
	case VK_RIGHT:xtrans += 0.1;
		break;
	case VK_LEFT: xtrans -= 0.1;
		break;
	case VK_UP: ytrans += 0.1;
		break;
	case VK_DOWN: ytrans -= 0.1;
		break;
	}
	// Redraw the scene once
	InvalidateRect(0, FALSE);
}


void CTWB1155098538View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CView::OnMouseMove(nFlags, point);
	current_point = point;
	if (nFlags == MK_LBUTTON && current_point.y > last_point.y + 2)
		xrot += 5;
	else
		if (nFlags == MK_LBUTTON && current_point.y < last_point.y - 2)
			xrot -= 5;
	//check the location of cursor in x direction to perform rotation about y axis
	if (nFlags == MK_LBUTTON && current_point.x > last_point.x + 2)
		yrot += 5;
	else
		if (nFlags == MK_LBUTTON && current_point.x < last_point.x - 2)
			yrot -= 5;
	last_point = point; //record the last point
	InvalidateRect(0, FALSE);
}


BOOL CTWB1155098538View::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: Add your message handler code here and/or call default
	if (zDelta > 0)
		m_fScale += 0.1f;
	else
		if (m_fScale > 0.1f)
			m_fScale -= 0.1f;
	InvalidateRect(NULL, FALSE);
	return CView::OnMouseWheel(nFlags, zDelta, pt);
}
