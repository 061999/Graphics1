#pragma once
#include "Graphics.h"
class VertexBuffer
{
public:
	VertexBuffer(Graphics * g);
private:
	ID3D11Buffer* pVertexBuffer = nullptr;
};

