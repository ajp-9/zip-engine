#include "Scene.hpp"

#include "Entity/Entity.hpp"
#include "Component/ModelComponent.hpp"
#include "Component/TransformComponent.hpp"

namespace nim
{
    Scene::Scene() {}

    Scene::~Scene() {}

    Entity Scene::createEntity()
    {
        return Entity(m_Registry.create(), this);
    }

    void Scene::destroyEntity(Entity entity)
    {
        m_Registry.destroy(entity);
    }

    void Scene::update()
    {
        
    }

    void Scene::physics()
    {
    }

    void Scene::render()
    {
        auto& view = m_Registry.view<Component::Model, Component::Transform>();

        for (auto& eID : view)
        {
            Component::Model model = m_Registry.get<Component::Model>(eID);
            Component::Transform transform = m_Registry.get<Component::Transform>(eID);

            auto& shaders = model.getShaders();

            for (auto& s : shaders)
            {
                s.lock()->bind();
                s.lock()->setModelMatrix(transform);
            }

            m_Registry.get<Component::Model>(eID).render();
        }
    }
}
