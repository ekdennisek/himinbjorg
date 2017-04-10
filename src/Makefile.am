lib_LTLIBRARIES = libhiminbjorg.la
libhiminbjorg_la_SOURCES = Components/BehaviorComponent.cpp \
				 		   Components/CameraComponent.cpp \
						   Components/ClickableComponent.cpp \
						   Components/ClickableOrthoPlane.cpp \
					 	   Components/Component.cpp \
						   Components/GeometryComponent.cpp \
					 	   Components/InputComponent.cpp \
						   Components/Lines.cpp \
						   Components/Mesh.cpp \
					 	   Components/MeshRenderer.cpp \
					 	   Components/OrthoPlane.cpp \
					 	   Components/OrthoPlaneRenderer.cpp \
					 	   Components/RenderingComponent.cpp \
						   Components/Text.cpp \
					 	   Components/TextRenderer.cpp \
					 	   Components/TransformComponent.cpp \
					 	   Systems/BehaviorSystem.cpp \
					 	   Systems/CameraSystem.cpp \
					 	   Systems/InputSystem.cpp \
					 	   Systems/RenderingSystem.cpp \
					 	   Systems/TransformSystem.cpp \
						   GraphicsManager.cpp \
					 	   HiminbjorgRoot.cpp \
						   InputManager.cpp \
					 	   Material.cpp \
					 	   Message.cpp \
					 	   MessageBus.cpp \
						   PhysicsManager.cpp \
					 	   ResourceManager.cpp \
					 	   SceneManager.cpp \
					 	   SceneNode.cpp
includefolderdir = $(includedir)/himinbjorg
includefolder_HEADERS = Himinbjorg.h \
				  Components/BehaviorComponent.h \
				  Components/CameraComponent.h \
				  Components/ClickableComponent.h \
				  Components/ClickableOrthoPlane.h \
				  Components/Component.h \
				  Components/GeometryComponent.h \
				  Components/InputComponent.h \
				  Components/Lines.h \
				  Components/Mesh.h \
				  Components/MeshRenderer.h \
				  Components/OrthoPlane.h \
				  Components/OrthoPlaneRenderer.h \
				  Components/RenderingComponent.h \
				  Components/Text.h \
				  Components/TextRenderer.h \
				  Components/TransformComponent.h \
				  Systems/BehaviorSystem.h \
				  Systems/CameraSystem.h \
				  Systems/InputSystem.h \
				  Systems/RenderingSystem.h \
				  Systems/TransformSystem.h \
				  GraphicsManager.h \
				  HiminbjorgRoot.h \
				  InputManager.h \
				  Material.h \
				  Message.h \
				  MessageBus.h \
				  PhysicsManager.h \
				  ResourceManager.h \
				  SceneManager.h \
				  SceneNode.h
libhiminbjorg_la_CPPFLAGS = ${glfw3_CFLAGS} ${bullet_CFLAGS} ${freetype2_CFLAGS}
libhiminbjorg_la_LIBADD = ${glfw3_LIBS} ${glew_LIBS} ${gl_LIBS} ${icu_LIBS} -lSOIL ${bullet_LIBS} ${freetype2_LIBS}
