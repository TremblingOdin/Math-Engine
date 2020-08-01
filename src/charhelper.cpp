#include <memory>

using namespace std;

static class charhelper {

	public:
		static std::string unconstchar(const char* s);
};

std::string charhelper::unconstchar(const char *s) {
    int i;
    std::string res;
    for (i = 0; s[i] != '\0'; i++) {
        res[i] = s[i];
    }
    res[i] = '\0';
    return res;
}
