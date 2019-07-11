#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <string>
#include <map>
#include <GL/glew.h>
#include <ft2build.h>	// TODO https://stackoverflow.com/questions/13978775/how-to-avoid-include-dependency-to-external-library
#include FT_FREETYPE_H	// TODO https://stackoverflow.com/questions/13978775/how-to-avoid-include-dependency-to-external-library
#include <glm/glm.hpp>	// glm::ivec2

namespace Himinbjorg
{
    // Forward definitions
    class Mesh;
    class Material;
    class HiminbjorgRoot;
    struct Glyph;

    struct Glyph
	{
		GLuint textureID;
		glm::ivec2 dimensions;
		glm::ivec2 bearings;
		FT_Pos offsetToNext;
	};

    class ResourceManager
    {
    public:
        static ResourceManager &getInstance();

        // Resource access
        Mesh *getMesh(std::string identifier);
        Material *getMaterial(std::string identifier);
        GLuint getShaderPrograms(std::string identifier);
        GLuint getTexture(std::string identifier);
        Glyph *getFont(std::string fontName, int size);

        // Helpers
        std::string readFile(std::string filePath);

        // Misc
        void cleanup();
    private:
        ResourceManager();
        virtual ~ResourceManager();

        // Resource loading
        void loadMesh(std::string identifier);
        void loadMaterial(std::string identifier);
        void loadShader(std::string identifier);
        void loadTexture(std::string identifier);
        void loadFont(std::string fontName, int size);

        // Resources
        std::map<std::string, GLuint> shaderPrograms;
        std::map<std::string, Mesh*> meshes;
        std::map<std::string, Material*> materials;
        std::map<std::string, GLuint> textures;
        std::map<std::string, std::map<int, Glyph*>> fonts;

        FT_Library ft;
    };
}

#endif
