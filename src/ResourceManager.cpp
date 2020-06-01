#include "ResourceManager.h"
#include "Components/Mesh.h"
#include "Material.h"
#include "../lib/json/single_include/nlohmann/json.hpp"
#include <fstream>
#include <vector>
#include "../lib/soil/include/SOIL/SOIL.h"
#include <iostream>

namespace Himinbjorg
{
    ResourceManager &ResourceManager::getInstance()
    {
    	static ResourceManager instance;
    	return instance;
    }

    ResourceManager::~ResourceManager()
    {
    }

    ResourceManager::ResourceManager()
    {
    	// Initiate the FreeType library
		if(FT_Init_FreeType(&ft))
			std::cout << "ResourceSystem::ResourceSystem(): Couldn't initialize FreeType.\n";
    }

    void ResourceManager::cleanup()
    {
    	// Release the meshes
        for(std::map<std::string, Mesh*>::iterator it = meshes.begin(); it != meshes.end(); it++)
        	delete it->second;
        meshes.erase(meshes.begin(), meshes.end());

        // Release the materials
        for(std::map<std::string, Material*>::iterator it = materials.begin(); it != materials.end(); it++)
        	delete it->second;
        materials.erase(materials.begin(), materials.end());

        // Release the shader programs
        for(std::map<std::string, GLuint>::iterator it = shaderPrograms.begin(); it != shaderPrograms.end(); it++)
        	glDeleteProgram(it->second);
        shaderPrograms.erase(shaderPrograms.begin(), shaderPrograms.end());

    	GLenum errorCode = GL_NO_ERROR;
    	while((errorCode = glGetError()) != GL_NO_ERROR)
    		std::cout << "ResourceSystem::~ResourceSystem(): OpenGL error: " << gluErrorString(errorCode) << std::endl;

    	// Unload the FreeType library
    	FT_Done_FreeType(ft);
    	for(std::map<std::string, std::map<int, Glyph*>>::iterator it = fonts.begin(); it != fonts.end(); it++)
    		for(std::map<int, Glyph*>::iterator iter = it->second.begin(); iter != it->second.end(); iter++)
    			delete[] iter->second;
    }

