#include <iostream>
#include <string>
#include <fstream>
#include "nlohmann/json.hpp"

int main(int, char**){
    std::cout << "Hello, from 32_2_movie_data_analysis!\n";

    std::ofstream file("films.json");

    nlohmann::json dict = {
        {"Amelie", {
            {"country", "France"},
            {"date", "25 April 2001"},
            {"studio", "Claudie Ossard Productions"},
            {"story_by","Guillaume Laurant,Jean-Pierre Jeunet"},
            {"director","Jean-Pierre Jeunet"},
            {"producer","Jean-Marc Deschamps,Claudie Ossard"},
            {"actros", {
                {"Audrey Tautou","Amélie Poulain"},
                {"Mathieu Kassovitz","Nino Quincampoix"},
                {"André Dussollier","The Narrator"},
                {"Rufus", "Raphaël Poulain, Amélie's father"},
                {"Lorella Cravotta" ,"Amandine Poulain, Amélie's mother"},
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
            {"actros", {
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
            {"actros", {
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
            {"actros", {
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
        {"Knockin' on Heaven's Door",{
            {"country", "Germany"},
            {"date", "20 February 1997"},
            {"studio", "Mr. Brown Entertainment"},
            {"story_by","Thomas Jahn"},
            {"director","Thomas Jahn"},
            {"producer","Til Schweiger"},
            {"actros", {
                {"Til Schweiger","Martin Brest"},
                {"Jan Josef Liefers","Rudi Wurlitzer"},
                {"Thierry Van Werveke", "Henk"},
                {"Moritz Bleibtreu","Abdul"},
                {"Huub Stapel"," Frankie 'Boy' Beluga"}  
                }
            }
        }}
    };

    file << dict;
}
