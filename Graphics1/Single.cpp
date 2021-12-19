#include "Single.h"

Single::Single(HWND hWnd)
{
	g = new Graphics(hWnd);
	VertexBuffer v(g);
	IndexBuffer i(g);
	Shader* s = new Shader(L"VertexShader.cso", L"PixelShader.cso", g);
	InputLayout layout(g, s);
	g->InitDevice();
}

void Single::draw(float x, float y, float z)
{
	g->ClearBuffer(x, y, z);
	g->DrawTriang();
	g->EndFrame();
}
