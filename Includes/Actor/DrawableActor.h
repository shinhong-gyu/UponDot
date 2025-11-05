#pragma once

#include "Actor.h"
#include "RTTI.h"

class ENGINE_API DrawableActor : public Actor
{
	//RTTI
	RTTI_DECLARATIONS(DrawableActor, Actor)
public:
	DrawableActor(const char* image = " ");
	virtual ~DrawableActor();

	virtual void Draw() override;
	virtual void SetPosition(const Vector2& newPoistion) override;


	inline void SetExpired(bool value) { this->isExpired = true; }
protected:
	// 화면에 그릴 문자 값
	const char* image = nullptr;

	Color color = Color::White;
};