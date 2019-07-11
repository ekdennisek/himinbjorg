#include "PhysicsManager.h"
#include "MessageBus.h"
#include "Message.h"
#include "GraphicsManager.h"
#include "Components/ClickableComponent.h"
#include <GL/glew.h>

namespace Himinbjorg
{
	PhysicsManager::PhysicsManager(MessageBus *messageBus, GraphicsManager *graphicsManager)
	{
		this->messageBus = messageBus;
		this->graphicsManager = graphicsManager;

		// Set up the message bus listener
		messageBus->registerListener(this);

		// Initiate the Bullet world for game objects
		collisionConfiguration = new btDefaultCollisionConfiguration();
		dispatcher = new btCollisionDispatcher(collisionConfiguration);
		overlappingPairCache = new btDbvtBroadphase();
		solver = new btSequentialImpulseConstraintSolver();
		dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, overlappingPairCache, solver, collisionConfiguration);

		// Initiate the Bullet world for GUI items
		guiCollisionConfiguration = new btDefaultCollisionConfiguration();
		guiDispatcher = new btCollisionDispatcher(collisionConfiguration);
		guiOverlappingPairCache = new btDbvtBroadphase();
		guiSolver = new btSequentialImpulseConstraintSolver();
		guiDynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, overlappingPairCache, solver, collisionConfiguration);

		// Enable debug drawing for GUI world
