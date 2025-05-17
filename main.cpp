#include "person.pb.h"
#include <iostream>
#include <string>
#include "emscripten/bind.h"

#define PROTOBUF_NAMESPACE "google::protobuf"

class Decoder{
    public:
        Decoder::Decoder(){};
        Decoder::~Decoder(){};
        std::string decode(){
            return "Hello World";
        }
};
EMSCRIPTEN_BINDINGS(Decoder) {
    emscripten::class_<Decoder>("Decoder")
        .constructor<>()
        .function("decode", &Decoder::decode);
}