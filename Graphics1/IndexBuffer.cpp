#include "IndexBuffer.h"

IndexBuffer::IndexBuffer(Graphics* g)
{
	unsigned short indices[] = {	// ע��������0��ʼ! 
	0, 1, 3,			// ��һ��������
	0, 3, 2,			// �ڶ���������
	};
	D3D11_BUFFER_DESC id = {};
	id.BindFlags = D3D11_BIND_INDEX_BUFFER;
	id.Usage = D3D11_USAGE_DEFAULT;
	id.CPUAccessFlags = 0u;
	id.MiscFlags = 0u;
	id.ByteWidth = sizeof(indices);
	id.StructureByteStride = sizeof(unsigned short);

	D3D11_SUBRESOURCE_DATA isd = {};
	isd.pSysMem = indices;

	g->pDevice->CreateBuffer(&id, &isd, &pIndexBuffer);
	g->pContext->IASetIndexBuffer(pIndexBuffer, DXGI_FORMAT_R16_UINT, 0u);
}
