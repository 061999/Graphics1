#pragma once
#include "Graphics.h"
class IndexBuffer
{
public:
	IndexBuffer(Graphics * g);
private:
	ID3D11Buffer* pIndexBuffer = nullptr;
};

