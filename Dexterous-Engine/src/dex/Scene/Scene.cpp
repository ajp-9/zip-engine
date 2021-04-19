#include "Scene.hpp"

#include "Entity/Entity.hpp"
#include "Component/ModelComponent.hpp"
#include "Component/TransformComponent.hpp"
#include "../Renderer/Shader/ShaderManager.hpp"

namespace dex
{
    Scene::Scene() {}

    Scene::~Scene() {}

    Entity Scene::createEntity()
    {
        return Entity(m_Registry.create(), this);
    }

    void Scene::destroyEntity(Entity entity)
    {
        if (entity.getComponent<Component::OrthographicCamera>().m_IsMainCamera)
            m_OrthoCamera = nullptr;
        if (entity.getComponent<Component::PerspectiveCamera>().m_IsMainCamera)
            m_PerspCamera = nullptr;

        m_Registry.destroy(entity);
    }

    void Scene::findSetMainCamera()
    {
        if (m_Registry.view<Component::OrthographicCamera>().size() + m_Registry.view<Component::PerspectiveCamera>().size() > 1)
            std::cout << "Scene: Too many main cameras\n";

        auto& orthoView = m_Registry.view<dex::Component::OrthographicCamera>();

        for (auto& entityID : orthoView)
        {
            auto& camera = m_Registry.get<Component::OrthographicCamera>(entityID);

            if (camera.m_IsMainCamera)
            {
                m_OrthoCamera = &camera;
            }
        }

        auto& perspView = m_Registry.view<Component::PerspectiveCamera>();

        for (auto& entityID : perspView)
        {
            auto& camera = m_Registry.get<Component::PerspectiveCamera>(entityID);

            if (camera.m_IsMainCamera)
            {
                m_PerspCamera = &camera;
            }
        }
    }

    void Scene::update()
    {
        
    }

    void Scene::physics()
    {
    }

    void Scene::render()
    {
        if (m_OrthoCamera != nullptr)
            ShaderManager::setProjectionViewMatrix(m_OrthoCamera->m_Camera.getProjectionViewMatrix());
        if (m_PerspCamera != nullptr)
            ShaderManager::setProjectionViewMatrix(m_PerspCamera->m_Camera.getProjectionViewMatrix());

        auto& view = m_Registry.view<Component::Model, Component::Transform>();

        for (auto& entityID : view)
        {
            m_Registry.get<Component::Model>(entityID).m_Material->m_Shader.lock()->setModelMatrix(m_Registry.get<Component::Transform>(entityID));
            m_Registry.get<Component::Model>(entityID).render();
        }
    }
}