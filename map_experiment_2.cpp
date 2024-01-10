#include <map>
#include <iostream>
#include <cstring>

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

struct static_string_if {
    virtual ~static_string_if() {}

    virtual operator char const*() const = 0;
};

template<int N> class static_string : public static_string_if {
    char m_buffer[N+1];

public:
    static_string() {
        *m_buffer = 0;
    }

    static_string(static_string const& other) {
        strncpy(m_buffer, other.m_buffer, N);
        m_buffer[N] = 0;
    }

    static_string(char const* in) {
        strncpy(m_buffer, in, N);
        m_buffer[N]=0;
    }

    static_string<N> const& operator=(static_string const& other) {
        strncpy(m_buffer, other.m_buffer, N);
        m_buffer[N] = 0;
        return *this;
    }

    virtual operator char const*() const {
        return m_buffer;
    }

    static_string& operator <<(static_string_if& other) {
        strncat(m_buffer, other, N - strlen(m_buffer));
        return *this;
    }
};


int main( int argc, char ** argv) {
    map<Key, static_string<32>> m;
    Key k(123);

    cout << "..." << endl;
    m[k] = {"Hello world!"};
    cout << static_cast<char const*>(m[k]) << endl;
    m[k] = {"Goodbye world!"};
    cout << static_cast<char const*>(m[k]) << endl;
    cout << "..." << endl;

    static_string<64> s1("Hello world!");
    static_string<1>  s2(" ");
    static_string<32> s3("Goodbye world!");

    s1 << s2 << s3;
    cout << static_cast<char const *>(s1) << endl;
    
    return 0;
}
