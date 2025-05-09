#pragma once
#include "PrimitiveComponent.h"
#include "UTexture.h"

struct FTexture;

class UBillboardComponent : public UPrimitiveComponent
{
    DECLARE_CLASS(UBillboardComponent, UPrimitiveComponent)
    
public:
    UBillboardComponent();
    virtual ~UBillboardComponent() override;
    UBillboardComponent(const UBillboardComponent& other);

    virtual void InitializeComponent() override;
    virtual void TickComponent(float DeltaTime) override;
    virtual int CheckRayIntersection(
        FVector& rayOrigin,
        FVector& rayDirection, float& pfNearHitDistance
    ) override;

    void SetTexture(FWString _fileName);
    void SetUUIDParent(USceneComponent* _parent);
    FMatrix CreateBillboardMatrix();
    virtual UObject* Duplicate() const override;
    virtual void DuplicateSubObjects(const UObject* Source) override;
    virtual void PostDuplicate() override;
    
    ID3D11Buffer* vertexTextureBuffer;
    ID3D11Buffer* indexTextureBuffer;
    UINT numVertices;
    UINT numIndices;
    float finalIndexU = 0.0f;
    float finalIndexV = 0.0f;
    std::shared_ptr<FTexture> Texture;
protected:



    USceneComponent* m_parent = nullptr;

    bool CheckPickingOnNDC(const TArray<FVector>& checkQuad, float& hitDistance);

private:
    void CreateQuadTextureVertexBuffer();
};