    void ResourceManager::loadMesh(std::string identifier)
    {
    	std::string filepath("data/models/");
    	filepath.append(identifier);
    	filepath.append(".obj");

        // Open file, verify success
        std::ifstream file(filepath.c_str());
        if(!file.is_open())
            std::cout << "ResourceSystem::loadMesh(): Couldn't open file.\n";
        else 
            std::cout << "ResourceSystem::loadMesh(): Reading from " << filepath << "\n";

        // Parse file
        std::vector<float*> vertices;
        std::vector<float*> textures;
        std::vector<float*> normals;
        std::vector<int**> faces;
        while(!file.eof())
        {
            // Read a single line from the file
            std::string line;
            std::getline(file, line);

            if(line.length() > 0)
            {
                // Tokenize and save the data
                char *arrayLine = new char[line.length()+1];
                strcpy(arrayLine, line.c_str());
                char *token = strtok(arrayLine, " ");
                if(strcmp(token, "v") == 0)
                {
                    // Store vertex
                    float *vertex = new float[3];
                    vertex[0] = atof(strtok(NULL, " "));
                    vertex[1] = atof(strtok(NULL, " "));
                    vertex[2] = atof(strtok(NULL, " "));
                    vertices.push_back(vertex);
                } 
                else if(strcmp(token, "vt") == 0) 
                {
                    // Store vertex texture
                    float *texture = new float[2];
                    texture[0] = atof(strtok(NULL, " "));
                    texture[1] = atof(strtok(NULL, " "));
                    textures.push_back(texture);
                } 
                else if(strcmp(token, "vn") == 0)
                {
                    // Store vertex normal
                    float *normal = new float[3];
                    normal[0] = atof(strtok(NULL, " "));
                    normal[1] = atof(strtok(NULL, " "));
                    normal[2] = atof(strtok(NULL, " "));
                    normals.push_back(normal);
                } 
                else if(strcmp(token, "f") == 0)
                {
                    // Store face data
                    char *faceVertices[3];
                    for(int i=0; i<3; i++)
                        faceVertices[i] = strtok(NULL, " ");

                    int **face = new int*[3];
                    for(int i=0; i<3; i++)
                        face[i] = new int[3];

                    face[0][0] = atoi(strtok(faceVertices[0], "/")) - 1; // -1 because of OBJ file indexing
                    face[0][1] = atoi(strtok(NULL, "/")) - 1;
                    face[0][2] = atoi(strtok(NULL, "/")) - 1;

                    face[1][0] = atoi(strtok(faceVertices[1], "/")) - 1;
                    face[1][1] = atoi(strtok(NULL, "/")) - 1;
                    face[1][2] = atoi(strtok(NULL, "/")) - 1;

                    face[2][0] = atoi(strtok(faceVertices[2], "/")) - 1;
                    face[2][1] = atoi(strtok(NULL, "/")) - 1;
                    face[2][2] = atoi(strtok(NULL, "/")) - 1;

                    faces.push_back((int**)face);
                } // if statements

                delete[] arrayLine;
            } // if(line.length() > 0)
        } // while(!file.eof()) File parsing finished
        std::cout << "ResourceSystem::loadMesh(): Read " << vertices.size() << " vertices, " << textures.size() << " texture coordinates, " << normals.size() << " normals, " << " and " << faces.size() << " faces.\n";

        // Create the vertex buffer
        // Vertex data is stores as VVVTTNNN
        // TODO: Indexed buffers
        GLfloat *vertexBuffer = new GLfloat[faces.size()*3*8];
        for(int i=0; i < faces.size(); i++)
        {
            int vertexBufferIndex = i*8*3; // Every face consists of 8 floats, process 3 faces at a time
            int **currentFaces = faces.at(i);

            for(int j=0; j<3; j++)
            {
            	int *currentFace = currentFaces[j];
            	float *currentVertex = vertices.at(currentFace[0]);
            	float *currentTexture = textures.at(currentFace[1]);
            	float *currentNormal = normals.at(currentFace[2]);

            	vertexBuffer[vertexBufferIndex + j*8 + 0] = currentVertex[0];
            	vertexBuffer[vertexBufferIndex + j*8 + 1] = currentVertex[1];
            	vertexBuffer[vertexBufferIndex + j*8 + 2] = currentVertex[2];
            	vertexBuffer[vertexBufferIndex + j*8 + 3] = currentTexture[0];
            	vertexBuffer[vertexBufferIndex + j*8 + 4] = 1 - currentTexture[1];
            	vertexBuffer[vertexBufferIndex + j*8 + 5] = currentNormal[0];
            	vertexBuffer[vertexBufferIndex + j*8 + 6] = currentNormal[1];
            	vertexBuffer[vertexBufferIndex + j*8 + 7] = currentNormal[2];
            }
        }

        meshes.insert(std::pair<std::string, Mesh*>(identifier, new Mesh(identifier, vertexBuffer, faces.size()*3)));

//        for(int i=0; i<faces.size()*24; i=i+8)
//        {
//        	std::cout << "============ Vertex " << (i/8) << " ============\n";
//        	std::cout << vertexBuffer[i+0] << ", " << vertexBuffer[i+1] << ", " << vertexBuffer[i+2] << "\n";
//        	std::cout << vertexBuffer[i+3] << ", " << vertexBuffer[i+4] << "\n";
//        	std::cout << vertexBuffer[i+5] << ", " << vertexBuffer[i+6] << ", " << vertexBuffer[i+7] << "\n";
//        }

        // Deallocate the arrays that are stores
        while(!vertices.empty()) 
        {
            delete[] vertices.back();
            vertices.pop_back();
        }

        while(!textures.empty())
        {
            delete[] textures.back();
            textures.pop_back();
        }

        while(!normals.empty())
        {
            delete[] normals.back();
            normals.pop_back();
        }

        while(!faces.empty())
        {
            for(int i=0; i<3; i++)
                delete[] faces.back()[i];
            delete[] faces.back();
            faces.pop_back();
        }

        // Close file
        file.close();
    } // loadMesh()

