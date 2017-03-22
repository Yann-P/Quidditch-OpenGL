#include <openglAPI.h>

using namespace std;


namespace OGL
{

 void init()
 {
    initGLFW();
    initGLEW();
// 	make_resources();
 }

void renderFrame(GLuint program, GLuint vao)
{
    //--------- clear the color-buffer and the depth-buffer, set some states
    glClearColor(0.1, 0.1, 0.1, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    //--------- bind shader program [and textures] (see later...)
    glUseProgram(program);
    //--------- Activate the VAO and call the drawing routine
    glBindVertexArray(vao);

    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

    GLFWwindow* window = glfwGetCurrentContext();

    glfwPollEvents();
    glfwSwapBuffers(window);

    //--------- Clean state again
    glBindVertexArray(0);
    glUseProgram(0);
}


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
