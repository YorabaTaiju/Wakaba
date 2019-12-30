/* coding: utf-8 */
/**
 * YorabaTaiju/Wakaba
 *
 * Copyright 2019-, Kaede Fujisaki
 */

#include "RenderPass.hpp"
#include "Vulkan.hpp"

namespace vk {

RenderPass::~RenderPass() noexcept{
  std::shared_ptr<Vulkan> vulkan =  vulkan_.lock();
  if(vulkan) {
    vkDestroyRenderPass(vulkan->vkDevice(), vkRenderPass_, nullptr);
  }
}

}
