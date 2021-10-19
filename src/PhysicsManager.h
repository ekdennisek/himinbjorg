#ifndef PHYSICSMANAGER_H
#define PHYSICSMANAGER_H

#include "IMessageBusListener.h"
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>
#include <functional>
#include <vector>
#include "../lib/glm/glm/gtc/matrix_transform.hpp"

namespace Himinbjorg
{
    // Forward declarations
    class Message;
    class MessageBus;
    class GraphicsManager;

	class PhysicsManager : public btIDebugDraw, public IMessageBusListener
	{
	public:
		PhysicsManager(MessageBus *messageBus, GraphicsManager *graphicsManager);
		virtual ~PhysicsManager();

		void update(double dt);

		void addRigidBody(btRigidBody *rididBody);
		void addRigidGUIbody(btRigidBody *rigidBody);
		void removeRigidBody(btRigidBody *rididBody);
		void removeRigidGUIbody(btRigidBody *rigidBody);
		void *rayTest(const glm::mat4 &projectionMatrix, const glm::mat4 &viewMatrix, const btDiscreteDynamicsWorld &world);

		virtual void drawLine (const btVector3 &from, const btVector3 &to, const btVector3 &color);
		virtual void drawContactPoint(const btVector3& PointOnB,const btVector3& normalOnB,btScalar distance,int lifeTime,const btVector3& color);
		virtual void reportErrorWarning(const char* warningString);
		virtual void draw3dText(const btVector3& location,const char* textString);
		virtual void setDebugMode(int debugMode);
		virtual int  getDebugMode() const;

		// Message bus listener
		Message* onMessage(Message *msg);
	private:
		MessageBus *messageBus;
		GraphicsManager *graphicsManager;

		// Line debug drawing
		std::vector<btVector3> froms;
		std::vector<btVector3> tos;
		std::vector<btVector3> colors;

		// Collision world for game objects
		btDefaultCollisionConfiguration *collisionConfiguration;
		btCollisionDispatcher *dispatcher;
		btBroadphaseInterface *overlappingPairCache;
		btSequentialImpulseConstraintSolver *solver;
		btDiscreteDynamicsWorld *dynamicsWorld;

		// Collision world for GUI items
		btDefaultCollisionConfiguration *guiCollisionConfiguration;
		btCollisionDispatcher *guiDispatcher;
		btBroadphaseInterface *guiOverlappingPairCache;
		btSequentialImpulseConstraintSolver *guiSolver;
		btDiscreteDynamicsWorld *guiDynamicsWorld;
	};
}

#endif
