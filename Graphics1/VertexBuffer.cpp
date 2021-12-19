#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(Graphics* g)
{
	float vertices[] = {
	0.5f  , 0.5f  , 0.0f , 0.1f , 0.2f,   // ÓÒÉÏ½Ç
	0.5f  , -0.5f , 0.0f , 0.3f , 0.4f, // ÓÒÏÂ½Ç
	//-0.5f , -0.5f , 0.0f , 0.5f , 0.6f,// ×óÏÂ½Ç
	//0.5f  , 0.5f  , 0.0f , 0.1f , 0.2f,   // ÓÒÉÏ½Ç
	-0.5f , 0.5f  , 0.0f , 0.7f , 0.8f, // ×óÉÏ½Ç
	-0.5f , -0.5f , 0.0f , 0.5f , 0.6f,// ×óÏÂ½Ç
	};						    
 
	D3D11_BUFFER_DESC bd = {};
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.CPUAccessFlags = 0u;
	bd.MiscFlags = 0u;
	bd.ByteWidth = sizeof(float)*30;
	bd.StructureByteStride = sizeof(float) * 5;

	D3D11_SUBRESOURCE_DATA sd = {};
	sd.pSysMem = vertices;

	g->pDevice->CreateBuffer(&bd, &sd, &pVertexBuffer);

	const UINT stride = sizeof(float) * 5;
	const UINT offset = 0u;
	g->pContext->IASetVertexBuffers(0u, 1u, &pVertexBuffer, &stride, &offset);
}
