#include <map>
#include <iostream>

using namespace std;

struct Key {
    int m_i;

    Key() {
         m_i=0;
         cout << "Key()" << endl;
    }

    Key(Key const& base) {
        m_i = base.m_i;
        cout << "Key(Key const& base) " << base.m_i << endl;
    }

    Key(int i) {
        m_i = i;
        cout << "Key(int i) " << i << endl;
    }

    ~Key() {
        cout << "~Key() " << m_i << endl;
    }

    bool operator<( Key const& base ) const {
        cout << "bool operator<(Key const& base) " << m_i << ", " << base.m_i << endl;
        return m_i < base.m_i;
    }

};

struct Data {
    int m_i;

    Data() {
         m_i=0;
         cout << "Data()" << endl;
    }

    Data(Data const & base) {
        m_i = base.m_i;
        cout << "Data(Data const& base) " << base.m_i << endl;
    }

    Data(int i) {
        m_i = i;
        cout << "Data(int i) " << i << endl;
    }

    const Data& operator=(Data const& base) {
        m_i = base.m_i;
        cout << "bool operator=(Data const& base) " << m_i << endl;
        return *this;
    }

    ~Data() {
        cout << "~Data() " << m_i << endl;
    }
};

int main( int argc, char ** argv) {
    map<Key, Data> m;
    Key k(123);

    cout << "..." << endl;
    m[k] = {1};
    m[k] = {2};
    cout << "..." << endl;

    return 0;
}
