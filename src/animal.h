#pragma once

#include <napi.h>

class Animal : public Napi::ObjectWrap<Animal> {
public:
  Animal(const Napi::CallbackInfo &);
  Napi::Value Greet(const Napi::CallbackInfo &);

  static Napi::Function GetClass(Napi::Env);

private:
  std::string _greeterName;
};
