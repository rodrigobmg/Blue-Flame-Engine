#pragma once
#include <string>
#include "BF/Graphics/Renderers/SpriteRenderer/SpriteRenderer.h"
#include "BF/Common.h"

#define BFE_WIDGET_DATA_SPRITES_LENGTH 8

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			class StyleSheet;

			struct State
			{
				BF::Graphics::Renderers::Sprite normal;
				BF::Graphics::Renderers::Sprite hovered;
				BF::Graphics::Renderers::Sprite pressed;
				BF::Graphics::Renderers::Sprite disabled;
			};

			struct WidgetData
			{
				std::vector<State> state;
				int minWidth = 0, minHeight = 0;
			};

			class BFE_API Widget : public BF::Application::Component
			{
				friend class WidgetManager;

				protected:
					BF::Graphics::Renderers::SpriteRenderer* spriteRenderer;

				//private:
					WidgetData widgetData;
					BF::Graphics::Renderers::Sprite* currentSprite;

					unsigned char currentState;

					bool mouseNotPressedOnWidget;

					bool hovered;
					bool pressed;
					bool pressedAndReleased;

					void(*OnClickCallBack)(void*);
					void* callBackPointer;

				public:
					Widget();
					~Widget();

					/*void AddOnClickListener(void(*OnClickCallBack)(void*), void* obj);

					virtual void SetPosition(const BF::Math::Vector2f& position);
					virtual void SetRectangle(const BF::Math::Rectangle& rectangle);
					void SetZLayer(int zLayer);

					inline BF::Graphics::Renderers::Text& GetText() { return widgetData.text; }

					inline BF::Math::Vector2f GetPosition() const { return currentSprite->GetPosition(); }
					inline BF::Math::Rectangle GetRectangle() const { return currentSprite->GetRectangle(); }

					inline bool IsHovered() const { return hovered; }
					inline bool IsPressed() const { return pressed; }
					inline bool IsPressedAndReleased() const { return pressedAndReleased; }

					inline int GetZLayer() const { return currentSprite->zLayer; }

				protected:
					virtual void Initialize(BF::Graphics::Renderers::SpriteRenderer& spriteRenderer, int zLayer);
					virtual void Load(const StyleSheet& styleSheet, const std::string& widgetName);
					virtual void Update();
					virtual void Render();

					void SwitchState();

			protected:
					bool IsMouseOnWidget();
					void FireAction();
					void SetCurrentSpriteToNormal();*/
			};
		}
	}
}