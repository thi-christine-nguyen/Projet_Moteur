#ifndef INTERFACE_HPP__
#define INTERFACE_HPP__

#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>
#include <imgui/ImGuiFileDialog.h>
#include <iostream>
#include <vector>
#include "TP1/Camera/Camera.hpp"
#include "SceneManager.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"
#include "Cube.hpp"
#include "Landscape.hpp"
#include "Player.hpp"



class Interface
{
private : 
    GLuint programID;

public : 

    Camera camera; 
    SceneManager *SM = new SceneManager(programID);
    Interface(GLuint programID) : programID(programID) {}

    void initImgui(GLFWwindow *window)
    {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        ImGui::StyleColorsDark();
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init("#version 330");
    }

    void createFrame(){
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    }

    void renderFrame(){
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    // Deletes all ImGUI instances
    void deleteFrame(){
       
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }


    void addGameObject(float _deltaTime) {
       

        static char name[128] = "";
        static GameObjectType selectedType = SPHERE; 
        static int resolution;
        static int size;
        static std::string texturePath;

       
        // Champ de saisie pour le nom de l'objet
        ImGui::InputText("Name", name, IM_ARRAYSIZE(name));

        ImGui::InputInt("Resolution", &resolution);
        ImGui::InputInt("Size/Radius", &size);
        // ImGui::InputInt("Texture ID", &textureID);

        if (ImGui::Button("Texture Path")) {
            IGFD::FileDialogConfig config;
            config.path = ".";
            ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgKey", "Choose File", ".png,.jpg,.bmp", config);
        }
        if (ImGuiFileDialog::Instance()->Display("ChooseFileDlgKey")) {
          
            if (ImGuiFileDialog::Instance()->IsOk()) { // action if OK
                texturePath = ImGuiFileDialog::Instance()->GetFilePathName();
                // std::string filePath = ImGuiFileDialog::Instance()->GetCurrentPath();

            }

            // Fermer la boîte de dialogue
            ImGuiFileDialog::Instance()->Close();
        }

        ImGui::Text("Selected File: %s", texturePath.c_str());
        

        // Boutons de radio pour choisir le type d'objet à créer
        ImGui::Text("Select Object Type:");
        ImGui::RadioButton("Sphere", reinterpret_cast<int*>(&selectedType), SPHERE);
        ImGui::RadioButton("Cube", reinterpret_cast<int*>(&selectedType), CUBE);
        ImGui::RadioButton("Plane", reinterpret_cast<int*>(&selectedType), PLANE);
        ImGui::RadioButton("Landscape", reinterpret_cast<int*>(&selectedType), LANDSCAPE);
        ImGui::RadioButton("Player", reinterpret_cast<int*>(&selectedType), PLAYER);

        if (ImGui::Button("Add Object")) {

            glActiveTexture(GL_TEXTURE0);
            GLuint textureID = loadTexture2DFromFilePath(texturePath); 
            glUniform1i(glGetUniformLocation(programID, "gameObjectTexture"), 0);

            // std::cout << textureID << std::endl; 
            GameObject* newObject;
            
            switch (selectedType) {
                case SPHERE:
                    newObject = new Sphere(name, resolution, size, textureID, texturePath.c_str(), programID);
                    break;
                case CUBE:
                    newObject = new Cube(name, size, textureID, texturePath.c_str(), programID);
                    break;
                case PLANE:
                    newObject = new Plane(name, resolution, size, textureID, texturePath.c_str(), programID);
                    break;
                case LANDSCAPE : 
                    newObject = new Landscape(name, resolution, size, textureID, texturePath.c_str()); 
                case PLAYER:
                    newObject = new Player(name, resolution, size, textureID, texturePath.c_str(), programID);
                    break;

            }
            // Ajoutez le nouvel objet à la scène   
            SM->addObject(std::move(newObject->ptr));

            name[0] = '\0';
            resolution = 0; 
            size = 0; 
            selectedType = SPHERE;
        }
        
    }

    void updateInterface(float _deltaTime)
	{
        if (ImGui::Begin("Interface")){
            if (ImGui::BeginTabBar("Tabs")) {
                camera.updateInterfaceCamera(_deltaTime); 
            }
            if (ImGui::BeginTabItem("Objects"))
            {
                for (const auto& object : SM->getObjects()) {
                    std::string objectName = object->getName();
                    if (ImGui::CollapsingHeader(objectName.c_str())) {
                        // Contenu détaillé de l'objet
                        ImGui::Text("Object Name: %s", objectName.c_str());
                    
                        object->updateInterfaceTransform(_deltaTime); 
                        
                    }
                }
                // if (ImGui::CollapsingHeader("Add texture")) {
                //     addGameObject(_deltaTime);
                // }
                if (ImGui::CollapsingHeader("Add")) {
                    addGameObject(_deltaTime);
                }

                ImGui::EndTabItem();
            }
            ImGui::EndTabBar();
        }
        ImGui::End();
    }

    void update(float _deltaTime, GLFWwindow* _window){
        updateInterface(_deltaTime);
       
    }



}; 
#endif