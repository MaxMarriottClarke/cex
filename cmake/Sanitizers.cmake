# cmake/Sanitizers.cmake

# EnableProjectSanitizers(<kind> <targets...>)
# <kind> = "asan_ubsan" | "tsan" | OFF
function(_apply_sanitizers target kind)
  if(NOT TARGET ${target})
    return()
  endif()

  if(kind STREQUAL "asan_ubsan")
    target_compile_options(${target} PRIVATE
      -fsanitize=address,undefined
      -fno-omit-frame-pointer
      -g -O1)
    target_link_options(${target} PRIVATE
      -fsanitize=address,undefined
      -fno-omit-frame-pointer)
  elseif(kind STREQUAL "tsan")
    target_compile_options(${target} PRIVATE
      -fsanitize=thread
      -fno-omit-frame-pointer
      -g -O1)
    target_link_options(${target} PRIVATE
      -fsanitize=thread
      -fno-omit-frame-pointer)
  endif()
endfunction()

function(EnableProjectSanitizers kind)
  foreach(t IN LISTS ARGN)
    _apply_sanitizers(${t} ${kind})
  endforeach()
endfunction()