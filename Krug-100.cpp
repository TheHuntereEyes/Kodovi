#include <iostream>
#include <cmath>

using namespace std;

struct Tacka {
    double x;
    double y;

    Tacka(double a = 0., double b = 0.) {
        x = a;
        y = b;
    }

    double dist(const Tacka& t) const {
        return sqrt((x - t.x)*(x - t.x) + (y - t.y)*(y - t.y));
    }

};

ostream& operator << (ostream &out, const Tacka& t) {
    out << "(" << t.x << ", " << t.y << ")";
    return out;
}

istream& operator >> (istream &in, Tacka& t) {
    in >> t.x >> t.y;
    return in;
}

struct Krug {
    Tacka c;
    double r;

    Krug(Tacka t = Tacka(), double x = 0.) {
        c = t;
        r = x;
    }

};

ostream& operator << (ostream &out, const Krug& k) {
    out << "[" << k.c << ", " << k.r << "]";
    return out;
}

istream& operator >> (istream &in, Krug& k) {
    in >> k.c >> k.r;
    return in;
}

int main()
{
    char izbor;
        do {
        cout << "Program za rad sa krugom i tackom" << endl;
        cout << "Unesite krug: ";
        Krug k;
        cin >> k;

        cout << "Unesite broj tacaka: ";
        int N;
        cin >> N;
        Tacka t[N] = {};
        for(auto i = 0; i < N; ++i) {
            cout << "Unesit " << i+1 <<". tacku: ";
            cin >> t[i];
        }

        for(auto i = 0; i < N; ++i) {
            auto odg = "";

            if( t[i].dist(k.c) <= k.r )
                odg = " ";
            else
                odg = " NE ";

            cout << "Tacka " << t[i] << odg << "pripada krugu " << k << endl;
        }

        cout << "Da li zelite ponovo da unesete vrednosit? [d/n]: ";
        cin >> izbor;

    }while(izbor == 'D' || izbor == 'd');
    return 0;
}