//		guiDynamicsWorld->setDebugDrawer(this);
//		guiDynamicsWorld->getDebugDrawer()->setDebugMode(btIDebugDraw::DBG_DrawWireframe);
	}

	PhysicsManager::~PhysicsManager()
	{
		// Unregister message bus listener
		messageBus->removeListener(this);

		// Deallocate every GUI collision world related object
		if(guiDynamicsWorld) delete guiDynamicsWorld;
		if(guiSolver) delete guiSolver;
		if(guiOverlappingPairCache) delete guiOverlappingPairCache;
		if(guiDispatcher) delete guiDispatcher;
		if(guiCollisionConfiguration) delete guiCollisionConfiguration;

		// Deallocate every game object collision world related object
		if(dynamicsWorld) delete dynamicsWorld;
		if(solver) delete solver;
		if(overlappingPairCache) delete overlappingPairCache;
		if(dispatcher) delete dispatcher;
		if(collisionConfiguration) delete collisionConfiguration;
	}

	void PhysicsManager::update(double dt)
	{
		// Debug drawing
//		guiDynamicsWorld->debugDrawWorld();
//		int nrOfLines = froms.size();
//		GLfloat *vertexBuffer = new GLfloat[nrOfLines*12];
//		for(int i=0; i<nrOfLines; i++)
//		{
//			btVector3 from = froms.at(i);
//			btVector3 to = tos.at(i);
//			btVector3 color = colors.at(i);
//
//			vertexBuffer[i*12+0] = from.getX();
//			vertexBuffer[i*12+1] = from.getY();
//			vertexBuffer[i*12+2] = from.getZ();
//			vertexBuffer[i*12+3] = color.getX();
//			vertexBuffer[i*12+4] = color.getY();
//			vertexBuffer[i*12+5] = color.getZ();
//			vertexBuffer[i*12+6] = to.getX();
//			vertexBuffer[i*12+7] = to.getY();
//			vertexBuffer[i*12+8] = to.getZ();
//			vertexBuffer[i*12+9] = color.getX();
//			vertexBuffer[i*12+10] = color.getY();
//			vertexBuffer[i*12+11] = color.getZ();
//		}
//		Lines lines(vertexBuffer, nrOfLines);
//		graphicsManager->drawLinesOrtho(lines, rs->getShaderPrograms("line"));
//		froms.clear();
//		tos.clear();
//		colors.clear();
	}

	void PhysicsManager::addRigidBody(btRigidBody *rigidBody)
	{
		dynamicsWorld->addRigidBody(rigidBody);
	}

	void PhysicsManager::addRigidGUIbody(btRigidBody *rigidBody)
	{
		guiDynamicsWorld->addRigidBody(rigidBody);
	}

	void PhysicsManager::removeRigidBody(btRigidBody *rigidBody)
	{
		dynamicsWorld->removeRigidBody(rigidBody);
	}

	void PhysicsManager::removeRigidGUIbody(btRigidBody *rigidBody)
	{
		guiDynamicsWorld->removeRigidBody(rigidBody);
	}

	void *PhysicsManager::rayTest(const glm::mat4 &projectionMatrix, const glm::mat4 &viewMatrix, const btDiscreteDynamicsWorld &world)
	{
		GLint viewport[4] = {0};
		glGetIntegerv(GL_VIEWPORT, viewport);

		double mouseX, mouseY;
		glfwGetCursorPos(graphicsManager->getWindow(), &mouseX, &mouseY);

		// Create the direction of the picking ray
		glm::vec3 nearPoint = glm::unProject(glm::vec3(mouseX, viewport[3]-mouseY, 0),
											viewMatrix,
											projectionMatrix,
											glm::vec4(viewport[0], viewport[1], viewport[2], viewport[3]));
		glm::vec3 farPoint = glm::unProject(glm::vec3(mouseX, viewport[3]-mouseY, 1),
											viewMatrix,
											projectionMatrix,
											glm::vec4(viewport[0], viewport[1], viewport[2], viewport[3]));
		glm::vec3 rayDirection = glm::normalize(farPoint - nearPoint);

		// Extract camera position from the view matrix (taken from https://www.opengl.org/discussion_boards/showthread.php/178484-Extracting-camera-position-from-a-ModelView-Matrix)
		glm::mat3 rotMat(viewMatrix);
		glm::vec3 d(viewMatrix[3]);
		glm::vec3 cameraPosition = -d * rotMat;

		// Define a start and end point for the picking ray (world space)
		glm::vec3 rayStart = glm::vec3(cameraPosition.x, cameraPosition.y, cameraPosition.z);
		glm::vec3 rayEnd = rayStart + rayDirection*1000.0f;

		// Test for ray intersection
		btCollisionWorld::ClosestRayResultCallback RayCallback(btVector3(rayStart.x, rayStart.y, rayStart.z),
															   btVector3(rayEnd.x, rayEnd.y, rayEnd.z));
		world.rayTest(btVector3(rayStart.x, rayStart.y, rayStart.z),
							   btVector3(rayEnd.x, rayEnd.y, rayEnd.z),
							   RayCallback);

		if(RayCallback.hasHit())
			return RayCallback.m_collisionObject->getUserPointer();

		return nullptr;
	}

	void PhysicsManager::drawLine (const btVector3 &from, const btVector3 &to, const btVector3 &color)
	{
		froms.push_back(btVector3(from.x(), from.y(), from.z()));
		tos.push_back(btVector3(to.x(), to.y(), to.z()));
		colors.push_back(btVector3(color.x(), color.y(), color.z()));
	}
	void PhysicsManager::drawContactPoint(const btVector3& PointOnB,const btVector3& normalOnB,btScalar distance,int lifeTime,const btVector3& color) {}
	void PhysicsManager::reportErrorWarning(const char* warningString) {}
	void PhysicsManager::draw3dText(const btVector3& location,const char* textString) {}
	void PhysicsManager::setDebugMode(int debugMode) {}
	int  PhysicsManager::getDebugMode() const { return btIDebugDraw::DBG_DrawWireframe; }

	Message *PhysicsManager::onMessage(Message *msg)
	{
		if(msg->type == Message::MOUSE_INPUT && msg->subType == Message::MOUSE_CLICK)
		{
			/*
			 * TEST FOR GUI HITS
			 */

			// Fetch the mouse coordinates
			double mouseX, mouseY;
			glfwGetCursorPos(graphicsManager->getWindow(), &mouseX, &mouseY);

			// Set up the ray for the ray tracing
			glm::vec3 rayDirection = glm::vec3(0, 0, -1);
			glm::vec3 rayStart = glm::vec3(mouseX, mouseY, 0);
			glm::vec3 rayEnd = rayStart + rayDirection*1000.0f;

			// Test for ray intersection
			btCollisionWorld::ClosestRayResultCallback RayCallback(btVector3(rayStart.x, rayStart.y, rayStart.z),
																   btVector3(rayEnd.x, rayEnd.y, rayEnd.z));
			guiDynamicsWorld->rayTest(btVector3(rayStart.x, rayStart.y, rayStart.z),
								      btVector3(rayEnd.x, rayEnd.y, rayEnd.z),
								      RayCallback);

			if(RayCallback.hasHit())
			{
				((ClickableComponent*) RayCallback.m_collisionObject->getUserPointer())->onClick();
				return msg;
			}

			/*
			 * TEST FOR GAME OBJECT HITS
			 */
			if(!graphicsManager->getActivePerspectiveProjectionMatrix() || !graphicsManager->getActiveViewMatrix())
				return msg;

			ClickableComponent *gameObjectHit = (ClickableComponent*) rayTest(*graphicsManager->getActivePerspectiveProjectionMatrix(),  // will crash if no active camera
					                                        *graphicsManager->getActiveViewMatrix(),  // TODO will crash if no active camera
										                    *dynamicsWorld);
			if(gameObjectHit)
				gameObjectHit->onClick();

			return msg;
		}

		return msg;
	}
}
