#pragma once
#include <d3d11.h>
#include "BF/Common.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace DirectX
			{
				class BFE_API DXConstantBuffer
				{
					private:
						ID3D11Buffer* buffer;

					public:
						DXConstantBuffer();
						~DXConstantBuffer();

						void Create(unsigned int size);
						void Update(const void* data);
				};
			}
		}
	}
}