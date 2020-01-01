/* coding: utf-8 */
/**
 * YorabaTaiju/Wakaba
 *
 * Copyright 2019-, Kaede Fujisaki
 */

#pragma once

#include <memory>
#include <string>

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace vk{
class Vulkan;

class ShaderModule final {
private:
  friend class Vulkan;
  std::weak_ptr<Vulkan> vulkan_;
  std::string name_;
  VkShaderModule vkShaderModule_;
public:
  ShaderModule() = delete;
  ShaderModule(ShaderModule const&) = delete;
  ShaderModule(ShaderModule&&) = default;
  ShaderModule& operator=(ShaderModule const&) = delete;
  ShaderModule& operator=(ShaderModule&&) = default;

private:
  explicit ShaderModule(std::weak_ptr<Vulkan> vulkan, std::string name, VkShaderModule shaderModule)
  : vulkan_(std::move(vulkan))
  , name_(std::move(name))
  , vkShaderModule_(shaderModule) {
  }

public:
  static ShaderModule create(std::shared_ptr<Vulkan> const& vulkan, uint32_t const* code, size_t length, const char* className) noexcept (false);

public:
  ~ShaderModule() noexcept;
  [[ nodiscard ]] VkShaderModule vkShaderModule() { return this->vkShaderModule_; };
  [[ nodiscard ]] std::string const& name() const { return this->name_; };
};

}
