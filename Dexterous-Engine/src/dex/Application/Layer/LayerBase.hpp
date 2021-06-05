#pragma once

#include <memory>

#include "../../Util/TypeDefs.hpp"
#include "Event/EventBase.hpp"

namespace dex
{
	namespace Layer
	{
		class Base
		{
		public:
			virtual void Attach() = 0;
			virtual void Detach() = 0;

			virtual void update() = 0;
			virtual void render() = 0;
			virtual void event(std::unique_ptr<Event::Base>& e) = 0;
		public:
			uint m_Index = 0;
		};
	}
}