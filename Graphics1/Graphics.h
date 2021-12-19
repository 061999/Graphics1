#pragma once
#include <d3d11.h>
#include <d3dcompiler.h>

class Graphics
{
public:
	Graphics(HWND hWnd);
	void EndFrame() {
		pSwap->Present(1u, 0u);
	}
	void ClearBuffer(float red, float green, float blue)noexcept {
		const float color[] = { red,green,blue,1.0f };
		pContext->ClearRenderTargetView(pTarget, color);
	}
	void InitDevice();

	void DrawTriang() {

		pContext->DrawIndexed(6,0,0);
		//pContext->Draw(6, 0);
	}
public:
	int number = 0;
	ID3D11Device* pDevice = nullptr;
	IDXGISwapChain* pSwap = nullptr;
	ID3D11DeviceContext* pContext = nullptr;
	ID3D11RenderTargetView* pTarget = nullptr;
	
};

