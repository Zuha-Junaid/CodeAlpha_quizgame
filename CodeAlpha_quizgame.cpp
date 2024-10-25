#include<iostream>
using namespace std;
class Question{
private:
    string questionText;
    string options[4]; 
    int correctAnswer;
public:
    void setValues(string q, string a1, string a2, string a3, string a4, int ca) {
        questionText = q;
        options[0] = a1;
        options[1] = a2;
        options[2] = a3;
        options[3] = a4;
        correctAnswer = ca;
    }
    bool askQuestion() {
        cout << questionText << endl;
        for (int i = 0; i < 4; i++) {
            cout << i + 1 << ". " << options[i] << endl;
        }
        int userAnswer;
        cout << "Your answer (1-4): ";
        cin >> userAnswer;
        if (userAnswer == correctAnswer) {
            cout << "Correct!" << endl;
            return true;
        } else {
            cout << "Incorrect! The correct answer was: " << options[correctAnswer - 1] << endl;
            return false;
        }
    }
    string getCorrectAnswer() {
        return options[correctAnswer - 1];
    }
};

class User {
private:
    string username; 
    int score;

public:
    User(string name) : username(name), score(0) {}
    void increaseScore() {
        score++;
    }

    int getScore() {
        return score;
    }
    string getUsername() {
        return username;
    }
};
int main() {
    string username;
    cout << "Welcome to the Gaming Quiz!" << endl;
    cout << "Please enter your username: ";
    cin >> username;

    User user(username);
    Question questions[5]; 
    questions[0].setValues("What is the best-selling video game of all time?", "Minecraft", "Tetris", "Wii Sports", "Grand Theft Auto V", 2);
    questions[1].setValues("Which company developed the PlayStation?", "Microsoft", "Nintendo", "Sony", "Sega", 3);
    questions[2].setValues("In which game do players compete to be the last one standing?", "Fortnite", "The Sims", "Animal Crossing", "Minecraft", 1);
    questions[3].setValues("What is the name of the main character in The Legend of Zelda?", "Link", "Zelda", "Ganon", "Kirby", 1);
    questions[4].setValues("Which game features a battle royale mode called Warzone?", "Call of Duty", "Battlefield", "Halo", "Counter-Strike", 1);
    for (int i = 0; i < 5; i++) {
        if (questions[i].askQuestion()) {
            user.increaseScore();
        }
    }
    cout << "\n" << user.getUsername() << ", your final score is: " << user.getScore() << " out of 5." << endl;
    cout << "Correct answers were:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Q" << (i + 1) << ": " << questions[i].getCorrectAnswer() << endl; 
    }
    return 0;
}
