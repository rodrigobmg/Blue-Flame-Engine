#pragma once
#include "BF/Application/Scene.h"
#include "BF/Graphics/GUI/Widget.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			class Scrollbar;

			class BFE_API ScrollbarSlider : public Widget
			{
				friend class Panel;
				friend class Scrollbar;

			private:
				enum class Orientation { Horizontal, Vertical };

				Scrollbar& scrollbar;
				Orientation orientation;

				int length;
				bool doonce = false;
				Math::Vector2f delta;

			public:
				ScrollbarSlider(Scrollbar& scrollbar, Orientation orientation);
				~ScrollbarSlider();

			protected:
				void Initialize(Renderers::SpriteRenderer& spriteRenderer, int zLayer) override;
				void Load(const StyleSheet& styleSheet, const std::string& widgetName) override;
				void Update() override;
				void Render() override;

			private:
				void SetPositionAndSize();
				void Move();
			};
		}
	}
}