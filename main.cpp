#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "nlohmann/json.hpp"

int main(int, char**){
    std::cout << "Hello, from 32_2_movie_data_analysis!\n";

    std::ifstream file("films.json");
    nlohmann::json films; 
    file >> films;
    file.close();

    std::string name;
    std::cout << "Enter actors name: ";
    std::getline(std::cin, name);

    std::vector<std::string> results;

    for(auto it = films.begin(); it != films.end(); ++it){

        auto actors_it = it->find("actors");

        if(actors_it != it->end()){
            auto name_it = actors_it->find(name);
            if(name_it != actors_it->end()){
                std::string out = "Film - " +  it.key()
                    + ", role - " + nlohmann::to_string(name_it.value());
                results.push_back(out);
            }     
        }
    }
    
    if(results.size() > 0){
        for(auto &result : results)
            std::cout<< result << std::endl;
    }else{
        std::cout << "Sorry, no such actor has been found.";
    }
}
