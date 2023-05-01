// DrawArea.cpp: ���� ����������
//

#include "stdafx.h"
#include "SineGraph.h"
#include "DrawArea.h"


using namespace Gdiplus;


// DrawArea

IMPLEMENT_DYNAMIC(DrawArea, CStatic)


DrawArea::DrawArea()
{

	GdiplusStartupInput input;
	Status s;

	s = GdiplusStartup(&token, &input, NULL);
	


}

DrawArea::~DrawArea()
{


	GdiplusShutdown(token);


}



BEGIN_MESSAGE_MAP(DrawArea, CStatic)
END_MESSAGE_MAP()



// ����������� ��������� DrawArea




void DrawArea::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{

	// TODO:  �������� �������� ��� ��� ����������� ���������� ��������

	CRect rect;
	GetClientRect(&rect);

	Bitmap myBitmap(rect.Width(), rect.Height());

	Graphics* grr = Graphics::FromImage(&myBitmap);
	grr->SetSmoothingMode(SmoothingModeAntiAlias);

	Graphics gr(lpDrawItemStruct->hDC);

	

	Matrix mtx; //������� ��������������



	
	int N = 512; //���-�� ����� ��� ����������� ���������
	float xMax = 4 * M_PI / dw; //������ ������� � �����������

	float yCoef = rect.Height() / 4.0f; //�������������� ����������� �� y
	float xCoef = rect.Width() / xMax;	//�������������� ����������� �� x\

	grr->Clear(Color::White); //������� ���� ����� ������

	Pen penAxis(Color::Black, 0.00000001);		//�������� ��� ����
	Pen penCurve(Color::DarkCyan, 0.000001);	//�������� ��� �������
	Pen penGrid(Color::LightGray, 0.000001);	//�������� ��� �����




	//��������� ������ ��������� � ������ ����� � ������ ���
	mtx.Translate(0.04f*rect.Width(), (0.95f)*rect.Height());
	mtx.Scale(0.92f*xCoef, -0.9f*yCoef);
	grr->SetTransform(&mtx);
	

	//��������� �����
	int GridLinesCount=12;
	PointF pt;
	CString str;

	Gdiplus::Font font(L"Arial", 10, FontStyleRegular, UnitPixel); //������� �����
	SolidBrush brText(Color::Black); //����� ��� ������


	for (int i = 0; i <= GridLinesCount; i++)
	{
		
		grr->DrawLine(&penGrid, xMax / GridLinesCount * i*1.0f, 0.0f, xMax / GridLinesCount * i*1.0f, 4.0f);
		grr->DrawLine(&penGrid, 0.0f, 4.0f / GridLinesCount * i, xMax, 4.0f / GridLinesCount * i);
		grr->ResetTransform();
		
		pt.X = 0.0f;
		pt.Y = 4.0f / GridLinesCount * i;
		str.Format(_T("%.1f"), pt.Y - 2.0f);

		mtx.TransformPoints(&pt);
		pt.X = pt.X - 25;
		pt.Y = pt.Y - 5;
	
		grr->DrawString(str, -1, &font, pt, &brText);

		pt.X = xMax / GridLinesCount * i;
		pt.Y = 0.0f;

		str.Format(_T("%.2f"), pt.X);
		mtx.TransformPoints(&pt);

	
		grr->DrawString(str, -1, &font, pt, &brText);

		grr->SetTransform(&mtx);


	}
	
	
	grr->DrawLine(&penAxis, 0.0f, 0.0f, xMax, 0.0f);
	grr->DrawLine(&penAxis, 0.0f, 0.0f, 0.0f, 4.0f);



	//������� � ������ ��������� � ��������������� � ������������ � ����������� ���������
	mtx.Reset();
	mtx.Translate(0.04f*rect.Width(), 0.5f*rect.Height());
	mtx.Scale(0.92f*xCoef, -0.9f*yCoef);
	
	grr->SetTransform(&mtx);

	float dx = xMax / N; //��� �� x
	float y, yprev;
	/*
	for (int i = 0; i < N; i++)
	{
		yprev = yCoef * (cos(100*dx*i) + cos(110 * dx*i));
		y = yCoef*(cos(100 *dx*(i + 1)) + cos(110 *dx*(i + 1)));
		gr.DrawLine(&pen, i*dx*xCoef, yprev, dx*(i + 1)*xCoef, y);
	}
	*/

	//��������� ���������
	for (int i = 0; i < N; i++)
	{
		yprev = cos(w * i*dx + dx * 20* phaseIncr) + cos((w + dw) * i*dx );
		y = cos(w * dx*(i + 1) + dx *20* phaseIncr) + cos((w + dw) *dx* (i + 1));
		grr->DrawLine(&penCurve, dx*i, yprev, dx*(i + 1), y);
	}


	/*


	Gdiplus::Font font(L"Arial", 10, FontStyleRegular, UnitPixel); //������� �����
	SolidBrush brText(Color::Black); //����� ��� ������

	//�������������� ��� ��������� ������� ��� x
	mtx.Reset();
	mtx.Translate(0.04f*rect.Width(), 0.95f*rect.Height());
	grr->SetTransform(&mtx);

	

	//������� ��� x
	for (int i = 0; i <= GridLinesCount; i++) {
		CString str;
		str.Format(_T("%.2f"), i* xMax / GridLinesCount);
		grr->DrawString(str, -1, &font, PointF(0.9f*rect.Width() / GridLinesCount * i*1.0f, 0.0f), &brText);

	}


	//�������������� ��� ��������� ������� ��� y
	mtx.Reset();
	mtx.Translate(0.04f*rect.Width(), rect.Height()/2);
	grr->SetTransform(&mtx);

	//������� ��� y
	for (REAL i = -8; i <= 8; i++) {
		CString str;
		str.Format(_T("%.1f"), -4.0f/GridLinesCount*i);
		grr->DrawString(str, -1, &font, PointF(-25.0f, -5.0f+0.9f*rect.Height() / GridLinesCount * i*1.0f), &brText);
	}

	*/


	


	gr.DrawImage(&myBitmap, 0, 0, rect.Width(), rect.Height()); //������ ����������� �� ������
	delete grr;

	phaseIncr++; //���������� ���������� ���� ��� ��������

}

void DrawArea::SetSineInfo(float freq, float freqDif)
{

	w = freq;
	dw = freqDif;

}

void DrawArea::ResetPhase()
{
	phaseIncr = 0;
}