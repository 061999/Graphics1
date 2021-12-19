#pragma once
#include "Graphics.h"
#include "Shader.h"
class InputLayout
{
public:
	InputLayout(Graphics * g,Shader *s);
private:
	ID3D11InputLayout* pInputLayout = nullptr;
};

