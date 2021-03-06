#pragma once
#include <vector>
#include <string>
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			class BFE_API VertexBufferLayout
			{
				public:
					enum class DataType { Int, Float, Float2, Float3, Float4 };

					struct BFE_API VertexBufferElement
					{
						int index = 0;
						std::string name = "";
						DataType dataType;
						unsigned int stride = 0;
						unsigned int offset = 0;
					};

				private:
					std::vector<VertexBufferElement> vertexBufferElements;

				public:
					VertexBufferLayout();
					~VertexBufferLayout();

					void Push(int index, const std::string& name, DataType dataType, unsigned int stride, unsigned int offset);

					inline const std::vector<VertexBufferElement>& GetBufferElement() const { return vertexBufferElements; }
			};
		}
	}
}