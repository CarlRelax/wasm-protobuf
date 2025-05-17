# wasm-protobuf
provide a solution of producing wasm with protobuf v3.20.1 in emscripten sdk and using it in js/ts with webENV.

# build
1. install emscripten SDK
```bash
   git clone https://github.com/emscripten-core/emsdk.git
```
2. install protobuf
```bash
   git clone https://github.com/protocolbuffers/protobuf.git
   cd protobuf
   git checkout v3.20.1
   ./autogen.sh
   emconfigure ./autogen.sh --disable-shared
   emmake make -j8
```
3. build your own project
```bash
./build.sh
```
# usage
```javascript
import Decoder from "./wasm-output/wasm_protobuf";
Decoder.then((decoder)=> {
    if(decoder) {
        const out_str = decoder.decode(data);
        console.log(out_str);
    }
})
```