    void ResourceManager::loadMaterial(std::string identifier)
    {
    	// Read the proper file into the materialFile variable
    	std::string materialFilePath("data/materials/");
    	materialFilePath.append(identifier);
    	materialFilePath.append(".material");
    	std::string materialFile = readFile(materialFilePath);

    	nlohmann::json materialJSON = nlohmann::json::parse(materialFile.c_str());

    	std::string shader = materialJSON["shader"].get<std::string>();
    	std::vector<float> color = materialJSON["color"].get<std::vector<float>>();
    	std::string texture; if(materialJSON["texture"] != nullptr) texture = materialJSON["texture"].get<std::string>();

    	float colorArray[] = { color.at(0), color.at(1), color.at(2), color.at(3) };
    	Material *material = new Material(getShaderPrograms(shader), texture.size() > 0 ? getTexture(texture) : 0, colorArray);
    	materials.insert(std::pair<std::string, Material*>(identifier, material));
    }

    void ResourceManager::loadShader(std::string identifier)
    {
    	// Used for OpenGL error checking
    	GLint success;
    	GLchar infoLog[512];

    	// Read vertex shader file
    	std::string vertexShaderFilePath("data/shaders/");
    	vertexShaderFilePath.append(identifier);
    	vertexShaderFilePath.append(".vertex");
    	std::string vertexShaderSource = readFile(vertexShaderFilePath);
    	const char *vertexShaderSourceChar = vertexShaderSource.c_str();

    	// Read fragment shader file
    	std::string fragmentShaderFilePath("data/shaders/");
    	fragmentShaderFilePath.append(identifier);
    	fragmentShaderFilePath.append(".fragment");
    	std::string fragmentShaderSource = readFile(fragmentShaderFilePath);
    	const char *fragmentShaderSourceChar = fragmentShaderSource.c_str();

    	// Compile vertex shader
    	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    	glShaderSource(vertexShader, 1, &vertexShaderSourceChar, NULL);
    	glCompileShader(vertexShader);
    	// Check for success
    	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    	if(!success)
    	{
    		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    		std::cout << "Couldn't compile vertex shader: " << infoLog << std::endl;
    	}

    	// Compile fragment shader
    	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    	glShaderSource(fragmentShader, 1, &fragmentShaderSourceChar, NULL);
    	glCompileShader(fragmentShader);
    	// Check for success
    	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    	if(!success)
    	{
    		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
    		std::cout << "Couldn't compile fragment shader: " << infoLog << std::endl;
    	}

    	// Add the shaders to a program and link
    	GLuint shaderProgram = glCreateProgram();
    	glAttachShader(shaderProgram, vertexShader);
    	glAttachShader(shaderProgram, fragmentShader);
    	glLinkProgram(shaderProgram);
    	// Check for success
    	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    	if(!success)
    	{
    		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
    		std::cout << infoLog << std::endl;
    	}

    	glDeleteShader(vertexShader);
    	glDeleteShader(fragmentShader);

    	shaderPrograms.insert(std::pair<std::string, GLuint>(identifier, shaderProgram));

    	// OpenGL error checking
    	GLenum errorCode = GL_NO_ERROR;
    	while((errorCode = glGetError()) != GL_NO_ERROR)
    		std::cout << "ResourceSystem::loadShader(): OpenGL error: " << gluErrorString(errorCode) << std::endl;
    }

    void ResourceManager::loadTexture(std::string identifier)
    {
    	// Load the image
    	int width, height;
    	std::string textureFilePath("data/textures/");
    	textureFilePath.append(identifier);
    	unsigned char *image = SOIL_load_image(textureFilePath.c_str(), &width, &height, 0, SOIL_LOAD_RGB);

    	// Upload the texture to VRAM
    	GLuint texture;
    	glGenTextures(1, &texture);
    	glBindTexture(GL_TEXTURE_2D, texture);
    	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    	glGenerateMipmap(GL_TEXTURE_2D);
    	glBindTexture(GL_TEXTURE_2D, 0);

    	// Finalize
    	SOIL_free_image_data(image);
    	textures.insert(std::pair<std::string, GLuint>(identifier, texture));

    	// OpenGL error checking
    	GLenum errorCode = GL_NO_ERROR;
    	while((errorCode = glGetError()) != GL_NO_ERROR)
    		std::cout << "ResourceSystem::loadTexture(): OpenGL error: " << gluErrorString(errorCode) << std::endl;
    }

