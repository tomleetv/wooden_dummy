#pragma once
#include "TCamera.h"

class TBackViewCamera : public TCamera
{
public:		
	//--------------------------------------------------------------------------------------
	// ī�޶� ��ġ ���� 
	//--------------------------------------------------------------------------------------
	void				MoveLook( float fValue );
	void				MoveSide( float fValue );	
	void				MoveUp( float fValue );	
	//--------------------------------------------------------------------------------------
	// ���Ϸ� ���� ���� �� ��� ��� 
	//--------------------------------------------------------------------------------------
	D3DXMATRIX			Update( float fElapseTime );

	//--------------------------------------------------------------------------------------
	// ī�޶� �����̵��� ��ǥ����.
	//--------------------------------------------------------------------------------------
	// �߰�
	D3DXVECTOR3			m_vCameraDestination;
	// ���� ���� ��ȯ ����� ���⺤��
	D3DXVECTOR3			m_vObjectVector[3];
	float				m_fPrevRadius;

public:

	//--------------------------------------------------------------------------------------
	// �� ��� ���  
	//--------------------------------------------------------------------------------------
	D3DXMATRIX			SetViewMatrix( D3DXVECTOR3 vPos, D3DXVECTOR3 vTarget, D3DXVECTOR3 vUp = D3DXVECTOR3( 0.0f, 1.0f, 0.0f ));	

public:
	TBackViewCamera(void);
	virtual ~TBackViewCamera(void);
};