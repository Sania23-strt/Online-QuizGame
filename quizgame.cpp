#include #include #include

using namespace std;

// User class for handling user information class User { public: string name; int score;

User(string userName) {
    name = userName;
    score = 0;
}
};

// Question class for handling questions, options, and answers class Question { public: string questionText; vector options; int correctAnswerIndex;

Question(string qText, vector<string> opts, int correctIndex) {
    questionText = qText;
    options = opts;
    correctAnswerIndex = correctIndex;
}

bool checkAnswer(int userAnswer) {
    return userAnswer == correctAnswerIndex;
}
};

// Quiz class for managing the entire quiz class Quiz { private: vector questions; public: void addQuestion(Question q) { questions.push_back(q); }

void startQuiz(User &user) {
    cout << "Starting quiz for " << user.name << "...\n\n";
    for (size_t i = 0; i < questions.size(); i++) {
        cout << "Q" << i + 1 << ": " << questions[i].questionText << "\n";
        for (size_t j = 0; j < questions[i].options.size(); j++) {
            cout << j + 1 << ": " << questions[i].options[j] << "\n";
        }
        int userAnswer;
        cout << "Your answer: ";
        cin >> userAnswer;

        if (questions[i].checkAnswer(userAnswer - 1)) {
            cout << "Correct!\n";
            user.score++;
        } else {
            cout << "Wrong! Correct answer was: " << questions[i].options[questions[i].correctAnswerIndex] << "\n";
        }
        cout << endl;
    }

    cout << "Quiz over! " << user.name << ", your score is: " << user.score << "/" << questions.size() << "\n";
}
};

int main() { // User registration string userName; cout << "Enter your name to register: "; getline(cin, userName); User user(userName);

// Initialize quiz
Quiz quiz;

// Adding questions to the quiz
quiz.addQuestion(Question("Which Country is known as the 'Land of the Rising Sun?'", { "Berlin", "Japan", "Paris", "Rome" }, 1)); quiz.addQuestion(Question("What is the Largest island in the world? ", { "Greenland", "Victoria", "Madagascar", "Honshu" }, 0)); quiz.addQuestion(Question("Who Painted 'the Last Supper?'", { "Heles guwei", "Armystry nekola", "Vinci", "Leonard da Vinci" }, 3));

// Start the quiz
quiz.startQuiz(user);

return 0;
}
