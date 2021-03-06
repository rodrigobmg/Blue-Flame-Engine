#pragma once
#include <vector>
#include "BF/ECS/ISystem.h"
#include "BF/Graphics/Camera.h"
#include "BF/Graphics/ConstantBufferManager.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		class CameraManager : public BF::ECS::ISystem
		{
			friend class BF::ECS::GameObject;
			friend class BF::Graphics::Camera;

		private:
			BF::Graphics::ConstantBufferManager& constantBufferManager;
			BF::Graphics::Camera* mainCamera;
			std::vector<Camera*> cameras;

		public:
			CameraManager(BF::Graphics::ConstantBufferManager& constantBufferManager);
			~CameraManager();

			void Initialize()			  override;
			void Load()					  override;
			void PostLoad()				  override;
			void Update(double deltaTime) override;
			void Render()				  override;

			void SetMainCamera(BF::Graphics::Camera* camera);

			void AddCamera(BF::Graphics::Camera* camera);
			void RemoveCamera();

			inline Camera& GetMainCamera() const { return *mainCamera; }
		};
	}
}