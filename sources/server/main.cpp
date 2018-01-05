#include <external_things/Test/Test.hpp>
#include <utils/Loader.hpp>

int main() {
    Loader<Test>            loader("./lib/libTest.so");

    loader.Open();
    loader.Load("entryPoint");
    loader.getInstance()->helloWorld();
    loader.Close();
}