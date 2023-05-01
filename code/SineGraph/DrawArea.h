#pragma once


// DrawArea

class DrawArea : public CStatic
{
	DECLARE_DYNAMIC(DrawArea)

public:
	DrawArea();
	virtual ~DrawArea();

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	ULONG_PTR token;
	float freqDif;
	void SetSineInfo(float freq, float freqDif);
	
	void ResetPhase();
	

private:
	float dw=10; //�������� ������
	float w=100; //������� 
	unsigned long int phaseIncr=0; //������� � ���� ��� ��������
};


