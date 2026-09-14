class Show {
private:
    int showId;
    Movie* movie;       // Aggregation: Movie exists independently of a Show.
    Screen* screen;     // Association: Show uses an existing Screen.
    string startTime;
    vector<ShowSeat> showSeats; // Composition: status objects belong to this screening.
public:
    Show(int showId, Movie* movie, Screen* screen, const string& startTime)
        : showId(showId), movie(movie), screen(screen), startTime(startTime) {
        for (Seat& seat : screen->getSeats()) showSeats.emplace_back(&seat);
    }
    int getShowId() const { return showId; }
    Movie* getMovie() const { return movie; }
    Screen* getScreen() const { return screen; }
    string getStartTime() const { return startTime; }
    vector<ShowSeat>& getShowSeats() { return showSeats; }
    const vector<ShowSeat>& getShowSeats() const { return showSeats; }
    ShowSeat* findSeat(const string& number) {
        for (ShowSeat& showSeat : showSeats) if (showSeat.getSeat().getNumber() == number) return &showSeat;
        return nullptr;
    }
    void printSeatLayout() const {
        cout << "\nScreen-" << screen->getScreenNumber() << " | " << startTime << " | " << movie->getTitle() << "\n";
        cout << "[ ] = AVAILABLE  [X] = BOOKED\n";
        for (const ShowSeat& showSeat : showSeats) {
            cout << "[" << (showSeat.isAvailable() ? " " : "X") << "] "
                 << showSeat.getSeat().getNumber() << " " << Seat::typeName(showSeat.getSeat().getType()) << "\n";
        }
    }
};
