#include <fstream>

class Shader {
    public:
        unsigned int id;
        Shader(const char* vertexFilePath, const char* fragmentFilePath);
        void use();
        static void unuse();
};