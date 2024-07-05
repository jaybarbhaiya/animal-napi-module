#pragma once

#include <napi.h>

class Animal : public Napi::ObjectWrap<Animal> {
public:
  Animal(const Napi::CallbackInfo &);
  Napi::Value CanFly(const Napi::CallbackInfo &);
  Napi::Value GetName(const Napi::CallbackInfo &);

  static Napi::Function GetClass(Napi::Env);

private:
  std::string _animalName;
  bool _canFly;
};
