#include "InputLayout.h"

InputLayout::InputLayout(Graphics* g, Shader* s)
{
	D3D11_INPUT_ELEMENT_DESC ied[] = {
		{"Position",0,DXGI_FORMAT_R32G32B32_FLOAT,0,0,D3D11_INPUT_PER_VERTEX_DATA,0},
		{"Color",0,DXGI_FORMAT_R32G32_FLOAT,0,12u,D3D11_INPUT_PER_VERTEX_DATA,0},
	};
	g->pDevice->CreateInputLayout(ied, 2, s->LayoutBlob->GetBufferPointer(), s->LayoutBlob->GetBufferSize(), &pInputLayout);
	g->pContext->IASetInputLayout(pInputLayout);
}
