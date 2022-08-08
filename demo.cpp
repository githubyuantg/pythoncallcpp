
#include <boost/python.hpp>
#include <boost/python/list.hpp>
#include <boost/python/extract.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
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

typedef std::vector<int> tlist;
class Clslst {
    public:
    Clslst() {

    }

    void setvec(const boost::python::object& iterable) {
        std::vector<int> vec = std::vector<int>(boost::python::stl_input_iterator<int>(iterable),
                            boost::python::stl_input_iterator<int>());
        vec_ = vec;
    };

    boost::python::list getvec() {
        typename std::vector<int>::iterator iter;
        boost::python::list list;
        for (iter = vec_.begin(); iter != vec_.end(); ++iter) {
            list.append(*iter);
        }
        return list;
    }

    int sum() const {
        int s = 0;
        for (const auto i : vec_) {
            s += i;
        }
        return s;
    }
    private:
    tlist vec_;
};

BOOST_PYTHON_MODULE(demo)
{
    boost::python::class_<World>("World")
        .def("greet", &World::greet)
        .def("set", &World::set)
        .def("many", &World::many)
    ;

    boost::python::class_<CatYou>("CatYou")
        .def("add", &CatYou::add)
        .def("cat", &CatYou::cat)
    ;

    boost::python::def("sayhi", sayhi);

    boost::python::class_<tlist>("tlist")
        .def(boost::python::vector_indexing_suite<tlist>() );
    boost::python::class_<Clslst>("Clslst")
        .def("setvec", &Clslst::setvec)
        .def("getvec", &Clslst::getvec)
        .def("sum", &Clslst::sum);
};