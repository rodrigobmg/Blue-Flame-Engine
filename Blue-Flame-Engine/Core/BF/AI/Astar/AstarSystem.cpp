#include "AstarSystem.h"

namespace BF
{
	namespace AI
	{
		namespace Astar
		{
			AstarSystem::AstarSystem()
			{
			}

			AstarSystem::~AstarSystem()
			{
			}

			void AstarSystem::Initialize()
			{
			}

			void AstarSystem::Load()
			{
			}

			void AstarSystem::PostLoad()
			{
			}

			void AstarSystem::Update(double deltaTime)
			{
				for (size_t i = 0; i < nodes.size(); i++)
				{

				}
			}

			void AstarSystem::Render()
			{
			}

			void AstarSystem::AddComponent(IAstarComponent* component)
			{
				if (component->type == IAstarComponent::Type::AstarNode)
				{
					nodes.emplace_back((AstarNode*)component);
				}
				else if (component->type == IAstarComponent::Type::AstarAgent)
				{
					agents.emplace_back((AstarAgent*)component);
				}
			}

			void AstarSystem::RemoveComponent(IAstarComponent* component)
			{
			}

			void AstarSystem::FindPath(AstarNode* startingNode, AstarNode* endingNode)
			{
			}
		}
	}
}