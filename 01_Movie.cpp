class Movie {
private:
    string title;
    string language;
    int durationMinutes;
public:
    Movie() : title(""), language(""), durationMinutes(0) {} // compile-time polymorphism: overloaded constructor
    Movie(const string& title, const string& language, int durationMinutes)
        : title(title), language(language), durationMinutes(durationMinutes) {}
    string getTitle() const { return title; }
    string getLanguage() const { return language; }
    int getDurationMinutes() const { return durationMinutes; }
};
