#include "lib.hpp"
#include "InputManager.hpp"
#include "SceneManager.hpp"
#include "PhysicManager.hpp"
#include "Camera.hpp"
#include "GameObject.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"
#include "Cube.hpp"

/*******************************************************************************/

int main( void )
{
    // Initialise GLFW
    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        getchar();
        return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Open a window and create its OpenGL context
    char title[50] = "Moteur de jeux - TP3 Graphe de scènes";
    window = glfwCreateWindow( 1024, 768, title, NULL, NULL);
    if( window == NULL ){
        fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
        getchar();
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    glewExperimental = true; // Needed for core profile
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        getchar();
        glfwTerminate();
        return -1;
    }

    // Ensure we can capture the escape key being pressed below
    // glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    // Hide the mouse and enable unlimited mouvement
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

    // Set the mouse at the center of the screen
    glfwPollEvents();
    glfwSetCursorPos(window, 1024/2, 768/2);

    // Dark blue background
    glClearColor(0.8f, 0.8f, 0.8f, 0.0f);

    // Enable depth test
    glEnable(GL_DEPTH_TEST);
    // Accept fragment if it closer to the camera than the former one
    glDepthFunc(GL_LESS);

    // Cull triangles which normal is not towards the camera
    //glEnable(GL_CULL_FACE);

    // Création de la caméra
    camera.setSpeed(0.1f);
    camera.setIsOrbiting(false);
    camera.setOrbitSpeed(0.025f);
    camera.setFov(45.0f);
    camera.resetCamera();

    // Création des managers
    SceneManager *SM = new SceneManager();
    InputManager *IM = new InputManager();
    PhysicManager *PM = new PhysicManager();

    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    GLuint vertexbuffer;
    GLuint uvbuffer;
    GLuint elementbuffer;
    GLuint normalbuffer;
    GLuint tangentbuffer;
    GLuint bitangentbuffer;

    // Create and compile our GLSL program from the shaders
    programID = LoadShaders( "vertex_shader.glsl", "fragment_shader.glsl" );
    glUseProgram(programID);

    //----------------------------------------- Init -----------------------------------------//

    // Création des différents GameObjects
    GameObject *landscape = new Plane("landscape", 16, 15, 1, "../data/textures/terrain.png");
    GameObject *basketBall = new Sphere("basketBall", 20, 1, 2, "../data/textures/ball.png");
    // GameObject *cube = new Cube("cube", 0.2, 0, "../data/textures/ball.png");

    // Ajout des GameObjects au SceneManager
    SM->addObject(std::move(landscape->ptr));
    SM->addObject(std::move(basketBall->ptr));
    // SM->addObject(std::move(cube->ptr));

    // Ajout des GameObjects au PhysicManager
    PM->addObject(landscape);
    PM->addObject(basketBall);

    // Initialisation des textures des GameObjects
    SM->initGameObjectsTexture();

    // Transformations sur les GameObjects
    basketBall->translate(glm::vec3(0.f, 1.f, 0.f));
    basketBall->scale(glm::vec3(0.2));

    // cube->translate(camera.getPosition());
    // cube->setColor(glm::vec4(0., 0.65, 0.6, 1.0));
    basketBall->setWeight(0.6f);

    // Get a handle for our "LightPosition" uniform
    glUseProgram(programID);
    GLuint LightID = glGetUniformLocation(programID, "LightPosition_worldspace");

    do{

        // Measure speed
        // per-frame time logic
        // --------------------
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        nbFrames++;
        totalDeltaTime += deltaTime;
        physicsClock += deltaTime;

        if (totalDeltaTime >= 1) { // On mets à jour les FPS toutes les secondes
            float FPS = nbFrames / totalDeltaTime;
            sprintf(title, "Moteur de jeux - TP4 Mouvements - (%.0f FPS)", FPS);
            glfwSetWindowTitle(window, title);
            nbFrames = 0;
            totalDeltaTime = 0.;
        }

        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Optimisation du rendu en cachant les éléments non visibles
        glEnable(GL_DEPTH_TEST);

        // Use our shader
        glUseProgram(programID);

        // Envoi de la matrice de vue et de projection au GPU
        camera.sendToShader(programID);

        // Input gérés par l'InputManager
        IM->processInput(window);

        // Test mode édition du terrain
        // if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
        //     glm::vec3 mousePositionOnPlane = landscape->getMousePositionOnPlane(window);
        //     std::cout << mousePositionOnPlane.x << ", " << mousePositionOnPlane.y << std::endl;
        // }

        //----------------------------------- Throw cube 45° from camera front -----------------------------------//
        if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
            basketBall->setPosition(camera.getPosition());
            float throwStrenght = 3.0f;
            glm::vec3 speedVector = glm::normalize(glm::vec3(camera.getFront().x, 1.0f, camera.getFront().z)) * throwStrenght;
            speedVector = glm::vec3((glm::rotate(glm::mat4(1.0f), glm::radians(-45.0f), glm::vec3(0.0f, 0.0f, 1.0f))) * glm::vec4(speedVector, 1.0f));
            basketBall->setVelocity(speedVector);
        }

        // Update des GameObjects dans la boucle
        SM->update(deltaTime);
        
        float updateTime = 1.0f/60.0f;

        while (physicsClock >= updateTime) {
            // Check des collisions entre le plan et les gameObjects
            PM->handleCollisions();
            physicsClock -= updateTime;
        }

        // Affichage de tous les élements de la scène via le SceneManager
        SM->draw();

        // Swap buffers
        glfwSwapBuffers(window);

        // Traiter les événements de la fenêtre
        glfwPollEvents();

    } // Check if the ESC key was pressed or the window was closed
    while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
           glfwWindowShouldClose(window) == 0 );

    // Cleanup VBO and shader
    glDeleteBuffers(1, &vertexbuffer);
    glDeleteBuffers(1, &uvbuffer);
    glDeleteBuffers(1, &normalbuffer);
    glDeleteBuffers(1, &elementbuffer);
    glDeleteProgram(programID);
    glDeleteVertexArrays(1, &VertexArrayID);

    // Close OpenGL window and terminate GLFW
    glfwTerminate();

    return 0;
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}
