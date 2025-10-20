#include "GameController.h"
#include "WindowController.h"
#include "ToolWindow.h"

GameController::GameController()
{
	m_shader = { };
    m_mesh = { };
	m_camera = { };
}

void GameController::Initialize()
{
    GLFWwindow* glfwWindow = WindowController::GetInstance().GetWindow(); // Call this first, as it creates a window required by GLEW
    M_ASSERT(glewInit() == GLEW_OK, "Failed to initialize GLEW."); // Initialize GLEW
    glfwSetInputMode(glfwWindow, GLFW_STICKY_KEYS, GL_TRUE); // Ensure we can capture the escape key
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // black background
    glEnable(GL_CULL_FACE);
	//Create a default perspective camera
	m_camera = Camera(WindowController::GetInstance().GetResolution());
	
	OpenGL::ToolWindow^ wnd = gcnew OpenGL::ToolWindow();
	wnd->Show();
}

void GameController::RunGame()
{
    m_shader = Shader();
    m_shader.LoadShaders("Shaders/SimpleVertexShader.vertexshader.txt", "Shaders/SimpleFragmentShader.fragmentshader.txt");
    m_mesh = Mesh();
    m_mesh.Create(&m_shader);

    GLFWwindow* window = WindowController::GetInstance().GetWindow();

    glUseProgram(m_shader.GetProgramID());

    do
    {
        glUseProgram(m_shader.GetProgramID());
        float yScale = OpenGL::ToolWindow::YPercent / 100.0f;
        float uScale = OpenGL::ToolWindow::UPercent / 100.0f;
        float vScale = OpenGL::ToolWindow::VPercent / 100.0f;
        int invertFlag;
        if (OpenGL::ToolWindow::InvertColors)
	        invertFlag = 1;
        else
	        invertFlag = 0;
        glUniform1f(m_shader.GetUniformYScale(), yScale);
        glUniform1f(m_shader.GetUniformUScale(), uScale);
        glUniform1f(m_shader.GetUniformVScale(), vScale);
        glUniform1i(m_shader.GetUniformInvertColors(), invertFlag);

        glClear(GL_COLOR_BUFFER_BIT); // Clear the screen
        m_mesh.Render(m_camera.GetProjection()* m_camera.GetView());
        glfwSwapBuffers(window); // Swap the front and back buffers
        glfwPollEvents();

    }
    while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS );

    m_mesh.Cleanup();
    m_shader.Cleanup();
}
