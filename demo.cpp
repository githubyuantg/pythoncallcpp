
#include <boost/python.hpp>
#include <boost/python/list.hpp>
#include <boost/python/extract.hpp>
#include <string>
#include <sstream>
#include <vector>

struct World
{
    void set(std::string msg) { mMsg = msg; }
    void many(boost::python::list msgs) {
        long l = len(msgs);
        std::stringstream ss;
        for (long i = 0; i<l; ++i) {
            if (i>0) ss << ", ";
            std::string s = boost::python::extract<std::string>(msgs[i]);
            ss << s;
        }
        mMsg = ss.str();
    }
    std::string greet() { return mMsg; }
    std::string mMsg;
};

struct CatYou
{

    int add(int a, int b) {
        return a + b;
    }

    std::string cat(int num, std::string str) {
        return str + std::to_string(num);
    }
};

char const* sayhi()
{
   return "hello, sayhi";
}

using namespace boost::python;

BOOST_PYTHON_MODULE(demo)
{
    class_<World>("World")
        .def("greet", &World::greet)
        .def("set", &World::set)
        .def("many", &World::many)
    ;

    class_<CatYou>("CatYou")
        .def("add", &CatYou::add)
        .def("cat", &CatYou::cat)
    ;

    def("sayhi", sayhi);
};