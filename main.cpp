#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "nlohmann/json.hpp"

int main(int, char**){
    std::cout << "Hello, from 32_2_movie_data_analysis!\n";

    std::ofstream file_out("films.json");

    nlohmann::json dict = {
        {"Amelie", {
            {"country", "France"},
            {"date", "25 April 2001"},
            {"studio", "Claudie Ossard Productions"},
            {"story_by","Guillaume Laurant, Jean-Pierre Jeunet"},
            {"director","Jean-Pierre Jeunet"},
            {"producer","Jean-Marc Deschamps,Claudie Ossard"},
            {"actors", {
                {"Audrey Tautou","Amelie Poulain"},
                {"Mathieu Kassovitz","Nino Quincampoix"},
                {"Andre Dussollier","The Narrator"},
                {"Rufus", "Raphael Poulain, Amelie's father"},
                {"Lorella Cravotta" ,"Amandine Poulain, Amelie's mother"},
                {"Jamel Debbouze", "Lucien"}}
            }}
        },
        {"Palp Fiction",  { 
            {"country", "United States"},
            {"date", "21 May 1994"},
            {"studio", "A Band Apart Jersey Films"},
            {"story_by","Quentin Tarantino"},
            {"director","Quentin Tarantino"},
            {"producer","Lawrence Bender"},
            {"actors", {
                {"John Travolta","Vincent Vega"},
                {"Samuel L. Jackson","Jules Winnfield"},
                {"Ving Rhames", "Marsellus Wallace"},
                {"Uma Thurman","Mia  Wallace"},
                {"Harvey Keitel", "Winston Wolf"},
                {"Tim Roth" ,"Pumpkin or Ringo"},
                {"Amanda Plummer", "Yolanda or Honey Bunny"},
                {"Maria de Medeiros","Fabienne"},
                {"Christopher Walken","Captain Koons"},
                {"Bruce Willis","Butch Coolidge"}
                }
            }

        }},
        {"Gentlemen of Fortune", {
            {"country", "Soviet Union"},
            {"date", "13 December 1971"},
            {"studio", "Mosfilm"},
            {"story_by","Georgiy Daneliya"},
            {"director","Aleksandr Sery"},
            {"producer",""},
            {"actors", {
                {"Yevgeny Leonov","Yevgeny Ivanovich Troshkin, Aleksandr Aleksandrovich 'Docent' Beliy"},
                {"Georgy Vitsin","Gavrila Petrovich 'Sad Sack' Sheremetyev"},
                {"Savely Kramarov", "Fyodor Petrovich 'Crosseyes' Yermakov"},
                {"Radner Muratov","Vasily Alibabayevich Alibaba"}
                }
            }
        }},
        {"Guest from the Future", {
            {"country", "Soviet Union"},
            {"date", "25 March 1985"},
            {"studio", "Soviet Central Television Gorky Film Studio"},
            {"story_by","Kir Bulychov"},
            {"director","Pavel Arsenov"},
            {"producer",""},
            {"actors", {
                {"Natalya Guseva","Alisa Seleznyova"},
                {"Aleksei Fomkin","Kolya Gerasimov"},
                {"Maryana Ionesyan", "Yulya Gribkova"},
                {"Ilya Naumov","Fima Korolyov"},
                {"Vyacheslav Nevinny","Veselchak U"},
                {"Mikhail Kononov","Krys"},
                {"Yevgeni Gerasimov", "Robot Werther"}
                }
            }
        }},
        {"Prisoner of the Caucasus",{
            {"country", "Soviet Union"},
            {"date", "1 April 1967"},
            {"studio", "Mosfilm"},
            {"story_by","Yakov Kostyukovsky, Leonid Gaidai"},
            {"director","Leonid Gaidai"},
            {"producer",""},
            {"actors", {
                {"Aleksandr Demyanenko","Shurik"},
                {"Natalya Varley","Nina"},
                {"Vladimir Etush", "Saakhov"},
                {"Yuri Nikulin","Fool"},
                {"Georgy Vitsin","Coward"},
                {"Yevgeny Morgunov", "Pro"}  
                }
            }
        }}
    };

    file_out << std::setw(4) << dict << std::endl;

    file_out.close();

    std::ifstream file_in("films.json");
    nlohmann::json films; 
    file_in >> films;
    file_in.close();



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
