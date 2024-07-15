#include <fstream>

class Shader {
    public:
        unsigned int id;
        Shader(const char* vertexFilePath, const char* fragmentFilePath);
        void use();
        void setUniform1f(const char* name, const float val);
        void setUniform2f(const char* name, const float val1, const float val2);
        void setUniform3f(const char* name, const float val1, const float val2, const float val3);
        void setUniform4f(const char* name, const float val1, const float val2, const float val3, const float val4);
        static void unuse();
};