#pragma once

#include <memory>
#include <bullet3/btBulletDynamicsCommon.h>
#include "RigidBody/RigidBody.hpp"
#include "../Util/Transform/BasicTransform.hpp"

namespace dex
{
    class Physics
    {
    public:
        Physics();
        ~Physics();

        void update();

        RigidBody createRigidbody(RigidBodyType type, const std::shared_ptr<CollisionShape>& collision_shape, float mass, const BasicTransform& transform);

        btRigidBody* sbody;
        btRigidBody* floor;

        btDefaultCollisionConfiguration*     m_CollisionConfig;
        btCollisionDispatcher*               m_CollisionDispatcher;
        btBroadphaseInterface*               m_BroadphaseInterface;
        btSequentialImpulseConstraintSolver* m_CollisionSolver;
        btDiscreteDynamicsWorld*             m_DynamicsWorld;
    };
}
