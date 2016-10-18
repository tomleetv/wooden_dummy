#pragma once
#include "TBasisStd.h"
#include "TShape.h"

enum T_POSITION
{
	P_BACK = 0,    // Point is positioned behind plane
	P_FRONT,   // Point is positioned in front of plane	
	P_ONPLANE, // Point is positioned on plane
	P_SPANNING // Point is spanning plane
};

class TFrustum 
{
public:
	public:
	bool		Init();
	bool		Frame();
	bool		PreRender(ID3D11DeviceContext*    pImmediateContext);
	bool		PostRender(ID3D11DeviceContext*    pImmediateContext);
	bool		Render(ID3D11DeviceContext*    pImmediateContext);
	bool		Release();
	bool		ResetDevice();
	bool		ResetResource(){return true;};

public:
	D3DXMATRIX  m_matViewProj;
	D3DXMATRIX  m_mWorld;
	D3DXMATRIX  m_mView;
	D3DXMATRIX  m_mProj;
	D3DXVECTOR3	m_vFrustum[8];	/// ���������� ������ ���� 8��
	vector<PNCT_VERTEX> m_VertexList;
	D3DXPLANE	m_DxPlane[6];	/// ���������� �����ϴ� 6���� ���
	T_PLANE		m_Plane[6];
	D3DXVECTOR3	m_vNearCenter;
	TBoxShape*	m_pBoxShape;
	ID3D11Device*		m_pd3dDevice;
	ComPtr<ID3D11PixelShader>  m_pPixelShader;
public:
	void	SetMatrix( D3DXMATRIX* pWorld, D3DXMATRIX* pView, D3DXMATRIX* pProj );
	bool	CreateRenderBox(ID3D11Device*  pd3dDevice,ID3D11DeviceContext*    pImmediateContext);
	bool	CreateFrustum();
	void	ExtractPlanesD3D( T_PLANE* pPlanes, const D3DXMATRIX & comboMatrix);
	BOOL	ClassifyPoint( D3DXVECTOR3* pv );
	BOOL	ClassifySphere( T_SPHERE* pSphere );
	BOOL	CheckOBBInPlane( T_BOX*  pBox );
	T_POSITION CheckPoitionOBBInPlane( T_BOX*  pBox );
public:
	/// ������
	TFrustum();
	virtual ~TFrustum();
};