/* coding: utf-8 */
/**
 * YorabaTaiju/Wakaba
 *
 * Copyright 2019-, Kaede Fujisaki
 */

#pragma once

#include <memory>
#include <utility>
#include "../../util/Shared.hpp"
#include "../ShaderModule.hpp"
#include "Shader.hpp"

namespace vk {

class Vulkan;
class ShaderModule;

/* protected class */
class VertexShader : public Shader {
public:
  VertexShader(VertexShader&&) = delete;
  VertexShader(VertexShader const&) = delete;
  VertexShader& operator=(VertexShader&&) = delete;
  VertexShader& operator=(VertexShader const&) = delete;
protected:
  explicit VertexShader(std::shared_ptr<Vulkan> const& vulkan, std::shared_ptr<ShaderModule> module)
  :Shader(vulkan,std::move(module))
  {
  }

public:
  ~VertexShader() noexcept override;
};

}