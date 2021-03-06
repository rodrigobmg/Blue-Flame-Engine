#include "Widget.h"
#include "BF/Graphics/GUI/StyleSheet.h"
#include "BF/Input/Mouse.h"
#include "BF/Math/Math.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			using namespace std;
			using namespace BF::Math;
			using namespace BF::Input;
			using namespace BF::Application;
			using namespace BF::Graphics::Renderers;

			Widget::Widget() :
				currentSprite(nullptr), OnClickCallBack(nullptr), callBackPointer(nullptr), currentState(0), mouseNotPressedOnWidget(false), hovered(false), pressed(false), pressedAndReleased(false)
			{
				Component::type = Component::Type::GUI;
			}

			Widget::~Widget()
			{
			}

			void Widget::Initialize(SpriteRenderer& spriteRenderer, int zLayer)
			{
				this->spriteRenderer = &spriteRenderer;
				SetZLayer(zLayer);
			}

			void Widget::Load(const StyleSheet& styleSheet, const string& widgetName)
			{
				widgetData = styleSheet.GetWidget(widgetName);
				currentSprite = &widgetData.sprites[0];
			}

			void Widget::AddOnClickListener(void(*OnClickCallBack)(void*), void* callBackPointers)
			{
				this->OnClickCallBack = OnClickCallBack;
				this->callBackPointer = callBackPointers;
			}

			void Widget::SetPosition(const Vector2f& position)
			{
				for (size_t i = 0; i < BFE_WIDGET_DATA_SPRITES_LENGTH; i++)
					widgetData.sprites[i].SetPosition(position);

				if (widgetData.hasText)
					widgetData.text.SetPosition(position);
			}

			void Widget::SetZLayer(int zLayer)
			{
				for (size_t i = 0; i < BFE_WIDGET_DATA_SPRITES_LENGTH; i++)
					widgetData.sprites[i].zLayer = zLayer;
			}

			void Widget::SetRectangle(const Rectangle& rectangle)
			{
				Math::Rectangle temp = rectangle;
				temp.width = Max(widgetData.minWidth, rectangle.width);
				temp.height = Max(widgetData.minHeight, rectangle.height);

				for (size_t i = 0; i < BFE_WIDGET_DATA_SPRITES_LENGTH; i++)
					widgetData.sprites[i].SetRectangle(temp);

				if (widgetData.hasText)
					widgetData.text.SetRectangle(rectangle);
			}

			bool Widget::IsMouseOnWidget()
			{
				//if (Mouse::IsInsideWindowClient())
				{
					if (Mouse::GetPosition().x >= currentSprite->GetRectangle().x + 1 && Mouse::GetPosition().x <= currentSprite->GetRectangle().x + currentSprite->GetRectangle().width - 1 &&
						Mouse::GetPosition().y >= currentSprite->GetRectangle().y + 1 && Mouse::GetPosition().y <= currentSprite->GetRectangle().y + currentSprite->GetRectangle().height - 1)
						return true;
				}

				return false;
			}

			void Widget::FireAction()
			{
				if (hovered && pressed && !Mouse::IsButtonHeldDown(Mouse::Button::Code::Left))
				{
					pressed = false;
					currentSprite = &widgetData.sprites[currentState + 0];

					if (OnClickCallBack != nullptr && callBackPointer != nullptr)
						OnClickCallBack(callBackPointer);

					pressedAndReleased = true;
				}
			}

			void Widget::SetCurrentSpriteToNormal()
			{
				currentSprite = &widgetData.sprites[currentState + 0];
			}

			void Widget::Update()
			{
				pressedAndReleased = false;

				hovered = IsMouseOnWidget();

				if (hovered)
					currentSprite = &widgetData.sprites[currentState + 1];
				else
					currentSprite = &widgetData.sprites[currentState + 0];

				if (!hovered && Mouse::IsButtonHeldDown(Mouse::Button::Code::Left))
					mouseNotPressedOnWidget = true;

				if (!mouseNotPressedOnWidget && hovered && Mouse::IsButtonHeldDown(Mouse::Button::Code::Left))
				{
					currentSprite = &widgetData.sprites[currentState + 2];
					pressed = true;
				}

				FireAction();

				if (!Mouse::IsButtonHeldDown(Mouse::Button::Code::Left))
				{
					mouseNotPressedOnWidget = false;
					pressed = false;
				}
			}

			void Widget::Render()
			{
				/*spriteRenderer->Render(*currentSprite);

				if (widgetData.hasText)
					spriteRenderer->Render(widgetData.text);*/
			}

			void Widget::SwitchState()
			{
				currentState == 0 ? currentState = 4 : currentState = 0;
			}
		}
	}
}