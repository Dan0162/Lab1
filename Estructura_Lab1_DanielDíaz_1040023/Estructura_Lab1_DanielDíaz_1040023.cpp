#include "pch.h"
#include <iostream>
#include <json/json.h>
#include <fstream>
#include "Apartment.h"
#include "Comparisons.h"

using namespace System;

int main(array<System::String ^> ^args)
{
    std::vector <Apartment> Apartments;
    std::vector <std::string> input2;
    std::string line;
    std::vector <int> outputs;
    std::string filepath;
    std::ifstream file;
    

    //Parseado-----------------------------------------------------------------

    //Se pide un filepath

    do
    {
        std::system("cls");
        std::cout << "Por favor ingresar el path de su archivo jsonl" << std::endl;

        std::cin >> filepath;

        file.open(filepath);

    } while (file.fail());    

    Json::Value actualJson;
    Json::Reader reader;

    //Se divide el archivo línea por línea
    while (getline(file, line)) 
    {
        //Se resetean ambos vectores para crear casos individuales por línea
        Apartments.clear();
        input2.clear();

        //Se obtiene el Jsonl parseado en actualJson
        reader.parse(line, actualJson);


        //input 1 parsing
        //Se extrae solamente input1 de actualJson y se ingresa en una variable constante para su manejo
        const Json::Value& input1 = actualJson["input1"];

        //Se iteran todos los objetos dentro de input1
        for (const auto& item : input1)
        {
            Apartment newApartment;
             
            //Se revisa si el objeto está vacío
            if (!item.empty())
            {
                //Si no lo está, se iteran por todos los negocios disponibles y se ingresan a objetos manejados por c++.
                for (const auto& category : item.getMemberNames()) 
                {                  
                    newApartment.pushBusiness(newApartment.setApartment(category, item[category].asBool()));                    
                }
                Apartments.push_back(newApartment);
            }
            else
            {
                //Si está vacío, se ingresa un objeto vacío. 
                Apartments.push_back(newApartment);
            }

        }


        //input 2 parsing
        //Se obtiene la parte de input2 y se itera por cada string, almacenándolos en un vector.
        for (int i = 0; i < actualJson["input2"].size(); i++) 
        {    
            input2.push_back(actualJson["input2"][i].asString());
        }



        //Comparaciones-----------------------------------------------------------------
        Comparisons Dea(Apartments, input2);
        Dea.createClosenessScore();
        
        outputs.push_back(Dea.getBestCase());


    }

    file.close();

    std::ofstream OutputFile;

    OutputFile.open("C:\\Users\\Public\\Documents\\OutputFile.txt");

    for (int i = 0; i < outputs.size(); i++)
    {
        if (outputs[i] != -1)
        {
            OutputFile << "[" << outputs[i] << "]" << "\n";
        }
        else
        {
            OutputFile << "[]" << "\n";
        }
        
    }

    std::cout << "Su documento ha sido exportado a C:\\Users\\Public\\Documents\\OutputFile.txt" << std::endl;
    std::system("cls");

    OutputFile.close();

    return 0;



}
