# ====== SRC =============

PROJECT(SurfaceEvolverGUI VERSION 1.0.0)

find_package(VTK REQUIRED
  vtkGUISupportQt
  vtkCommonColor
  vtkCommonCore
  vtkIOCore
  vtkIOLegacy
  vtkIOImport
  vtkIOExport
  vtkFiltersSources
  vtkInteractionStyle
  vtkRenderingContextOpenGL2
  vtkRenderingCore
  vtkRenderingFreeType
  vtkRenderingGL2PSOpenGL2
  vtkRenderingOpenGL2
  QUIET
)

if (NOT VTK_FOUND)
  message("Skipping SurfaceEvolverGUI: ${VTK_NOT_FOUND_MESSAGE}")
  return ()
endif()
message (STATUS "VTK_VERSION: ${VTK_VERSION}")

if(vtkGUISupportQt_LOADED OR TARGET VTK::GUISupportQt)
  if (VTK_VERSION VERSION_LESS "8.90.0")
    # Instruct CMake to run moc automatically when needed.
    set(CMAKE_AUTOMOC ON)
  else()
     # Instruct CMake to run moc automatically when needed.
    set(CMAKE_AUTOMOC ON)
    set(CMAKE_AUTOUIC ON)
  endif()
  # We have ui files, this will bring in the macro: qt5_wrap_ui
  find_package(Qt5Widgets REQUIRED QUIET)
else()
  message(STATUS "GuiSupportQt not found.")
  return()
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

# UI .ui
file(GLOB UI_FILES *.ui)

# WRAPPED HEADERS .h
file(GLOB QT_WRAPPED_H *.h)

# WRAPPED SOURCE .cpp
file(GLOB QT_WRAPPED_CPP *.cpp)

qt5_wrap_ui(UISrcs ${UI_FILES})

add_library(POLY2TRI
    poly2tri/poly2tri.h 
    poly2tri/common/shapes.cc 
    poly2tri/common/shapes.h
    poly2tri/common/utils.h
    poly2tri/sweep/advancing_front.cc 
    poly2tri/sweep/advancing_front.h
    poly2tri/sweep/cdt.cc 
    poly2tri/sweep/cdt.h
    poly2tri/sweep/sweep.cc 
    poly2tri/sweep/sweep.h
    poly2tri/sweep/sweep_context.cc 
    poly2tri/sweep/sweep_context.h
)

if (VTK_VERSION VERSION_LESS "8.90.0")
  # old system
  include(${VTK_USE_FILE})
  # CMAKE_AUTOMOC in ON so the MOC headers will be automatically wrapped.
  add_executable(SurfaceEvolverGUI MACOSX_BUNDLE
    ${QT_WRAPPED_CPP} ${UISrcs} ${QT_WRAPPED_H})
  qt5_use_modules(SurfaceEvolverGUI Core Gui Widgets)
  target_link_libraries(SurfaceEvolverGUI ${VTK_LIBRARIES} POLY2TRI)
else()
  # CMAKE_AUTOMOC in ON so the MOC headers will be automatically wrapped.
  add_executable(SurfaceEvolverGUI MACOSX_BUNDLE
    ${QT_WRAPPED_CPP} ${UISrcs} ${QT_WRAPPED_H})
  qt5_use_modules(SurfaceEvolverGUI Core Gui Widgets)
  target_link_libraries(SurfaceEvolverGUI ${VTK_LIBRARIES} POLY2TRI)
  # vtk_module_autoinit is needed
  vtk_module_autoinit(
    TARGETS SurfaceEvolverGUI
    MODULES ${VTK_LIBRARIES}
  )
endif()

add_custom_command(TARGET ${PROJECT_NAME}
                   POST_BUILD
                   COMMAND "windeployqt.exe" "$(OutDir)$(TargetName)$(TargetExt)"
                   COMMENT "Win deploy qt")