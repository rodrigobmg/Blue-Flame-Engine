#include "Context.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			RenderAPI Context::renderAPI = RenderAPI::none;

			Context::Context(Application::Window* window, RenderAPI renderAPI) :
				window(window)
			{
				this->renderAPI = renderAPI;

#ifdef BF_PLATFORM_WINDOWS
				if (renderAPI == RenderAPI::DirectX)
					dxContext = new Platform::API::DirectX::DXContext(window);
				else if (renderAPI == RenderAPI::OpenGL)
					winGLContext = new Platform::API::OpenGL::WINGLContext(window);
#elif BF_PLATFORM_LINUX
				if (renderAPI == RenderAPI::OpenGL)
					lxGLContext = new Platform::API::OpenGL::LXGLContext(window->GetLXWindow());
#elif BF_PLATFORM_WEBGL
				if (renderAPI == RenderAPI::OpenGL)
					webGLContext = new Platform::API::OpenGL::WEBGLContext(window->GetWEBWindow());
#endif
			}

			Context::~Context()
			{
			}

			void Context::SetPrimitiveType(PrimitiveType primitiveType)
			{
#ifdef BF_PLATFORM_WINDOWS
				if (renderAPI == RenderAPI::DirectX)
					dxContext->SetPrimitiveType(primitiveType);
#endif
#if defined BF_PLATFORM_WINDOWS || defined BF_PLATFORM_LINUX || defined BF_PLATFORM_WEBGL
				if (renderAPI == RenderAPI::OpenGL)
					winGLContext->SetPrimitiveType(primitiveType);
#endif
			}

			void Context::Clear(Math::Vector4 color)
			{
#ifdef BF_PLATFORM_WINDOWS
				if (renderAPI == RenderAPI::DirectX)
					dxContext->Clear(color);
				else if (renderAPI == RenderAPI::OpenGL)
					winGLContext->Clear(color);
#elif BF_PLATFORM_LINUX
				if (renderAPI == RenderAPI::OpenGL)
					lxGLContext->Clear(color);
#elif BF_PLATFORM_WEBGL
				if (renderAPI == RenderAPI::OpenGL)
					webGLContext->Clear(color);
#endif
			}

			void Context::Draw(unsigned int vertexCount)
			{
#ifdef BF_PLATFORM_WINDOWS
				if (renderAPI == RenderAPI::DirectX)
					dxContext->Draw(vertexCount);
				else if (renderAPI == RenderAPI::OpenGL)
					winGLContext->Draw(vertexCount);
#elif BF_PLATFORM_LINUX
				if (renderAPI == RenderAPI::OpenGL)
					lxGLContext->Draw(GL_PRIMITIVE_TYPE, vertexCount, GL_UNSIGNED_INT);
#elif BF_PLATFORM_WEBGL
				if (renderAPI == RenderAPI::OpenGL)
					webGLContext->Draw(GL_PRIMITIVE_TYPE, vertexCount, GL_UNSIGNED_INT);
#endif
			}

			void Context::SwapBuffers()
			{
#ifdef BF_PLATFORM_WINDOWS
				if (renderAPI == RenderAPI::DirectX)
					dxContext->SwapBuffers();
				else if (renderAPI == RenderAPI::OpenGL)
					winGLContext->SwapBuffers();
#elif BF_PLATFORM_LINUX
				if (renderAPI == RenderAPI::OpenGL)
					lxGLContext->SwapBuffers();
#elif BF_PLATFORM_WEBGL
				if (renderAPI == RenderAPI::OpenGL)
					webGLContext->SwapBuffers();
#endif
			}
			void Context::EnableDepthBuffer(bool state)
			{
#ifdef BF_PLATFORM_WINDOWS
				if (renderAPI == RenderAPI::DirectX)
				{
					//dxContext->SwapBuffers();
				}
				else if (renderAPI == RenderAPI::OpenGL)
				{
					winGLContext->EnableDepthBuffer(state);
				}
#elif BF_PLATFORM_LINUX
#elif BF_PLATFORM_WEBGL
#endif
			}
		}
	}
}