#include "animal.h"

using namespace Napi;

Animal::Animal(const Napi::CallbackInfo &info) : ObjectWrap(info) {
  Napi::Env env = info.Env();

  if (info.Length() < 2) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
    return;
  }

  if (!info[0].IsString()) {
    Napi::TypeError::New(env, "Specify the name as a string for the animal")
        .ThrowAsJavaScriptException();
    return;
  }

  if (!info[1].IsBoolean()) {
    Napi::TypeError::New(
        env, "Specify a boolean value to determine if the animal can fly")
        .ThrowAsJavaScriptException();
    return;
  }

  this->_animalName = info[0].As<Napi::String>().Utf8Value();
  this->_canFly = info[1].As<Napi::Boolean>();
}

Napi::Value Animal::GetName(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();

  printf("Animal's name is %s\n", this->_animalName.c_str());

  return Napi::String::New(env, this->_animalName);
}

Napi::Value Animal::CanFly(const Napi::CallbackInfo &info) {
  Napi::Env env = info.Env();

  if (this->_canFly) {
    printf("%s can fly\n", this->_animalName.c_str());
  } else {
    printf("%s cannot fly\n", this->_animalName.c_str());
  }
  return Napi::Boolean::New(env, this->_canFly);
}

Napi::Function Animal::GetClass(Napi::Env env) {
  return DefineClass(env, "Animal",
                     {
                         Animal::InstanceMethod("getName", &Animal::GetName),
                         Animal::InstanceMethod("canFly", &Animal::CanFly),
                     });
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  Napi::String name = Napi::String::New(env, "Animal");
  exports.Set(name, Animal::GetClass(env));
  return exports;
}

NODE_API_MODULE(addon, Init)
