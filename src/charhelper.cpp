

static class charhelper {

	public:
		static char* unconstchar(const char* s) {
			int i;
			char* res = new char[256];
			for (i = 0; s[i] != '\0'; i++) {
				res[i] = s[i];
			}
			res[i] = '\0';
			return res;
		}
};