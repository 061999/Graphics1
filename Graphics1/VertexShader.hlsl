struct vsout
{
    float3 color : Color;
    float4 pos : SV_Position;

};

vsout main(float2 pos : Position,float3 color:Color)
{
    vsout vso;
    vso.color = color;
    vso.pos = float4(pos.x, pos.y, 0.0f, 1.0f);
    return vso;
}