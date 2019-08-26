#pragma once
#include <vector>
#include "BF/System/Transformable.h"
#include "BF/Math/Vector2.h"
#include "BF/Math/Rectangle.h"
#include "BF/Common.h"

namespace BF
{
	namespace System
	{
		class BFE_API RenderableTransform : public Transformable
		{
		public:
			BF::Math::Rectangle edges;
			BF::Math::Vector2i size;
			BF::Math::Vector2f pivot;
			BF::Math::Vector2f corners[4];

		public:
			RenderableTransform(BF::Math::Vector2i& size, BF::Math::Vector2f& pivot);
			~RenderableTransform();
		};
	}
}