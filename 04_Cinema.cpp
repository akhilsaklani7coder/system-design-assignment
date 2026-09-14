class Cinema {
private:
    string name;
    vector<Screen> screens; // Composition: screens belong to this cinema.
public:
    explicit Cinema(const string& name) : name(name) {}
    void addScreen(int screenNumber) { screens.emplace_back(screenNumber); }
    string getName() const { return name; }
    vector<Screen>& getScreens() { return screens; }
    const vector<Screen>& getScreens() const { return screens; }
};
