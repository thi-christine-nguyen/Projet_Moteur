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
#include "PhysicManager.hpp"
#include "InputManager.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"
#include "Cube.hpp"
#include "Landscape.hpp"
#include "Player.hpp"



class Interface
{
private : 
    GLuint programID;
    Player* player = nullptr;

public : 

    Camera camera; 
    SceneManager *SM = new SceneManager(programID);
    PhysicManager *PM = new PhysicManager(); 
    InputManager * IM = new InputManager(); 
    

    Interface(GLuint programID) : programID(programID) {}

    Player getPlayer(){
        return player; 
    }

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


    void addGameObject(float _deltaTime, GLFWwindow* _window) {
       

        static char name[128] = "";
        static GameObjectType selectedType = SPHERE; 
        static int resolution;
        static int size;
        static std::string meshPath;
        static std::string texturePath;
        static bool playable = false; 
        static bool physic = false; 
        static float poids = 0; 
        static Transform transform; 
        static bool scaleLocked_ = false; 

       
        // Champ de saisie pour le nom de l'objet
        ImGui::InputText("Name", name, IM_ARRAYSIZE(name));


        if (ImGui::Button("Mesh Path")) {
            IGFD::FileDialogConfig config;
            config.path = ".";
            ImGuiFileDialog::Instance()->OpenDialog("ChooseMeshDlgKey", "Choose Mesh File", ".obj", config);
        }

        if (ImGuiFileDialog::Instance()->Display("ChooseMeshDlgKey")) {
            if (ImGuiFileDialog::Instance()->IsOk()) {
                meshPath = ImGuiFileDialog::Instance()->GetFilePathName();
            }
            ImGuiFileDialog::Instance()->Close();
        }

        if (ImGui::Button("Annuler le mesh")){
            meshPath = ""; 
        };

        if(meshPath == ""){
            ImGui::InputInt("Resolution", &resolution);
            ImGui::InputInt("Size/Radius", &size);
        }

        
        ImGui::Text("Selected Mesh File: %s", meshPath.c_str());
       

        if (ImGui::Button("Texture Path")) {
            IGFD::FileDialogConfig config;
            config.path = ".";
            ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgTextureKey", "Choose File", ".png, .jpg, .bmp", config);
        }
        if (ImGuiFileDialog::Instance()->Display("ChooseFileDlgTextureKey")) {
          
            if (ImGuiFileDialog::Instance()->IsOk()) { // action if OK
                texturePath = ImGuiFileDialog::Instance()->GetFilePathName();
            }

            // Fermer la boîte de dialogue
            ImGuiFileDialog::Instance()->Close();
        }
        // std::cout << texturePath << std::endl; 

        ImGui::Text("Selected Texture File: %s", texturePath.c_str());


        // Ajustement du transform de base
        ImGui::Text("Position");
        glm::vec3 position = transform.getPosition();
        ImGui::DragFloat3("Position", glm::value_ptr(position));

        glm::vec3 rotation = transform.getRotation();
        ImGui::Text("Rotation");
        ImGui::DragFloat3("##Rotation", glm::value_ptr(rotation));

        glm::vec3 scale = transform.getScale();

        ImGui::Text("Lock Scale");
        ImGui::SameLine();
        ImGui::Checkbox("##LockScale", &scaleLocked_);

        if (scaleLocked_) {
            // Si l'échelle est verrouillée, utilisez une seule valeur pour les trois axes
            ImGui::Text("Scale");
            ImGui::DragFloat((std::string("##") + name + "Scale").c_str(), &scale.x, 0.1f, 0.0f, FLT_MAX);
            scale.y = scale.x;
            scale.z = scale.x;
        } else {
            ImGui::Text("Scale x, y, z");
            // Sinon, laissez l'utilisateur modifier chaque valeur de l'échelle individuellement
            ImGui::DragFloat3((std::string("##") + name + "Scale").c_str(), glm::value_ptr(scale), 0.1f, 0.0f, FLT_MAX);

        }

        transform.setPosition(position);
        transform.setRotation(rotation);
        transform.setScale(scale);
        

        // Boutons de radio pour choisir le type d'objet à créer
        ImGui::Text("Select Object Type:");
        ImGui::RadioButton("Sphere", reinterpret_cast<int*>(&selectedType), SPHERE);
        ImGui::RadioButton("Cube", reinterpret_cast<int*>(&selectedType), CUBE);
        ImGui::RadioButton("Plane", reinterpret_cast<int*>(&selectedType), PLANE);

        if(selectedType == SPHERE){
            ImGui::Text("Is playable ?");
            ImGui::SameLine();
            ImGui::Checkbox("##Playable", &playable);
       
        }

        ImGui::Text("Has physical properties ?");
        ImGui::SameLine();
        ImGui::Checkbox("##Physic", &physic);

        if(physic == true){
            ImGui::Text("Poids de l'objet");
            ImGui::SliderFloat("Poids", &poids, 0.0f, 10.0f);
        }
        

        if (ImGui::Button("Add Object")) {

            glActiveTexture(GL_TEXTURE0);
            GLuint textureID = loadTexture2DFromFilePath(texturePath); 
            glUniform1i(glGetUniformLocation(programID, "gameObjectTexture"), 0);

            // std::cout << textureID << std::endl; 
            GameObject* newObject;
            
            switch (selectedType) {
                case SPHERE :
                    if(playable = true){
                        player = meshPath.empty() ?  new Player(name, resolution, size, textureID, texturePath.c_str(), programID) :
                                                        new Player(name, meshPath.c_str(), textureID, texturePath.c_str(), programID); 
                        
                        player->setTransform(transform); 
                        player->setInitalTransform(transform); 
                        if(physic == true){
                            player->setWeight(poids); 
                            PM->addObject(player); 
                        }
                        SM->addObject(std::move(player->ptr)); 

                    }else {
                        newObject = meshPath.empty() ?  new Sphere(name, resolution, size, textureID, texturePath.c_str(), programID) :
                                                        new Sphere(name, meshPath.c_str(), textureID, texturePath.c_str(), programID);

                    }
                    break;

                case CUBE:
                    newObject = meshPath.empty() ?  new Cube(name, size, textureID, texturePath.c_str(), programID):
                                                    new Cube(name, meshPath.c_str(), textureID, texturePath.c_str(), programID);
                    break;
                   
                case PLANE:
                    newObject = meshPath.empty() ?  new Plane(name, resolution, size, textureID, texturePath.c_str(), programID):
                                                    new Plane(name, meshPath.c_str(), textureID, texturePath.c_str(), programID);
                    break;
                // case LANDSCAPE : 
                //     newObject = new Landscape(name, resolution, size, textureID, texturePath.c_str()); 
                // case PLAYER:
                //     newObject = new Player(name, resolution, size, textureID, texturePath.c_str(), programID);
                //     break;

            }

            if(selectedType != SPHERE){
                if(physic == true){
                    newObject->setWeight(poids); 
                    PM->addObject(newObject); 
                    
                }

                SM->addObject(std::move(newObject->ptr));

            }

            

            name[0] = '\0';
            resolution = 0; 
            size = 0; 
            selectedType = SPHERE;
        }
        
    }

    void updateInterface(float _deltaTime, GLFWwindow* _window)
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
                        if(ImGui::Button("Suprimer")){
                            SM->removeObjectByName(objectName); 
                        }
                        
                    }
                }
                // if (ImGui::CollapsingHeader("Add texture")) {
                //     addGameObject(_deltaTime);
                // }
                if (ImGui::CollapsingHeader("Add")) {
                    addGameObject(_deltaTime, _window);
                }

                ImGui::EndTabItem();
            }
            ImGui::EndTabBar();
        }
        ImGui::End();
    }

    void update(float _deltaTime, GLFWwindow* _window){
        updateInterface(_deltaTime, _window);

        
        if (player != nullptr) {
            IM->processInput(_window, player, _deltaTime); 
        }   
       
    }



}; 
#endif