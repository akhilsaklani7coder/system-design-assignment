class Movie {
private:
    string title;
    string language;
    int durationMinutes;
public:
    Movie() : title(""), language(""), durationMinutes(0) {} // Compile-time polymorphism: overloaded constructor.
    Movie(const string& title, const string& language, int durationMinutes) {
        this->title = title; // this keyword: refers to the current Movie object.
        this->language = language;
        this->durationMinutes = durationMinutes;
    }
    string getTitle() const { return title; }
    string getLanguage() const { return language; }
    int getDurationMinutes() const { return durationMinutes; }
};
