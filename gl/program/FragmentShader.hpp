//
// Created by kaede on 2019/09/24.
//

#pragma once

#include <memory>
#include "Shader.hpp"
#include "../../util/SharedUtil.hpp"

namespace gl {

class FragmentShader final : public Shader {
private:
  explicit FragmentShader(GLuint id);
public:
  static std::shared_ptr<FragmentShader> compile(util::Logger& log, std::string const& src);
private:
  ENABLE_SHARED_HELPER
};

}