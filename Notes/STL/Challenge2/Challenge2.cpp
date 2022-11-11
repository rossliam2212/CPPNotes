//
// Created by Liam Ross on 09/07/2022.
//

#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <iomanip>
#include <cctype>

class Song {
private:
    friend std::ostream& operator<<(std::ostream& os, const Song& song);
    std::string name;
    std::string artist;
    int rating{};

public:
    Song() = default;
    Song(std::string& name, std::string& artist, int rating) : name{name}, artist{artist}, rating{rating} { }
    Song(std::string&& name, std::string&& artist, int rating) : Song(name, artist, rating) { }

    bool operator==(const Song& rhs) const { return this->name == rhs.name; }
    bool operator<(const Song& rhs) const { return this->name < rhs.name; }
};

std::ostream& operator<<(std::ostream& os, const Song& song) {
    os << std::setw(35) << std::left << song.name
       << std::setw(25) << std::left << song.artist
       << std::setw(2) << std::left << song.rating << "\n";

    return os;
}

void displayMenu();
void displayPlaylist(const std::list<Song>& playList, const Song& currentSong);
void playCurrentSong(const Song& currentSong);

int main() {
    std::list<Song> playList {
            {"Ghost", "Justin Bieber", 5},
            {"Brazil", "Declan McKenna", 5},
            {"Pursuit of Happiness", "Steve Aoki", 5},
            {"The Spins", "Mac Miller", 5},
            {"The Thrill", "Wiz Khalifia", 5}
    };
    auto currentSong = playList.begin();
    bool quit{false};
    displayPlaylist(playList, *currentSong);

    while (!quit) {
        char choice;

        displayMenu();
        std::cin >> choice;

        switch (tolower(choice)) {
            case 'f':
                currentSong = playList.begin();
                playCurrentSong(*currentSong);
                break;

            case 'n':
                currentSong++;
                if (currentSong == playList.end())
                    currentSong = playList.begin();
                playCurrentSong(*currentSong);
                break;

            case 'p':
                currentSong--;
                if (currentSong == playList.begin())
                    currentSong = playList.end();
                playCurrentSong(*currentSong);
                break;

            case 'a': {
                std::string name, artist;
                int rating;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Enter the song name:\n>";
                getline(std::cin, name);

                std::cout << "Enter the artist:\n>";
                getline(std::cin, artist);

                std::cout << "Enter the song rating:\n>";
                std::cin >> rating;

                playList.insert(currentSong, Song{name, artist, rating});
                currentSong--;
                playCurrentSong(*currentSong);
                break;
            }
            case 'l':
                displayPlaylist(playList, *currentSong);
                break;
            case 'q':
                quit = true;
                break;
            default:
                std::cout << "Invalid option!" << std::endl;
                break;
        }
    }
    return 0;
}

void displayMenu() {
    std::cout << "\nF - Player First song." << std::endl;
    std::cout << "N - Player Next song." << std::endl;
    std::cout << "P - Player Previous song." << std::endl;
    std::cout << "A - Add and Play a new Song at current location." << std::endl;
    std::cout << "L - List the playlist." << std::endl;
    std::cout << "Q - Quit." << std::endl;
    std::cout << "==============================================================" << std::endl;
    std::cout << "What would you like to do?\n>";

}
void displayPlaylist(const std::list<Song>& playList, const Song& currentSong) {
    for(const auto& s : playList)
        std::cout << s;

    std::cout << "\nCurrent Song:\n" << currentSong << std::endl;
}
void playCurrentSong(const Song& currentSong) {
    std::cout << "Playing:\n" << currentSong;
}

