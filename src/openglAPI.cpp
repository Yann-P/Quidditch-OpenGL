#include <openglAPI.h>
#include <iterator>
#include <map>


using namespace std;


namespace OGL
{

     void init()
     {
        initGLFW();
        initGLEW();
    // 	make_resources();
     }

    // void renderFrame(ObjectsToDraw & objs)
    // {
    //     objs.drawAll();
    // }


    void file_contents(string chemin, int* longueur, GLchar * res)
    {
        ifstream fichier(chemin,std::ios::in);
        int count = 0;
        GLchar c;

        if (!fichier) {
            std::cerr << "ERREUR a l'ouverture du fichier" << std::endl;
        }

        while(fichier.get(c))
        {
            res[count] = c;
            count++;
        }
        *longueur = count * sizeof(char);
        fichier.close();

    }


    void createVBO(float* attributes,int nbVertices,int nbComponents, GLuint & vbo)
    {

        glGenBuffers(1,&vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float)*nbComponents*nbVertices, attributes, GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, 0);

    }

    void createIBO(unsigned int* indices,int nbIndices,  GLuint & ibo)
    {
        glGenBuffers(1,&ibo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int)*nbIndices, indices, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    void createVAO(GLuint & shaderProgram, GLuint & ibo, GLuint & vbo, GLuint & vao)
    {
        glGenVertexArrays(1,&vao);
        glBindVertexArray( vao);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        GLint positionIndex = glGetAttribLocation(shaderProgram, "position");
        glEnableVertexAttribArray(positionIndex);
        glVertexAttribPointer(positionIndex,2,GL_FLOAT,GL_FALSE,0,0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
        glBindVertexArray(0);
    }


    GLuint createShaderProgram(GLchar* vSource, const GLint vLength, GLchar* fSource, const GLint fLength)
    {
        GLuint vShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vShader, 1, (const GLchar**)(&vSource), &vLength);
        glCompileShader(vShader);

        GLuint fShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fShader, 1, (const GLchar**)(&fSource), &fLength);
        glCompileShader(fShader);

        GLuint program = glCreateProgram();
        glAttachShader(program, vShader);
        glAttachShader(program, fShader);
        glLinkProgram(program);
        return program;

    }




    char *read_tga(const char *filename, int& width, int& height, int& depth)/*{{{*/
    {
        struct tga_header {
           char  id_length;
           char  color_map_type;
           char  data_type_code;
           unsigned char  color_map_origin[2];
           unsigned char  color_map_length[2];
           char  color_map_depth;
           unsigned char  x_origin[2];
           unsigned char  y_origin[2];
           unsigned char  width[2];
           unsigned char  height[2];
           char  bits_per_pixel;
           char  image_descriptor;
        } header;
        int i, color_map_size;
        FILE *f;
        size_t read;
        char *pixels;

        f = fopen(filename, "rb");

        if (!f) {
            fprintf(stderr, "Unable to open %s for reading\n", filename);
            return NULL;
        }

        read = fread(&header, 1, sizeof(header), f);

        if (read != sizeof(header)) {
            fprintf(stderr, "%s has incomplete tga header\n", filename);
            fclose(f);
            return NULL;
        }
        if (header.data_type_code != 2) {
            fprintf(stderr, "%s is not an uncompressed RGB tga file\n", filename);
            fclose(f);
            return NULL;
        }
        if (header.bits_per_pixel != 24 and header.bits_per_pixel != 32) {
            fprintf(stderr, "%s is not a 24-bit or 32-bit uncompressed RGB tga file but %i\n", filename, header.bits_per_pixel);
            fclose(f);
            return NULL;
        }

        for (i = 0; i < header.id_length; ++i)
            if (getc(f) == EOF) {
                fprintf(stderr, "%s has incomplete id string\n", filename);
                fclose(f);
                return NULL;
            }

        color_map_size = le_short(header.color_map_length) * (header.color_map_depth/8);
        for (i = 0; i < color_map_size; ++i)
            if (getc(f) == EOF) {
                fprintf(stderr, "%s has incomplete color map\n", filename);
                fclose(f);
                return NULL;
            }

        width = le_short(header.width); height = le_short(header.height);
        depth = (header.bits_per_pixel/8);
        unsigned int pixels_size = width * height * depth;
        pixels = new char[pixels_size];

        read = fread(pixels, 1, pixels_size, f);

        if (read != pixels_size) {
            fprintf(stderr, "%s has incomplete image\n", filename);
            fclose(f);
            delete [] pixels;
            return NULL;
        }

        return pixels;
    }


    long int time() {
        struct timeval tp;
        gettimeofday(&tp, NULL);
        return tp.tv_sec * 1000 + tp.tv_usec / 1000;
    }


}



void initGLFW()
{
    int width = 500, height=500;

    if (!glfwInit())
    {
        glfwTerminate();
        return;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,4);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

    const GLFWvidmode *screen_info =  glfwGetVideoMode(glfwGetPrimaryMonitor());

    width = screen_info->width;
    height = screen_info->height;

    GLFWwindow* window = glfwCreateWindow(width, height, "Triangle application",NULL,NULL);

    if (!window)
    {
        std::cerr << "Could not open window" << std::endl;
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);
    }

    void initGLEW()
    {
    glewExperimental = GL_TRUE;
    GLenum GlewInitResult = glewInit();

    if (GlewInitResult != GLEW_OK)
    {
        std::cerr << "ERROR" << std::endl;
        glfwTerminate();
        return;
    }
}

short le_short(unsigned char *bytes)
{
    return bytes[0] | ((char)bytes[1] << 8);
}