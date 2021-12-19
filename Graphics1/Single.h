#pragma once
#include "Graphics.h"
#include "IndexBuffer.h"
#include "VertexBuffer.h"
#include "Shader.h"
#include "InputLayout.h"
class Single
{
public:
	Single(HWND hWnd);
	void draw(float x, float y, float z)
; private:
	Graphics* g = nullptr;
};

