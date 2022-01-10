#pragma once

#include "../Entity/Entity.hpp"

namespace dex
{
    namespace Component
    {
        struct Base
        {
            Base(const Entity& entity)
                : m_Entity(entity)
            {}
        protected:
            Entity m_Entity;
        public:
            friend class dex::Entity;
        };
    }
}