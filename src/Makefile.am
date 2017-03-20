lib_LTLIBRARIES = libhiminbjorg.la
libhiminbjorg_la_SOURCES = Components/BehaviorComponent.cpp \
				 		   Components/CameraComponent.cpp \
						   Components/ClickableBehaviorComponent.cpp \
						   Components/ClickableOrthoPlaneBehaviorComponent.cpp \
					 	   Components/Component.cpp \
						   Components/GeometryComponent.cpp \
					 	   Components/InputComponent.cpp \
						   Components/Lines.cpp \
						   Components/Mesh.cpp \
					 	   Components/MeshRenderer.cpp \
					 	   Components/OrthoPlane.cpp \
					 	   Components/OrthoPlaneRenderer.cpp \
					 	   Components/RenderingComponent.cpp \
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
include_HEADERS = Himinbjorg.h
libhiminbjorg_la_CPPFLAGS = ${glfw3_CFLAGS} ${bullet_CFLAGS} ${freetype2_CFLAGS}
libhiminbjorg_la_LIBADD = ${glfw3_LIBS} ${glew_LIBS} ${gl_LIBS} ${icu_LIBS} -lSOIL ${bullet_LIBS} ${freetype2_LIBS}
