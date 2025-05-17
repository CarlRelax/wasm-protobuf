#include "person.pb.h"
#include <iostream>
#include <string>
#include "emscripten/bind.h"

#define PROTOBUF_NAMESPACE "google::protobuf"

class Decoder{
    public:
        Decoder(){}
        ~Decoder(){}
        std::string decode(const std::string& data){
            Person person;
            person.ParseFromString(data);
            std::cout << "Name: " << person.name() << std::endl;
            return person.DebugString();
        }
};
EMSCRIPTEN_BINDINGS(decoder) {
    emscripten::class_<Decoder>("Decoder")
        .constructor<>()
        .function("decode", &Decoder::decode);
}