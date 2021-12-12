#pragma once
#include <d3d11.h>
#include <d3dcompiler.h>
#pragma comment(lib,"d3d11.lib")
#pragma comment(lib,"D3DCompiler.lib")
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

		pContext->Draw(3u, 0u);
	}
private:
	ID3D11Device* pDevice = nullptr;
	IDXGISwapChain* pSwap = nullptr;
	ID3D11DeviceContext* pContext = nullptr;
	ID3D11RenderTargetView* pTarget = nullptr;
	ID3D11Buffer* pVertexBuffer = nullptr;
	ID3D11InputLayout* pInputLayout = nullptr;
};

