#include <iostream>
#include <memory>
// using namespace std;
using std::cout;
using std::endl;
using std::string;
using std::unique_ptr;
using std::shared_ptr;
using std::weak_ptr;
using std::make_unique;
using std::make_shared;
using std::move;

class Song {
public:
    int duration;
    Song(string s1, string s2) : duration(5) {
        this->duration = s1.length() + s2.length();
    }
};

void UseRawPointer() {
    Song* pSong = new Song("Nothing on You", "Bruno Mars");
    delete pSong;
}

void UseSmartPointer() {
    // 1. unique_ptr - using new
    unique_ptr<Song> song2(new Song("show me", "the money!"));
    auto len = song2->duration;
    std::cout << len << std::endl;

    auto song3 = std::move(song2);
    len = song3->duration;
    std::cout << len << std::endl;

    // 2. unique_ptr - using make_unique
    auto song4 = make_unique<Song>("good", "bad");
    unique_ptr<Song> song5 = std::move(song4);

    // 3. shared_ptr - using new
    shared_ptr<Song> song_sp1(new Song("1", "2"));

    // 4. shared_ptr - using make_shared
    auto song_sp2 = make_shared<Song>("2", "3");
    cout << song_sp2.use_count() << endl;
    {
        auto song_sp3 = song_sp2;
        cout << song_sp3.use_count() << endl;
    }
    cout << song_sp2.use_count() << endl;

    // 5. weak_ptr
    weak_ptr<int> wp1;
    {
        shared_ptr<int>sp1 = make_shared<int>(25);
        wp1 = sp1;
        cout << "wp1.expired(): " << wp1.expired() << endl;
        cout << *sp1 << endl;
        weak_ptr<int> wp2(sp1);
        cout << wp2.expired() << endl;
    }
    cout << "wp1.expired(): " << wp1.expired() << endl;
}

int main(void) {
    UseRawPointer();
    UseSmartPointer();

    return 0;
}