    void ResourceManager::loadFont(std::string fontName, int size)
    {
    	FT_Face face;
    	std::string fontPath = "/usr/share/fonts/";
    	fontPath.append(fontName);
    	if(FT_New_Face(ft, fontPath.c_str(), 0, &face))
			std::cout << "ResourceSystem::loadFont(): Couldn't load FreeType font.\n";
		else
			std::cout << "ResourceSystem:loadFont(): Successfully loaded font.\n";

    	Glyph *glyphs = new Glyph[128];
    	// If this is the first size of the font that's rendered: special case
    	if(fonts.find(fontName) == fonts.end())
    	{
    		std::map<int, Glyph*> font;
    		fonts.insert(std::pair<std::string, std::map<int, Glyph*>>(fontName, font));
    	}
    	fonts.find(fontName)->second.insert(std::pair<int, Glyph*>(size, glyphs));
    	FT_Set_Pixel_Sizes(face, 0, size);

    	// Render the glyphs into OpenGL textures
    	glPixelStorei(GL_UNPACK_ALIGNMENT, 1); // TODO Restore???
    			for(FT_ULong glyphValue=0; glyphValue<127; glyphValue++) // Load the first 128 glyphs
    			{
    				if(FT_Load_Char(face, glyphValue, FT_LOAD_RENDER))
    					std::cout << "Couldn't load FreeType face.\n";
    				GLuint textureID;
    				glGenTextures(1, &textureID);
    				glBindTexture(GL_TEXTURE_2D, textureID);
    				glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, face->glyph->bitmap.width, face->glyph->bitmap.rows, 0, GL_RED, GL_UNSIGNED_BYTE, face->glyph->bitmap.buffer);
    			    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    			    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    			    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    			    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    			    glyphs[glyphValue] = {
    			    		textureID,
    						glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
    						glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
    						face->glyph->advance.x
    			    };
    			}
    }

    Mesh* ResourceManager::getMesh(std::string identifier)
    {
    	if(meshes.find(identifier) == meshes.end())
    		loadMesh(identifier);

    	Mesh *mesh = new Mesh((*meshes.find(identifier)->second));
    	return mesh;
    }

    Material *ResourceManager::getMaterial(std::string identifier)
    {
    	if(materials.find(identifier) == materials.end())
    		loadMaterial(identifier);

    	Material *material = new Material((*materials.find(identifier)->second));
    	return material;
    }

    GLuint ResourceManager::getTexture(std::string identifier)
    {
    	if(textures.find(identifier) == textures.end())
    		loadTexture(identifier);

    	return textures.find(identifier)->second;
    }

    GLuint ResourceManager::getShaderPrograms(std::string identifier)
    {
    	if(shaderPrograms.find(identifier) == shaderPrograms.end())
    		loadShader(identifier);

    	return shaderPrograms.find(identifier)->second;
    }

    Glyph *ResourceManager::getFont(std::string fontName, int size)
    {
    	// If either glyphs of specified font are loaded, or if the font isn't loaded at the correct size
    	// TODO: Second check ought to be enough..?
    	if(fonts.find(fontName) == fonts.end() || fonts.find(fontName)->second.find(size) == fonts.find(fontName)->second.end())
    		loadFont(fontName, size);

    	return fonts.find(fontName)->second.find(size)->second;
    }

    std::string ResourceManager::readFile(std::string filePath)
    {
    	std::ifstream file(filePath);
    	if(!file.is_open())
    		std::cout << "ResourceSystem::readFile(): Couldn't open " << filePath << std::endl;
    	else
    		std::cout << "ResourceSystem::readFile(): Reading from " << filePath << std::endl;

    	std::string content, line;
    	while(std::getline(file, line))
    	{
    	    content.append(line);
    	    content.append("\n");
    	}
    	file.close();

    	return content;
    }


}
